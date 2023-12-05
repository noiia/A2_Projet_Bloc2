#pragma once
#include "Article.h"
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
	private: 
		 System::Windows::Forms::NumericUpDown^ NudPriceVAT;
		 System::Windows::Forms::NumericUpDown^ NudPriceWT;
		 System::Windows::Forms::NumericUpDown^ NudPriceATI;
		 System::Windows::Forms::DateTimePicker^ DtpTreshold;
		 System::Windows::Forms::NumericUpDown^ NudStock;
		 System::Windows::Forms::TextBox^ TboxIDReference;
		 System::Windows::Forms::Label^ LbIdArticle;
		 System::Windows::Forms::TextBox^ TboxKind;
		 System::Windows::Forms::Label^ LbKind;
		 System::Windows::Forms::NumericUpDown^ NudTresholdLimit;
		 System::Windows::Forms::Label^ LbTresholdLimit;
		 Article^ article;
		 bool addOrEdit;
	public:
		// addOrEdit == 0 : add
		// addOrEdit == 1 : edit
		AddArticle(Article^ article, bool addOrEdit)
		{
			this->article = article;
			this->addOrEdit = addOrEdit;
			InitializeComponent();
			this->NudPriceWT->ValueChanged += gcnew System::EventHandler(this, &AddArticle::UpdatePriceATI);
			this->NudPriceVAT->ValueChanged += gcnew System::EventHandler(this, &AddArticle::UpdatePriceATI);

			System::Diagnostics::Debug::WriteLine("add article " + this->addOrEdit);

			if (addOrEdit) {
				this->TboxIDReference->Text = article->getIdArticle();
				this->TboxName->Text = article->getName();
				this->TboxKind->Text = article->getKind();
				this->NudPriceWT->Value = Convert::ToDecimal(article->getPriceWT());
				this->NudPriceVAT->Value = Convert::ToDecimal(article->getVAT());
				this->NudPriceATI->Value = Convert::ToDecimal(article->getPriceATI());
				this->NudStock->Value = article->getStock();
				this->DtpTreshold->Value = Convert::ToDateTime(article->getRestockingDate());
				this->NudTresholdLimit->Value = article->getRestockingLimit();
			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~AddArticle() override
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ Title;
			 System::Windows::Forms::Label^ LbName;
			 System::Windows::Forms::Label^ LbTresholdDate;
			 System::Windows::Forms::Label^ LbQuantity;			
			 System::Windows::Forms::Label^ LbVAT;
			 System::Windows::Forms::Label^ LbPriceWithoutTax;
			 System::Windows::Forms::Label^ LbPriceWithTaxes;
			 System::Windows::Forms::TextBox^ TboxName;

			 System::Windows::Forms::Button^ BtnAddArticle;
			 System::Windows::Forms::Button^ BtnCancel;
			
			
			
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddArticle::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->LbName = (gcnew System::Windows::Forms::Label());
			this->LbTresholdDate = (gcnew System::Windows::Forms::Label());
			this->LbQuantity = (gcnew System::Windows::Forms::Label());
			this->LbVAT = (gcnew System::Windows::Forms::Label());
			this->LbPriceWithoutTax = (gcnew System::Windows::Forms::Label());
			this->LbPriceWithTaxes = (gcnew System::Windows::Forms::Label());
			this->TboxName = (gcnew System::Windows::Forms::TextBox());
			this->BtnAddArticle = (gcnew System::Windows::Forms::Button());
			this->BtnCancel = (gcnew System::Windows::Forms::Button());
			this->NudPriceVAT = (gcnew System::Windows::Forms::NumericUpDown());
			this->NudPriceWT = (gcnew System::Windows::Forms::NumericUpDown());
			this->NudPriceATI = (gcnew System::Windows::Forms::NumericUpDown());
			this->DtpTreshold = (gcnew System::Windows::Forms::DateTimePicker());
			this->NudStock = (gcnew System::Windows::Forms::NumericUpDown());
			this->TboxIDReference = (gcnew System::Windows::Forms::TextBox());
			this->LbIdArticle = (gcnew System::Windows::Forms::Label());
			this->TboxKind = (gcnew System::Windows::Forms::TextBox());
			this->LbKind = (gcnew System::Windows::Forms::Label());
			this->NudTresholdLimit = (gcnew System::Windows::Forms::NumericUpDown());
			this->LbTresholdLimit = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudPriceVAT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudPriceWT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudPriceATI))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudStock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudTresholdLimit))->BeginInit();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(19, 26);
			this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(299, 28);
			this->Title->TabIndex = 0;
			// 
			// LbName
			// 
			this->LbName->AutoSize = true;
			this->LbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbName->Location = System::Drawing::Point(20, 139);
			this->LbName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbName->Name = L"LbName";
			this->LbName->Size = System::Drawing::Size(44, 19);
			this->LbName->TabIndex = 1;
			this->LbName->Text = L"Nom";
			// 
			// LbTresholdDate
			// 
			this->LbTresholdDate->AutoSize = true;
			this->LbTresholdDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbTresholdDate->Location = System::Drawing::Point(24, 590);
			this->LbTresholdDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbTresholdDate->Name = L"LbTresholdDate";
			this->LbTresholdDate->Size = System::Drawing::Size(228, 19);
			this->LbTresholdDate->TabIndex = 2;
			this->LbTresholdDate->Text = L"Date de réapprovisionnement";
			// 
			// LbQuantity
			// 
			this->LbQuantity->AutoSize = true;
			this->LbQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbQuantity->Location = System::Drawing::Point(26, 510);
			this->LbQuantity->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbQuantity->Name = L"LbQuantity";
			this->LbQuantity->Size = System::Drawing::Size(75, 19);
			this->LbQuantity->TabIndex = 3;
			this->LbQuantity->Text = L"Quantité";
			// 
			// LbVAT
			// 
			this->LbVAT->AutoSize = true;
			this->LbVAT->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbVAT->Location = System::Drawing::Point(24, 356);
			this->LbVAT->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
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
			this->LbPriceWithoutTax->Location = System::Drawing::Point(22, 280);
			this->LbPriceWithoutTax->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
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
			this->LbPriceWithTaxes->Location = System::Drawing::Point(22, 430);
			this->LbPriceWithTaxes->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbPriceWithTaxes->Name = L"LbPriceWithTaxes";
			this->LbPriceWithTaxes->Size = System::Drawing::Size(68, 19);
			this->LbPriceWithTaxes->TabIndex = 6;
			this->LbPriceWithTaxes->Text = L"Prix TTC";
			// 
			// TboxName
			// 
			this->TboxName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TboxName->Location = System::Drawing::Point(24, 162);
			this->TboxName->Margin = System::Windows::Forms::Padding(4);
			this->TboxName->Name = L"TboxName";
			this->TboxName->Size = System::Drawing::Size(270, 26);
			this->TboxName->TabIndex = 2;
			// 
			// BtnAddArticle
			// 
			this->BtnAddArticle->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddArticle->Location = System::Drawing::Point(27, 758);
			this->BtnAddArticle->Margin = System::Windows::Forms::Padding(4);
			this->BtnAddArticle->Name = L"BtnAddArticle";
			this->BtnAddArticle->Size = System::Drawing::Size(120, 44);
			this->BtnAddArticle->TabIndex = 10;
			this->BtnAddArticle->UseVisualStyleBackColor = true;
			this->BtnAddArticle->Click += gcnew System::EventHandler(this, &AddArticle::BtnAddArticle_Click);
			// 
			// BtnCancel
			// 
			this->BtnCancel->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCancel->Location = System::Drawing::Point(198, 758);
			this->BtnCancel->Margin = System::Windows::Forms::Padding(4);
			this->BtnCancel->Name = L"BtnCancel";
			this->BtnCancel->Size = System::Drawing::Size(120, 44);
			this->BtnCancel->TabIndex = 11;
			this->BtnCancel->Text = L"Annuler";
			this->BtnCancel->UseVisualStyleBackColor = true;
			this->BtnCancel->Click += gcnew System::EventHandler(this, &AddArticle::BtnCancel_Click);
			// 
			// NudPriceVAT
			// 
			this->NudPriceVAT->DecimalPlaces = 2;
			this->NudPriceVAT->Font = (gcnew System::Drawing::Font(L"Orkney", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudPriceVAT->Location = System::Drawing::Point(28, 391);
			this->NudPriceVAT->Margin = System::Windows::Forms::Padding(4);
			this->NudPriceVAT->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->NudPriceVAT->Name = L"NudPriceVAT";
			this->NudPriceVAT->Size = System::Drawing::Size(272, 25);
			this->NudPriceVAT->TabIndex = 5;
			this->NudPriceVAT->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// NudPriceWT
			// 
			this->NudPriceWT->DecimalPlaces = 2;
			this->NudPriceWT->Font = (gcnew System::Drawing::Font(L"Orkney", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudPriceWT->Location = System::Drawing::Point(28, 312);
			this->NudPriceWT->Margin = System::Windows::Forms::Padding(4);
			this->NudPriceWT->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->NudPriceWT->Name = L"NudPriceWT";
			this->NudPriceWT->Size = System::Drawing::Size(272, 25);
			this->NudPriceWT->TabIndex = 4;
			this->NudPriceWT->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// NudPriceATI
			// 
			this->NudPriceATI->DecimalPlaces = 2;
			this->NudPriceATI->Font = (gcnew System::Drawing::Font(L"Orkney", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudPriceATI->Location = System::Drawing::Point(28, 467);
			this->NudPriceATI->Margin = System::Windows::Forms::Padding(4);
			this->NudPriceATI->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->NudPriceATI->Name = L"NudPriceATI";
			this->NudPriceATI->Size = System::Drawing::Size(272, 25);
			this->NudPriceATI->TabIndex = 6;
			this->NudPriceATI->ThousandsSeparator = true;
			// 
			// DtpTreshold
			// 
			this->DtpTreshold->Location = System::Drawing::Point(28, 627);
			this->DtpTreshold->Margin = System::Windows::Forms::Padding(4);
			this->DtpTreshold->Name = L"DtpTreshold";
			this->DtpTreshold->Size = System::Drawing::Size(298, 25);
			this->DtpTreshold->TabIndex = 8;
			this->DtpTreshold->Value = System::DateTime(2023, 11, 28);
			// 
			// NudStock
			// 
			this->NudStock->Font = (gcnew System::Drawing::Font(L"Orkney", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudStock->Location = System::Drawing::Point(28, 548);
			this->NudStock->Margin = System::Windows::Forms::Padding(4);
			this->NudStock->Name = L"NudStock";
			this->NudStock->Size = System::Drawing::Size(272, 25);
			this->NudStock->TabIndex = 7;
			this->NudStock->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// TboxIDReference
			// 
			this->TboxIDReference->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TboxIDReference->Location = System::Drawing::Point(22, 99);
			this->TboxIDReference->Margin = System::Windows::Forms::Padding(4);
			this->TboxIDReference->Name = L"TboxIDReference";
			this->TboxIDReference->Size = System::Drawing::Size(270, 26);
			this->TboxIDReference->TabIndex = 1;
			// 
			// LbIdArticle
			// 
			this->LbIdArticle->AutoSize = true;
			this->LbIdArticle->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbIdArticle->Location = System::Drawing::Point(22, 76);
			this->LbIdArticle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbIdArticle->Name = L"LbIdArticle";
			this->LbIdArticle->Size = System::Drawing::Size(160, 19);
			this->LbIdArticle->TabIndex = 22;
			this->LbIdArticle->Text = L"Référence catalogue";
			// 
			// TboxKind
			// 
			this->TboxKind->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TboxKind->Location = System::Drawing::Point(24, 235);
			this->TboxKind->Margin = System::Windows::Forms::Padding(4);
			this->TboxKind->Name = L"TboxKind";
			this->TboxKind->Size = System::Drawing::Size(270, 26);
			this->TboxKind->TabIndex = 3;
			// 
			// LbKind
			// 
			this->LbKind->AutoSize = true;
			this->LbKind->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbKind->Location = System::Drawing::Point(20, 212);
			this->LbKind->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbKind->Name = L"LbKind";
			this->LbKind->Size = System::Drawing::Size(45, 19);
			this->LbKind->TabIndex = 23;
			this->LbKind->Text = L"Type";
			// 
			// NudTresholdLimit
			// 
			this->NudTresholdLimit->Font = (gcnew System::Drawing::Font(L"Orkney", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudTresholdLimit->Location = System::Drawing::Point(28, 703);
			this->NudTresholdLimit->Margin = System::Windows::Forms::Padding(4);
			this->NudTresholdLimit->Name = L"NudTresholdLimit";
			this->NudTresholdLimit->Size = System::Drawing::Size(272, 25);
			this->NudTresholdLimit->TabIndex = 9;
			this->NudTresholdLimit->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// LbTresholdLimit
			// 
			this->LbTresholdLimit->AutoSize = true;
			this->LbTresholdLimit->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbTresholdLimit->Location = System::Drawing::Point(26, 671);
			this->LbTresholdLimit->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbTresholdLimit->Name = L"LbTresholdLimit";
			this->LbTresholdLimit->Size = System::Drawing::Size(245, 19);
			this->LbTresholdLimit->TabIndex = 25;
			this->LbTresholdLimit->Text = L"Limite avant approvisionnement";
			//
			// paramètre si modification de profil existant
			//
			System::Diagnostics::Debug::WriteLine("before if else " + this->addOrEdit);
			System::Diagnostics::Debug::WriteLine("before if else " + addOrEdit);
			if (this->addOrEdit) {
				System::Diagnostics::Debug::WriteLine(this->addOrEdit);
				this->Title->Text = L"Modifier l'article";
				this->TboxIDReference->ReadOnly = true;
				this->BtnAddArticle->Text = L"Valider";
				this->BtnAddArticle->Location = System::Drawing::Point(112, 758);
				this->BtnCancel->Visible = false; 
			}
			else {
				this->Title->Text = L"Ajouter un nouvel article";
				this->TboxIDReference->ReadOnly = false;
				this->BtnAddArticle->Text = L"Ajouter";
			}
			// 
			// AddArticle
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->ControlBox = false;
			this->ClientSize = System::Drawing::Size(354, 828);
			this->Controls->Add(this->NudTresholdLimit);
			this->Controls->Add(this->LbTresholdLimit);
			this->Controls->Add(this->TboxKind);
			this->Controls->Add(this->LbKind);
			this->Controls->Add(this->LbIdArticle);
			this->Controls->Add(this->TboxIDReference);
			this->Controls->Add(this->NudStock);
			this->Controls->Add(this->DtpTreshold);
			this->Controls->Add(this->NudPriceATI);
			this->Controls->Add(this->NudPriceWT);
			this->Controls->Add(this->NudPriceVAT);
			this->Controls->Add(this->BtnCancel);
			this->Controls->Add(this->BtnAddArticle);
			this->Controls->Add(this->TboxName);
			this->Controls->Add(this->LbPriceWithTaxes);
			this->Controls->Add(this->LbPriceWithoutTax);
			this->Controls->Add(this->LbVAT);
			this->Controls->Add(this->LbQuantity);
			this->Controls->Add(this->LbTresholdDate);
			this->Controls->Add(this->LbName);
			this->Controls->Add(this->Title);
			this->Font = (gcnew System::Drawing::Font(L"Orkney", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AddArticle";
			this->Text = L"AddArticle";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudPriceVAT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudPriceWT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudPriceATI))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudStock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudTresholdLimit))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CbbVAT_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	//this->Dispose();
}
private: System::Void BtnAddArticle_Click(System::Object^ sender, System::EventArgs^ e) {
	// la ligne suivante permet de paramétrer le type de convention d'écriture des nombre à virgule avec un point à la place de la virgule
	System::Threading::Thread::CurrentThread->CurrentCulture = System::Globalization::CultureInfo::InvariantCulture;

	this->article->setIdArticle(this->TboxIDReference->Text);
	this->article->setName(this->TboxName->Text);
	this->article->setKind(this->TboxKind->Text);
	this->article->setPriceWT((Decimal^)this->NudPriceWT->Value);
	this->article->setVAT((int)this->NudPriceVAT->Value);
	this->article->setPriceATI(this->NudPriceATI->Value);
	this->article->setStock((long long)this->NudStock->Value);
	String^ dateString = this->DtpTreshold->Value.ToString("yyyy-MM-dd");
	DateTime restockingDate = DateTime::ParseExact(dateString, "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
	this->article->setRestockingDate(restockingDate);
	this->article->setRestockingLimit((long long)this->NudTresholdLimit->Value);
	this->Close();
}
	private: System::Void UpdatePriceATI(System::Object^ sender, System::EventArgs^ e) {
		Decimal priceWT = this->NudPriceWT->Value;
		Decimal priceVAT = this->NudPriceVAT->Value;
		Decimal priceATI = priceWT * (1 + (priceVAT / 100));
		this->NudPriceATI->Value = priceATI;
	}
};
}