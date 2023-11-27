#pragma once
#include "BDD.h"
#include "FastCatalog.h"
#include "FastClientCatalog.h"
#include "CartReminder.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Order
	/// </summary>

	public ref class Order : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		Order(BDD^ mabdd)
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
		~Order()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Button^ BtnCatalogForm;
	private: System::Windows::Forms::Label^ TxtArticleReference;
	private: System::Windows::Forms::TextBox^ TbOrder;
	private: System::Windows::Forms::TextBox^ TbBilling;
	private: System::Windows::Forms::TextBox^ TbDelivery;
	private: System::Windows::Forms::Label^ LbOrder;
	private: System::Windows::Forms::Label^ LbDeliveryAddress;
	private: System::Windows::Forms::Label^ LbBillingAddress;
	private: System::Windows::Forms::Label^ LbPriceTaxesFree;
	private: System::Windows::Forms::Label^ LbVAT;
	private: System::Windows::Forms::Label^ LbPriceWithTaxes;
	private: System::Windows::Forms::DomainUpDown^ DudQuantity;
	private: System::Windows::Forms::Button^ BtnValidate;
	private: System::Windows::Forms::Label^ LbQuantity;
	private: System::Windows::Forms::Label^ LbPriceValue;
	private: System::Windows::Forms::Label^ LbVatValue;
	private: System::Windows::Forms::Label^ LbPriceWithTaxesValue;
	private: System::Windows::Forms::Button^ BtnFastClientCatalog;

	private: System::Windows::Forms::Label^ LbIdUserValue;
	private: System::Windows::Forms::Label^ LbNameValue;
	private: System::Windows::Forms::Label^ LbSurnameValue;
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
			this->BtnCatalogForm = (gcnew System::Windows::Forms::Button());
			this->TxtArticleReference = (gcnew System::Windows::Forms::Label());
			this->TbOrder = (gcnew System::Windows::Forms::TextBox());
			this->TbBilling = (gcnew System::Windows::Forms::TextBox());
			this->TbDelivery = (gcnew System::Windows::Forms::TextBox());
			this->LbOrder = (gcnew System::Windows::Forms::Label());
			this->LbDeliveryAddress = (gcnew System::Windows::Forms::Label());
			this->LbBillingAddress = (gcnew System::Windows::Forms::Label());
			this->LbPriceTaxesFree = (gcnew System::Windows::Forms::Label());
			this->LbVAT = (gcnew System::Windows::Forms::Label());
			this->LbPriceWithTaxes = (gcnew System::Windows::Forms::Label());
			this->DudQuantity = (gcnew System::Windows::Forms::DomainUpDown());
			this->BtnValidate = (gcnew System::Windows::Forms::Button());
			this->LbQuantity = (gcnew System::Windows::Forms::Label());
			this->LbPriceValue = (gcnew System::Windows::Forms::Label());
			this->LbVatValue = (gcnew System::Windows::Forms::Label());
			this->LbPriceWithTaxesValue = (gcnew System::Windows::Forms::Label());
			this->BtnFastClientCatalog = (gcnew System::Windows::Forms::Button());
			this->LbIdUserValue = (gcnew System::Windows::Forms::Label());
			this->LbNameValue = (gcnew System::Windows::Forms::Label());
			this->LbSurnameValue = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(79, 19);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(312, 28);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Formulaire de commande";
			// 
			// BtnCatalogForm
			// 
			this->BtnCatalogForm->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCatalogForm->Location = System::Drawing::Point(354, 68);
			this->BtnCatalogForm->Name = L"BtnCatalogForm";
			this->BtnCatalogForm->Size = System::Drawing::Size(104, 32);
			this->BtnCatalogForm->TabIndex = 1;
			this->BtnCatalogForm->Text = L"Catalogue";
			this->BtnCatalogForm->UseVisualStyleBackColor = true;
			this->BtnCatalogForm->Click += gcnew System::EventHandler(this, &Order::BtnCatalogForm_Click);
			// 
			// TxtArticleReference
			// 
			this->TxtArticleReference->AutoSize = true;
			this->TxtArticleReference->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtArticleReference->Location = System::Drawing::Point(99, 86);
			this->TxtArticleReference->Name = L"TxtArticleReference";
			this->TxtArticleReference->Size = System::Drawing::Size(0, 19);
			this->TxtArticleReference->TabIndex = 2;
			// 
			// TbOrder
			// 
			this->TbOrder->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbOrder->Location = System::Drawing::Point(217, 118);
			this->TbOrder->Name = L"TbOrder";
			this->TbOrder->Size = System::Drawing::Size(192, 26);
			this->TbOrder->TabIndex = 3;
			// 
			// TbBilling
			// 
			this->TbBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbBilling->Location = System::Drawing::Point(217, 301);
			this->TbBilling->Name = L"TbBilling";
			this->TbBilling->Size = System::Drawing::Size(192, 26);
			this->TbBilling->TabIndex = 4;
			// 
			// TbDelivery
			// 
			this->TbDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbDelivery->Location = System::Drawing::Point(217, 269);
			this->TbDelivery->Name = L"TbDelivery";
			this->TbDelivery->Size = System::Drawing::Size(192, 26);
			this->TbDelivery->TabIndex = 5;
			// 
			// LbOrder
			// 
			this->LbOrder->AutoSize = true;
			this->LbOrder->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbOrder->Location = System::Drawing::Point(24, 125);
			this->LbOrder->Name = L"LbOrder";
			this->LbOrder->Size = System::Drawing::Size(152, 19);
			this->LbOrder->TabIndex = 6;
			this->LbOrder->Text = L"Date de commande";
			// 
			// LbDeliveryAddress
			// 
			this->LbDeliveryAddress->AutoSize = true;
			this->LbDeliveryAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbDeliveryAddress->Location = System::Drawing::Point(24, 276);
			this->LbDeliveryAddress->Name = L"LbDeliveryAddress";
			this->LbDeliveryAddress->Size = System::Drawing::Size(160, 19);
			this->LbDeliveryAddress->TabIndex = 7;
			this->LbDeliveryAddress->Text = L"Adresse de livraison";
			// 
			// LbBillingAddress
			// 
			this->LbBillingAddress->AutoSize = true;
			this->LbBillingAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBillingAddress->Location = System::Drawing::Point(24, 304);
			this->LbBillingAddress->Name = L"LbBillingAddress";
			this->LbBillingAddress->Size = System::Drawing::Size(179, 19);
			this->LbBillingAddress->TabIndex = 8;
			this->LbBillingAddress->Text = L"Adresse de facturation";
			// 
			// LbPriceTaxesFree
			// 
			this->LbPriceTaxesFree->AutoSize = true;
			this->LbPriceTaxesFree->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceTaxesFree->Location = System::Drawing::Point(29, 397);
			this->LbPriceTaxesFree->Name = L"LbPriceTaxesFree";
			this->LbPriceTaxesFree->Size = System::Drawing::Size(61, 19);
			this->LbPriceTaxesFree->TabIndex = 9;
			this->LbPriceTaxesFree->Text = L"Prix HT";
			// 
			// LbVAT
			// 
			this->LbVAT->AutoSize = true;
			this->LbVAT->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbVAT->Location = System::Drawing::Point(29, 433);
			this->LbVAT->Name = L"LbVAT";
			this->LbVAT->Size = System::Drawing::Size(92, 19);
			this->LbVAT->TabIndex = 10;
			this->LbVAT->Text = L"Valeur TVA";
			// 
			// LbPriceWithTaxes
			// 
			this->LbPriceWithTaxes->AutoSize = true;
			this->LbPriceWithTaxes->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceWithTaxes->Location = System::Drawing::Point(29, 470);
			this->LbPriceWithTaxes->Name = L"LbPriceWithTaxes";
			this->LbPriceWithTaxes->Size = System::Drawing::Size(68, 19);
			this->LbPriceWithTaxes->TabIndex = 11;
			this->LbPriceWithTaxes->Text = L"Prix TTC";
			// 
			// DudQuantity
			// 
			this->DudQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DudQuantity->Location = System::Drawing::Point(217, 342);
			this->DudQuantity->Name = L"DudQuantity";
			this->DudQuantity->Size = System::Drawing::Size(192, 26);
			this->DudQuantity->TabIndex = 12;
			// 
			// BtnValidate
			// 
			this->BtnValidate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnValidate->Location = System::Drawing::Point(326, 527);
			this->BtnValidate->Name = L"BtnValidate";
			this->BtnValidate->Size = System::Drawing::Size(104, 32);
			this->BtnValidate->TabIndex = 13;
			this->BtnValidate->Text = L"Valider";
			this->BtnValidate->UseVisualStyleBackColor = true;
			this->BtnValidate->Click += gcnew System::EventHandler(this, &Order::BtnValidate_Click);
			// 
			// LbQuantity
			// 
			this->LbQuantity->AutoSize = true;
			this->LbQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbQuantity->Location = System::Drawing::Point(24, 349);
			this->LbQuantity->Name = L"LbQuantity";
			this->LbQuantity->Size = System::Drawing::Size(75, 19);
			this->LbQuantity->TabIndex = 14;
			this->LbQuantity->Text = L"Quantité";
			// 
			// LbPriceValue
			// 
			this->LbPriceValue->AutoSize = true;
			this->LbPriceValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceValue->Location = System::Drawing::Point(284, 397);
			this->LbPriceValue->Name = L"LbPriceValue";
			this->LbPriceValue->Size = System::Drawing::Size(47, 19);
			this->LbPriceValue->TabIndex = 15;
			this->LbPriceValue->Text = L"P_Ht";
			// 
			// LbVatValue
			// 
			this->LbVatValue->AutoSize = true;
			this->LbVatValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbVatValue->Location = System::Drawing::Point(284, 433);
			this->LbVatValue->Name = L"LbVatValue";
			this->LbVatValue->Size = System::Drawing::Size(57, 19);
			this->LbVatValue->TabIndex = 16;
			this->LbVatValue->Text = L"P_VAT";
			// 
			// LbPriceWithTaxesValue
			// 
			this->LbPriceWithTaxesValue->AutoSize = true;
			this->LbPriceWithTaxesValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceWithTaxesValue->Location = System::Drawing::Point(284, 470);
			this->LbPriceWithTaxesValue->Name = L"LbPriceWithTaxesValue";
			this->LbPriceWithTaxesValue->Size = System::Drawing::Size(57, 19);
			this->LbPriceWithTaxesValue->TabIndex = 17;
			this->LbPriceWithTaxesValue->Text = L"P_TTC";
			// 
			// BtnFastClientCatalog
			// 
			this->BtnFastClientCatalog->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnFastClientCatalog->Location = System::Drawing::Point(305, 182);
			this->BtnFastClientCatalog->Name = L"BtnFastClientCatalog";
			this->BtnFastClientCatalog->Size = System::Drawing::Size(104, 49);
			this->BtnFastClientCatalog->TabIndex = 18;
			this->BtnFastClientCatalog->Text = L"Recherche client";
			this->BtnFastClientCatalog->UseVisualStyleBackColor = true;
			this->BtnFastClientCatalog->Click += gcnew System::EventHandler(this, &Order::BtnFastClientCatalog_Click);
			// 
			// LbIdUserValue
			// 
			this->LbIdUserValue->AutoSize = true;
			this->LbIdUserValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbIdUserValue->Location = System::Drawing::Point(56, 234);
			this->LbIdUserValue->Name = L"LbIdUserValue";
			this->LbIdUserValue->Size = System::Drawing::Size(114, 19);
			this->LbIdUserValue->TabIndex = 21;
			this->LbIdUserValue->Text = L"ID_Utilisateur";
			// 
			// LbNameValue
			// 
			this->LbNameValue->AutoSize = true;
			this->LbNameValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbNameValue->Location = System::Drawing::Point(56, 197);
			this->LbNameValue->Name = L"LbNameValue";
			this->LbNameValue->Size = System::Drawing::Size(65, 19);
			this->LbNameValue->TabIndex = 20;
			this->LbNameValue->Text = L"Prénom";
			// 
			// LbSurnameValue
			// 
			this->LbSurnameValue->AutoSize = true;
			this->LbSurnameValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSurnameValue->Location = System::Drawing::Point(56, 161);
			this->LbSurnameValue->Name = L"LbSurnameValue";
			this->LbSurnameValue->Size = System::Drawing::Size(44, 19);
			this->LbSurnameValue->TabIndex = 19;
			this->LbSurnameValue->Text = L"Nom";
			// 
			// Order
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 613);
			this->Controls->Add(this->LbIdUserValue);
			this->Controls->Add(this->LbNameValue);
			this->Controls->Add(this->LbSurnameValue);
			this->Controls->Add(this->BtnFastClientCatalog);
			this->Controls->Add(this->LbPriceWithTaxesValue);
			this->Controls->Add(this->LbVatValue);
			this->Controls->Add(this->LbPriceValue);
			this->Controls->Add(this->LbQuantity);
			this->Controls->Add(this->BtnValidate);
			this->Controls->Add(this->DudQuantity);
			this->Controls->Add(this->LbPriceWithTaxes);
			this->Controls->Add(this->LbVAT);
			this->Controls->Add(this->LbPriceTaxesFree);
			this->Controls->Add(this->LbBillingAddress);
			this->Controls->Add(this->LbDeliveryAddress);
			this->Controls->Add(this->LbOrder);
			this->Controls->Add(this->TbDelivery);
			this->Controls->Add(this->TbBilling);
			this->Controls->Add(this->TbOrder);
			this->Controls->Add(this->TxtArticleReference);
			this->Controls->Add(this->BtnCatalogForm);
			this->Controls->Add(this->Title);
			this->Name = L"Order";
			this->Text = L"Order";
			this->Load += gcnew System::EventHandler(this, &Order::Order_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Order_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BtnCatalogForm_Click(System::Object^ sender, System::EventArgs^ e) {
		
		fastCatalog^ fastCatalogForm = gcnew fastCatalog(mabdd);
		fastCatalogForm->ShowDialog();
	}

	private: System::Void BtnFastClientCatalog_Click(System::Object^ sender, System::EventArgs^ e) {
		fastClientCatalog^ fastClientCatalogForm = gcnew fastClientCatalog(mabdd);
		fastClientCatalogForm->ShowDialog();
	}
private: System::Void BtnValidate_Click(System::Object^ sender, System::EventArgs^ e) {
	cartReminder^ cartReminderForm = gcnew cartReminder(mabdd);
	cartReminderForm->ShowDialog();
	this->Close();
}
};
}
