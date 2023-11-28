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
	/// Description r�sum�e de AddArticle
	/// </summary>
	public ref class AddArticle : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		AddArticle(BDD^ mabdd)
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
		~AddArticle()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ LbTresholdDate;

	private: System::Windows::Forms::Label^ LbQuantity;

	private: System::Windows::Forms::Label^ LbVAT;
	private: System::Windows::Forms::Label^ LbPriceWithoutTax;
	private: System::Windows::Forms::Label^ LbPriceWithTaxes;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ TbPriceWithoutTax;
	private: System::Windows::Forms::TextBox^ TbPriceWithTaxes;
	private: System::Windows::Forms::TextBox^ TbQuantity;
	private: System::Windows::Forms::TextBox^ TbTresholdDate;




	private: System::Windows::Forms::ComboBox^ CbbVAT;
	private: System::Windows::Forms::Button^ BtnAddArticle;
	private: System::Windows::Forms::Button^ BtnCancel;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LbTresholdDate = (gcnew System::Windows::Forms::Label());
			this->LbQuantity = (gcnew System::Windows::Forms::Label());
			this->LbVAT = (gcnew System::Windows::Forms::Label());
			this->LbPriceWithoutTax = (gcnew System::Windows::Forms::Label());
			this->LbPriceWithTaxes = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->TbPriceWithoutTax = (gcnew System::Windows::Forms::TextBox());
			this->TbPriceWithTaxes = (gcnew System::Windows::Forms::TextBox());
			this->TbQuantity = (gcnew System::Windows::Forms::TextBox());
			this->TbTresholdDate = (gcnew System::Windows::Forms::TextBox());
			this->CbbVAT = (gcnew System::Windows::Forms::ComboBox());
			this->BtnAddArticle = (gcnew System::Windows::Forms::Button());
			this->BtnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(32, 19);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(299, 28);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Ajouter un nouvel article";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 19);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nom";
			// 
			// LbTresholdDate
			// 
			this->LbTresholdDate->AutoSize = true;
			this->LbTresholdDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbTresholdDate->Location = System::Drawing::Point(12, 432);
			this->LbTresholdDate->Name = L"LbTresholdDate";
			this->LbTresholdDate->Size = System::Drawing::Size(228, 19);
			this->LbTresholdDate->TabIndex = 2;
			this->LbTresholdDate->Text = L"Date de r�approvisionnement";
			// 
			// LbQuantity
			// 
			this->LbQuantity->AutoSize = true;
			this->LbQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbQuantity->Location = System::Drawing::Point(12, 359);
			this->LbQuantity->Name = L"LbQuantity";
			this->LbQuantity->Size = System::Drawing::Size(75, 19);
			this->LbQuantity->TabIndex = 3;
			this->LbQuantity->Text = L"Quantit�";
			// 
			// LbVAT
			// 
			this->LbVAT->AutoSize = true;
			this->LbVAT->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbVAT->Location = System::Drawing::Point(12, 215);
			this->LbVAT->Name = L"LbVAT";
			this->LbVAT->Size = System::Drawing::Size(39, 19);
			this->LbVAT->TabIndex = 4;
			this->LbVAT->Text = L"TVA";
			// 
			// LbPriceWithoutTax
			// 
			this->LbPriceWithoutTax->AutoSize = true;
			this->LbPriceWithoutTax->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceWithoutTax->Location = System::Drawing::Point(12, 141);
			this->LbPriceWithoutTax->Name = L"LbPriceWithoutTax";
			this->LbPriceWithoutTax->Size = System::Drawing::Size(61, 19);
			this->LbPriceWithoutTax->TabIndex = 5;
			this->LbPriceWithoutTax->Text = L"Prix HT";
			// 
			// LbPriceWithTaxes
			// 
			this->LbPriceWithTaxes->AutoSize = true;
			this->LbPriceWithTaxes->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceWithTaxes->Location = System::Drawing::Point(12, 295);
			this->LbPriceWithTaxes->Name = L"LbPriceWithTaxes";
			this->LbPriceWithTaxes->Size = System::Drawing::Size(68, 19);
			this->LbPriceWithTaxes->TabIndex = 6;
			this->LbPriceWithTaxes->Text = L"Prix TTC";
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
			// TbTresholdDate
			// 
			this->TbTresholdDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbTresholdDate->Location = System::Drawing::Point(16, 454);
			this->TbTresholdDate->Name = L"TbTresholdDate";
			this->TbTresholdDate->Size = System::Drawing::Size(315, 26);
			this->TbTresholdDate->TabIndex = 11;
			// 
			// CbbVAT
			// 
			this->CbbVAT->FormattingEnabled = true;
			this->CbbVAT->Location = System::Drawing::Point(16, 237);
			this->CbbVAT->Name = L"CbbVAT";
			this->CbbVAT->Size = System::Drawing::Size(316, 21);
			this->CbbVAT->TabIndex = 12;
			this->CbbVAT->SelectedIndexChanged += gcnew System::EventHandler(this, &AddArticle::CbbVAT_SelectedIndexChanged);
			// 
			// BtnAddArticle
			// 
			this->BtnAddArticle->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddArticle->Location = System::Drawing::Point(52, 520);
			this->BtnAddArticle->Name = L"BtnAddArticle";
			this->BtnAddArticle->Size = System::Drawing::Size(111, 42);
			this->BtnAddArticle->TabIndex = 13;
			this->BtnAddArticle->Text = L"Ajouter";
			this->BtnAddArticle->UseVisualStyleBackColor = true;
			// 
			// BtnCancel
			// 
			this->BtnCancel->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCancel->Location = System::Drawing::Point(232, 520);
			this->BtnCancel->Name = L"BtnCancel";
			this->BtnCancel->Size = System::Drawing::Size(111, 42);
			this->BtnCancel->TabIndex = 14;
			this->BtnCancel->Text = L"Annuler";
			this->BtnCancel->UseVisualStyleBackColor = true;
			this->BtnCancel->Click += gcnew System::EventHandler(this, &AddArticle::BtnCancel_Click);
			// 
			// AddArticle
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(377, 585);
			this->Controls->Add(this->BtnCancel);
			this->Controls->Add(this->BtnAddArticle);
			this->Controls->Add(this->CbbVAT);
			this->Controls->Add(this->TbTresholdDate);
			this->Controls->Add(this->TbQuantity);
			this->Controls->Add(this->TbPriceWithTaxes);
			this->Controls->Add(this->TbPriceWithoutTax);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->LbPriceWithTaxes);
			this->Controls->Add(this->LbPriceWithoutTax);
			this->Controls->Add(this->LbVAT);
			this->Controls->Add(this->LbQuantity);
			this->Controls->Add(this->LbTresholdDate);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Title);
			this->Name = L"AddArticle";
			this->Text = L"AddArticle";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CbbVAT_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}