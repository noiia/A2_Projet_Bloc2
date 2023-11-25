#pragma once

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de modifUser
	/// </summary>
	public ref class modifUser : public System::Windows::Forms::Form
	{
	public:
		modifUser(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~modifUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LbUserInfo;
	private: System::Windows::Forms::Label^ LbName;
	private: System::Windows::Forms::Label^ LbFirstName;
	protected:


	protected:



	private: System::Windows::Forms::TextBox^ TbName;
	private: System::Windows::Forms::TextBox^ TbFirstName;
	private: System::Windows::Forms::Label^ LbAdress;




	private: System::Windows::Forms::Label^ LbBirthDate;
	private: System::Windows::Forms::Label^ LbNCompany;


	private: System::Windows::Forms::TextBox^ TbAdress;

	private: System::Windows::Forms::TextBox^ TbBirthDate;
	private: System::Windows::Forms::TextBox^ TbNCompany;

	private: System::Windows::Forms::Button^ BtValidate;
	private: System::Windows::Forms::Button^ BtReturn;




	protected:

	private:
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
			this->LbUserInfo = (gcnew System::Windows::Forms::Label());
			this->LbName = (gcnew System::Windows::Forms::Label());
			this->LbFirstName = (gcnew System::Windows::Forms::Label());
			this->TbName = (gcnew System::Windows::Forms::TextBox());
			this->TbFirstName = (gcnew System::Windows::Forms::TextBox());
			this->LbAdress = (gcnew System::Windows::Forms::Label());
			this->LbBirthDate = (gcnew System::Windows::Forms::Label());
			this->LbNCompany = (gcnew System::Windows::Forms::Label());
			this->TbAdress = (gcnew System::Windows::Forms::TextBox());
			this->TbBirthDate = (gcnew System::Windows::Forms::TextBox());
			this->TbNCompany = (gcnew System::Windows::Forms::TextBox());
			this->BtValidate = (gcnew System::Windows::Forms::Button());
			this->BtReturn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LbUserInfo
			// 
			this->LbUserInfo->AutoSize = true;
			this->LbUserInfo->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbUserInfo->Location = System::Drawing::Point(11, 23);
			this->LbUserInfo->Name = L"LbUserInfo";
			this->LbUserInfo->Size = System::Drawing::Size(289, 28);
			this->LbUserInfo->TabIndex = 0;
			this->LbUserInfo->Text = L"Informations Utilisateur";
			// 
			// LbName
			// 
			this->LbName->AutoSize = true;
			this->LbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbName->Location = System::Drawing::Point(12, 70);
			this->LbName->Name = L"LbName";
			this->LbName->Size = System::Drawing::Size(44, 19);
			this->LbName->TabIndex = 1;
			this->LbName->Text = L"Nom";
			// 
			// LbFirstName
			// 
			this->LbFirstName->AutoSize = true;
			this->LbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbFirstName->Location = System::Drawing::Point(12, 136);
			this->LbFirstName->Name = L"LbFirstName";
			this->LbFirstName->Size = System::Drawing::Size(65, 19);
			this->LbFirstName->TabIndex = 2;
			this->LbFirstName->Text = L"Prénom";
			// 
			// TbName
			// 
			this->TbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbName->Location = System::Drawing::Point(36, 92);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(236, 27);
			this->TbName->TabIndex = 3;
			// 
			// TbFirstName
			// 
			this->TbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbFirstName->Location = System::Drawing::Point(36, 158);
			this->TbFirstName->Name = L"TbFirstName";
			this->TbFirstName->Size = System::Drawing::Size(236, 27);
			this->TbFirstName->TabIndex = 4;
			// 
			// LbAdress
			// 
			this->LbAdress->AutoSize = true;
			this->LbAdress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbAdress->Location = System::Drawing::Point(12, 259);
			this->LbAdress->Name = L"LbAdress";
			this->LbAdress->Size = System::Drawing::Size(71, 19);
			this->LbAdress->TabIndex = 5;
			this->LbAdress->Text = L"Adresse";
			// 
			// LbBirthDate
			// 
			this->LbBirthDate->AutoSize = true;
			this->LbBirthDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBirthDate->Location = System::Drawing::Point(12, 200);
			this->LbBirthDate->Name = L"LbBirthDate";
			this->LbBirthDate->Size = System::Drawing::Size(143, 19);
			this->LbBirthDate->TabIndex = 6;
			this->LbBirthDate->Text = L"Date de naissance";
			// 
			// LbNCompany
			// 
			this->LbNCompany->AutoSize = true;
			this->LbNCompany->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbNCompany->Location = System::Drawing::Point(16, 322);
			this->LbNCompany->Name = L"LbNCompany";
			this->LbNCompany->Size = System::Drawing::Size(109, 19);
			this->LbNCompany->TabIndex = 7;
			this->LbNCompany->Text = L"N° Entreprise";
			// 
			// TbAdress
			// 
			this->TbAdress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbAdress->Location = System::Drawing::Point(36, 281);
			this->TbAdress->Name = L"TbAdress";
			this->TbAdress->Size = System::Drawing::Size(236, 27);
			this->TbAdress->TabIndex = 8;
			// 
			// TbBirthDate
			// 
			this->TbBirthDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbBirthDate->Location = System::Drawing::Point(36, 222);
			this->TbBirthDate->Name = L"TbBirthDate";
			this->TbBirthDate->Size = System::Drawing::Size(236, 27);
			this->TbBirthDate->TabIndex = 9;
			// 
			// TbNCompany
			// 
			this->TbNCompany->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbNCompany->Location = System::Drawing::Point(36, 344);
			this->TbNCompany->Name = L"TbNCompany";
			this->TbNCompany->Size = System::Drawing::Size(236, 27);
			this->TbNCompany->TabIndex = 10;
			// 
			// BtValidate
			// 
			this->BtValidate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtValidate->Location = System::Drawing::Point(20, 402);
			this->BtValidate->Name = L"BtValidate";
			this->BtValidate->Size = System::Drawing::Size(99, 35);
			this->BtValidate->TabIndex = 11;
			this->BtValidate->Text = L"Valider";
			this->BtValidate->UseVisualStyleBackColor = true;
			// 
			// BtReturn
			// 
			this->BtReturn->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtReturn->Location = System::Drawing::Point(201, 402);
			this->BtReturn->Name = L"BtReturn";
			this->BtReturn->Size = System::Drawing::Size(99, 35);
			this->BtReturn->TabIndex = 12;
			this->BtReturn->Text = L"Retour";
			this->BtReturn->UseVisualStyleBackColor = true;
			// 
			// modifUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(316, 469);
			this->Controls->Add(this->BtReturn);
			this->Controls->Add(this->BtValidate);
			this->Controls->Add(this->TbNCompany);
			this->Controls->Add(this->TbBirthDate);
			this->Controls->Add(this->TbAdress);
			this->Controls->Add(this->LbNCompany);
			this->Controls->Add(this->LbBirthDate);
			this->Controls->Add(this->LbAdress);
			this->Controls->Add(this->TbFirstName);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->LbFirstName);
			this->Controls->Add(this->LbName);
			this->Controls->Add(this->LbUserInfo);
			this->Name = L"modifUser";
			this->Text = L"modifUser";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	};
}
