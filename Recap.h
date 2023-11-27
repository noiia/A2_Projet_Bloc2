#pragma once

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Recap
	/// </summary>
	public ref class Recap : public System::Windows::Forms::Form
	{
	public:
		Recap(void)
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
		~Recap()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LbIdOrder;
	private: System::Windows::Forms::Label^ LbIdUser;
	private: System::Windows::Forms::Label^ LbNbArticles;
	private: System::Windows::Forms::Label^ LbBuyDate;
	private: System::Windows::Forms::Label^ LbDeliveryDate;
	private: System::Windows::Forms::Label^ LbPrice;
	protected:





	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ LbBuyingDate;

	private: System::Windows::Forms::Label^ LbArticleCount;
	private: System::Windows::Forms::Label^ LBDeliveryDateValue;
	private: System::Windows::Forms::Label^ LbPriceValue;
	private: System::Windows::Forms::Label^ LbIterate;
	private: System::Windows::Forms::Button^ BtnClose;





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
			this->LbIdOrder = (gcnew System::Windows::Forms::Label());
			this->LbIdUser = (gcnew System::Windows::Forms::Label());
			this->LbNbArticles = (gcnew System::Windows::Forms::Label());
			this->LbBuyDate = (gcnew System::Windows::Forms::Label());
			this->LbDeliveryDate = (gcnew System::Windows::Forms::Label());
			this->LbPrice = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->LbBuyingDate = (gcnew System::Windows::Forms::Label());
			this->LbArticleCount = (gcnew System::Windows::Forms::Label());
			this->LBDeliveryDateValue = (gcnew System::Windows::Forms::Label());
			this->LbPriceValue = (gcnew System::Windows::Forms::Label());
			this->LbIterate = (gcnew System::Windows::Forms::Label());
			this->BtnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LbIdOrder
			// 
			this->LbIdOrder->AutoSize = true;
			this->LbIdOrder->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbIdOrder->Location = System::Drawing::Point(172, 83);
			this->LbIdOrder->Name = L"LbIdOrder";
			this->LbIdOrder->Size = System::Drawing::Size(46, 19);
			this->LbIdOrder->TabIndex = 0;
			this->LbIdOrder->Text = L"ID_C";
			// 
			// LbIdUser
			// 
			this->LbIdUser->AutoSize = true;
			this->LbIdUser->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbIdUser->Location = System::Drawing::Point(172, 121);
			this->LbIdUser->Name = L"LbIdUser";
			this->LbIdUser->Size = System::Drawing::Size(47, 19);
			this->LbIdUser->TabIndex = 1;
			this->LbIdUser->Text = L"ID_U";
			// 
			// LbNbArticles
			// 
			this->LbNbArticles->AutoSize = true;
			this->LbNbArticles->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbNbArticles->Location = System::Drawing::Point(47, 165);
			this->LbNbArticles->Name = L"LbNbArticles";
			this->LbNbArticles->Size = System::Drawing::Size(99, 19);
			this->LbNbArticles->TabIndex = 2;
			this->LbNbArticles->Text = L"Nb_Articles";
			// 
			// LbBuyDate
			// 
			this->LbBuyDate->AutoSize = true;
			this->LbBuyDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBuyDate->Location = System::Drawing::Point(47, 200);
			this->LbBuyDate->Name = L"LbBuyDate";
			this->LbBuyDate->Size = System::Drawing::Size(102, 19);
			this->LbBuyDate->TabIndex = 3;
			this->LbBuyDate->Text = L"Date d\'achat";
			// 
			// LbDeliveryDate
			// 
			this->LbDeliveryDate->AutoSize = true;
			this->LbDeliveryDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbDeliveryDate->Location = System::Drawing::Point(47, 263);
			this->LbDeliveryDate->Name = L"LbDeliveryDate";
			this->LbDeliveryDate->Size = System::Drawing::Size(133, 19);
			this->LbDeliveryDate->TabIndex = 4;
			this->LbDeliveryDate->Text = L"Date de livraison";
			// 
			// LbPrice
			// 
			this->LbPrice->AutoSize = true;
			this->LbPrice->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPrice->Location = System::Drawing::Point(47, 305);
			this->LbPrice->Name = L"LbPrice";
			this->LbPrice->Size = System::Drawing::Size(89, 19);
			this->LbPrice->TabIndex = 5;
			this->LbPrice->Text = L"Sous-total";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(47, 349);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(157, 19);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Nombre d\'itérations";
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(118, 24);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(163, 28);
			this->Title->TabIndex = 7;
			this->Title->Text = L"Récapitulatif";
			// 
			// LbBuyingDate
			// 
			this->LbBuyingDate->AutoSize = true;
			this->LbBuyingDate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBuyingDate->Location = System::Drawing::Point(275, 200);
			this->LbBuyingDate->Name = L"LbBuyingDate";
			this->LbBuyingDate->Size = System::Drawing::Size(50, 19);
			this->LbBuyingDate->TabIndex = 8;
			this->LbBuyingDate->Text = L"B_Da";
			// 
			// LbArticleCount
			// 
			this->LbArticleCount->AutoSize = true;
			this->LbArticleCount->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbArticleCount->Location = System::Drawing::Point(275, 165);
			this->LbArticleCount->Name = L"LbArticleCount";
			this->LbArticleCount->Size = System::Drawing::Size(54, 19);
			this->LbArticleCount->TabIndex = 9;
			this->LbArticleCount->Text = L"Nb_A";
			// 
			// LBDeliveryDateValue
			// 
			this->LBDeliveryDateValue->AutoSize = true;
			this->LBDeliveryDateValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBDeliveryDateValue->Location = System::Drawing::Point(275, 263);
			this->LBDeliveryDateValue->Name = L"LBDeliveryDateValue";
			this->LBDeliveryDateValue->Size = System::Drawing::Size(51, 19);
			this->LBDeliveryDateValue->TabIndex = 10;
			this->LBDeliveryDateValue->Text = L"D_Da";
			// 
			// LbPriceValue
			// 
			this->LbPriceValue->AutoSize = true;
			this->LbPriceValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceValue->Location = System::Drawing::Point(275, 305);
			this->LbPriceValue->Name = L"LbPriceValue";
			this->LbPriceValue->Size = System::Drawing::Size(18, 19);
			this->LbPriceValue->TabIndex = 11;
			this->LbPriceValue->Text = L"P";
			// 
			// LbIterate
			// 
			this->LbIterate->AutoSize = true;
			this->LbIterate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbIterate->Location = System::Drawing::Point(275, 349);
			this->LbIterate->Name = L"LbIterate";
			this->LbIterate->Size = System::Drawing::Size(13, 19);
			this->LbIterate->TabIndex = 12;
			this->LbIterate->Text = L"I";
			// 
			// BtnClose
			// 
			this->BtnClose->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnClose->Location = System::Drawing::Point(269, 406);
			this->BtnClose->Name = L"BtnClose";
			this->BtnClose->Size = System::Drawing::Size(92, 31);
			this->BtnClose->TabIndex = 13;
			this->BtnClose->Text = L"Fermer";
			this->BtnClose->UseVisualStyleBackColor = true;
			// 
			// Recap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(411, 461);
			this->Controls->Add(this->BtnClose);
			this->Controls->Add(this->LbIterate);
			this->Controls->Add(this->LbPriceValue);
			this->Controls->Add(this->LBDeliveryDateValue);
			this->Controls->Add(this->LbArticleCount);
			this->Controls->Add(this->LbBuyingDate);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->LbPrice);
			this->Controls->Add(this->LbDeliveryDate);
			this->Controls->Add(this->LbBuyDate);
			this->Controls->Add(this->LbNbArticles);
			this->Controls->Add(this->LbIdUser);
			this->Controls->Add(this->LbIdOrder);
			this->Name = L"Recap";
			this->Text = L"Recap";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
