#pragma once
#include "BDD.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de TotalValuePurchaseClient
	/// </summary>
	public ref class TotalValuePurchaseClient : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		TotalValuePurchaseClient(BDD^ mabdd)
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
		~TotalValuePurchaseClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:

	private: System::Windows::Forms::Label^ LbLastName;
	private: System::Windows::Forms::TextBox^ TbLastName;

	private: System::Windows::Forms::Label^ LbFirstName;
	private: System::Windows::Forms::TextBox^ TbFirstName;
	private: System::Windows::Forms::Label^ LbAmountTotal;
	private: System::Windows::Forms::Button^ BtnSearch;



	protected:

	private:
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
			this->Title = (gcnew System::Windows::Forms::Label());
			this->LbLastName = (gcnew System::Windows::Forms::Label());
			this->TbLastName = (gcnew System::Windows::Forms::TextBox());
			this->LbFirstName = (gcnew System::Windows::Forms::Label());
			this->TbFirstName = (gcnew System::Windows::Forms::TextBox());
			this->LbAmountTotal = (gcnew System::Windows::Forms::Label());
			this->BtnSearch = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(59, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(457, 28);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Montant total des achats pour un client";
			// 
			// LbLastName
			// 
			this->LbLastName->AutoSize = true;
			this->LbLastName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbLastName->Location = System::Drawing::Point(24, 80);
			this->LbLastName->Name = L"LbLastName";
			this->LbLastName->Size = System::Drawing::Size(44, 19);
			this->LbLastName->TabIndex = 1;
			this->LbLastName->Text = L"Nom";
			// 
			// TbLastName
			// 
			this->TbLastName->Location = System::Drawing::Point(28, 102);
			this->TbLastName->Name = L"TbLastName";
			this->TbLastName->Size = System::Drawing::Size(156, 20);
			this->TbLastName->TabIndex = 2;
			// 
			// LbFirstName
			// 
			this->LbFirstName->AutoSize = true;
			this->LbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbFirstName->Location = System::Drawing::Point(24, 153);
			this->LbFirstName->Name = L"LbFirstName";
			this->LbFirstName->Size = System::Drawing::Size(65, 19);
			this->LbFirstName->TabIndex = 3;
			this->LbFirstName->Text = L"Prenom";
			// 
			// TbFirstName
			// 
			this->TbFirstName->Location = System::Drawing::Point(28, 175);
			this->TbFirstName->Name = L"TbFirstName";
			this->TbFirstName->Size = System::Drawing::Size(156, 20);
			this->TbFirstName->TabIndex = 4;
			// 
			// LbAmountTotal
			// 
			this->LbAmountTotal->AutoSize = true;
			this->LbAmountTotal->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbAmountTotal->Location = System::Drawing::Point(24, 297);
			this->LbAmountTotal->Name = L"LbAmountTotal";
			this->LbAmountTotal->Size = System::Drawing::Size(193, 19);
			this->LbAmountTotal->TabIndex = 5;
			this->LbAmountTotal->Text = L"Montant total des achats";
			// 
			// BtnSearch
			// 
			this->BtnSearch->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnSearch->Location = System::Drawing::Point(45, 215);
			this->BtnSearch->Name = L"BtnSearch";
			this->BtnSearch->Size = System::Drawing::Size(108, 23);
			this->BtnSearch->TabIndex = 6;
			this->BtnSearch->Text = L"Rechercher";
			this->BtnSearch->UseVisualStyleBackColor = true;
			this->BtnSearch->Click += gcnew System::EventHandler(this, &TotalValuePurchaseClient::BtnSearch_Click);
			// 
			// TotalValuePurchaseClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(565, 400);
			this->Controls->Add(this->BtnSearch);
			this->Controls->Add(this->LbAmountTotal);
			this->Controls->Add(this->TbFirstName);
			this->Controls->Add(this->LbFirstName);
			this->Controls->Add(this->TbLastName);
			this->Controls->Add(this->LbLastName);
			this->Controls->Add(this->Title);
			this->Name = L"TotalValuePurchaseClient";
			this->Text = L"TotalValuePurchaseClient";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ lastName = TbLastName->Text;
		String^ firstName = TbFirstName->Text;

	}

	};
}