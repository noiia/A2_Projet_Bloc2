#pragma once

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de cartReminder
	/// </summary>
	public ref class cartReminder : public System::Windows::Forms::Form
	{
	public:
		cartReminder(void)
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
		~cartReminder()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ BtnReturn;
	private: System::Windows::Forms::Button^ BtnValidation;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->BtnReturn = (gcnew System::Windows::Forms::Button());
			this->BtnValidation = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(223, 30);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(152, 29);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Récapitulatif";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(36, 78);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(528, 341);
			this->dataGridView1->TabIndex = 1;
			// 
			// BtnReturn
			// 
			this->BtnReturn->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnReturn->Location = System::Drawing::Point(36, 441);
			this->BtnReturn->Name = L"BtnReturn";
			this->BtnReturn->Size = System::Drawing::Size(100, 42);
			this->BtnReturn->TabIndex = 2;
			this->BtnReturn->Text = L"Retour";
			this->BtnReturn->UseVisualStyleBackColor = true;
			// 
			// BtnValidation
			// 
			this->BtnValidation->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnValidation->Location = System::Drawing::Point(464, 441);
			this->BtnValidation->Name = L"BtnValidation";
			this->BtnValidation->Size = System::Drawing::Size(100, 42);
			this->BtnValidation->TabIndex = 3;
			this->BtnValidation->Text = L"Valider";
			this->BtnValidation->UseVisualStyleBackColor = true;
			// 
			// cartReminder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(597, 509);
			this->Controls->Add(this->BtnValidation);
			this->Controls->Add(this->BtnReturn);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->Title);
			this->Name = L"cartReminder";
			this->Text = L"cartReminder";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
