#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "BDD.h"
#include "FormVisioCommandRepository.h"
#include "Command.h"
namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Description r�sum�e de Cart
	/// </summary>
	public ref class FormVisioCommand : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		FormVisioCommandRepository^ cartRepository;
		Thread^ reloadThread;
		Command^ command;
		String^ idCommand;
		float totalAmount;
	private: System::Windows::Forms::NumericUpDown^ NudFirstMonth;
	private: System::Windows::Forms::NumericUpDown^ NudSecondMonth;
	private: System::Windows::Forms::NumericUpDown^ NudThirdMonth;
		   System::Threading::Mutex^ reloadMutex;
	public:
		FormVisioCommand(BDD^ mabdd, String^ idCommand)
		{
			this->idCommand = idCommand;
			this->mabdd = mabdd;
			//totalAmount = this->command->getCommandAmount();
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			reloadMutex = gcnew System::Threading::Mutex();

			DGVCommand->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcReference = gcnew DataGridViewTextBoxColumn();
			dgvtbcReference->Name = "Références";
			this->DGVCommand->Columns->Add(dgvtbcReference);
			DataGridViewTextBoxColumn^ dgvtbcNameArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcNameArticle->Name = "Nom de l'article";
			this->DGVCommand->Columns->Add(dgvtbcNameArticle);
			DataGridViewTextBoxColumn^ dgvtbcIdArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdArticle->Name = "IdArticle";
			this->DGVCommand->Columns->Add(dgvtbcIdArticle);
			DataGridViewTextBoxColumn^ dgvtbcQuantity = gcnew DataGridViewTextBoxColumn();
			dgvtbcQuantity->Name = "Quantité";
			this->DGVCommand->Columns->Add(dgvtbcQuantity);
			DataGridViewTextBoxColumn^ dgvtbcPriceATI = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceATI->Name = "Prix TCC de l'article";
			this->DGVCommand->Columns->Add(dgvtbcPriceATI);
			DataGridViewTextBoxColumn^ dgvtbcTotalPrice = gcnew DataGridViewTextBoxColumn();
			dgvtbcTotalPrice->Name = "Prix total";
			this->DGVCommand->Columns->Add(dgvtbcTotalPrice);
			cartRepository = gcnew FormVisioCommandRepository(mabdd);

			this->reload();
		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Command^>^ articles = cartRepository->getArticle(idCommand);
				//this->DGVCart->Rows->Clear();
				for each (Command ^ a in articles) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();

					DataGridViewTextBoxCell^ dgvcReference = gcnew DataGridViewTextBoxCell();
					dgvcReference->Value = a->getReference();
					dgvr->Cells->Add(dgvcReference);
					DataGridViewTextBoxCell^ dgvcPriceATI = gcnew DataGridViewTextBoxCell();
					DataGridViewTextBoxCell^ dgvcName = gcnew DataGridViewTextBoxCell();
					DataGridViewTextBoxCell^ dgvcIdArticle = gcnew DataGridViewTextBoxCell();
					Decimal^ PriceATI = Decimal(0);
					String^ Name;
					String^ IdArticle;
					for each (Article ^ art in a->getArticle()) {
						PriceATI = (Decimal^)art->getPriceATI();
						Name = (String^)art->getName();
						IdArticle = (String^)art->getIdArticle();
					}
					dgvcPriceATI->Value = PriceATI;
					dgvcName->Value = Name;
					dgvr->Cells->Add(dgvcName);
					dgvcIdArticle->Value = IdArticle;
					dgvr->Cells->Add(dgvcIdArticle);
					DataGridViewTextBoxCell^ dgvcQuantity = gcnew DataGridViewTextBoxCell();
					dgvcQuantity->Value = a->getQuantity();
					dgvr->Cells->Add(dgvcQuantity);
					dgvr->Cells->Add(dgvcPriceATI);

					DataGridViewTextBoxCell^ dgvcTotal = gcnew DataGridViewTextBoxCell();
					totalAmount = a->getQuantity() * Convert::ToSingle(PriceATI);
					 dgvcTotal->Value = totalAmount;
					dgvr->Cells->Add(dgvcTotal);

					dgvr->Tag = a;
					this->DGVCommand->Rows->Add(dgvr);

				}
				reloadMutex->ReleaseMutex();
			}
		}
		void launchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &FormVisioCommand::reload));
			reloadThread->Start();
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FormVisioCommand()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ DGVCommand;
	protected:


	protected:




	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormVisioCommand::typeid));
			this->DGVCommand = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVCommand))->BeginInit();
			this->SuspendLayout();
			// 
			// DGVCommand
			// 
			this->DGVCommand->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVCommand->Location = System::Drawing::Point(51, 45);
			this->DGVCommand->Name = L"DGVCommand";
			this->DGVCommand->Size = System::Drawing::Size(597, 428);
			this->DGVCommand->TabIndex = 0;
			// 
			// FormVisioCommand
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(695, 515);
			this->Controls->Add(this->DGVCommand);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormVisioCommand";
			this->Text = L"FormVisioCommand";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVCommand))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
