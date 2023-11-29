#pragma once
#include "BDD.h"
#include "AddArticle.h"
#include "ArticleRepository.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de ListClient
	/// </summary>
	public ref class ListArticles : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		ArticleRepository^ articleRepository;
	public:
		ListArticles(BDD^ mabdd)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		DataGridViewTextBoxColumn^ dgvtbcIdArticle = gcnew DataGridViewTextBoxColumn();
		dgvtbcIdArticle->Name = "Références";
		this->DGVSearchStaff->Columns->Add(dgvtbcIdArticle);
		DataGridViewTextBoxColumn^ dgvtbcName = gcnew DataGridViewTextBoxColumn();
		dgvtbcName->Name = "Nom";
		this->DGVSearchStaff->Columns->Add(dgvtbcName);
		DataGridViewTextBoxColumn^ dgvtbcPriceWT = gcnew DataGridViewTextBoxColumn();
		dgvtbcPriceWT->Name = "Prix HT";
		this->DGVSearchStaff->Columns->Add(dgvtbcPriceWT);
		articleRepository = gcnew ArticleRepository(mabdd);
		this->reload();
			
		}
		void reload() {
			System::Collections::Generic::List<Article^>^ articles = articleRepository->getArticle();
			this->DGVSearchStaff->Rows->Clear();
			for each (Article^ a in articles) {
				DataGridViewRow^ dgvr = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ dgvcIdArticle = gcnew DataGridViewTextBoxCell();
				dgvcIdArticle->Value = a->getIdArticle();
				dgvr->Cells->Add(dgvcIdArticle);
				DataGridViewTextBoxCell^ dgvcName = gcnew DataGridViewTextBoxCell();
				dgvcName->Value = a->getName() ;
				dgvr->Cells->Add(dgvcName);
				DataGridViewTextBoxCell^ dgvcPriceWT = gcnew DataGridViewTextBoxCell();
				dgvcPriceWT->Value = Convert::ToString(a->getPriceWT());
				dgvr->Cells->Add(dgvcPriceWT);
				dgvr->Tag = a;
				this->DGVSearchStaff->Rows->Add(dgvr);
			}
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ListArticles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnModify;
			 System::Windows::Forms::Button^ BtnAddArticle;
			 System::Windows::Forms::DataGridView^ DGVSearchStaff;
			 System::Windows::Forms::Label^ Title;			
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
			this->BtnModify = (gcnew System::Windows::Forms::Button());
			this->BtnAddArticle = (gcnew System::Windows::Forms::Button());
			this->DGVSearchStaff = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(691, 456);
			this->BtnModify->Name = L"BtnModify";
			this->BtnModify->Size = System::Drawing::Size(135, 48);
			this->BtnModify->TabIndex = 27;
			this->BtnModify->Text = L"Modifier";
			this->BtnModify->UseVisualStyleBackColor = true;
			// 
			// BtnAddArticle
			// 
			this->BtnAddArticle->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddArticle->Location = System::Drawing::Point(691, 81);
			this->BtnAddArticle->Name = L"BtnAddArticle";
			this->BtnAddArticle->Size = System::Drawing::Size(135, 48);
			this->BtnAddArticle->TabIndex = 26;
			this->BtnAddArticle->Text = L"Ajouter";
			this->BtnAddArticle->UseVisualStyleBackColor = true;
			this->BtnAddArticle->Click += gcnew System::EventHandler(this, &ListArticles::BtnAddArticle_Click);
			// 
			// DGVSearchStaff
			// 
			this->DGVSearchStaff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVSearchStaff->Location = System::Drawing::Point(26, 56);
			this->DGVSearchStaff->Name = L"DGVSearchStaff";
			this->DGVSearchStaff->Size = System::Drawing::Size(603, 526);
			this->DGVSearchStaff->TabIndex = 25;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(351, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(211, 28);
			this->Title->TabIndex = 24;
			this->Title->Text = L"Liste des articles";
			// 
			// ListArticles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 623);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddArticle);
			this->Controls->Add(this->DGVSearchStaff);
			this->Controls->Add(this->Title);
			this->Name = L"ListArticles";
			this->Text = L"ListClient";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnAddArticle_Click(System::Object^ sender, System::EventArgs^ e) {
		Article^ newArticle = gcnew Article();
		AddArticle^ addArticleForm = gcnew AddArticle(newArticle);
		addArticleForm->ShowDialog();
		System::Diagnostics::Debug::WriteLine(newArticle->ToString());
		articleRepository->insertArticle(newArticle);
		this->reload();
	}
};
}
