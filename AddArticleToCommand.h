#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "BDD.h"
#include "Article.h"
#include "Command.h"
#include "AAtoCRepository.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	/// <summary>
	/// Description résumée de AddArticleToCommand
	/// </summary>
	public ref class AddArticleToCommand : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		AAtoCRepository^ articleToCommand;
		Article^ article;
		Thread^ reloadThread;
		String^ sharedSearchedValue = "";
		Article^ clickedArticle;
		Command^ command;
		String^ commandReference;
		bool clicked = false;
		int research = 0;
	private: System::Windows::Forms::Label^ LbOr;

		   System::Threading::Mutex^ reloadMutex;

	public:
		AddArticleToCommand(BDD^ mabdd, Command^ command, String^ commandReference)
		{
			this->command = command;
			this->commandReference = commandReference;
			InitializeComponent();
			this->NudQuantity->ValueChanged += gcnew System::EventHandler(this, &AddArticleToCommand::CalculTotal);
			reloadMutex = gcnew System::Threading::Mutex();

			DGVArticle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcIdArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdArticle->Name = "Références";
			this->DGVArticle->Columns->Add(dgvtbcIdArticle);
			DataGridViewTextBoxColumn^ dgvtbcName = gcnew DataGridViewTextBoxColumn();
			dgvtbcName->Name = "Nom";
			this->DGVArticle->Columns->Add(dgvtbcName);
			DataGridViewTextBoxColumn^ dgvtbcType = gcnew DataGridViewTextBoxColumn();
			dgvtbcType->Name = "Type";
			this->DGVArticle->Columns->Add(dgvtbcType);
			DataGridViewTextBoxColumn^ dgvtbcPriceWT = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceWT->Name = "Prix HT";
			this->DGVArticle->Columns->Add(dgvtbcPriceWT);
			DataGridViewTextBoxColumn^ dgvtbcVAT = gcnew DataGridViewTextBoxColumn();
			dgvtbcVAT->Name = "TVA";
			this->DGVArticle->Columns->Add(dgvtbcVAT);
			DataGridViewTextBoxColumn^ dgvtbcPriceATI = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceATI->Name = "Prix TTC";
			this->DGVArticle->Columns->Add(dgvtbcPriceATI);
			DataGridViewTextBoxColumn^ dgvtbcStock = gcnew DataGridViewTextBoxColumn();
			dgvtbcStock->Name = "Stock";
			this->DGVArticle->Columns->Add(dgvtbcStock);
			DataGridViewTextBoxColumn^ dgvtbcTresholdLimit = gcnew DataGridViewTextBoxColumn();
			dgvtbcTresholdLimit->Name = "Limite avant réapprovisionnement";
			this->DGVArticle->Columns->Add(dgvtbcTresholdLimit);
			DataGridViewTextBoxColumn^ dgvtbcTresholdDate = gcnew DataGridViewTextBoxColumn();
			dgvtbcTresholdDate->Name = "Date de réapprovisionnement";
			this->DGVArticle->Columns->Add(dgvtbcTresholdDate);

			articleToCommand = gcnew AAtoCRepository(mabdd);

			this->reload();

		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Diagnostics::Debug::WriteLine(sharedSearchedValue);
				System::Collections::Generic::List<Article^>^ articles = articleToCommand->getArticle(sharedSearchedValue, research);
				this->DGVArticle->Rows->Clear();
				for each (Article ^ a in articles) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdArticle = gcnew DataGridViewTextBoxCell();
					dgvcIdArticle->Value = a->getIdArticle();
					dgvr->Cells->Add(dgvcIdArticle);
					DataGridViewTextBoxCell^ dgvcName = gcnew DataGridViewTextBoxCell();
					dgvcName->Value = a->getName();
					dgvr->Cells->Add(dgvcName);
					DataGridViewTextBoxCell^ dgvcType = gcnew DataGridViewTextBoxCell();
					dgvcType->Value = a->getKind();
					dgvr->Cells->Add(dgvcType);
					DataGridViewTextBoxCell^ dgvcPriceWT = gcnew DataGridViewTextBoxCell();
					dgvcPriceWT->Value = Convert::ToString(a->getPriceWT());
					dgvr->Cells->Add(dgvcPriceWT);
					DataGridViewTextBoxCell^ dgvcVAT = gcnew DataGridViewTextBoxCell();
					dgvcVAT->Value = Convert::ToString(a->getVAT());
					dgvr->Cells->Add(dgvcVAT);
					DataGridViewTextBoxCell^ dgvcPriceATI = gcnew DataGridViewTextBoxCell();
					dgvcPriceATI->Value = Convert::ToString(a->getPriceATI());
					dgvr->Cells->Add(dgvcPriceATI);
					DataGridViewTextBoxCell^ dgvcStock = gcnew DataGridViewTextBoxCell();
					dgvcStock->Value = Convert::ToString(a->getStock());
					dgvr->Cells->Add(dgvcStock);
					DataGridViewTextBoxCell^ dgvcRestockingLimit = gcnew DataGridViewTextBoxCell();
					dgvcRestockingLimit->Value = Convert::ToString(a->getRestockingLimit());
					dgvr->Cells->Add(dgvcRestockingLimit);
					DataGridViewTextBoxCell^ dgvcRestockingDate = gcnew DataGridViewTextBoxCell();
					DateTime^ restockingDate = a->getRestockingDate();
					dgvcRestockingDate->Value = restockingDate->ToString("yyyy-MM-dd");
					dgvr->Cells->Add(dgvcRestockingDate);
					dgvr->Tag = a;
					this->DGVArticle->Rows->Add(dgvr);
				}
				reloadMutex->ReleaseMutex();
			}
		}
		void launchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &AddArticleToCommand::reload));
			reloadThread->Start();
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~AddArticleToCommand()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnAddCommand;

		   System::Windows::Forms::TextBox^ TboxReferences;
		   System::Windows::Forms::Label^ LbQuantity;
		   System::Windows::Forms::Label^ LbReferences;
		   System::Windows::Forms::TextBox^ TboxArticleName;
		   System::Windows::Forms::Label^ LbArticleName;
		   System::Windows::Forms::Label^ LbPriceTxt;
		   System::Windows::Forms::Label^ LbPriceValue;
		   System::Windows::Forms::Button^ BtnResearchArticle;
	private: System::Windows::Forms::DataGridView^ DGVArticle;
	private: System::Windows::Forms::Label^ LbRefSelected;
	private: System::Windows::Forms::NumericUpDown^ NudQuantity;

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
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddArticleToCommand::typeid));
			   this->BtnAddCommand = (gcnew System::Windows::Forms::Button());
			   this->TboxReferences = (gcnew System::Windows::Forms::TextBox());
			   this->LbQuantity = (gcnew System::Windows::Forms::Label());
			   this->LbReferences = (gcnew System::Windows::Forms::Label());
			   this->TboxArticleName = (gcnew System::Windows::Forms::TextBox());
			   this->LbArticleName = (gcnew System::Windows::Forms::Label());
			   this->LbPriceTxt = (gcnew System::Windows::Forms::Label());
			   this->LbPriceValue = (gcnew System::Windows::Forms::Label());
			   this->BtnResearchArticle = (gcnew System::Windows::Forms::Button());
			   this->DGVArticle = (gcnew System::Windows::Forms::DataGridView());
			   this->LbRefSelected = (gcnew System::Windows::Forms::Label());
			   this->NudQuantity = (gcnew System::Windows::Forms::NumericUpDown());
			   this->LbOr = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVArticle))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudQuantity))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // BtnAddCommand
			   // 
			   this->BtnAddCommand->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnAddCommand->Location = System::Drawing::Point(786, 503);
			   this->BtnAddCommand->Name = L"BtnAddCommand";
			   this->BtnAddCommand->Size = System::Drawing::Size(111, 42);
			   this->BtnAddCommand->TabIndex = 22;
			   this->BtnAddCommand->Text = L"Ajouter";
			   this->BtnAddCommand->UseVisualStyleBackColor = true;
			   this->BtnAddCommand->Click += gcnew System::EventHandler(this, &AddArticleToCommand::BtnAddCommand_Click);
			   // 
			   // TboxReferences
			   // 
			   this->TboxReferences->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TboxReferences->Location = System::Drawing::Point(40, 47);
			   this->TboxReferences->Name = L"TboxReferences";
			   this->TboxReferences->Size = System::Drawing::Size(315, 26);
			   this->TboxReferences->TabIndex = 18;
			   // 
			   // LbQuantity
			   // 
			   this->LbQuantity->AutoSize = true;
			   this->LbQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbQuantity->Location = System::Drawing::Point(36, 360);
			   this->LbQuantity->Name = L"LbQuantity";
			   this->LbQuantity->Size = System::Drawing::Size(75, 19);
			   this->LbQuantity->TabIndex = 15;
			   this->LbQuantity->Text = L"Quantité";
			   // 
			   // LbReferences
			   // 
			   this->LbReferences->AutoSize = true;
			   this->LbReferences->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbReferences->Location = System::Drawing::Point(36, 25);
			   this->LbReferences->Name = L"LbReferences";
			   this->LbReferences->Size = System::Drawing::Size(82, 19);
			   this->LbReferences->TabIndex = 14;
			   this->LbReferences->Text = L"Référence";
			   // 
			   // TboxArticleName
			   // 
			   this->TboxArticleName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TboxArticleName->Location = System::Drawing::Point(40, 146);
			   this->TboxArticleName->Name = L"TboxArticleName";
			   this->TboxArticleName->Size = System::Drawing::Size(315, 26);
			   this->TboxArticleName->TabIndex = 24;
			   // 
			   // LbArticleName
			   // 
			   this->LbArticleName->AutoSize = true;
			   this->LbArticleName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbArticleName->Location = System::Drawing::Point(36, 124);
			   this->LbArticleName->Name = L"LbArticleName";
			   this->LbArticleName->Size = System::Drawing::Size(126, 19);
			   this->LbArticleName->TabIndex = 23;
			   this->LbArticleName->Text = L"Nom de l\'article";
			   // 
			   // LbPriceTxt
			   // 
			   this->LbPriceTxt->AutoSize = true;
			   this->LbPriceTxt->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbPriceTxt->Location = System::Drawing::Point(60, 455);
			   this->LbPriceTxt->Name = L"LbPriceTxt";
			   this->LbPriceTxt->Size = System::Drawing::Size(45, 19);
			   this->LbPriceTxt->TabIndex = 27;
			   this->LbPriceTxt->Text = L"Prix :";
			   // 
			   // LbPriceValue
			   // 
			   this->LbPriceValue->AutoSize = true;
			   this->LbPriceValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbPriceValue->Location = System::Drawing::Point(120, 455);
			   this->LbPriceValue->Name = L"LbPriceValue";
			   this->LbPriceValue->Size = System::Drawing::Size(0, 19);
			   this->LbPriceValue->TabIndex = 28;
			   // 
			   // BtnResearchArticle
			   // 
			   this->BtnResearchArticle->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnResearchArticle->Location = System::Drawing::Point(136, 189);
			   this->BtnResearchArticle->Name = L"BtnResearchArticle";
			   this->BtnResearchArticle->Size = System::Drawing::Size(111, 42);
			   this->BtnResearchArticle->TabIndex = 29;
			   this->BtnResearchArticle->Text = L"Rechercher";
			   this->BtnResearchArticle->UseVisualStyleBackColor = true;
			   this->BtnResearchArticle->Click += gcnew System::EventHandler(this, &AddArticleToCommand::BtnResearchArticle_Click);
			   // 
			   // DGVArticle
			   // 
			   this->DGVArticle->AllowUserToAddRows = false;
			   this->DGVArticle->AllowUserToDeleteRows = false;
			   this->DGVArticle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->DGVArticle->Location = System::Drawing::Point(420, 25);
			   this->DGVArticle->Name = L"DGVArticle";
			   this->DGVArticle->ReadOnly = true;
			   this->DGVArticle->Size = System::Drawing::Size(506, 437);
			   this->DGVArticle->TabIndex = 30;
			   this->DGVArticle->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &AddArticleToCommand::DGVArticle_CellMouseDoubleClick);
			   // 
			   // LbRefSelected
			   // 
			   this->LbRefSelected->AutoSize = true;
			   this->LbRefSelected->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbRefSelected->Location = System::Drawing::Point(36, 302);
			   this->LbRefSelected->Name = L"LbRefSelected";
			   this->LbRefSelected->Size = System::Drawing::Size(192, 19);
			   this->LbRefSelected->TabIndex = 31;
			   this->LbRefSelected->Text = L"Référence sélectionnée : ";
			   // 
			   // NudQuantity
			   // 
			   this->NudQuantity->Location = System::Drawing::Point(40, 395);
			   this->NudQuantity->Name = L"NudQuantity";
			   this->NudQuantity->Size = System::Drawing::Size(315, 20);
			   this->NudQuantity->TabIndex = 32;
			   // 
			   // LbOr
			   // 
			   this->LbOr->AutoSize = true;
			   this->LbOr->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbOr->Location = System::Drawing::Point(179, 87);
			   this->LbOr->Name = L"LbOr";
			   this->LbOr->Size = System::Drawing::Size(32, 19);
			   this->LbOr->TabIndex = 42;
			   this->LbOr->Text = L"Ou";
			   // 
			   // AddArticleToCommand
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(961, 571);
			   this->Controls->Add(this->LbOr);
			   this->Controls->Add(this->NudQuantity);
			   this->Controls->Add(this->LbRefSelected);
			   this->Controls->Add(this->DGVArticle);
			   this->Controls->Add(this->BtnResearchArticle);
			   this->Controls->Add(this->LbPriceValue);
			   this->Controls->Add(this->LbPriceTxt);
			   this->Controls->Add(this->TboxArticleName);
			   this->Controls->Add(this->LbArticleName);
			   this->Controls->Add(this->BtnAddCommand);
			   this->Controls->Add(this->TboxReferences);
			   this->Controls->Add(this->LbQuantity);
			   this->Controls->Add(this->LbReferences);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MaximizeBox = false;
			   this->Name = L"AddArticleToCommand";
			   this->Text = L"AddArticleToCommand";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVArticle))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudQuantity))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void BtnResearchArticle_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->TboxReferences->Text != "" && this->TboxArticleName->Text == "") {
			System::Diagnostics::Debug::WriteLine(this->TboxReferences->Text);
			sharedSearchedValue = this->TboxReferences->Text;
			research = 1;
			this->reload();
		}
		else if (this->TboxReferences->Text == "" && this->TboxArticleName->Text != "") {
			System::Diagnostics::Debug::WriteLine(this->TboxReferences->Text);
			sharedSearchedValue = this->TboxArticleName->Text;
			research = 2;
			this->reload();
		}
		else {
			research = 0;
		}
	}
	private: System::Void CalculTotal(System::Object^ sender, System::EventArgs^ e) {
		if (clicked) {
			float tempo = Decimal::ToSingle(this->NudQuantity->Value);
			float total = Convert::ToSingle(clickedArticle->getPriceATI()) * tempo;
			String^ formattedTotal = total.ToString("F2") + " €";
			this->LbPriceValue->Text = formattedTotal;
		}
	}
	private: System::Void DGVArticle_CellMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVArticle->Rows[e->RowIndex];
			clickedArticle = (Article^)sharedDgvrRow->Tag;
			this->LbRefSelected->Text = "Référence sélectionnée : " + clickedArticle->getIdArticle();
			clicked = true;
			this->NudQuantity->Maximum = clickedArticle->getStock();
		}

	}
	private: System::Void BtnAddCommand_Click(System::Object^ sender, System::EventArgs^ e) {
		this->command->setIdArticle(this->clickedArticle->getIdArticle());
		this->command->setReference(commandReference);
		this->command->setQuantity(Convert::ToInt32(this->NudQuantity->Value));
		this->Close();
	}
};
}
