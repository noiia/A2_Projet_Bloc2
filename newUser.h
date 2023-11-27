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
	public ref class newUser : public System::Windows::Forms::Form
	{
	public:
		newUser(void)
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
		~newUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LbUserInfo;
	private: System::Windows::Forms::Label^ LbName;
	private: System::Windows::Forms::Label^ LbFirstName;
	private: System::Windows::Forms::TextBox^ TbName;
	private: System::Windows::Forms::TextBox^ TbFirstName;
	private: System::Windows::Forms::Label^ LbDeliveryAdress;
	private: System::Windows::Forms::Label^ LbBirthDate;
	private: System::Windows::Forms::Label^ LbNCompany;
	private: System::Windows::Forms::TextBox^ TbAdress;
	private: System::Windows::Forms::TextBox^ TbBirthDate;
	private: System::Windows::Forms::TextBox^ TbNEntreprise;
	private: System::Windows::Forms::Button^ BtValidate;
	private: System::Windows::Forms::Button^ BtReturn;
	private: System::Windows::Forms::Label^ LbPersonalAdress;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::CheckBox^ CboxCompany;
	private: System::Windows::Forms::Label^ LbLogo;
	private: System::Windows::Forms::TextBox^ TbLogo;

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
			this->LbDeliveryAdress = (gcnew System::Windows::Forms::Label());
			this->LbBirthDate = (gcnew System::Windows::Forms::Label());
			this->LbNCompany = (gcnew System::Windows::Forms::Label());
			this->TbAdress = (gcnew System::Windows::Forms::TextBox());
			this->TbBirthDate = (gcnew System::Windows::Forms::TextBox());
			this->TbNEntreprise = (gcnew System::Windows::Forms::TextBox());
			this->BtValidate = (gcnew System::Windows::Forms::Button());
			this->BtReturn = (gcnew System::Windows::Forms::Button());
			this->LbPersonalAdress = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->CboxCompany = (gcnew System::Windows::Forms::CheckBox());
			this->LbLogo = (gcnew System::Windows::Forms::Label());
			this->TbLogo = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// LbUserInfo
			// 
			this->LbUserInfo->AutoSize = true;
			this->LbUserInfo->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbUserInfo->Location = System::Drawing::Point(16, 34);
			this->LbUserInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbUserInfo->Name = L"LbUserInfo";
			this->LbUserInfo->Size = System::Drawing::Size(212, 29);
			this->LbUserInfo->TabIndex = 0;
			this->LbUserInfo->Text = L"Nouvel utilisateur";
			// 
			// LbName
			// 
			this->LbName->AutoSize = true;
			this->LbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbName->Location = System::Drawing::Point(18, 102);
			this->LbName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
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
			this->LbFirstName->Location = System::Drawing::Point(18, 199);
			this->LbFirstName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbFirstName->Name = L"LbFirstName";
			this->LbFirstName->Size = System::Drawing::Size(65, 19);
			this->LbFirstName->TabIndex = 2;
			this->LbFirstName->Text = L"Prénom";
			// 
			// TbName
			// 
			this->TbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbName->Location = System::Drawing::Point(24, 136);
			this->TbName->Margin = System::Windows::Forms::Padding(4);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(352, 26);
			this->TbName->TabIndex = 3;
			// 
			// TbFirstName
			// 
			this->TbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbFirstName->Location = System::Drawing::Point(24, 232);
			this->TbFirstName->Margin = System::Windows::Forms::Padding(4);
			this->TbFirstName->Name = L"TbFirstName";
			this->TbFirstName->Size = System::Drawing::Size(352, 26);
			this->TbFirstName->TabIndex = 4;
			// 
			// LbDeliveryAdress
			// 
			this->LbDeliveryAdress->AutoSize = true;
			this->LbDeliveryAdress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbDeliveryAdress->Location = System::Drawing::Point(18, 379);
			this->LbDeliveryAdress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbDeliveryAdress->Name = L"LbDeliveryAdress";
			this->LbDeliveryAdress->Size = System::Drawing::Size(160, 19);
			this->LbDeliveryAdress->TabIndex = 5;
			this->LbDeliveryAdress->Text = L"Adresse de livraison";
			// 
			// LbBirthDate
			// 
			this->LbBirthDate->AutoSize = true;
			this->LbBirthDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBirthDate->Location = System::Drawing::Point(18, 292);
			this->LbBirthDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
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
			this->LbNCompany->Location = System::Drawing::Point(18, 618);
			this->LbNCompany->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbNCompany->Name = L"LbNCompany";
			this->LbNCompany->Size = System::Drawing::Size(109, 19);
			this->LbNCompany->TabIndex = 7;
			this->LbNCompany->Text = L"N° Entreprise";
			// 
			// TbAdress
			// 
			this->TbAdress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbAdress->Location = System::Drawing::Point(24, 412);
			this->TbAdress->Margin = System::Windows::Forms::Padding(4);
			this->TbAdress->Name = L"TbAdress";
			this->TbAdress->Size = System::Drawing::Size(352, 26);
			this->TbAdress->TabIndex = 8;
			// 
			// TbBirthDate
			// 
			this->TbBirthDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbBirthDate->Location = System::Drawing::Point(24, 326);
			this->TbBirthDate->Margin = System::Windows::Forms::Padding(4);
			this->TbBirthDate->Name = L"TbBirthDate";
			this->TbBirthDate->Size = System::Drawing::Size(352, 26);
			this->TbBirthDate->TabIndex = 9;
			// 
			// TbNEntreprise
			// 
			this->TbNEntreprise->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbNEntreprise->Location = System::Drawing::Point(24, 675);
			this->TbNEntreprise->Margin = System::Windows::Forms::Padding(4);
			this->TbNEntreprise->Name = L"TbNEntreprise";
			this->TbNEntreprise->Size = System::Drawing::Size(352, 26);
			this->TbNEntreprise->TabIndex = 10;
			// 
			// BtValidate
			// 
			this->BtValidate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtValidate->Location = System::Drawing::Point(39, 836);
			this->BtValidate->Margin = System::Windows::Forms::Padding(4);
			this->BtValidate->Name = L"BtValidate";
			this->BtValidate->Size = System::Drawing::Size(148, 51);
			this->BtValidate->TabIndex = 11;
			this->BtValidate->Text = L"Valider";
			this->BtValidate->UseVisualStyleBackColor = true;
			// 
			// BtReturn
			// 
			this->BtReturn->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtReturn->Location = System::Drawing::Point(219, 836);
			this->BtReturn->Margin = System::Windows::Forms::Padding(4);
			this->BtReturn->Name = L"BtReturn";
			this->BtReturn->Size = System::Drawing::Size(148, 51);
			this->BtReturn->TabIndex = 12;
			this->BtReturn->Text = L"Retour";
			this->BtReturn->UseVisualStyleBackColor = true;
			// 
			// LbPersonalAdress
			// 
			this->LbPersonalAdress->AutoSize = true;
			this->LbPersonalAdress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPersonalAdress->Location = System::Drawing::Point(24, 471);
			this->LbPersonalAdress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbPersonalAdress->Name = L"LbPersonalAdress";
			this->LbPersonalAdress->Size = System::Drawing::Size(163, 19);
			this->LbPersonalAdress->TabIndex = 13;
			this->LbPersonalAdress->Text = L"Adresse personnelle";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(24, 504);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(352, 26);
			this->textBox1->TabIndex = 14;
			// 
			// CboxCompany
			// 
			this->CboxCompany->AutoSize = true;
			this->CboxCompany->Font = (gcnew System::Drawing::Font(L"Orkney", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CboxCompany->Location = System::Drawing::Point(18, 582);
			this->CboxCompany->Margin = System::Windows::Forms::Padding(4);
			this->CboxCompany->Name = L"CboxCompany";
			this->CboxCompany->Size = System::Drawing::Size(200, 22);
			this->CboxCompany->TabIndex = 15;
			this->CboxCompany->Text = L"Etes-vous une entreprise";
			this->CboxCompany->UseVisualStyleBackColor = true;
			// 
			// LbLogo
			// 
			this->LbLogo->AutoSize = true;
			this->LbLogo->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbLogo->Location = System::Drawing::Point(26, 735);
			this->LbLogo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbLogo->Name = L"LbLogo";
			this->LbLogo->Size = System::Drawing::Size(45, 19);
			this->LbLogo->TabIndex = 16;
			this->LbLogo->Text = L"Logo";
			// 
			// TbLogo
			// 
			this->TbLogo->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbLogo->Location = System::Drawing::Point(24, 766);
			this->TbLogo->Margin = System::Windows::Forms::Padding(4);
			this->TbLogo->Name = L"TbLogo";
			this->TbLogo->Size = System::Drawing::Size(352, 26);
			this->TbLogo->TabIndex = 17;
			// 
			// modifUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(420, 895);
			this->Controls->Add(this->TbLogo);
			this->Controls->Add(this->LbLogo);
			this->Controls->Add(this->CboxCompany);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->LbPersonalAdress);
			this->Controls->Add(this->BtReturn);
			this->Controls->Add(this->BtValidate);
			this->Controls->Add(this->TbNEntreprise);
			this->Controls->Add(this->TbBirthDate);
			this->Controls->Add(this->TbAdress);
			this->Controls->Add(this->LbNCompany);
			this->Controls->Add(this->LbBirthDate);
			this->Controls->Add(this->LbDeliveryAdress);
			this->Controls->Add(this->TbFirstName);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->LbFirstName);
			this->Controls->Add(this->LbName);
			this->Controls->Add(this->LbUserInfo);
			this->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"modifUser";
			this->Text = L"modifUser";
			this->ResumeLayout(false);
			this->PerformLayout();

		};
	};
}