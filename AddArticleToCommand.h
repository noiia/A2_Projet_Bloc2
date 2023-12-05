#pragma once

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de AddArticleToCommand
	/// </summary>
	public ref class AddArticleToCommand : public System::Windows::Forms::Form
	{
	public:
		AddArticleToCommand(void)
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
		~AddArticleToCommand()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnAddCommand;
	private: System::Windows::Forms::TextBox^ TboxQuantity;
	protected:

	private: System::Windows::Forms::TextBox^ TboxReferences;


	private: System::Windows::Forms::Label^ LbQuantity;
	private: System::Windows::Forms::Label^ LbReferences;
	private: System::Windows::Forms::TextBox^ TboxArticleName;



	private: System::Windows::Forms::Label^ LbArticleName;




	private: System::Windows::Forms::Label^ LbPriceTxt;


	private: System::Windows::Forms::Label^ LbPriceValue;

	private: System::Windows::Forms::Button^ BtnResearchArticle;
	private: System::Windows::Forms::DataGridView^ DGV;


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
			this->BtnAddCommand = (gcnew System::Windows::Forms::Button());
			this->TboxQuantity = (gcnew System::Windows::Forms::TextBox());
			this->TboxReferences = (gcnew System::Windows::Forms::TextBox());
			this->LbQuantity = (gcnew System::Windows::Forms::Label());
			this->LbReferences = (gcnew System::Windows::Forms::Label());
			this->TboxArticleName = (gcnew System::Windows::Forms::TextBox());
			this->LbArticleName = (gcnew System::Windows::Forms::Label());
			this->LbPriceTxt = (gcnew System::Windows::Forms::Label());
			this->LbPriceValue = (gcnew System::Windows::Forms::Label());
			this->BtnResearchArticle = (gcnew System::Windows::Forms::Button());
			this->DGV = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGV))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnAddCommand
			// 
			this->BtnAddCommand->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddCommand->Location = System::Drawing::Point(790, 496);
			this->BtnAddCommand->Name = L"BtnAddCommand";
			this->BtnAddCommand->Size = System::Drawing::Size(111, 42);
			this->BtnAddCommand->TabIndex = 22;
			this->BtnAddCommand->Text = L"Ajouter";
			this->BtnAddCommand->UseVisualStyleBackColor = true;
			// 
			// TboxQuantity
			// 
			this->TboxQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TboxQuantity->Location = System::Drawing::Point(40, 382);
			this->TboxQuantity->Name = L"TboxQuantity";
			this->TboxQuantity->Size = System::Drawing::Size(315, 26);
			this->TboxQuantity->TabIndex = 21;
			// 
			// TboxReferences
			// 
			this->TboxReferences->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TboxReferences->Location = System::Drawing::Point(40, 47);
			this->TboxReferences->Name = L"TboxReferences";
			this->TboxReferences->Size = System::Drawing::Size(315, 26);
			this->TboxReferences->TabIndex = 18;
			// 
			// LbQuantity
			// 
			this->LbQuantity->AutoSize = true;
			this->LbQuantity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbQuantity->Location = System::Drawing::Point(36, 360);
			this->LbQuantity->Name = L"LbQuantity";
			this->LbQuantity->Size = System::Drawing::Size(75, 19);
			this->LbQuantity->TabIndex = 15;
			this->LbQuantity->Text = L"Quantité";
			// 
			// LbReferences
			// 
			this->LbReferences->AutoSize = true;
			this->LbReferences->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbReferences->Location = System::Drawing::Point(36, 25);
			this->LbReferences->Name = L"LbReferences";
			this->LbReferences->Size = System::Drawing::Size(82, 19);
			this->LbReferences->TabIndex = 14;
			this->LbReferences->Text = L"Référence";
			// 
			// TboxArticleName
			// 
			this->TboxArticleName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TboxArticleName->Location = System::Drawing::Point(40, 129);
			this->TboxArticleName->Name = L"TboxArticleName";
			this->TboxArticleName->Size = System::Drawing::Size(315, 26);
			this->TboxArticleName->TabIndex = 24;
			// 
			// LbArticleName
			// 
			this->LbArticleName->AutoSize = true;
			this->LbArticleName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbArticleName->Location = System::Drawing::Point(36, 107);
			this->LbArticleName->Name = L"LbArticleName";
			this->LbArticleName->Size = System::Drawing::Size(126, 19);
			this->LbArticleName->TabIndex = 23;
			this->LbArticleName->Text = L"Nom de l\'article";
			// 
			// LbPriceTxt
			// 
			this->LbPriceTxt->AutoSize = true;
			this->LbPriceTxt->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceTxt->Location = System::Drawing::Point(60, 455);
			this->LbPriceTxt->Name = L"LbPriceTxt";
			this->LbPriceTxt->Size = System::Drawing::Size(45, 19);
			this->LbPriceTxt->TabIndex = 27;
			this->LbPriceTxt->Text = L"Prix :";
			// 
			// LbPriceValue
			// 
			this->LbPriceValue->AutoSize = true;
			this->LbPriceValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceValue->Location = System::Drawing::Point(120, 455);
			this->LbPriceValue->Name = L"LbPriceValue";
			this->LbPriceValue->Size = System::Drawing::Size(20, 19);
			this->LbPriceValue->TabIndex = 28;
			this->LbPriceValue->Text = L"0";
			// 
			// BtnResearchArticle
			// 
			this->BtnResearchArticle->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnResearchArticle->Location = System::Drawing::Point(136, 189);
			this->BtnResearchArticle->Name = L"BtnResearchArticle";
			this->BtnResearchArticle->Size = System::Drawing::Size(111, 42);
			this->BtnResearchArticle->TabIndex = 29;
			this->BtnResearchArticle->Text = L"Rechercher";
			this->BtnResearchArticle->UseVisualStyleBackColor = true;
			// 
			// DGV
			// 
			this->DGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGV->Location = System::Drawing::Point(420, 25);
			this->DGV->Name = L"DGV";
			this->DGV->Size = System::Drawing::Size(506, 437);
			this->DGV->TabIndex = 30;
			// 
			// AddArticleToCommand
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(955, 571);
			this->Controls->Add(this->DGV);
			this->Controls->Add(this->BtnResearchArticle);
			this->Controls->Add(this->LbPriceValue);
			this->Controls->Add(this->LbPriceTxt);
			this->Controls->Add(this->TboxArticleName);
			this->Controls->Add(this->LbArticleName);
			this->Controls->Add(this->BtnAddCommand);
			this->Controls->Add(this->TboxQuantity);
			this->Controls->Add(this->TboxReferences);
			this->Controls->Add(this->LbQuantity);
			this->Controls->Add(this->LbReferences);
			this->Name = L"AddArticleToCommand";
			this->Text = L"AddArticleToCommand";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
