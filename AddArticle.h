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
		 System::Windows::Forms::NumericUpDown^ NudPriceVAT;
		 System::Windows::Forms::NumericUpDown^ NudPriceWT;
		 System::Windows::Forms::NumericUpDown^ NudPriceATI;
		 System::Windows::Forms::DateTimePicker^ DtpTreshold;
		 System::Windows::Forms::NumericUpDown^ NudStock;
		 System::Windows::Forms::TextBox^ TboxIDReference;
		 System::Windows::Forms::Label^ LbIdArticle;
	private: System::Windows::Forms::TextBox^ TboxKind;
	private: System::Windows::Forms::Label^ LbKind;
	private: System::Windows::Forms::NumericUpDown^ NudTresholdLimit;
	private: System::Windows::Forms::Label^ LbTresholdLimit;

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
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Name = L"AddArticle";
			this->Load += gcnew System::EventHandler(this, &AddArticle::AddArticle_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CbbVAT_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
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
	this->article->setRestockingDate(this->DtpTreshold->Value.ToString("yyyy-MM-dd"));
	this->article->setRestockingLimit((long long)this->NudTresholdLimit->Value);
	this->Close();
}
	private: System::Void AddArticle_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}