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
	/// Description r�sum�e de AddClient
	/// </summary>
	public ref class AddClient : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		AddClient(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~AddClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ LbSurname;
	private: System::Windows::Forms::Label^ LbCompagnyPhone;
	protected:

	protected:


	private: System::Windows::Forms::Label^ LbbillingAddress;




	private: System::Windows::Forms::Label^ LbName;
	private: System::Windows::Forms::Label^ LbDeliveryAddress;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ TbPriceWithoutTax;
	private: System::Windows::Forms::TextBox^ TbPriceWithTaxes;
	private: System::Windows::Forms::TextBox^ TbQuantity;
	private: System::Windows::Forms::TextBox^ TbCompagnyPhone;






	private: System::Windows::Forms::Button^ BtnAddClient;
	private: System::Windows::Forms::Button^ BtnCancel;
	private: System::Windows::Forms::TextBox^ TbBirthday;
	private: System::Windows::Forms::Label^ LbBirthday;
	private: System::Windows::Forms::CheckBox^ CboxCompagny;
	private: System::Windows::Forms::TextBox^ TbCompagnyLogo;
	private: System::Windows::Forms::Label^ LbCompagnyLogo;





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
			this->Title = (gcnew System::Windows::Forms::Label());
			this->LbSurname = (gcnew System::Windows::Forms::Label());
			this->LbCompagnyPhone = (gcnew System::Windows::Forms::Label());
			this->LbbillingAddress = (gcnew System::Windows::Forms::Label());
			this->LbName = (gcnew System::Windows::Forms::Label());
			this->LbDeliveryAddress = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->TbPriceWithoutTax = (gcnew System::Windows::Forms::TextBox());
			this->TbPriceWithTaxes = (gcnew System::Windows::Forms::TextBox());
			this->TbQuantity = (gcnew System::Windows::Forms::TextBox());
			this->TbCompagnyPhone = (gcnew System::Windows::Forms::TextBox());
			this->BtnAddClient = (gcnew System::Windows::Forms::Button());
			this->BtnCancel = (gcnew System::Windows::Forms::Button());
			this->TbBirthday = (gcnew System::Windows::Forms::TextBox());
			this->LbBirthday = (gcnew System::Windows::Forms::Label());
			this->CboxCompagny = (gcnew System::Windows::Forms::CheckBox());
			this->TbCompagnyLogo = (gcnew System::Windows::Forms::TextBox());
			this->LbCompagnyLogo = (gcnew System::Windows::Forms::Label());
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
			// LbSurname
			// 
			this->LbSurname->AutoSize = true;
			this->LbSurname->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSurname->Location = System::Drawing::Point(12, 69);
			this->LbSurname->Name = L"LbSurname";
			this->LbSurname->Size = System::Drawing::Size(44, 19);
			this->LbSurname->TabIndex = 1;
			this->LbSurname->Text = L"Nom";
			// 
			// LbCompagnyPhone
			// 
			this->LbCompagnyPhone->AutoSize = true;
			this->LbCompagnyPhone->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbCompagnyPhone->Location = System::Drawing::Point(12, 479);
			this->LbCompagnyPhone->Name = L"LbCompagnyPhone";
			this->LbCompagnyPhone->Size = System::Drawing::Size(109, 19);
			this->LbCompagnyPhone->TabIndex = 2;
			this->LbCompagnyPhone->Text = L"N° Entreprise";
			// 
			// LbbillingAddress
			// 
			this->LbbillingAddress->AutoSize = true;
			this->LbbillingAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbbillingAddress->Location = System::Drawing::Point(12, 359);
			this->LbbillingAddress->Name = L"LbbillingAddress";
			this->LbbillingAddress->Size = System::Drawing::Size(179, 19);
			this->LbbillingAddress->TabIndex = 3;
			this->LbbillingAddress->Text = L"Adresse de facturation";
			// 
			// LbName
			// 
			this->LbName->AutoSize = true;
			this->LbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbName->Location = System::Drawing::Point(12, 141);
			this->LbName->Name = L"LbName";
			this->LbName->Size = System::Drawing::Size(65, 19);
			this->LbName->TabIndex = 5;
			this->LbName->Text = L"Prénom";
			// 
			// LbDeliveryAddress
			// 
			this->LbDeliveryAddress->AutoSize = true;
			this->LbDeliveryAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbDeliveryAddress->Location = System::Drawing::Point(12, 295);
			this->LbDeliveryAddress->Name = L"LbDeliveryAddress";
			this->LbDeliveryAddress->Size = System::Drawing::Size(160, 19);
			this->LbDeliveryAddress->TabIndex = 6;
			this->LbDeliveryAddress->Text = L"Adresse de livraison";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(16, 91);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(315, 26);
			this->textBox1->TabIndex = 7;
			// 
			// TbPriceWithoutTax
			// 
			this->TbPriceWithoutTax->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPriceWithoutTax->Location = System::Drawing::Point(16, 163);
			this->TbPriceWithoutTax->Name = L"TbPriceWithoutTax";
			this->TbPriceWithoutTax->Size = System::Drawing::Size(315, 26);
			this->TbPriceWithoutTax->TabIndex = 8;
			// 
			// TbPriceWithTaxes
			// 
			this->TbPriceWithTaxes->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPriceWithTaxes->Location = System::Drawing::Point(16, 317);
			this->TbPriceWithTaxes->Name = L"TbPriceWithTaxes";
			this->TbPriceWithTaxes->Size = System::Drawing::Size(315, 26);
			this->TbPriceWithTaxes->TabIndex = 9;
			// 
			// TbQuantity
			// 
			this->TbQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbQuantity->Location = System::Drawing::Point(16, 381);
			this->TbQuantity->Name = L"TbQuantity";
			this->TbQuantity->Size = System::Drawing::Size(315, 26);
			this->TbQuantity->TabIndex = 10;
			// 
			// TbCompagnyPhone
			// 
			this->TbCompagnyPhone->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbCompagnyPhone->Location = System::Drawing::Point(16, 501);
			this->TbCompagnyPhone->Name = L"TbCompagnyPhone";
			this->TbCompagnyPhone->Size = System::Drawing::Size(315, 26);
			this->TbCompagnyPhone->TabIndex = 11;
			// 
			// BtnAddClient
			// 
			this->BtnAddClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddClient->Location = System::Drawing::Point(44, 652);
			this->BtnAddClient->Name = L"BtnAddClient";
			this->BtnAddClient->Size = System::Drawing::Size(111, 42);
			this->BtnAddClient->TabIndex = 13;
			this->BtnAddClient->Text = L"Ajouter";
			this->BtnAddClient->UseVisualStyleBackColor = true;
			// 
			// BtnCancel
			// 
			this->BtnCancel->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCancel->Location = System::Drawing::Point(220, 652);
			this->BtnCancel->Name = L"BtnCancel";
			this->BtnCancel->Size = System::Drawing::Size(111, 42);
			this->BtnCancel->TabIndex = 14;
			this->BtnCancel->Text = L"Annuler";
			this->BtnCancel->UseVisualStyleBackColor = true;
			this->BtnCancel->Click += gcnew System::EventHandler(this, &AddClient::BtnCancel_Click);
			// 
			// TbBirthday
			// 
			this->TbBirthday->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbBirthday->Location = System::Drawing::Point(16, 239);
			this->TbBirthday->Name = L"TbBirthday";
			this->TbBirthday->Size = System::Drawing::Size(315, 26);
			this->TbBirthday->TabIndex = 15;
			// 
			// LbBirthday
			// 
			this->LbBirthday->AutoSize = true;
			this->LbBirthday->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBirthday->Location = System::Drawing::Point(12, 217);
			this->LbBirthday->Name = L"LbBirthday";
			this->LbBirthday->Size = System::Drawing::Size(143, 19);
			this->LbBirthday->TabIndex = 16;
			this->LbBirthday->Text = L"Date de naissance";
			// 
			// CboxCompagny
			// 
			this->CboxCompagny->AutoSize = true;
			this->CboxCompagny->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CboxCompagny->Location = System::Drawing::Point(12, 439);
			this->CboxCompagny->Name = L"CboxCompagny";
			this->CboxCompagny->Size = System::Drawing::Size(228, 23);
			this->CboxCompagny->TabIndex = 17;
			this->CboxCompagny->Text = L"Etes-vous une entreprise \?";
			this->CboxCompagny->UseVisualStyleBackColor = true;
			// 
			// TbCompagnyLogo
			// 
			this->TbCompagnyLogo->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbCompagnyLogo->Location = System::Drawing::Point(16, 572);
			this->TbCompagnyLogo->Name = L"TbCompagnyLogo";
			this->TbCompagnyLogo->Size = System::Drawing::Size(315, 26);
			this->TbCompagnyLogo->TabIndex = 19;
			// 
			// LbCompagnyLogo
			// 
			this->LbCompagnyLogo->AutoSize = true;
			this->LbCompagnyLogo->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbCompagnyLogo->Location = System::Drawing::Point(12, 550);
			this->LbCompagnyLogo->Name = L"LbCompagnyLogo";
			this->LbCompagnyLogo->Size = System::Drawing::Size(228, 19);
			this->LbCompagnyLogo->TabIndex = 18;
			this->LbCompagnyLogo->Text = L"Date de r�approvisionnement";
			// 
			// AddClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(395, 715);
			this->Controls->Add(this->TbCompagnyLogo);
			this->Controls->Add(this->LbCompagnyLogo);
			this->Controls->Add(this->CboxCompagny);
			this->Controls->Add(this->LbBirthday);
			this->Controls->Add(this->TbBirthday);
			this->Controls->Add(this->BtnCancel);
			this->Controls->Add(this->BtnAddClient);
			this->Controls->Add(this->TbCompagnyPhone);
			this->Controls->Add(this->TbQuantity);
			this->Controls->Add(this->TbPriceWithTaxes);
			this->Controls->Add(this->TbPriceWithoutTax);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->LbDeliveryAddress);
			this->Controls->Add(this->LbName);
			this->Controls->Add(this->LbbillingAddress);
			this->Controls->Add(this->LbCompagnyPhone);
			this->Controls->Add(this->LbSurname);
			this->Controls->Add(this->Title);
			this->Name = L"AddClient";
			this->Text = L"AddClient";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}