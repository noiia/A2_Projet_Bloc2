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
		Article^ sharedA;
		bool delOrRestore;
		Thread^ reloadThread;
		ArticleRepository^ articleRepository;
		System::Threading::Mutex^ reloadMutex;
		System::Windows::Forms::Button^ BtnDelete;
		System::Windows::Forms::CheckBox^ CboxDeletedLines;
	public:
		ListArticles(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();

			reloadMutex = gcnew System::Threading::Mutex();

			DGVSearchArticle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcIdArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdArticle->Name = "Références";
			this->DGVSearchArticle->Columns->Add(dgvtbcIdArticle);
			DataGridViewTextBoxColumn^ dgvtbcName = gcnew DataGridViewTextBoxColumn();
			dgvtbcName->Name = "Nom";
			this->DGVSearchArticle->Columns->Add(dgvtbcName);
			DataGridViewTextBoxColumn^ dgvtbcType = gcnew DataGridViewTextBoxColumn();
			dgvtbcType->Name = "Type";
			this->DGVSearchArticle->Columns->Add(dgvtbcType);
			DataGridViewTextBoxColumn^ dgvtbcPriceWT = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceWT->Name = "Prix HT";
			this->DGVSearchArticle->Columns->Add(dgvtbcPriceWT);
			DataGridViewTextBoxColumn^ dgvtbcVAT = gcnew DataGridViewTextBoxColumn();
			dgvtbcVAT->Name = "TVA";
			this->DGVSearchArticle->Columns->Add(dgvtbcVAT);
			DataGridViewTextBoxColumn^ dgvtbcPriceATI = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceATI->Name = "Prix TTC";
			this->DGVSearchArticle->Columns->Add(dgvtbcPriceATI);
			DataGridViewTextBoxColumn^ dgvtbcStock = gcnew DataGridViewTextBoxColumn();
			dgvtbcStock->Name = "Stock";
			this->DGVSearchArticle->Columns->Add(dgvtbcStock);
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
					this->DGVSearchArticle->Rows->Add(dgvr);


					this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->BtnDelete->Size = System::Drawing::Size(135, 48);
					this->BtnDelete->TabIndex = 28;
					this->BtnDelete->UseVisualStyleBackColor = true;
					this->BtnDelete->Click += gcnew System::EventHandler(this, &ListArticles::BtnDelete_Click);

					if (this->CboxDeletedLines->Checked) {
						this->BtnDelete->Text = L"Restaurer";
						this->BtnDelete->Location = System::Drawing::Point(1017, 464);
						System::Diagnostics::Debug::WriteLine("restaurer");
						delOrRestore = 0;
					}
					else {
						this->BtnDelete->Text = L"Supprimer";
						this->BtnDelete->Location = System::Drawing::Point(1017,464);
							System::Diagnostics::Debug::WriteLine("supprimer");
						delOrRestore = 1;
					}
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
			this->BtnModify->Location = System::Drawing::Point(1017, 372);
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
			this->BtnAddArticle->Location = System::Drawing::Point(1017, 56);
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
			this->DGVSearchArticle->ReadOnly = true;
			this->DGVSearchArticle->Size = System::Drawing::Size(944, 526);
			this->DGVSearchArticle->TabIndex = 25;
			this->DGVSearchArticle->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ListArticles::DGVSearchArticle_RowEnter);
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(497, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(211, 28);
			this->Title->TabIndex = 24;
			this->Title->Text = L"Liste des articles";
			// 
			// BtnDelete
			// 
			this->BtnDelete->Location = System::Drawing::Point(0, 0);
			this->BtnDelete->Name = L"BtnDelete";
			this->BtnDelete->Size = System::Drawing::Size(75, 23);
			this->BtnDelete->TabIndex = 30;
			// 
			// CboxDeletedLines
			// 
			this->CboxDeletedLines->AutoSize = true;
			this->CboxDeletedLines->Font = (gcnew System::Drawing::Font(L"Orkney", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CboxDeletedLines->Location = System::Drawing::Point(1017, 539);
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
			this->ClientSize = System::Drawing::Size(1215, 623);
			this->Controls->Add(this->CboxDeletedLines);
			this->Controls->Add(this->BtnDelete);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddArticle);
			this->Controls->Add(this->DGVSearchArticle);
			this->Controls->Add(this->Title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ListArticles";
			this->Text = L"TurboStock";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchArticle))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnAddArticle_Click(System::Object^ sender, System::EventArgs^ e) {
		Article^ newArticle = gcnew Article();
		AddArticle^ addArticleForm = gcnew AddArticle(newArticle, false);
		addArticleForm->ShowDialog();
		articleRepository->insertArticle(newArticle);
		this->reload();
	}
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Debug::WriteLine(sharedA + " voilà a");
		articleRepository->deleteArticle(sharedA, delOrRestore);
		this->reload();
	}

	private: System::Void BtnModify_Click(System::Object^ sender, System::EventArgs^ e) {
		AddArticle^ formModifArticle = gcnew AddArticle(sharedA, true);
		formModifArticle->ShowDialog();
		articleRepository->editArticle(sharedA);

		int selected = this->DGVSearchArticle->SelectedRows[0]->Index;
		this->reload();
		this->DGVSearchArticle->Rows[selected]->Selected = true;
	}

	private: System::Void CboxDeletedLines_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->reload();
}
private: System::Void DGVSearchArticle_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0) {
		DataGridViewRow^ sharedDgvrRow = DGVSearchArticle->Rows[e->RowIndex];
		sharedA = (Article^)sharedDgvrRow->Tag;
		System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedA->ToString());

	}
}
};
}
