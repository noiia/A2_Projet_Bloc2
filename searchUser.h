#pragma once
#include "BDD.h"
#include "NewUser.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de searchUser1
	/// </summary>
	public ref class SearchUser : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		SearchUser(BDD^ mabdd)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~SearchUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnNewClient;
	protected:

	protected:
	private: System::Windows::Forms::Button^ BtnValidate;
	private: System::Windows::Forms::DataGridView^ DGVSearchStaff;
	private: System::Windows::Forms::TextBox^ TbCity;
	private: System::Windows::Forms::TextBox^ TbPostalCode;
	private: System::Windows::Forms::TextBox^ TbFirstName;
	private: System::Windows::Forms::TextBox^ TbName;
	private: System::Windows::Forms::Label^ LbCity;
	private: System::Windows::Forms::Label^ LbFirstName;
	private: System::Windows::Forms::Label^ LbPostalCode;
	private: System::Windows::Forms::Label^ LbName;
	private: System::Windows::Forms::Label^ Title;


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
			this->BtnNewClient = (gcnew System::Windows::Forms::Button());
			this->BtnValidate = (gcnew System::Windows::Forms::Button());
			this->DGVSearchStaff = (gcnew System::Windows::Forms::DataGridView());
			this->TbCity = (gcnew System::Windows::Forms::TextBox());
			this->TbPostalCode = (gcnew System::Windows::Forms::TextBox());
			this->TbFirstName = (gcnew System::Windows::Forms::TextBox());
			this->TbName = (gcnew System::Windows::Forms::TextBox());
			this->LbCity = (gcnew System::Windows::Forms::Label());
			this->LbFirstName = (gcnew System::Windows::Forms::Label());
			this->LbPostalCode = (gcnew System::Windows::Forms::Label());
			this->LbName = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnNewClient
			// 
			this->BtnNewClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnNewClient->Location = System::Drawing::Point(295, 530);
			this->BtnNewClient->Name = L"BtnNewClient";
			this->BtnNewClient->Size = System::Drawing::Size(378, 48);
			this->BtnNewClient->TabIndex = 23;
			this->BtnNewClient->Text = L"Enregistrer un nouveau client";
			this->BtnNewClient->UseVisualStyleBackColor = true;
			this->BtnNewClient->Click += gcnew System::EventHandler(this, &SearchUser::BtnNewClient_Click);
			// 
			// BtnValidate
			// 
			this->BtnValidate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnValidate->Location = System::Drawing::Point(71, 403);
			this->BtnValidate->Name = L"BtnValidate";
			this->BtnValidate->Size = System::Drawing::Size(135, 48);
			this->BtnValidate->TabIndex = 22;
			this->BtnValidate->Text = L"Valider";
			this->BtnValidate->UseVisualStyleBackColor = true;
			// 
			// DGVSearchStaff
			// 
			this->DGVSearchStaff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVSearchStaff->Location = System::Drawing::Point(295, 122);
			this->DGVSearchStaff->Name = L"DGVSearchStaff";
			this->DGVSearchStaff->Size = System::Drawing::Size(378, 365);
			this->DGVSearchStaff->TabIndex = 21;
			// 
			// TbCity
			// 
			this->TbCity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbCity->Location = System::Drawing::Point(37, 335);
			this->TbCity->Name = L"TbCity";
			this->TbCity->Size = System::Drawing::Size(211, 26);
			this->TbCity->TabIndex = 20;
			// 
			// TbPostalCode
			// 
			this->TbPostalCode->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPostalCode->Location = System::Drawing::Point(37, 265);
			this->TbPostalCode->Name = L"TbPostalCode";
			this->TbPostalCode->Size = System::Drawing::Size(211, 26);
			this->TbPostalCode->TabIndex = 19;
			// 
			// TbFirstName
			// 
			this->TbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbFirstName->Location = System::Drawing::Point(37, 196);
			this->TbFirstName->Name = L"TbFirstName";
			this->TbFirstName->Size = System::Drawing::Size(211, 26);
			this->TbFirstName->TabIndex = 18;
			// 
			// TbName
			// 
			this->TbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbName->Location = System::Drawing::Point(37, 122);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(211, 26);
			this->TbName->TabIndex = 17;
			// 
			// LbCity
			// 
			this->LbCity->AutoSize = true;
			this->LbCity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbCity->Location = System::Drawing::Point(33, 313);
			this->LbCity->Name = L"LbCity";
			this->LbCity->Size = System::Drawing::Size(43, 19);
			this->LbCity->TabIndex = 16;
			this->LbCity->Text = L"Ville";
			// 
			// LbFirstName
			// 
			this->LbFirstName->AutoSize = true;
			this->LbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbFirstName->Location = System::Drawing::Point(33, 174);
			this->LbFirstName->Name = L"LbFirstName";
			this->LbFirstName->Size = System::Drawing::Size(65, 19);
			this->LbFirstName->TabIndex = 15;
			this->LbFirstName->Text = L"Prénom";
			// 
			// LbPostalCode
			// 
			this->LbPostalCode->AutoSize = true;
			this->LbPostalCode->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPostalCode->Location = System::Drawing::Point(33, 243);
			this->LbPostalCode->Name = L"LbPostalCode";
			this->LbPostalCode->Size = System::Drawing::Size(97, 19);
			this->LbPostalCode->TabIndex = 14;
			this->LbPostalCode->Text = L"Code Postal";
			// 
			// LbName
			// 
			this->LbName->AutoSize = true;
			this->LbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbName->Location = System::Drawing::Point(33, 100);
			this->LbName->Name = L"LbName";
			this->LbName->Size = System::Drawing::Size(44, 19);
			this->LbName->TabIndex = 13;
			this->LbName->Text = L"Nom";
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(218, 40);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(264, 28);
			this->Title->TabIndex = 12;
			this->Title->Text = L"Recherche d\'un client";
			// 
			// searchUser1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(718, 600);
			this->Controls->Add(this->BtnNewClient);
			this->Controls->Add(this->BtnValidate);
			this->Controls->Add(this->DGVSearchStaff);
			this->Controls->Add(this->TbCity);
			this->Controls->Add(this->TbPostalCode);
			this->Controls->Add(this->TbFirstName);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->LbCity);
			this->Controls->Add(this->LbFirstName);
			this->Controls->Add(this->LbPostalCode);
			this->Controls->Add(this->LbName);
			this->Controls->Add(this->Title);
			this->Name = L"searchUser1";
			this->Text = L"searchUser";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnNewClient_Click(System::Object^ sender, System::EventArgs^ e) {
		NewUser^ newUserForm = gcnew NewUser(mabdd);
		newUserForm->ShowDialog();
	}
};
}
