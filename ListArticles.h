#pragma once
#include <iostream>
#include <thread>
#include <mutex>
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
	using namespace System::Threading;

	/// <summary>
	/// Description résumée de ListClient
	/// </summary>
	public ref class ListArticles : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		int delStateValue = 0;
		Article^ sharedA;
		Thread^ reloadThread;
		System::Threading::Mutex^ reloadMutex;
		private: System::Windows::Forms::Button^ BtnDelete;
	private: System::Windows::Forms::CheckBox^ CboxDeletedLines;
		   ArticleRepository^ articleRepository;
	public:
		ListArticles(BDD^ mabdd)
		{
			InitializeComponent();

			reloadMutex = gcnew System::Threading::Mutex();

			DGVSearchArticle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcIdArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdArticle->Name = "Références";
			this->DGVSearchArticle->Columns->Add(dgvtbcIdArticle);
			DataGridViewTextBoxColumn^ dgvtbcName = gcnew DataGridViewTextBoxColumn();
			dgvtbcName->Name = "Nom";
			this->DGVSearchArticle->Columns->Add(dgvtbcName);
			DataGridViewTextBoxColumn^ dgvtbcPriceWT = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceWT->Name = "Prix HT";
			this->DGVSearchArticle->Columns->Add(dgvtbcPriceWT);
			DataGridViewTextBoxColumn^ dgvtbcVAT = gcnew DataGridViewTextBoxColumn();
			dgvtbcVAT->Name = "TVA";
			this->DGVSearchArticle->Columns->Add(dgvtbcVAT);
			DataGridViewTextBoxColumn^ dgvtbcPriceATI = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceATI->Name = "Prix TTC";
			this->DGVSearchArticle->Columns->Add(dgvtbcPriceATI);
			DataGridViewTextBoxColumn^ dgvtbcTresholdLimit = gcnew DataGridViewTextBoxColumn();
			dgvtbcTresholdLimit->Name = "Limite avant réapprovisionnement";
			this->DGVSearchArticle->Columns->Add(dgvtbcTresholdLimit);
			DataGridViewTextBoxColumn^ dgvtbcTresholdDate = gcnew DataGridViewTextBoxColumn();
			dgvtbcTresholdDate->Name = "Date de réapprovisionnement";
			this->DGVSearchArticle->Columns->Add(dgvtbcTresholdDate);
			articleRepository = gcnew ArticleRepository(mabdd);
			this->reload();
			
		}

		
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Article^>^ articles = articleRepository->getArticle(this->CboxDeletedLines->Checked);
				this->DGVSearchArticle->Rows->Clear();
				for each (Article ^ a in articles) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdArticle = gcnew DataGridViewTextBoxCell();
					dgvcIdArticle->Value = a->getIdArticle();
					dgvr->Cells->Add(dgvcIdArticle);
					DataGridViewTextBoxCell^ dgvcName = gcnew DataGridViewTextBoxCell();
					dgvcName->Value = a->getName();
					dgvr->Cells->Add(dgvcName);
					DataGridViewTextBoxCell^ dgvcPriceWT = gcnew DataGridViewTextBoxCell();
					dgvcPriceWT->Value = Convert::ToString(a->getPriceWT());
					dgvr->Cells->Add(dgvcPriceWT);
					DataGridViewTextBoxCell^ dgvcVAT = gcnew DataGridViewTextBoxCell();
					dgvcVAT->Value = Convert::ToString(a->getVAT());
					dgvr->Cells->Add(dgvcVAT);
					DataGridViewTextBoxCell^ dgvcPriceATI = gcnew DataGridViewTextBoxCell();
					dgvcPriceATI->Value = Convert::ToString(a->getPriceATI());
					dgvr->Cells->Add(dgvcPriceATI);
					DataGridViewTextBoxCell^ dgvcRestockingLimit = gcnew DataGridViewTextBoxCell();
					dgvcRestockingLimit->Value = Convert::ToString(a->getRestockingLimit());
					dgvr->Cells->Add(dgvcRestockingLimit);
					DataGridViewTextBoxCell^ dgvcRestockingDate = gcnew DataGridViewTextBoxCell();
					dgvcRestockingDate->Value = a->getRestockingDate();
					dgvr->Cells->Add(dgvcRestockingDate);
					dgvr->Tag = a;
					this->DGVSearchArticle->Rows->Add(dgvr);
				}
				reloadMutex->ReleaseMutex();
			}
		}
		void launchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &ListArticles::reload));
			reloadThread->Start();
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
			 System::Windows::Forms::DataGridView^ DGVSearchArticle;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ListArticles::typeid));
			this->BtnModify = (gcnew System::Windows::Forms::Button());
			this->BtnAddArticle = (gcnew System::Windows::Forms::Button());
			this->DGVSearchArticle = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BtnDelete = (gcnew System::Windows::Forms::Button());
			this->CboxDeletedLines = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchArticle))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(691, 418);
			this->BtnModify->Name = L"BtnModify";
			this->BtnModify->Size = System::Drawing::Size(135, 48);
			this->BtnModify->TabIndex = 27;
			this->BtnModify->Text = L"Modifier";
			this->BtnModify->UseVisualStyleBackColor = true;
			this->BtnModify->Click += gcnew System::EventHandler(this, &ListArticles::BtnModify_Click);
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
			// DGVSearchArticle
			// 
			this->DGVSearchArticle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVSearchArticle->Location = System::Drawing::Point(26, 56);
			this->DGVSearchArticle->Name = L"DGVSearchArticle";
			this->DGVSearchArticle->Size = System::Drawing::Size(603, 526);
			this->DGVSearchArticle->TabIndex = 25;
			this->DGVSearchArticle->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ListArticles::DGVSearchArticle_CellMouseClick);
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
			// BtnDelete
			// 
			this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnDelete->Location = System::Drawing::Point(691, 510);
			this->BtnDelete->Name = L"BtnDelete";
			this->BtnDelete->Size = System::Drawing::Size(135, 48);
			this->BtnDelete->TabIndex = 28;
			this->BtnDelete->Text = L"Supprimer";
			this->BtnDelete->UseVisualStyleBackColor = true;
			this->BtnDelete->Click += gcnew System::EventHandler(this, &ListArticles::BtnDelete_Click);
			// 
			// CboxDeletedLines
			// 
			this->CboxDeletedLines->AutoSize = true;
			this->CboxDeletedLines->Font = (gcnew System::Drawing::Font(L"Orkney", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CboxDeletedLines->Location = System::Drawing::Point(691, 564);
			this->CboxDeletedLines->Name = L"CboxDeletedLines";
			this->CboxDeletedLines->Size = System::Drawing::Size(150, 38);
			this->CboxDeletedLines->TabIndex = 29;
			this->CboxDeletedLines->Text = L"Afficher les lignes \n supprimées";
			this->CboxDeletedLines->UseVisualStyleBackColor = true;
			this->CboxDeletedLines->CheckedChanged += gcnew System::EventHandler(this, &ListArticles::CboxDeletedLines_CheckedChanged);
			// 
			// ListArticles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 623);
			this->Controls->Add(this->CboxDeletedLines);
			this->Controls->Add(this->BtnDelete);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddArticle);
			this->Controls->Add(this->DGVSearchArticle);
			this->Controls->Add(this->Title);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ListArticles";
			this->Text = L"TurboStock";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchArticle))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnAddArticle_Click(System::Object^ sender, System::EventArgs^ e) {
		Article^ newArticle = gcnew Article();
		AddArticle^ addArticleForm = gcnew AddArticle(newArticle,0);
		addArticleForm->ShowDialog();
		System::Diagnostics::Debug::WriteLine(newArticle->ToString());
		articleRepository->insertArticle(newArticle);
		this->reload();
	}
	
	private: System::Void DGVSearchArticle_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVSearchArticle->Rows[e->RowIndex];
			sharedA = (Article^)sharedDgvrRow->Tag;
			System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedA->ToString());

		}
	}
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Debug::WriteLine(sharedA + " voilà a");
		articleRepository->deleteArticle(sharedA);
		this->reload();
	}

	private: System::Void BtnModify_Click(System::Object^ sender, System::EventArgs^ e) {
		AddArticle^ formModifArticle = gcnew AddArticle(sharedA,1);
		formModifArticle->ShowDialog();
		articleRepository->editArticle(sharedA);
	}

	private: System::Void CboxDeletedLines_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->reload();
}
};
}
