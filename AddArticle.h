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
			this->SuspendLayout();
			// 
			// AddArticle
			// 
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"AddArticle";
			this->Load += gcnew System::EventHandler(this, &AddArticle::AddArticle_Load);
			this->ResumeLayout(false);

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
private: System::Void AddArticle_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}