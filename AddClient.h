#pragma once
#include "Client.h"
namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class AddClient : public System::Windows::Forms::Form
	{
		Client^ client;
		bool addOrEdit;

	public:
		AddClient(Client^ client, bool addOrEdit)
		{
			this->client = client;
			this->addOrEdit = addOrEdit;

			InitializeComponent();

			System::Diagnostics::Debug::WriteLine("add article " + this->addOrEdit);
			if (addOrEdit) {
				this->TbFirstName->Text = client->getFirstName();
				this->TbLastName->Text = client->getLastName(); 
				}
	}

	protected:
		
		~AddClient() override
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
		   System::Windows::Forms::Label^ LbFirstName;
		   System::Windows::Forms::TextBox^ TbFirstName;
		   System::Windows::Forms::Button^ BtnAddClient;
		   System::Windows::Forms::Button^ BtnCancel;
		   System::Windows::Forms::Label^ LbBirthday;
		   System::Windows::Forms::TextBox^ TbPostalCodeBilling;
		   System::Windows::Forms::Label^ LbPostalCodeBilling;
		   System::Windows::Forms::Label^ LbLastName;
		   System::Windows::Forms::TextBox^ TbLastName;
		   System::Windows::Forms::CheckBox^ CbCompany;
		   System::Windows::Forms::DateTimePicker^ DtpBirthdate;
		   System::Windows::Forms::Label^ LbBillingAddress;
		   System::Windows::Forms::TextBox^ TbNumberBilling;
		   System::Windows::Forms::Label^ LbStreetBilling;
		   System::Windows::Forms::TextBox^ TbStreetBilling;
		   System::Windows::Forms::Label^ LbNumberBilling;
		   System::Windows::Forms::Label^ LbDeliveryAddress;
		   System::Windows::Forms::Label^ LbNumberDelivery;
		   System::Windows::Forms::TextBox^ TbNumberDelivery;
		   System::Windows::Forms::Label^ LbStreetDelivery;
		   System::Windows::Forms::TextBox^ TbStreetDelivery;
		   System::Windows::Forms::Label^ LbPostalCodeDelivery;
		   System::Windows::Forms::TextBox^ TbPostalCodeDelivery;

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
			   this->LbFirstName = (gcnew System::Windows::Forms::Label());
			   this->TbFirstName = (gcnew System::Windows::Forms::TextBox());
			   this->BtnAddClient = (gcnew System::Windows::Forms::Button());
			   this->BtnCancel = (gcnew System::Windows::Forms::Button());
			   this->LbBirthday = (gcnew System::Windows::Forms::Label());
			   this->TbPostalCodeBilling = (gcnew System::Windows::Forms::TextBox());
			   this->LbPostalCodeBilling = (gcnew System::Windows::Forms::Label());
			   this->LbLastName = (gcnew System::Windows::Forms::Label());
			   this->TbLastName = (gcnew System::Windows::Forms::TextBox());
			   this->CbCompany = (gcnew System::Windows::Forms::CheckBox());
			   this->DtpBirthdate = (gcnew System::Windows::Forms::DateTimePicker());
			   this->LbBillingAddress = (gcnew System::Windows::Forms::Label());
			   this->TbNumberBilling = (gcnew System::Windows::Forms::TextBox());
			   this->LbStreetBilling = (gcnew System::Windows::Forms::Label());
			   this->TbStreetBilling = (gcnew System::Windows::Forms::TextBox());
			   this->LbNumberBilling = (gcnew System::Windows::Forms::Label());
			   this->LbDeliveryAddress = (gcnew System::Windows::Forms::Label());
			   this->LbNumberDelivery = (gcnew System::Windows::Forms::Label());
			   this->TbNumberDelivery = (gcnew System::Windows::Forms::TextBox());
			   this->LbStreetDelivery = (gcnew System::Windows::Forms::Label());
			   this->TbStreetDelivery = (gcnew System::Windows::Forms::TextBox());
			   this->LbPostalCodeDelivery = (gcnew System::Windows::Forms::Label());
			   this->TbPostalCodeDelivery = (gcnew System::Windows::Forms::TextBox());
			   this->SuspendLayout();
			   // 
			   // Title
			   // 
			   this->Title->AutoSize = true;
			   this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Title->Location = System::Drawing::Point(364, 11);
			   this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->Title->Name = L"Title";
			   this->Title->Size = System::Drawing::Size(379, 36);
			   this->Title->TabIndex = 0;
			   this->Title->Text = L"Ajouter un nouveau client";
			   // 
			   // LbFirstName
			   // 
			   this->LbFirstName->AutoSize = true;
			   this->LbFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbFirstName->Location = System::Drawing::Point(16, 174);
			   this->LbFirstName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbFirstName->Name = L"LbFirstName";
			   this->LbFirstName->Size = System::Drawing::Size(80, 25);
			   this->LbFirstName->TabIndex = 5;
			   this->LbFirstName->Text = L"Prenom";
			   // 
			   // TbFirstName
			   // 
			   this->TbFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TbFirstName->Location = System::Drawing::Point(21, 201);
			   this->TbFirstName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TbFirstName->Name = L"TbFirstName";
			   this->TbFirstName->Size = System::Drawing::Size(419, 30);
			   this->TbFirstName->TabIndex = 8;
			   // 
			   // BtnAddClient
			   // 
			   this->BtnAddClient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnAddClient->Location = System::Drawing::Point(16, 511);
			   this->BtnAddClient->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->BtnAddClient->Name = L"BtnAddClient";
			   this->BtnAddClient->Size = System::Drawing::Size(148, 52);
			   this->BtnAddClient->TabIndex = 13;
			   this->BtnAddClient->Text = L"Ajouter";
			   this->BtnAddClient->UseVisualStyleBackColor = true;
			   this->BtnAddClient->Click += gcnew System::EventHandler(this, &AddClient::BtnAddClient_Click);
			   // 
			   // BtnCancel
			   // 
			   this->BtnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnCancel->Location = System::Drawing::Point(288, 511);
			   this->BtnCancel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->BtnCancel->Name = L"BtnCancel";
			   this->BtnCancel->Size = System::Drawing::Size(148, 52);
			   this->BtnCancel->TabIndex = 14;
			   this->BtnCancel->Text = L"Annuler";
			   this->BtnCancel->UseVisualStyleBackColor = true;
			   this->BtnCancel->Click += gcnew System::EventHandler(this, &AddClient::BtnCancel_Click);
			   // 
			   // LbBirthday
			   // 
			   this->LbBirthday->AutoSize = true;
			   this->LbBirthday->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbBirthday->Location = System::Drawing::Point(16, 256);
			   this->LbBirthday->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbBirthday->Name = L"LbBirthday";
			   this->LbBirthday->Size = System::Drawing::Size(174, 25);
			   this->LbBirthday->TabIndex = 16;
			   this->LbBirthday->Text = L"Date de naissance";
			   // 
			   // TbPostalCodeBilling
			   // 
			   this->TbPostalCodeBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->TbPostalCodeBilling->Location = System::Drawing::Point(592, 310);
			   this->TbPostalCodeBilling->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TbPostalCodeBilling->Name = L"TbPostalCodeBilling";
			   this->TbPostalCodeBilling->Size = System::Drawing::Size(419, 30);
			   this->TbPostalCodeBilling->TabIndex = 30;
			   // 
			   // LbPostalCodeBilling
			   // 
			   this->LbPostalCodeBilling->AutoSize = true;
			   this->LbPostalCodeBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->LbPostalCodeBilling->Location = System::Drawing::Point(587, 283);
			   this->LbPostalCodeBilling->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbPostalCodeBilling->Name = L"LbPostalCodeBilling";
			   this->LbPostalCodeBilling->Size = System::Drawing::Size(112, 25);
			   this->LbPostalCodeBilling->TabIndex = 29;
			   this->LbPostalCodeBilling->Text = L"Codepostal";
			   // 
			   // LbLastName
			   // 
			   this->LbLastName->AutoSize = true;
			   this->LbLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbLastName->Location = System::Drawing::Point(16, 85);
			   this->LbLastName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbLastName->Name = L"LbLastName";
			   this->LbLastName->Size = System::Drawing::Size(53, 25);
			   this->LbLastName->TabIndex = 1;
			   this->LbLastName->Text = L"Nom";
			   // 
			   // TbLastName
			   // 
			   this->TbLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TbLastName->Location = System::Drawing::Point(21, 112);
			   this->TbLastName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TbLastName->Name = L"TbLastName";
			   this->TbLastName->Size = System::Drawing::Size(419, 30);
			   this->TbLastName->TabIndex = 7;
			   // 
			   // CbCompany
			   // 
			   this->CbCompany->AutoSize = true;
			   this->CbCompany->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->CbCompany->Location = System::Drawing::Point(79, 345);
			   this->CbCompany->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->CbCompany->Name = L"CbCompany";
			   this->CbCompany->Size = System::Drawing::Size(249, 29);
			   this->CbCompany->TabIndex = 31;
			   this->CbCompany->Text = L"etes-vous une entreprise";
			   this->CbCompany->UseVisualStyleBackColor = true;
			   this->CbCompany->CheckedChanged += gcnew System::EventHandler(this, &AddClient::CbCompany_CheckedChanged);
			   // 
			   // DtpBirthdate
			   // 
			   this->DtpBirthdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->DtpBirthdate->Location = System::Drawing::Point(21, 283);
			   this->DtpBirthdate->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->DtpBirthdate->Name = L"DtpBirthdate";
			   this->DtpBirthdate->Size = System::Drawing::Size(419, 30);
			   this->DtpBirthdate->TabIndex = 32;
			   this->DtpBirthdate->Value = System::DateTime(2023, 11, 28, 0, 0, 0, 0);
			   // 
			   // LbBillingAddress
			   // 
			   this->LbBillingAddress->AutoSize = true;
			   this->LbBillingAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbBillingAddress->Location = System::Drawing::Point(587, 85);
			   this->LbBillingAddress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbBillingAddress->Name = L"LbBillingAddress";
			   this->LbBillingAddress->Size = System::Drawing::Size(207, 25);
			   this->LbBillingAddress->TabIndex = 33;
			   this->LbBillingAddress->Text = L"Adresse de facturation";
			   // 
			   // TbNumberBilling
			   // 
			   this->TbNumberBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TbNumberBilling->Location = System::Drawing::Point(592, 146);
			   this->TbNumberBilling->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TbNumberBilling->Name = L"TbNumberBilling";
			   this->TbNumberBilling->Size = System::Drawing::Size(419, 30);
			   this->TbNumberBilling->TabIndex = 34;
			   // 
			   // LbStreetBilling
			   // 
			   this->LbStreetBilling->AutoSize = true;
			   this->LbStreetBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbStreetBilling->Location = System::Drawing::Point(587, 201);
			   this->LbStreetBilling->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbStreetBilling->Name = L"LbStreetBilling";
			   this->LbStreetBilling->Size = System::Drawing::Size(113, 25);
			   this->LbStreetBilling->TabIndex = 35;
			   this->LbStreetBilling->Text = L"Nom de rue";
			   // 
			   // TbStreetBilling
			   // 
			   this->TbStreetBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TbStreetBilling->Location = System::Drawing::Point(592, 228);
			   this->TbStreetBilling->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TbStreetBilling->Name = L"TbStreetBilling";
			   this->TbStreetBilling->Size = System::Drawing::Size(419, 30);
			   this->TbStreetBilling->TabIndex = 36;
			   // 
			   // LbNumberBilling
			   // 
			   this->LbNumberBilling->AutoSize = true;
			   this->LbNumberBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbNumberBilling->Location = System::Drawing::Point(587, 119);
			   this->LbNumberBilling->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbNumberBilling->Name = L"LbNumberBilling";
			   this->LbNumberBilling->Size = System::Drawing::Size(81, 25);
			   this->LbNumberBilling->TabIndex = 39;
			   this->LbNumberBilling->Text = L"Numero";
			   // 
			   // LbDeliveryAddress
			   // 
			   this->LbDeliveryAddress->AutoSize = true;
			   this->LbDeliveryAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbDeliveryAddress->Location = System::Drawing::Point(587, 389);
			   this->LbDeliveryAddress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbDeliveryAddress->Name = L"LbDeliveryAddress";
			   this->LbDeliveryAddress->Size = System::Drawing::Size(188, 25);
			   this->LbDeliveryAddress->TabIndex = 40;
			   this->LbDeliveryAddress->Text = L"Adresse de livraison";
			   // 
			   // LbNumberDelivery
			   // 
			   this->LbNumberDelivery->AutoSize = true;
			   this->LbNumberDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbNumberDelivery->Location = System::Drawing::Point(587, 436);
			   this->LbNumberDelivery->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbNumberDelivery->Name = L"LbNumberDelivery";
			   this->LbNumberDelivery->Size = System::Drawing::Size(81, 25);
			   this->LbNumberDelivery->TabIndex = 41;
			   this->LbNumberDelivery->Text = L"Numero";
			   // 
			   // TbNumberDelivery
			   // 
			   this->TbNumberDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TbNumberDelivery->Location = System::Drawing::Point(593, 463);
			   this->TbNumberDelivery->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TbNumberDelivery->Name = L"TbNumberDelivery";
			   this->TbNumberDelivery->Size = System::Drawing::Size(419, 30);
			   this->TbNumberDelivery->TabIndex = 42;
			   // 
			   // LbStreetDelivery
			   // 
			   this->LbStreetDelivery->AutoSize = true;
			   this->LbStreetDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbStreetDelivery->Location = System::Drawing::Point(587, 526);
			   this->LbStreetDelivery->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbStreetDelivery->Name = L"LbStreetDelivery";
			   this->LbStreetDelivery->Size = System::Drawing::Size(113, 25);
			   this->LbStreetDelivery->TabIndex = 43;
			   this->LbStreetDelivery->Text = L"Nom de rue";
			   // 
			   // TbStreetDelivery
			   // 
			   this->TbStreetDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TbStreetDelivery->Location = System::Drawing::Point(592, 553);
			   this->TbStreetDelivery->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TbStreetDelivery->Name = L"TbStreetDelivery";
			   this->TbStreetDelivery->Size = System::Drawing::Size(419, 30);
			   this->TbStreetDelivery->TabIndex = 44;
			   // 
			   // LbPostalCodeDelivery
			   // 
			   this->LbPostalCodeDelivery->AutoSize = true;
			   this->LbPostalCodeDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->LbPostalCodeDelivery->Location = System::Drawing::Point(588, 620);
			   this->LbPostalCodeDelivery->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->LbPostalCodeDelivery->Name = L"LbPostalCodeDelivery";
			   this->LbPostalCodeDelivery->Size = System::Drawing::Size(112, 25);
			   this->LbPostalCodeDelivery->TabIndex = 45;
			   this->LbPostalCodeDelivery->Text = L"Codepostal";
			   // 
			   // TbPostalCodeDelivery
			   // 
			   this->TbPostalCodeDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->TbPostalCodeDelivery->Location = System::Drawing::Point(592, 647);
			   this->TbPostalCodeDelivery->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->TbPostalCodeDelivery->Name = L"TbPostalCodeDelivery";
			   this->TbPostalCodeDelivery->Size = System::Drawing::Size(419, 30);
			   this->TbPostalCodeDelivery->TabIndex = 46;
			   //
			   // paramètre si modification de profil existant
			   //
			   System::Diagnostics::Debug::WriteLine("before if else " + this->addOrEdit);
			   System::Diagnostics::Debug::WriteLine("before if else " + addOrEdit);
			   if (this->addOrEdit) {
				   System::Diagnostics::Debug::WriteLine(this->addOrEdit);
				   this->Title->Text = L"Modicifation info Client";
				   this->BtnAddClient->Text = L"Valider";
				   this->BtnAddClient->Location = System::Drawing::Point(112, 480);
				   this->BtnCancel->Visible = false;
			   }
			   else {
				   this->Title->Text = L"Ajouter un nouveau Client";
				   this->BtnAddClient->Text = L"Ajouter";
			   }
			   // 
			   // AddClient
			   // 
			   this->MaximizeBox = false;
			   this->ControlBox = false;
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1171, 746);
			   this->Controls->Add(this->TbPostalCodeDelivery);
			   this->Controls->Add(this->LbPostalCodeDelivery);
			   this->Controls->Add(this->TbStreetDelivery);
			   this->Controls->Add(this->LbStreetDelivery);
			   this->Controls->Add(this->TbNumberDelivery);
			   this->Controls->Add(this->LbNumberDelivery);
			   this->Controls->Add(this->LbDeliveryAddress);
			   this->Controls->Add(this->LbNumberBilling);
			   this->Controls->Add(this->TbStreetBilling);
			   this->Controls->Add(this->LbStreetBilling);
			   this->Controls->Add(this->TbNumberBilling);
			   this->Controls->Add(this->LbBillingAddress);
			   this->Controls->Add(this->DtpBirthdate);
			   this->Controls->Add(this->CbCompany);
			   this->Controls->Add(this->TbPostalCodeBilling);
			   this->Controls->Add(this->LbPostalCodeBilling);
			   this->Controls->Add(this->LbBirthday);
			   this->Controls->Add(this->BtnCancel);
			   this->Controls->Add(this->BtnAddClient);
			   this->Controls->Add(this->TbFirstName);
			   this->Controls->Add(this->TbLastName);
			   this->Controls->Add(this->LbFirstName);
			   this->Controls->Add(this->LbLastName);
			   this->Controls->Add(this->Title);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->MaximizeBox = false;
			   this->Name = L"AddClient";
			   this->Text = L"AddClient";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void CbCompany_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (CbCompany->Checked) {
			DtpBirthdate->Enabled = false;
			this->client->setTypeClient("Entreprise");
		}
		else {
			DtpBirthdate->Enabled = true;
			this->client->setTypeClient("Particulier");
		}
	}
	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	
	private: System::Void BtnAddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		this->client->setFirstName(this->TbFirstName->Text);
		this->client->setLastName(this->TbLastName->Text);
		String^ dateString = this->DtpBirthdate->Value.ToString("yyyy-MM-dd");
		DateTime Birthday = DateTime::ParseExact(dateString, "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
		this->client->setBirthday(Birthday);
		//this->client->setTypeClient(this->)
		this->Close();
	}
	};
}