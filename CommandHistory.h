#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "BDD.h"
#include "ClientFinder.h"
#include "AddAddressToCommand.h"
#include "Cart.h"
#include "Command.h"
#include "CHistoryRepository.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Description résumée de CommandHistory
	/// </summary>
	public ref class CommandHistory : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		bool delOrRestore;
		CHistory^ sharedComHist;
		Command^ addClient;
		CHistoryRepository^ cHistoryRepository;
		System::Threading::Mutex^ reloadMutex;
		System::Windows::Forms::CheckBox^ CboxDeletedLines;
	private: System::Windows::Forms::Button^ BtnAddCommand;



		   System::Windows::Forms::Button^ BtnDelete;
	public:
		CommandHistory(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();

			reloadMutex = gcnew System::Threading::Mutex();
			// référence, date de livraison, daet d'émission, les dates de paiement, moyen de paiement, date à laquelle le règlement est enregistré 
			DGVOrderHistory->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcIdCommand = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdCommand->Name = "Références";
			this->DGVOrderHistory->Columns->Add(dgvtbcIdCommand);
			DataGridViewTextBoxColumn^ dgvtbcOrderDate = gcnew DataGridViewTextBoxColumn();
			dgvtbcOrderDate->Name = "Date de commande";
			this->DGVOrderHistory->Columns->Add(dgvtbcOrderDate);
			DataGridViewTextBoxColumn^ dgvtbcDeliveryDate = gcnew DataGridViewTextBoxColumn();
			dgvtbcDeliveryDate->Name = "Date de livraison";
			this->DGVOrderHistory->Columns->Add(dgvtbcDeliveryDate);
			DataGridViewTextBoxColumn^ dgvtbcPaiement = gcnew DataGridViewTextBoxColumn();
			dgvtbcPaiement->Name = "Paiement";
			this->DGVOrderHistory->Columns->Add(dgvtbcPaiement);

			cHistoryRepository = gcnew CHistoryRepository(mabdd);

			this->reload();

		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<CHistory^>^ commands = cHistoryRepository->getCommand();
				this->DGVOrderHistory->Rows->Clear();
				for each (CHistory ^ command in commands) {

					DataGridViewRow^ dgvr = gcnew DataGridViewRow();

					DataGridViewTextBoxCell^ dgvcIdCommand = gcnew DataGridViewTextBoxCell();
					dgvcIdCommand->Value = command->getIdCommand();
					dgvr->Cells->Add(dgvcIdCommand);
					DataGridViewTextBoxCell^ dgvcOrderDate = gcnew DataGridViewTextBoxCell();
					DateTime^ orderDate = command->getOrderDate();
					dgvcOrderDate->Value = orderDate->ToString("yyyy-MM-dd");
					dgvr->Cells->Add(dgvcOrderDate);
					DataGridViewTextBoxCell^ dgvcDeliveryDate = gcnew DataGridViewTextBoxCell();
					DateTime^ deliveryDate = command->getDeliveryDate();
					dgvcDeliveryDate->Value = deliveryDate->ToString("yyyy-MM-dd");
					dgvr->Cells->Add(dgvcDeliveryDate);

					DataGridViewTextBoxCell^ dgvcPaiement = gcnew DataGridViewTextBoxCell();
					Decimal totalPaye = Decimal(0);
					for each (InstallmentPayment ^ ip in command->getPayments()) {
						totalPaye = Decimal::Add(totalPaye, ip->getAmount());
					}
					dgvcPaiement->Value = totalPaye + "";
					dgvr->Cells->Add(dgvcPaiement);
					/*
					DataGridViewTextBoxCell^ dgvcInstallmentNumber = gcnew DataGridViewTextBoxCell();
					dgvcInstallmentNumber->Value = command->getInstallmentNumber();
					dgvr->Cells->Add(dgvcInstallmentNumber);
					DataGridViewTextBoxCell^ dgvcBalancePaymentDate = gcnew DataGridViewTextBoxCell();
					DateTime^ balancePaymentDate = command->getBalancePaymentDate();
					dgvcBalancePaymentDate->Value = balancePaymentDate->ToString("yyyy-MM-dd");
					dgvr->Cells->Add(dgvcBalancePaymentDate);
					DataGridViewTextBoxCell^ dgvcPaymentDate = gcnew DataGridViewTextBoxCell();
					DateTime^ paymentDate = command->getPaymentDate();
					dgvcPaymentDate->Value = paymentDate->ToString("yyyy-MM-dd");
					dgvr->Cells->Add(dgvcPaymentDate);
					DataGridViewTextBoxCell^ dgvcPaymentMode = gcnew DataGridViewTextBoxCell();
					dgvcPaymentMode->Value = command->getPaymentMode();
					dgvr->Cells->Add(dgvcPaymentMode);
					DataGridViewTextBoxCell^ dgvcAmount = gcnew DataGridViewTextBoxCell();
					dgvcAmount->Value = command->getAmount();
					dgvr->Cells->Add(dgvcAmount);
					*/

					dgvr->Tag = command;
					this->DGVOrderHistory->Rows->Add(dgvr);

					this->BtnDelete = (gcnew System::Windows::Forms::Button());
					this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->BtnDelete->Size = System::Drawing::Size(135, 48);
					this->BtnDelete->TabIndex = 28;
					this->BtnDelete->UseVisualStyleBackColor = true;
					this->BtnDelete->Click += gcnew System::EventHandler(this, &CommandHistory::BtnDelete_Click);

					if (this->CboxDeletedLines->Checked) {
						this->BtnDelete->Text = L"Restaurer";
						this->BtnDelete->Location = System::Drawing::Point(1017, 464);
						System::Diagnostics::Debug::WriteLine("restaurer");
						delOrRestore = 0;
					}
					else {
						this->BtnDelete->Text = L"Supprimer";
						this->BtnDelete->Location = System::Drawing::Point(1017, 464);
						System::Diagnostics::Debug::WriteLine("supprimer");
						delOrRestore = 1;
					}
				}
				reloadMutex->ReleaseMutex();
			}
		}
	private: void launchReloadThread() {
		Thread^ reloadThread = gcnew Thread(gcnew ThreadStart(this, &CommandHistory::reload));
		reloadThread->Start();
	}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~CommandHistory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnModify;
		   System::Windows::Forms::DataGridView^ DGVOrderHistory;
		   System::Windows::Forms::Label^ Title;

		   /// <summary>
		   /// Variable nécessaire au concepteur.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		   /// le contenu de cette méthode avec l'éditeur de code.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CommandHistory::typeid));
			   this->BtnModify = (gcnew System::Windows::Forms::Button());
			   this->DGVOrderHistory = (gcnew System::Windows::Forms::DataGridView());
			   this->CboxDeletedLines = (gcnew System::Windows::Forms::CheckBox());
			   this->BtnAddCommand = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVOrderHistory))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // BtnModify
			   // 
			   this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnModify->Location = System::Drawing::Point(868, 356);
			   this->BtnModify->Margin = System::Windows::Forms::Padding(8, 6, 8, 6);
			   this->BtnModify->Name = L"BtnModify";
			   this->BtnModify->Size = System::Drawing::Size(204, 51);
			   this->BtnModify->TabIndex = 27;
			   this->BtnModify->Text = L"Modifier";
			   this->BtnModify->UseVisualStyleBackColor = true;
			   // 
			   // DGVOrderHistory
			   // 
			   this->DGVOrderHistory->AllowUserToAddRows = false;
			   this->DGVOrderHistory->AllowUserToDeleteRows = false;
			   this->DGVOrderHistory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->DGVOrderHistory->Location = System::Drawing::Point(26, 56);
			   this->DGVOrderHistory->Name = L"DGVOrderHistory";
			   this->DGVOrderHistory->ReadOnly = true;
			   this->DGVOrderHistory->Size = System::Drawing::Size(818, 486);
			   this->DGVOrderHistory->TabIndex = 25;
			   this->DGVOrderHistory->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CommandHistory::DGVOrderHistory_RowEnter);
			   // 
			   // CboxDeletedLines
			   // 
			   this->CboxDeletedLines->AutoSize = true;
			   this->CboxDeletedLines->Font = (gcnew System::Drawing::Font(L"Orkney", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->CboxDeletedLines->Location = System::Drawing::Point(912, 527);
			   this->CboxDeletedLines->Name = L"CboxDeletedLines";
			   this->CboxDeletedLines->Size = System::Drawing::Size(150, 38);
			   this->CboxDeletedLines->TabIndex = 29;
			   this->CboxDeletedLines->Text = L"Afficher les lignes \n supprimées";
			   this->CboxDeletedLines->UseVisualStyleBackColor = true;
			   this->CboxDeletedLines->CheckedChanged += gcnew System::EventHandler(this, &CommandHistory::CboxDeletedLines_CheckedChanged);
			   // 
			   // BtnAddCommand
			   // 
			   this->BtnAddCommand->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnAddCommand->Location = System::Drawing::Point(868, 94);
			   this->BtnAddCommand->Margin = System::Windows::Forms::Padding(8, 6, 8, 6);
			   this->BtnAddCommand->Name = L"BtnAddCommand";
			   this->BtnAddCommand->Size = System::Drawing::Size(204, 51);
			   this->BtnAddCommand->TabIndex = 30;
			   this->BtnAddCommand->Text = L"Nouvelle commande";
			   this->BtnAddCommand->UseVisualStyleBackColor = true;
			   this->BtnAddCommand->Click += gcnew System::EventHandler(this, &CommandHistory::BtnAddCommand_Click);
			   // 
			   // CommandHistory
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 17);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->MaximizeBox = false;
			   this->AutoSize = true;
			   this->ClientSize = System::Drawing::Size(1100, 700);
			   this->Controls->Add(this->BtnAddCommand);
			   this->Controls->Add(this->CboxDeletedLines);
			   this->Controls->Add(this->BtnModify);
			   this->Controls->Add(this->DGVOrderHistory);
			   this->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Location = System::Drawing::Point(317, 9);
			   this->Margin = System::Windows::Forms::Padding(8, 6, 8, 6);
			   this->Name = L"CommandHistory";
			   this->Text = L"CommandHistory";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVOrderHistory))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
		   
#pragma endregion
	private: System::Void BtnAddCommand_Click(System::Object^ sender, System::EventArgs^ e) {
		addClient = gcnew Command();
		ClientFinder^ clientFinderForm = gcnew ClientFinder(mabdd, addClient);
		clientFinderForm->ShowDialog();
		int tempo = addClient->getIdClient();
		if (tempo > 0) {
			AddAddressToCommand^ cartCommandAddress = gcnew AddAddressToCommand(mabdd, addClient);
			cartCommandAddress->ShowDialog();
			System::Diagnostics::Debug::WriteLine(addClient->getNameCityDelivery());
			Cart^ cartForm = gcnew Cart(mabdd, addClient);
			cartForm->ShowDialog();
		}
	}
	String^ generateCommandReference() {
		addClient->getFirstNameClient();
		addClient->getLastNameClient();
		//addClient->getOrderDate();
		addClient->getNameCityDelivery();
		// ajouter le numéro incrémentiel de la commande
		String^ generatedValue;
		return generatedValue;
	}
	private: System::Void CboxDeletedLines_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->reload();
	}
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Debug::WriteLine(sharedComHist + " voilà a");
		cHistoryRepository->deleteArticle(sharedComHist, delOrRestore);
		this->reload();
	}
	private: System::Void DGVOrderHistory_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVOrderHistory->Rows[e->RowIndex];
			sharedComHist = (CHistory^)sharedDgvrRow->Tag;
			System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedComHist->ToString());

		}
	}
	};
}
