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
	/// Description résumée de fastCatalog
	/// </summary>
	public ref class FastCatalog : public System::Windows::Forms::Form
	{
	private:
		BDD^ mabdd;
	public:
		// Constructeur prenant BDD en paramètre
		FastCatalog(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FastCatalog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ TbReference;
	private: System::Windows::Forms::Label^ LbPrice;
	private: System::Windows::Forms::Label^ LbQuantity;
	private: System::Windows::Forms::Label^ LbRestock;
	protected:



	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ LbPriceValue;
	private: System::Windows::Forms::Label^ LbQuantityValue;
	private: System::Windows::Forms::Label^ LbDateRestockValue;
	private: System::Windows::Forms::Button^ BtnValidation;
	private: System::Windows::Forms::Label^ LbRef;

	protected:

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
			this->TbReference = (gcnew System::Windows::Forms::TextBox());
			this->LbPrice = (gcnew System::Windows::Forms::Label());
			this->LbQuantity = (gcnew System::Windows::Forms::Label());
			this->LbRestock = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->LbPriceValue = (gcnew System::Windows::Forms::Label());
			this->LbQuantityValue = (gcnew System::Windows::Forms::Label());
			this->LbDateRestockValue = (gcnew System::Windows::Forms::Label());
			this->BtnValidation = (gcnew System::Windows::Forms::Button());
			this->LbRef = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// TbReference
			// 
			this->TbReference->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbReference->Location = System::Drawing::Point(161, 92);
			this->TbReference->Name = L"TbReference";
			this->TbReference->Size = System::Drawing::Size(284, 29);
			this->TbReference->TabIndex = 0;
			this->TbReference->TextChanged += gcnew System::EventHandler(this, &FastCatalog::TbReference_TextChanged);
			// 
			// LbPrice
			// 
			this->LbPrice->AutoSize = true;
			this->LbPrice->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPrice->Location = System::Drawing::Point(47, 162);
			this->LbPrice->Name = L"LbPrice";
			this->LbPrice->Size = System::Drawing::Size(36, 19);
			this->LbPrice->TabIndex = 1;
			this->LbPrice->Text = L"Prix";
			// 
			// LbQuantity
			// 
			this->LbQuantity->AutoSize = true;
			this->LbQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbQuantity->Location = System::Drawing::Point(47, 210);
			this->LbQuantity->Name = L"LbQuantity";
			this->LbQuantity->Size = System::Drawing::Size(75, 19);
			this->LbQuantity->TabIndex = 2;
			this->LbQuantity->Text = L"Quantité";
			// 
			// LbRestock
			// 
			this->LbRestock->AutoSize = true;
			this->LbRestock->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbRestock->Location = System::Drawing::Point(47, 255);
			this->LbRestock->Name = L"LbRestock";
			this->LbRestock->Size = System::Drawing::Size(228, 19);
			this->LbRestock->TabIndex = 3;
			this->LbRestock->Text = L"Date de réapprovisionnement";
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(141, 33);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(216, 28);
			this->Title->TabIndex = 4;
			this->Title->Text = L"Catalogue rapide";
			// 
			// LbPriceValue
			// 
			this->LbPriceValue->AutoSize = true;
			this->LbPriceValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceValue->Location = System::Drawing::Point(383, 162);
			this->LbPriceValue->Name = L"LbPriceValue";
			this->LbPriceValue->Size = System::Drawing::Size(18, 19);
			this->LbPriceValue->TabIndex = 5;
			this->LbPriceValue->Text = L"P";
			// 
			// LbQuantityValue
			// 
			this->LbQuantityValue->AutoSize = true;
			this->LbQuantityValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbQuantityValue->Location = System::Drawing::Point(383, 210);
			this->LbQuantityValue->Name = L"LbQuantityValue";
			this->LbQuantityValue->Size = System::Drawing::Size(22, 19);
			this->LbQuantityValue->TabIndex = 6;
			this->LbQuantityValue->Text = L"Q";
			// 
			// LbDateRestockValue
			// 
			this->LbDateRestockValue->AutoSize = true;
			this->LbDateRestockValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbDateRestockValue->Location = System::Drawing::Point(383, 255);
			this->LbDateRestockValue->Name = L"LbDateRestockValue";
			this->LbDateRestockValue->Size = System::Drawing::Size(20, 19);
			this->LbDateRestockValue->TabIndex = 7;
			this->LbDateRestockValue->Text = L"D";
			// 
			// BtnValidation
			// 
			this->BtnValidation->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnValidation->Location = System::Drawing::Point(337, 305);
			this->BtnValidation->Name = L"BtnValidation";
			this->BtnValidation->Size = System::Drawing::Size(98, 35);
			this->BtnValidation->TabIndex = 8;
			this->BtnValidation->Text = L"Valider";
			this->BtnValidation->UseVisualStyleBackColor = true;
			// 
			// LbRef
			// 
			this->LbRef->AutoSize = true;
			this->LbRef->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbRef->Location = System::Drawing::Point(47, 98);
			this->LbRef->Name = L"LbRef";
			this->LbRef->Size = System::Drawing::Size(91, 19);
			this->LbRef->TabIndex = 9;
			this->LbRef->Text = L"Référence :";
			// 
			// fastCatalog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 366);
			this->Controls->Add(this->LbRef);
			this->Controls->Add(this->BtnValidation);
			this->Controls->Add(this->LbDateRestockValue);
			this->Controls->Add(this->LbQuantityValue);
			this->Controls->Add(this->LbPriceValue);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->LbRestock);
			this->Controls->Add(this->LbQuantity);
			this->Controls->Add(this->LbPrice);
			this->Controls->Add(this->TbReference);
			this->Name = L"fastCatalog";
			this->Text = L"fastCatalog";
			this->Load += gcnew System::EventHandler(this, &FastCatalog::fastCatalog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void fastCatalog_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	

private: System::Void TbReference_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
