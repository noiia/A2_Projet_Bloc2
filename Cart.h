﻿#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "BDD.h"
#include "AddArticleToCommand.h"
#include "CartRepository.h"
#include "Command.h"
#include "PaymentForm.h"
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
	public ref class Cart : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		CartRepository^ cartRepository;
		Command^ sharedA;
		Thread^ reloadThread;
		Command^ command;
		float totalCart;
	private: System::Windows::Forms::Button^ BtnReturn;

		   System::Threading::Mutex^ reloadMutex;
	public:
		Cart(BDD^ mabdd, Command^ command)
		{
			this->command = command;
			this->mabdd = mabdd;
			InitializeComponent();
			reloadMutex = gcnew System::Threading::Mutex();

			DGVCart->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcNameArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcNameArticle->Name = "IdArticle";
			this->DGVCart->Columns->Add(dgvtbcNameArticle);
			DataGridViewTextBoxColumn^ dgvtbcIdArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdArticle->Name = "Nom de l'article";
			this->DGVCart->Columns->Add(dgvtbcIdArticle);
			DataGridViewTextBoxColumn^ dgvtbcQuantity = gcnew DataGridViewTextBoxColumn();
			dgvtbcQuantity->Name = "Quantité";
			this->DGVCart->Columns->Add(dgvtbcQuantity);
			DataGridViewTextBoxColumn^ dgvtbcPriceATI = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceATI->Name = "Prix TCC de l'article";
			this->DGVCart->Columns->Add(dgvtbcPriceATI);
			DataGridViewTextBoxColumn^ dgvtbcTotalPrice = gcnew DataGridViewTextBoxColumn();
			dgvtbcTotalPrice->Name = "Prix total";
			this->DGVCart->Columns->Add(dgvtbcTotalPrice);
			cartRepository = gcnew CartRepository(mabdd);

			this->reload();
		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Command^>^ articles = cartRepository->getArticle(command->getReference());
				this->DGVCart->Rows->Clear();
				for each (Command ^ a in articles) {
					Decimal^ PriceATI = Decimal(0);
					String^ Name;
					String^ IdArticle;
					for each (Article ^ art in a->getArticle()) {
						IdArticle = (String^)art->getIdArticle();
						PriceATI = (Decimal^)art->getPriceATI();
						Name = (String^)art->getName();
					}
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdArticle = gcnew DataGridViewTextBoxCell();
					DataGridViewTextBoxCell^ dgvcName = gcnew DataGridViewTextBoxCell();
					DataGridViewTextBoxCell^ dgvcPriceATI = gcnew DataGridViewTextBoxCell();
					DataGridViewTextBoxCell^ dgvcQuantity = gcnew DataGridViewTextBoxCell();
					DataGridViewTextBoxCell^ dgvcTotal = gcnew DataGridViewTextBoxCell();

					dgvcPriceATI->Value = PriceATI;
					dgvcName->Value = Name;
					dgvcIdArticle->Value = IdArticle;
					dgvcQuantity->Value = a->getQuantity();
					dgvcTotal->Value = a->getQuantity() * Convert::ToSingle(PriceATI);

					dgvr->Cells->Add(dgvcIdArticle);
					dgvr->Cells->Add(dgvcName);
					dgvr->Cells->Add(dgvcQuantity);
					dgvr->Cells->Add(dgvcPriceATI);
					dgvr->Cells->Add(dgvcTotal);

					dgvr->Tag = a;
					this->DGVCart->Rows->Add(dgvr);
					totalCart += Convert::ToSingle(dgvcTotal->Value);
					this->LbTotal->Text = "Sous-total : " + totalCart + " €";
					command->setCommandAmount(totalCart);
				}
				reloadMutex->ReleaseMutex();
			}
		}
		void launchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &Cart::reload));
			reloadThread->Start();
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~Cart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
		   System::Windows::Forms::Button^ BtnAddArticle;
		   System::Windows::Forms::Button^ BtnDelete;
		   System::Windows::Forms::DataGridView^ DGVCart;
		   System::Windows::Forms::Button^ BtnPayCart;
		   System::Windows::Forms::Button^ BtnModify;
		   System::Windows::Forms::Label^ LbTotal;

		   /// <summary>
		   /// Variable n�cessaire au concepteur.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		   /// le contenu de cette m�thode avec l'�diteur de code.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Cart::typeid));
			   this->Title = (gcnew System::Windows::Forms::Label());
			   this->BtnAddArticle = (gcnew System::Windows::Forms::Button());
			   this->BtnDelete = (gcnew System::Windows::Forms::Button());
			   this->DGVCart = (gcnew System::Windows::Forms::DataGridView());
			   this->BtnPayCart = (gcnew System::Windows::Forms::Button());
			   this->BtnModify = (gcnew System::Windows::Forms::Button());
			   this->LbTotal = (gcnew System::Windows::Forms::Label());
			   this->BtnReturn = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVCart))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // Title
			   // 
			   this->Title->AutoSize = true;
			   this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Title->Location = System::Drawing::Point(101, 9);
			   this->Title->Name = L"Title";
			   this->Title->Size = System::Drawing::Size(0, 28);
			   this->Title->TabIndex = 0;
			   this->Title->Text = "Commande " + command->getReference();
			   // 
			   // BtnAddArticle
			   // 
			   this->BtnAddArticle->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnAddArticle->Location = System::Drawing::Point(21, 479);
			   this->BtnAddArticle->Name = L"BtnAddArticle";
			   this->BtnAddArticle->Size = System::Drawing::Size(111, 42);
			   this->BtnAddArticle->TabIndex = 13;
			   this->BtnAddArticle->Text = L"Ajouter";
			   this->BtnAddArticle->UseVisualStyleBackColor = true;
			   this->BtnAddArticle->Click += gcnew System::EventHandler(this, &Cart::BtnAddCommand_Click);
			   // 
			   // BtnDelete
			   // 
			   this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnDelete->Location = System::Drawing::Point(424, 479);
			   this->BtnDelete->Name = L"BtnDelete";
			   this->BtnDelete->Size = System::Drawing::Size(111, 42);
			   this->BtnDelete->TabIndex = 14;
			   this->BtnDelete->Text = L"Supprimer";
			   this->BtnDelete->UseVisualStyleBackColor = true;
			   this->BtnDelete->Click += gcnew System::EventHandler(this, &Cart::BtnDelete_Click);
			   // 
			   // DGVCart
			   // 
			   this->DGVCart->AllowUserToAddRows = false;
			   this->DGVCart->AllowUserToDeleteRows = false;
			   this->DGVCart->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->DGVCart->Location = System::Drawing::Point(21, 82);
			   this->DGVCart->Name = L"DGVCart";
			   this->DGVCart->ReadOnly = true;
			   this->DGVCart->Size = System::Drawing::Size(514, 381);
			   this->DGVCart->TabIndex = 15;
			   this->DGVCart->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Cart::DGVCart_CellMouseClick);
			   // 
			   // BtnPayCart
			   // 
			   this->BtnPayCart->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnPayCart->Location = System::Drawing::Point(424, 546);
			   this->BtnPayCart->Name = L"BtnPayCart";
			   this->BtnPayCart->Size = System::Drawing::Size(111, 42);
			   this->BtnPayCart->TabIndex = 16;
			   this->BtnPayCart->Text = L"Payer";
			   this->BtnPayCart->UseVisualStyleBackColor = true;
			   this->BtnPayCart->Click += gcnew System::EventHandler(this, &Cart::BtnPayCart_Click);
			   // 
			   // BtnModify
			   // 
			   this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnModify->Location = System::Drawing::Point(220, 479);
			   this->BtnModify->Name = L"BtnModify";
			   this->BtnModify->Size = System::Drawing::Size(111, 42);
			   this->BtnModify->TabIndex = 17;
			   this->BtnModify->Text = L"Modifier";
			   this->BtnModify->UseVisualStyleBackColor = true;
			   this->BtnModify->Click += gcnew System::EventHandler(this, &Cart::BtnModify_Click);
			   // 
			   // LbTotal
			   // 
			   this->LbTotal->AutoSize = true;
			   this->LbTotal->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbTotal->Location = System::Drawing::Point(188, 558);
			   this->LbTotal->Name = L"LbTotal";
			   this->LbTotal->Size = System::Drawing::Size(88, 19);
			   this->LbTotal->TabIndex = 18;
			   this->LbTotal->Text = L"Prix total : ";
			   // 
			   // BtnReturn
			   // 
			   this->BtnReturn->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnReturn->Location = System::Drawing::Point(21, 546);
			   this->BtnReturn->Name = L"BtnReturn";
			   this->BtnReturn->Size = System::Drawing::Size(111, 42);
			   this->BtnReturn->TabIndex = 19;
			   this->BtnReturn->Text = L"Retour";
			   this->BtnReturn->UseVisualStyleBackColor = true;
			   this->BtnReturn->Click += gcnew System::EventHandler(this, &Cart::BtnReturn_Click);
			   // 
			   // Cart
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(567, 615);
			   this->ControlBox = false;
			   this->Controls->Add(this->BtnReturn);
			   this->Controls->Add(this->LbTotal);
			   this->Controls->Add(this->BtnModify);
			   this->Controls->Add(this->BtnPayCart);
			   this->Controls->Add(this->DGVCart);
			   this->Controls->Add(this->BtnDelete);
			   this->Controls->Add(this->BtnAddArticle);
			   this->Controls->Add(this->Title);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MaximizeBox = false;
			   this->Name = L"Cart";
			   this->Text = L"Panier";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVCart))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void BtnAddCommand_Click(System::Object^ sender, System::EventArgs^ e) {
		Command^ addArticle = gcnew Command();
		AddArticleToCommand^ formAddArticleToCommand = gcnew AddArticleToCommand(mabdd, addArticle, command->getReference(), false);
		formAddArticleToCommand->ShowDialog();
		cartRepository->insertArticle(addArticle);
		this->reload();
	}
	private: System::Void BtnPayCart_Click(System::Object^ sender, System::EventArgs^ e) {
		PaymentForm^ formPayment = gcnew PaymentForm(mabdd, command);
		formPayment->ShowDialog();
		cartRepository->insertCommand(this->command->getNumberOfPayment(), command);
		this->Close();
	}
	private: System::Void BtnReturn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->DGVCart->RowCount < 1) {
			cartRepository->dropCommand(command);
		}
		this->Close();
	}
	private: System::Void BtnModify_Click(System::Object^ sender, System::EventArgs^ e) {
		Diagnostics::Debug::WriteLine(this->command->getIdArticleInCart());
		AddArticleToCommand^ formAddArticleToCommand = gcnew AddArticleToCommand(mabdd, sharedA, command->getReference(), true);
		formAddArticleToCommand->ShowDialog();
		System::Diagnostics::Debug::WriteLine(sharedA);
		cartRepository->editCommand(sharedA);
		this->reload();
	}
	private: System::Void DGVCart_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVCart->Rows[e->RowIndex];
			sharedA = (Command^)sharedDgvrRow->Tag;
			System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedA->ToString());
		}
	}
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		cartRepository->delArticle(sharedA);
		this->reload();
	}
	};
}