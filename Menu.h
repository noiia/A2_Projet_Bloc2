#pragma once
#include "BDD.h"
#include "Order.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Menu
	/// </summary>
	public ref class Menu : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		Menu(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			DataGridViewTextBoxColumn^ dgvtbcReferences = gcnew DataGridViewTextBoxColumn();
			dgvtbcReferences->Name = "Référence";
			this->dgvCatalog->Columns->Add(dgvtbcReferences);
			DataGridViewTextBoxColumn^ dgvtbcQuantity = gcnew DataGridViewTextBoxColumn();
			dgvtbcQuantity->Name = "Quantité";
			this->dgvCatalog->Columns->Add(dgvtbcQuantity);
			DataGridViewTextBoxColumn^ dgvtbcRestock = gcnew DataGridViewTextBoxColumn();
			dgvtbcRestock->Name = "Date de restock";
			this->dgvCatalog->Columns->Add(dgvtbcRestock);

			DataSet^ ds = mabdd->executeQuery("SELECT * FROM Stock");

			for each (DataRow ^ row in ds->Tables[0]->Rows)
			{
				String^ references = (String^)row[0];
				System::Diagnostics::Debug::WriteLine("nom " + references);
				String^ quantity = (String^)row[1];
				System::Diagnostics::Debug::WriteLine("quantity " + quantity);
				String^ restock = (String^)row[2];
				System::Diagnostics::Debug::WriteLine("restock date " + restock);

				DataGridViewRow^ dgvr = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ dgvcReferences = gcnew DataGridViewTextBoxCell();
				dgvcReferences->Value = references;
				dgvr->Cells->Add(dgvcReferences);
				DataGridViewTextBoxCell^ dgvcQuantity = gcnew DataGridViewTextBoxCell();
				dgvcQuantity->Value = quantity;
				dgvr->Cells->Add(dgvcQuantity);
				DataGridViewTextBoxCell^ dgvcRestock = gcnew DataGridViewTextBoxCell();
				dgvcRestock->Value = restock;
				dgvr->Cells->Add(dgvcRestock);
				this->dgvCatalog->Rows->Add(dgvr);


			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Button^ BtnEquipeList;
	private: System::Windows::Forms::Button^ BtnBuyerList;
	private: System::Windows::Forms::DataGridView^ dgvCatalog;
	private: System::Windows::Forms::Button^ BtnOrderForm;
	private: System::Windows::Forms::Button^ BtnNewArticleForm;
	private: System::Windows::Forms::Button^ BtnResearch;

	private: System::Windows::Forms::TextBox^ TBReference;
	private: System::Windows::Forms::TextBox^ TBIdArticle;
	private: System::Windows::Forms::Label^ LbSearchingZone;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BtnEquipeList = (gcnew System::Windows::Forms::Button());
			this->BtnBuyerList = (gcnew System::Windows::Forms::Button());
			this->dgvCatalog = (gcnew System::Windows::Forms::DataGridView());
			this->BtnOrderForm = (gcnew System::Windows::Forms::Button());
			this->BtnNewArticleForm = (gcnew System::Windows::Forms::Button());
			this->BtnResearch = (gcnew System::Windows::Forms::Button());
			this->TBReference = (gcnew System::Windows::Forms::TextBox());
			this->TBIdArticle = (gcnew System::Windows::Forms::TextBox());
			this->LbSearchingZone = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCatalog))->BeginInit();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(539, 25);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(162, 32);
			this->Title->TabIndex = 0;
			this->Title->Text = L"TurboStock";
			// 
			// BtnEquipeList
			// 
			this->BtnEquipeList->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnEquipeList->Location = System::Drawing::Point(28, 150);
			this->BtnEquipeList->Name = L"BtnEquipeList";
			this->BtnEquipeList->Size = System::Drawing::Size(184, 61);
			this->BtnEquipeList->TabIndex = 1;
			this->BtnEquipeList->Text = L"Liste des employés";
			this->BtnEquipeList->UseVisualStyleBackColor = true;
			this->BtnEquipeList->Click += gcnew System::EventHandler(this, &Menu::BtnEquipeList_Click);
			// 
			// BtnBuyerList
			// 
			this->BtnBuyerList->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnBuyerList->Location = System::Drawing::Point(28, 234);
			this->BtnBuyerList->Name = L"BtnBuyerList";
			this->BtnBuyerList->Size = System::Drawing::Size(184, 61);
			this->BtnBuyerList->TabIndex = 2;
			this->BtnBuyerList->Text = L"Liste des acheteurs";
			this->BtnBuyerList->UseVisualStyleBackColor = true;
			this->BtnBuyerList->Click += gcnew System::EventHandler(this, &Menu::BtnBuyerList_Click);
			// 
			// dgvCatalog
			// 
			this->dgvCatalog->AllowUserToAddRows = false;
			this->dgvCatalog->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Orkney", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dgvCatalog->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvCatalog->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCatalog->Location = System::Drawing::Point(242, 81);
			this->dgvCatalog->MultiSelect = false;
			this->dgvCatalog->Name = L"dgvCatalog";
			this->dgvCatalog->ReadOnly = true;
			this->dgvCatalog->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCatalog->Size = System::Drawing::Size(708, 508);
			this->dgvCatalog->TabIndex = 3;
			this->dgvCatalog->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Menu::dgvCatalog_CellContentClick);
			this->dgvCatalog->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Menu::dgvCatalog_CellMouseClick);
			// 
			// BtnOrderForm
			// 
			this->BtnOrderForm->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnOrderForm->Location = System::Drawing::Point(28, 327);
			this->BtnOrderForm->Name = L"BtnOrderForm";
			this->BtnOrderForm->Size = System::Drawing::Size(184, 61);
			this->BtnOrderForm->TabIndex = 4;
			this->BtnOrderForm->Text = L"Nouvelle commande";
			this->BtnOrderForm->UseVisualStyleBackColor = true;
			this->BtnOrderForm->Click += gcnew System::EventHandler(this, &Menu::BtnOrderForm_Click);
			// 
			// BtnNewArticleForm
			// 
			this->BtnNewArticleForm->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnNewArticleForm->Location = System::Drawing::Point(28, 414);
			this->BtnNewArticleForm->Name = L"BtnNewArticleForm";
			this->BtnNewArticleForm->Size = System::Drawing::Size(184, 61);
			this->BtnNewArticleForm->TabIndex = 5;
			this->BtnNewArticleForm->Text = L"Ajouter un article";
			this->BtnNewArticleForm->UseVisualStyleBackColor = true;
			this->BtnNewArticleForm->Click += gcnew System::EventHandler(this, &Menu::BtnNewArticleForm_Click);
			// 
			// BtnResearch
			// 
			this->BtnResearch->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnResearch->Location = System::Drawing::Point(1021, 333);
			this->BtnResearch->Name = L"BtnResearch";
			this->BtnResearch->Size = System::Drawing::Size(135, 51);
			this->BtnResearch->TabIndex = 6;
			this->BtnResearch->Text = L"Rechercher";
			this->BtnResearch->UseVisualStyleBackColor = true;
			// 
			// TBReference
			// 
			this->TBReference->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TBReference->Location = System::Drawing::Point(979, 196);
			this->TBReference->Name = L"TBReference";
			this->TBReference->Size = System::Drawing::Size(212, 30);
			this->TBReference->TabIndex = 7;
			// 
			// TBIdArticle
			// 
			this->TBIdArticle->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TBIdArticle->Location = System::Drawing::Point(979, 274);
			this->TBIdArticle->Name = L"TBIdArticle";
			this->TBIdArticle->Size = System::Drawing::Size(212, 30);
			this->TBIdArticle->TabIndex = 8;
			// 
			// LbSearchingZone
			// 
			this->LbSearchingZone->AutoSize = true;
			this->LbSearchingZone->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 16.25F, System::Drawing::FontStyle::Bold));
			this->LbSearchingZone->Location = System::Drawing::Point(992, 127);
			this->LbSearchingZone->Name = L"LbSearchingZone";
			this->LbSearchingZone->Size = System::Drawing::Size(187, 52);
			this->LbSearchingZone->TabIndex = 9;
			this->LbSearchingZone->Text = L"Rechercher dans\nle stock";
			this->LbSearchingZone->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1226, 615);
			this->Controls->Add(this->LbSearchingZone);
			this->Controls->Add(this->TBIdArticle);
			this->Controls->Add(this->TBReference);
			this->Controls->Add(this->BtnResearch);
			this->Controls->Add(this->BtnNewArticleForm);
			this->Controls->Add(this->BtnOrderForm);
			this->Controls->Add(this->dgvCatalog);
			this->Controls->Add(this->BtnBuyerList);
			this->Controls->Add(this->BtnEquipeList);
			this->Controls->Add(this->Title);
			this->Name = L"Menu";
			this->Text = L"Turbostock";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCatalog))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void dgvCatalog_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		}
	private: System::Void dgvCatalog_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		DataGridViewRow^ dgvr = this->dgvCatalog->Rows[e->RowIndex];
		DataGridViewTextBoxCell^ cell = (DataGridViewTextBoxCell^)dgvr->Cells[0];
		System::Diagnostics::Debug::WriteLine("Cliqué sur " + cell->Value);
		}
#pragma endregion
	private: System::Void BtnNewArticleForm_Click(System::Object^ sender, System::EventArgs^ e) {
		Order^ orderForm = gcnew Order(mabdd);
		orderForm->ShowDialog();
		}
	private: System::Void BtnOrderForm_Click(System::Object^ sender, System::EventArgs^ e) {
		}
	private: System::Void BtnBuyerList_Click(System::Object^ sender, System::EventArgs^ e) {
		}
	private: System::Void BtnEquipeList_Click(System::Object^ sender, System::EventArgs^ e) {
		}
	};
}
