#pragma once

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Payment
	/// </summary>
	public ref class Payment : public System::Windows::Forms::Form
	{
	public:
		Payment(void)
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
		~Payment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LBIdOrder;
	private: System::Windows::Forms::Label^ LbPriceValue;
	protected:

	protected:


	private: System::Windows::Forms::RadioButton^ RbtnBlueCard;
	private: System::Windows::Forms::RadioButton^ RbtnBankTransfer;
	private: System::Windows::Forms::RadioButton^ RbtnBankCheck;




	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::CheckBox^ CboxDividedPayment;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ BtnValidation;
	private: System::Windows::Forms::Button^ BtnReturn;



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
			this->LBIdOrder = (gcnew System::Windows::Forms::Label());
			this->LbPriceValue = (gcnew System::Windows::Forms::Label());
			this->RbtnBlueCard = (gcnew System::Windows::Forms::RadioButton());
			this->RbtnBankTransfer = (gcnew System::Windows::Forms::RadioButton());
			this->RbtnBankCheck = (gcnew System::Windows::Forms::RadioButton());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->CboxDividedPayment = (gcnew System::Windows::Forms::CheckBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->BtnValidation = (gcnew System::Windows::Forms::Button());
			this->BtnReturn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// LBIdOrder
			// 
			this->LBIdOrder->AutoSize = true;
			this->LBIdOrder->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LBIdOrder->Location = System::Drawing::Point(257, 78);
			this->LBIdOrder->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LBIdOrder->Name = L"LBIdOrder";
			this->LBIdOrder->Size = System::Drawing::Size(24, 19);
			this->LBIdOrder->TabIndex = 0;
			this->LBIdOrder->Text = L"ID";
			// 
			// LbPriceValue
			// 
			this->LbPriceValue->AutoSize = true;
			this->LbPriceValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPriceValue->Location = System::Drawing::Point(257, 119);
			this->LbPriceValue->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbPriceValue->Name = L"LbPriceValue";
			this->LbPriceValue->Size = System::Drawing::Size(18, 19);
			this->LbPriceValue->TabIndex = 1;
			this->LbPriceValue->Text = L"P";
			// 
			// RbtnBlueCard
			// 
			this->RbtnBlueCard->AutoSize = true;
			this->RbtnBlueCard->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RbtnBlueCard->Location = System::Drawing::Point(24, 178);
			this->RbtnBlueCard->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->RbtnBlueCard->Name = L"RbtnBlueCard";
			this->RbtnBlueCard->Size = System::Drawing::Size(106, 23);
			this->RbtnBlueCard->TabIndex = 3;
			this->RbtnBlueCard->TabStop = true;
			this->RbtnBlueCard->Text = L"Carte Bleu";
			this->RbtnBlueCard->UseVisualStyleBackColor = true;
			this->RbtnBlueCard->CheckedChanged += gcnew System::EventHandler(this, &Payment::RbtnBlueCard_CheckedChanged);
			// 
			// RbtnBankTransfer
			// 
			this->RbtnBankTransfer->AutoSize = true;
			this->RbtnBankTransfer->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RbtnBankTransfer->Location = System::Drawing::Point(180, 178);
			this->RbtnBankTransfer->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->RbtnBankTransfer->Name = L"RbtnBankTransfer";
			this->RbtnBankTransfer->Size = System::Drawing::Size(162, 23);
			this->RbtnBankTransfer->TabIndex = 4;
			this->RbtnBankTransfer->TabStop = true;
			this->RbtnBankTransfer->Text = L"Virement bancaire";
			this->RbtnBankTransfer->UseVisualStyleBackColor = true;
			this->RbtnBankTransfer->CheckedChanged += gcnew System::EventHandler(this, &Payment::RbtnBankTransfer_CheckedChanged);
			// 
			// RbtnBankCheck
			// 
			this->RbtnBankCheck->AutoSize = true;
			this->RbtnBankCheck->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RbtnBankCheck->Location = System::Drawing::Point(395, 178);
			this->RbtnBankCheck->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->RbtnBankCheck->Name = L"RbtnBankCheck";
			this->RbtnBankCheck->Size = System::Drawing::Size(85, 23);
			this->RbtnBankCheck->TabIndex = 5;
			this->RbtnBankCheck->TabStop = true;
			this->RbtnBankCheck->Text = L"Chèque";
			this->RbtnBankCheck->UseVisualStyleBackColor = true;
			this->RbtnBankCheck->CheckedChanged += gcnew System::EventHandler(this, &Payment::RbtnBankCheck_CheckedChanged);
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(156, 29);
			this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(232, 28);
			this->Title->TabIndex = 6;
			this->Title->Text = L"Mode de paiement";
			// 
			// CboxDividedPayment
			// 
			this->CboxDividedPayment->AutoSize = true;
			this->CboxDividedPayment->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CboxDividedPayment->Location = System::Drawing::Point(57, 224);
			this->CboxDividedPayment->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->CboxDividedPayment->Name = L"CboxDividedPayment";
			this->CboxDividedPayment->Size = System::Drawing::Size(215, 23);
			this->CboxDividedPayment->TabIndex = 7;
			this->CboxDividedPayment->Text = L"Paiement en 3x sans frais";
			this->CboxDividedPayment->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(57, 271);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(412, 295);
			this->dataGridView1->TabIndex = 8;
			// 
			// BtnValidation
			// 
			this->BtnValidation->Location = System::Drawing::Point(406, 603);
			this->BtnValidation->Name = L"BtnValidation";
			this->BtnValidation->Size = System::Drawing::Size(85, 34);
			this->BtnValidation->TabIndex = 9;
			this->BtnValidation->Text = L"Valider";
			this->BtnValidation->UseVisualStyleBackColor = true;
			// 
			// BtnReturn
			// 
			this->BtnReturn->Location = System::Drawing::Point(24, 603);
			this->BtnReturn->Name = L"BtnReturn";
			this->BtnReturn->Size = System::Drawing::Size(85, 34);
			this->BtnReturn->TabIndex = 10;
			this->BtnReturn->Text = L"Retour";
			this->BtnReturn->UseVisualStyleBackColor = true;
			// 
			// Payment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 649);
			this->Controls->Add(this->BtnReturn);
			this->Controls->Add(this->BtnValidation);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->CboxDividedPayment);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->RbtnBankCheck);
			this->Controls->Add(this->RbtnBankTransfer);
			this->Controls->Add(this->RbtnBlueCard);
			this->Controls->Add(this->LbPriceValue);
			this->Controls->Add(this->LBIdOrder);
			this->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Payment";
			this->Text = L"Payment";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RbtnBankTransfer_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void RbtnBlueCard_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void RbtnBankCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
