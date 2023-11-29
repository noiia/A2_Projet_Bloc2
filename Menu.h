#pragma once
#include <iostream>
#include <ctime>
#include "BDD.h"
#include "ListArticles.h"
#include "CommandHistory.h"
#include "ListClient.h"
#include "ListStaff.h"

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
			 System::Windows::Forms::Button^ BtnEquipeList;
			 System::Windows::Forms::Button^ BtnBuyerList;
			
			 System::Windows::Forms::Button^ BtnOrderForm;
			 System::Windows::Forms::Button^ BtnArticleForm;
			
			
			 System::Windows::Forms::Button^ BtnStats;
			
			
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
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BtnEquipeList = (gcnew System::Windows::Forms::Button());
			this->BtnBuyerList = (gcnew System::Windows::Forms::Button());
			this->BtnOrderForm = (gcnew System::Windows::Forms::Button());
			this->BtnArticleForm = (gcnew System::Windows::Forms::Button());
			this->BtnStats = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(205, 43);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(162, 32);
			this->Title->TabIndex = 0;
			this->Title->Text = L"TurboStock";
			// 
			// BtnEquipeList
			// 
			this->BtnEquipeList->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnEquipeList->Location = System::Drawing::Point(74, 115);
			this->BtnEquipeList->Name = L"BtnEquipeList";
			this->BtnEquipeList->Size = System::Drawing::Size(184, 61);
			this->BtnEquipeList->TabIndex = 1;
			this->BtnEquipeList->Text = L"Liste des Employés";
			this->BtnEquipeList->UseVisualStyleBackColor = true;
			this->BtnEquipeList->Click += gcnew System::EventHandler(this, &Menu::BtnEquipeList_Click);
			// 
			// BtnBuyerList
			// 
			this->BtnBuyerList->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnBuyerList->Location = System::Drawing::Point(309, 115);
			this->BtnBuyerList->Name = L"BtnBuyerList";
			this->BtnBuyerList->Size = System::Drawing::Size(184, 61);
			this->BtnBuyerList->TabIndex = 2;
			this->BtnBuyerList->Text = L"Liste des Clients";
			this->BtnBuyerList->UseVisualStyleBackColor = true;
			this->BtnBuyerList->Click += gcnew System::EventHandler(this, &Menu::BtnBuyerList_Click);
			// 
			// BtnOrderForm
			// 
			this->BtnOrderForm->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnOrderForm->Location = System::Drawing::Point(309, 202);
			this->BtnOrderForm->Name = L"BtnOrderForm";
			this->BtnOrderForm->Size = System::Drawing::Size(184, 61);
			this->BtnOrderForm->TabIndex = 4;
			this->BtnOrderForm->Text = L"Nouvelle Commande";
			this->BtnOrderForm->UseVisualStyleBackColor = true;
			this->BtnOrderForm->Click += gcnew System::EventHandler(this, &Menu::BtnOrderForm_Click);
			// 
			// BtnArticleForm
			// 
			this->BtnArticleForm->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnArticleForm->Location = System::Drawing::Point(74, 202);
			this->BtnArticleForm->Name = L"BtnArticleForm";
			this->BtnArticleForm->Size = System::Drawing::Size(184, 61);
			this->BtnArticleForm->TabIndex = 5;
			this->BtnArticleForm->Text = L"Liste des Articles";
			this->BtnArticleForm->UseVisualStyleBackColor = true;
			this->BtnArticleForm->Click += gcnew System::EventHandler(this, &Menu::BtnNewArticleForm_Click);
			// 
			// BtnStats
			// 
			this->BtnStats->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnStats->Location = System::Drawing::Point(220, 285);
			this->BtnStats->Name = L"BtnStats";
			this->BtnStats->Size = System::Drawing::Size(135, 51);
			this->BtnStats->TabIndex = 6;
			this->BtnStats->Text = L"Statistiques";
			this->BtnStats->UseVisualStyleBackColor = true;
			// 
			// Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 409);
			this->Controls->Add(this->BtnStats);
			this->Controls->Add(this->BtnArticleForm);
			this->Controls->Add(this->BtnOrderForm);
			this->Controls->Add(this->BtnBuyerList);
			this->Controls->Add(this->BtnEquipeList);
			this->Controls->Add(this->Title);
			this->Name = L"Menu";
			this->Text = L"Turbostock";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnNewArticleForm_Click(System::Object^ sender, System::EventArgs^ e) {
		ListArticles^ listArticlesForm = gcnew ListArticles(mabdd);
		listArticlesForm->ShowDialog();
		}
	private: System::Void BtnOrderForm_Click(System::Object^ sender, System::EventArgs^ e) {
		CommandHistory^ CommandHistoryForm = gcnew CommandHistory(mabdd);
		CommandHistoryForm->ShowDialog();
		}
	private: System::Void BtnBuyerList_Click(System::Object^ sender, System::EventArgs^ e) {
		ListClient^ listClientForm = gcnew ListClient(mabdd);
		listClientForm->ShowDialog();
		}
	private: System::Void BtnEquipeList_Click(System::Object^ sender, System::EventArgs^ e) {
		ListStaff^ listStaffForm = gcnew ListStaff(mabdd);
		listStaffForm->ShowDialog();
		}
	};
}
