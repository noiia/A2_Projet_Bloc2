#pragma once

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:
	private: System::Windows::Forms::Button^ BtnCatalogForm;
	private: System::Windows::Forms::Label^ TxtArticleReference;
	private: System::Windows::Forms::TextBox^ TbOrder;
	private: System::Windows::Forms::TextBox^ TbBilling;


	private: System::Windows::Forms::TextBox^ TbDelivery;

	private: System::Windows::Forms::Label^ TxtOrder;
	private: System::Windows::Forms::Label^ TxtDeliveryAddress;
	private: System::Windows::Forms::Label^ TxtBillingAddress;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DomainUpDown^ DudQuantity;
	private: System::Windows::Forms::Button^ BtnValidate;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ TxtPriceValue;
	private: System::Windows::Forms::Label^ TxtVatValue;
	private: System::Windows::Forms::Label^ TxtAllTaxesIncludedValue;
	private: System::Windows::Forms::Button^ Btn;
	private: System::Windows::Forms::Label^ TxtIdUserValue;
	private: System::Windows::Forms::Label^ TxtNameValue;
	private: System::Windows::Forms::Label^ TxtSurnameValue;

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
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BtnCatalogForm = (gcnew System::Windows::Forms::Button());
			this->TxtArticleReference = (gcnew System::Windows::Forms::Label());
			this->TbOrder = (gcnew System::Windows::Forms::TextBox());
			this->TbBilling = (gcnew System::Windows::Forms::TextBox());
			this->TbDelivery = (gcnew System::Windows::Forms::TextBox());
			this->TxtOrder = (gcnew System::Windows::Forms::Label());
			this->TxtDeliveryAddress = (gcnew System::Windows::Forms::Label());
			this->TxtBillingAddress = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DudQuantity = (gcnew System::Windows::Forms::DomainUpDown());
			this->BtnValidate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TxtPriceValue = (gcnew System::Windows::Forms::Label());
			this->TxtVatValue = (gcnew System::Windows::Forms::Label());
			this->TxtAllTaxesIncludedValue = (gcnew System::Windows::Forms::Label());
			this->Btn = (gcnew System::Windows::Forms::Button());
			this->TxtIdUserValue = (gcnew System::Windows::Forms::Label());
			this->TxtNameValue = (gcnew System::Windows::Forms::Label());
			this->TxtSurnameValue = (gcnew System::Windows::Forms::Label());
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
			// TxtOrder
			// 
			this->TxtOrder->AutoSize = true;
			this->TxtOrder->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtOrder->Location = System::Drawing::Point(24, 125);
			this->TxtOrder->Name = L"TxtOrder";
			this->TxtOrder->Size = System::Drawing::Size(152, 19);
			this->TxtOrder->TabIndex = 6;
			this->TxtOrder->Text = L"Date de commande";
			// 
			// TxtDeliveryAddress
			// 
			this->TxtDeliveryAddress->AutoSize = true;
			this->TxtDeliveryAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtDeliveryAddress->Location = System::Drawing::Point(24, 276);
			this->TxtDeliveryAddress->Name = L"TxtDeliveryAddress";
			this->TxtDeliveryAddress->Size = System::Drawing::Size(160, 19);
			this->TxtDeliveryAddress->TabIndex = 7;
			this->TxtDeliveryAddress->Text = L"Adresse de livraison";
			// 
			// TxtBillingAddress
			// 
			this->TxtBillingAddress->AutoSize = true;
			this->TxtBillingAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtBillingAddress->Location = System::Drawing::Point(24, 304);
			this->TxtBillingAddress->Name = L"TxtBillingAddress";
			this->TxtBillingAddress->Size = System::Drawing::Size(179, 19);
			this->TxtBillingAddress->TabIndex = 8;
			this->TxtBillingAddress->Text = L"Adresse de facturation";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(29, 397);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 19);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Prix HT";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(29, 433);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 19);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Valeur TVA";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(29, 470);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 19);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Prix TTC";
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
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(24, 349);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 19);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Quantité";
			// 
			// TxtPriceValue
			// 
			this->TxtPriceValue->AutoSize = true;
			this->TxtPriceValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtPriceValue->Location = System::Drawing::Point(284, 397);
			this->TxtPriceValue->Name = L"TxtPriceValue";
			this->TxtPriceValue->Size = System::Drawing::Size(47, 19);
			this->TxtPriceValue->TabIndex = 15;
			this->TxtPriceValue->Text = L"P_Ht";
			// 
			// TxtVatValue
			// 
			this->TxtVatValue->AutoSize = true;
			this->TxtVatValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtVatValue->Location = System::Drawing::Point(284, 433);
			this->TxtVatValue->Name = L"TxtVatValue";
			this->TxtVatValue->Size = System::Drawing::Size(57, 19);
			this->TxtVatValue->TabIndex = 16;
			this->TxtVatValue->Text = L"P_VAT";
			// 
			// TxtAllTaxesIncludedValue
			// 
			this->TxtAllTaxesIncludedValue->AutoSize = true;
			this->TxtAllTaxesIncludedValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtAllTaxesIncludedValue->Location = System::Drawing::Point(284, 470);
			this->TxtAllTaxesIncludedValue->Name = L"TxtAllTaxesIncludedValue";
			this->TxtAllTaxesIncludedValue->Size = System::Drawing::Size(57, 19);
			this->TxtAllTaxesIncludedValue->TabIndex = 17;
			this->TxtAllTaxesIncludedValue->Text = L"P_TTC";
			// 
			// Btn
			// 
			this->Btn->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Btn->Location = System::Drawing::Point(305, 182);
			this->Btn->Name = L"Btn";
			this->Btn->Size = System::Drawing::Size(104, 49);
			this->Btn->TabIndex = 18;
			this->Btn->Text = L"Recherche client";
			this->Btn->UseVisualStyleBackColor = true;
			// 
			// TxtIdUserValue
			// 
			this->TxtIdUserValue->AutoSize = true;
			this->TxtIdUserValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtIdUserValue->Location = System::Drawing::Point(56, 234);
			this->TxtIdUserValue->Name = L"TxtIdUserValue";
			this->TxtIdUserValue->Size = System::Drawing::Size(114, 19);
			this->TxtIdUserValue->TabIndex = 21;
			this->TxtIdUserValue->Text = L"ID_Utilisateur";
			// 
			// TxtNameValue
			// 
			this->TxtNameValue->AutoSize = true;
			this->TxtNameValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtNameValue->Location = System::Drawing::Point(56, 197);
			this->TxtNameValue->Name = L"TxtNameValue";
			this->TxtNameValue->Size = System::Drawing::Size(65, 19);
			this->TxtNameValue->TabIndex = 20;
			this->TxtNameValue->Text = L"Prénom";
			// 
			// TxtSurnameValue
			// 
			this->TxtSurnameValue->AutoSize = true;
			this->TxtSurnameValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtSurnameValue->Location = System::Drawing::Point(56, 161);
			this->TxtSurnameValue->Name = L"TxtSurnameValue";
			this->TxtSurnameValue->Size = System::Drawing::Size(44, 19);
			this->TxtSurnameValue->TabIndex = 19;
			this->TxtSurnameValue->Text = L"Nom";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 613);
			this->Controls->Add(this->TxtIdUserValue);
			this->Controls->Add(this->TxtNameValue);
			this->Controls->Add(this->TxtSurnameValue);
			this->Controls->Add(this->Btn);
			this->Controls->Add(this->TxtAllTaxesIncludedValue);
			this->Controls->Add(this->TxtVatValue);
			this->Controls->Add(this->TxtPriceValue);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BtnValidate);
			this->Controls->Add(this->DudQuantity);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->TxtBillingAddress);
			this->Controls->Add(this->TxtDeliveryAddress);
			this->Controls->Add(this->TxtOrder);
			this->Controls->Add(this->TbDelivery);
			this->Controls->Add(this->TbBilling);
			this->Controls->Add(this->TbOrder);
			this->Controls->Add(this->TxtArticleReference);
			this->Controls->Add(this->BtnCatalogForm);
			this->Controls->Add(this->Title);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
