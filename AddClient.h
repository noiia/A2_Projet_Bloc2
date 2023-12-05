#pragma once
#include "BDD.h"
#include "Client.h"
namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r sum e de AddClient
	/// </summary>
	public ref class AddClient : public System::Windows::Forms::Form
	{
		Client^ client;
	public:
		AddClient(Client^ client)
		{
			this->client = client;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis es.
		/// </summary>
		~AddClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ LbBillingAddress;


	protected:

	protected:



	private: System::Windows::Forms::Label^ LbFirstName;



	private: System::Windows::Forms::Label^ LbDeliveryAddress;
	private: System::Windows::Forms::TextBox^ TbFirstName;
	private: System::Windows::Forms::TextBox^ TbNumeroAdressDelivery;

	private: System::Windows::Forms::TextBox^ TbNumeroBilling;



	private: System::Windows::Forms::Button^ BtnAddClient;
	private: System::Windows::Forms::Button^ BtnCancel;

	private: System::Windows::Forms::Label^ LbBirthday;
	private: System::Windows::Forms::Label^ LbNumeroBilling;
	private: System::Windows::Forms::Label^ LbNumeroAdressDelivery;
	private: System::Windows::Forms::Label^ LbStreetDelivery;
	private: System::Windows::Forms::TextBox^ TbStreetDelivery;
	private: System::Windows::Forms::TextBox^ TbCityDelivery;



	private: System::Windows::Forms::Label^ LbCityDelivery;
	private: System::Windows::Forms::Label^ LbPostalCodeDelivery;
	private: System::Windows::Forms::TextBox^ TbPostalCodeDelivery;


	private: System::Windows::Forms::TextBox^ TbPostalCodeBilling;


	private: System::Windows::Forms::Label^ LbPostalCodeBilling;

	private: System::Windows::Forms::Label^ LbCityBilling;
	private: System::Windows::Forms::TextBox^ TbCityBilling;


	private: System::Windows::Forms::TextBox^ TbStreetBilling;

	private: System::Windows::Forms::Label^ LbStreetBilling;

	private: System::Windows::Forms::Label^ LbLastName;
	private: System::Windows::Forms::TextBox^ TbLastName;
	private: System::Windows::Forms::CheckBox^ CbCompany;
	private: System::Windows::Forms::DateTimePicker^ DtpBirthdate;




	private:
		/// <summary>
		/// Variable n cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m thode avec l' diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddClient::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->LbBillingAddress = (gcnew System::Windows::Forms::Label());
			this->LbFirstName = (gcnew System::Windows::Forms::Label());
			this->LbDeliveryAddress = (gcnew System::Windows::Forms::Label());
			this->TbFirstName = (gcnew System::Windows::Forms::TextBox());
			this->TbNumeroAdressDelivery = (gcnew System::Windows::Forms::TextBox());
			this->TbNumeroBilling = (gcnew System::Windows::Forms::TextBox());
			this->BtnAddClient = (gcnew System::Windows::Forms::Button());
			this->BtnCancel = (gcnew System::Windows::Forms::Button());
			this->LbBirthday = (gcnew System::Windows::Forms::Label());
			this->LbNumeroBilling = (gcnew System::Windows::Forms::Label());
			this->LbNumeroAdressDelivery = (gcnew System::Windows::Forms::Label());
			this->LbStreetDelivery = (gcnew System::Windows::Forms::Label());
			this->TbStreetDelivery = (gcnew System::Windows::Forms::TextBox());
			this->TbCityDelivery = (gcnew System::Windows::Forms::TextBox());
			this->LbCityDelivery = (gcnew System::Windows::Forms::Label());
			this->LbPostalCodeDelivery = (gcnew System::Windows::Forms::Label());
			this->TbPostalCodeDelivery = (gcnew System::Windows::Forms::TextBox());
			this->TbPostalCodeBilling = (gcnew System::Windows::Forms::TextBox());
			this->LbPostalCodeBilling = (gcnew System::Windows::Forms::Label());
			this->LbCityBilling = (gcnew System::Windows::Forms::Label());
			this->TbCityBilling = (gcnew System::Windows::Forms::TextBox());
			this->TbStreetBilling = (gcnew System::Windows::Forms::TextBox());
			this->LbStreetBilling = (gcnew System::Windows::Forms::Label());
			this->LbLastName = (gcnew System::Windows::Forms::Label());
			this->TbLastName = (gcnew System::Windows::Forms::TextBox());
			this->CbCompany = (gcnew System::Windows::Forms::CheckBox());
			this->DtpBirthdate = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(39, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(309, 28);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Ajouter un nouveau client";
			// 
			// LbBillingAddress
			// 
			this->LbBillingAddress->AutoSize = true;
			this->LbBillingAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBillingAddress->Location = System::Drawing::Point(14, 467);
			this->LbBillingAddress->Name = L"LbBillingAddress";
			this->LbBillingAddress->Size = System::Drawing::Size(179, 19);
			this->LbBillingAddress->TabIndex = 3;
			this->LbBillingAddress->Text = L"Adresse de facturation";
			// 
			// LbFirstName
			// 
			this->LbFirstName->AutoSize = true;
			this->LbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbFirstName->Location = System::Drawing::Point(12, 141);
			this->LbFirstName->Name = L"LbFirstName";
			this->LbFirstName->Size = System::Drawing::Size(65, 19);
			this->LbFirstName->TabIndex = 5;
			this->LbFirstName->Text = L"Prénom";
			// 
			// LbDeliveryAddress
			// 
			this->LbDeliveryAddress->AutoSize = true;
			this->LbDeliveryAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbDeliveryAddress->Location = System::Drawing::Point(13, 209);
			this->LbDeliveryAddress->Name = L"LbDeliveryAddress";
			this->LbDeliveryAddress->Size = System::Drawing::Size(160, 19);
			this->LbDeliveryAddress->TabIndex = 6;
			this->LbDeliveryAddress->Text = L"Adresse de livraison";
			// 
			// TbFirstName
			// 
			this->TbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbFirstName->Location = System::Drawing::Point(16, 163);
			this->TbFirstName->Name = L"TbFirstName";
			this->TbFirstName->Size = System::Drawing::Size(315, 27);
			this->TbFirstName->TabIndex = 8;
			// 
			// TbNumeroAdressDelivery
			// 
			this->TbNumeroAdressDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbNumeroAdressDelivery->Location = System::Drawing::Point(17, 250);
			this->TbNumeroAdressDelivery->Name = L"TbNumeroAdressDelivery";
			this->TbNumeroAdressDelivery->Size = System::Drawing::Size(315, 27);
			this->TbNumeroAdressDelivery->TabIndex = 9;
			// 
			// TbNumeroBilling
			// 
			this->TbNumeroBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbNumeroBilling->Location = System::Drawing::Point(13, 508);
			this->TbNumeroBilling->Name = L"TbNumeroBilling";
			this->TbNumeroBilling->Size = System::Drawing::Size(315, 27);
			this->TbNumeroBilling->TabIndex = 10;
			// 
			// BtnAddClient
			// 
			this->BtnAddClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddClient->Location = System::Drawing::Point(17, 809);
			this->BtnAddClient->Name = L"BtnAddClient";
			this->BtnAddClient->Size = System::Drawing::Size(111, 42);
			this->BtnAddClient->TabIndex = 13;
			this->BtnAddClient->Text = L"Ajouter";
			this->BtnAddClient->UseVisualStyleBackColor = true;
			this->BtnAddClient->Click += gcnew System::EventHandler(this, &AddClient::BtnAddClient_Click);
			// 
			// BtnCancel
			// 
			this->BtnCancel->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCancel->Location = System::Drawing::Point(216, 809);
			this->BtnCancel->Name = L"BtnCancel";
			this->BtnCancel->Size = System::Drawing::Size(111, 42);
			this->BtnCancel->TabIndex = 14;
			this->BtnCancel->Text = L"Annuler";
			this->BtnCancel->UseVisualStyleBackColor = true;
			this->BtnCancel->Click += gcnew System::EventHandler(this, &AddClient::BtnCancel_Click);
			// 
			// LbBirthday
			// 
			this->LbBirthday->AutoSize = true;
			this->LbBirthday->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBirthday->Location = System::Drawing::Point(8, 729);
			this->LbBirthday->Name = L"LbBirthday";
			this->LbBirthday->Size = System::Drawing::Size(143, 19);
			this->LbBirthday->TabIndex = 16;
			this->LbBirthday->Text = L"Date de naissance";
			// 
			// LbNumeroBilling
			// 
			this->LbNumeroBilling->AutoSize = true;
			this->LbNumeroBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbNumeroBilling->Location = System::Drawing::Point(14, 486);
			this->LbNumeroBilling->Name = L"LbNumeroBilling";
			this->LbNumeroBilling->Size = System::Drawing::Size(69, 19);
			this->LbNumeroBilling->TabIndex = 17;
			this->LbNumeroBilling->Text = L"Numero";
			// 
			// LbNumeroAdressDelivery
			// 
			this->LbNumeroAdressDelivery->AutoSize = true;
			this->LbNumeroAdressDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbNumeroAdressDelivery->Location = System::Drawing::Point(13, 228);
			this->LbNumeroAdressDelivery->Name = L"LbNumeroAdressDelivery";
			this->LbNumeroAdressDelivery->Size = System::Drawing::Size(69, 19);
			this->LbNumeroAdressDelivery->TabIndex = 18;
			this->LbNumeroAdressDelivery->Text = L"Numero";
			// 
			// LbStreetDelivery
			// 
			this->LbStreetDelivery->AutoSize = true;
			this->LbStreetDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbStreetDelivery->Location = System::Drawing::Point(13, 280);
			this->LbStreetDelivery->Name = L"LbStreetDelivery";
			this->LbStreetDelivery->Size = System::Drawing::Size(37, 19);
			this->LbStreetDelivery->TabIndex = 19;
			this->LbStreetDelivery->Text = L"Rue";
			// 
			// TbStreetDelivery
			// 
			this->TbStreetDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbStreetDelivery->Location = System::Drawing::Point(17, 302);
			this->TbStreetDelivery->Name = L"TbStreetDelivery";
			this->TbStreetDelivery->Size = System::Drawing::Size(315, 27);
			this->TbStreetDelivery->TabIndex = 20;
			// 
			// TbCityDelivery
			// 
			this->TbCityDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbCityDelivery->Location = System::Drawing::Point(17, 355);
			this->TbCityDelivery->Name = L"TbCityDelivery";
			this->TbCityDelivery->Size = System::Drawing::Size(315, 27);
			this->TbCityDelivery->TabIndex = 21;
			// 
			// LbCityDelivery
			// 
			this->LbCityDelivery->AutoSize = true;
			this->LbCityDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbCityDelivery->Location = System::Drawing::Point(13, 333);
			this->LbCityDelivery->Name = L"LbCityDelivery";
			this->LbCityDelivery->Size = System::Drawing::Size(43, 19);
			this->LbCityDelivery->TabIndex = 22;
			this->LbCityDelivery->Text = L"Ville";
			// 
			// LbPostalCodeDelivery
			// 
			this->LbPostalCodeDelivery->AutoSize = true;
			this->LbPostalCodeDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPostalCodeDelivery->Location = System::Drawing::Point(14, 385);
			this->LbPostalCodeDelivery->Name = L"LbPostalCodeDelivery";
			this->LbPostalCodeDelivery->Size = System::Drawing::Size(95, 19);
			this->LbPostalCodeDelivery->TabIndex = 23;
			this->LbPostalCodeDelivery->Text = L"Codepostal";
			// 
			// TbPostalCodeDelivery
			// 
			this->TbPostalCodeDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPostalCodeDelivery->Location = System::Drawing::Point(17, 407);
			this->TbPostalCodeDelivery->Name = L"TbPostalCodeDelivery";
			this->TbPostalCodeDelivery->Size = System::Drawing::Size(315, 27);
			this->TbPostalCodeDelivery->TabIndex = 24;
			// 
			// TbPostalCodeBilling
			// 
			this->TbPostalCodeBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPostalCodeBilling->Location = System::Drawing::Point(13, 662);
			this->TbPostalCodeBilling->Name = L"TbPostalCodeBilling";
			this->TbPostalCodeBilling->Size = System::Drawing::Size(315, 27);
			this->TbPostalCodeBilling->TabIndex = 30;
			// 
			// LbPostalCodeBilling
			// 
			this->LbPostalCodeBilling->AutoSize = true;
			this->LbPostalCodeBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPostalCodeBilling->Location = System::Drawing::Point(14, 640);
			this->LbPostalCodeBilling->Name = L"LbPostalCodeBilling";
			this->LbPostalCodeBilling->Size = System::Drawing::Size(95, 19);
			this->LbPostalCodeBilling->TabIndex = 29;
			this->LbPostalCodeBilling->Text = L"Codepostal";
			// 
			// LbCityBilling
			// 
			this->LbCityBilling->AutoSize = true;
			this->LbCityBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbCityBilling->Location = System::Drawing::Point(14, 587);
			this->LbCityBilling->Name = L"LbCityBilling";
			this->LbCityBilling->Size = System::Drawing::Size(43, 19);
			this->LbCityBilling->TabIndex = 28;
			this->LbCityBilling->Text = L"Ville";
			// 
			// TbCityBilling
			// 
			this->TbCityBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbCityBilling->Location = System::Drawing::Point(13, 610);
			this->TbCityBilling->Name = L"TbCityBilling";
			this->TbCityBilling->Size = System::Drawing::Size(315, 27);
			this->TbCityBilling->TabIndex = 27;
			// 
			// TbStreetBilling
			// 
			this->TbStreetBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbStreetBilling->Location = System::Drawing::Point(13, 557);
			this->TbStreetBilling->Name = L"TbStreetBilling";
			this->TbStreetBilling->Size = System::Drawing::Size(315, 27);
			this->TbStreetBilling->TabIndex = 26;
			// 
			// LbStreetBilling
			// 
			this->LbStreetBilling->AutoSize = true;
			this->LbStreetBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbStreetBilling->Location = System::Drawing::Point(13, 535);
			this->LbStreetBilling->Name = L"LbStreetBilling";
			this->LbStreetBilling->Size = System::Drawing::Size(37, 19);
			this->LbStreetBilling->TabIndex = 25;
			this->LbStreetBilling->Text = L"Rue";
			// 
			// LbLastName
			// 
			this->LbLastName->AutoSize = true;
			this->LbLastName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbLastName->Location = System::Drawing::Point(12, 69);
			this->LbLastName->Name = L"LbLastName";
			this->LbLastName->Size = System::Drawing::Size(44, 19);
			this->LbLastName->TabIndex = 1;
			this->LbLastName->Text = L"Nom";
			// 
			// TbLastName
			// 
			this->TbLastName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbLastName->Location = System::Drawing::Point(16, 91);
			this->TbLastName->Name = L"TbLastName";
			this->TbLastName->Size = System::Drawing::Size(315, 27);
			this->TbLastName->TabIndex = 7;
			// 
			// CbCompany
			// 
			this->CbCompany->AutoSize = true;
			this->CbCompany->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CbCompany->Location = System::Drawing::Point(12, 703);
			this->CbCompany->Name = L"CbCompany";
			this->CbCompany->Size = System::Drawing::Size(215, 23);
			this->CbCompany->TabIndex = 31;
			this->CbCompany->Text = L"etes-vous une entreprise";
			this->CbCompany->UseVisualStyleBackColor = true;
			// 
			// DtpBirthdate
			// 
			this->DtpBirthdate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DtpBirthdate->Location = System::Drawing::Point(16, 751);
			this->DtpBirthdate->Name = L"DtpBirthdate";
			this->DtpBirthdate->Size = System::Drawing::Size(315, 27);
			this->DtpBirthdate->TabIndex = 32;
			// 
			// AddClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(395, 874);
			this->Controls->Add(this->DtpBirthdate);
			this->Controls->Add(this->CbCompany);
			this->Controls->Add(this->TbPostalCodeBilling);
			this->Controls->Add(this->LbPostalCodeBilling);
			this->Controls->Add(this->LbCityBilling);
			this->Controls->Add(this->TbCityBilling);
			this->Controls->Add(this->TbStreetBilling);
			this->Controls->Add(this->LbStreetBilling);
			this->Controls->Add(this->TbPostalCodeDelivery);
			this->Controls->Add(this->LbPostalCodeDelivery);
			this->Controls->Add(this->LbCityDelivery);
			this->Controls->Add(this->TbCityDelivery);
			this->Controls->Add(this->TbStreetDelivery);
			this->Controls->Add(this->LbStreetDelivery);
			this->Controls->Add(this->LbNumeroAdressDelivery);
			this->Controls->Add(this->LbNumeroBilling);
			this->Controls->Add(this->LbBirthday);
			this->Controls->Add(this->BtnCancel);
			this->Controls->Add(this->BtnAddClient);
			this->Controls->Add(this->TbNumeroBilling);
			this->Controls->Add(this->TbNumeroAdressDelivery);
			this->Controls->Add(this->TbFirstName);
			this->Controls->Add(this->TbLastName);
			this->Controls->Add(this->LbDeliveryAddress);
			this->Controls->Add(this->LbFirstName);
			this->Controls->Add(this->LbBillingAddress);
			this->Controls->Add(this->LbLastName);
			this->Controls->Add(this->Title);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddClient";
			this->Text = L"AddClient";
			this->Load += gcnew System::EventHandler(this, &AddClient::AddClient_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void BtnAddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		this->client->setFirstName(this->TbFirstName->Text);
		this->client->setLastName(this->TbLastName->Text);
		this->client->setBirthday(this->DtpBirthdate->Value);
		this->client->setNumeroAdressDelivery(this->TbNumeroAdressDelivery->Text);
		this->client->setStreetDelivery(this->TbStreetDelivery->Text);
		this->client->setCityDelivery(this->TbCityDelivery->Text);
		this->client->setPostalCodeDelivery(this->TbPostalCodeDelivery->Text);
		this->client->setNumeroBilling(this->TbNumeroBilling->Text);
		this->client->setStreetBilling(this->TbStreetBilling->Text);
		this->client->setCityBilling(this->TbCityBilling->Text);
		this->client->setPostalCodeBilling(this->TbPostalCodeBilling->Text);
		this->Close();
	}
	private: System::Void AddClient_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
