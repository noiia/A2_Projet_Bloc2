#pragma once

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de fastClientCatalog
	/// </summary>
	public ref class fastClientCatalog : public System::Windows::Forms::Form
	{
	public:
		fastClientCatalog(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~fastClientCatalog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ TbSurname;
	protected:
	private: System::Windows::Forms::TextBox^ TbPostalCode;
	private: System::Windows::Forms::TextBox^ TbName;
	private: System::Windows::Forms::Button^ BtnReturn;
	private: System::Windows::Forms::Button^ BtnValidation;
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ LbIdClient;

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TbSurname = (gcnew System::Windows::Forms::TextBox());
			this->TbPostalCode = (gcnew System::Windows::Forms::TextBox());
			this->TbName = (gcnew System::Windows::Forms::TextBox());
			this->BtnReturn = (gcnew System::Windows::Forms::Button());
			this->BtnValidation = (gcnew System::Windows::Forms::Button());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->LbIdClient = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// TbSurname
			// 
			this->TbSurname->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbSurname->Location = System::Drawing::Point(94, 112);
			this->TbSurname->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->TbSurname->Name = L"TbSurname";
			this->TbSurname->Size = System::Drawing::Size(254, 26);
			this->TbSurname->TabIndex = 0;
			// 
			// TbPostalCode
			// 
			this->TbPostalCode->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPostalCode->Location = System::Drawing::Point(94, 242);
			this->TbPostalCode->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->TbPostalCode->Name = L"TbPostalCode";
			this->TbPostalCode->Size = System::Drawing::Size(254, 26);
			this->TbPostalCode->TabIndex = 1;
			// 
			// TbName
			// 
			this->TbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbName->Location = System::Drawing::Point(94, 178);
			this->TbName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(254, 26);
			this->TbName->TabIndex = 2;
			// 
			// BtnReturn
			// 
			this->BtnReturn->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnReturn->Location = System::Drawing::Point(50, 384);
			this->BtnReturn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->BtnReturn->Name = L"BtnReturn";
			this->BtnReturn->Size = System::Drawing::Size(93, 34);
			this->BtnReturn->TabIndex = 3;
			this->BtnReturn->Text = L"Retour";
			this->BtnReturn->UseVisualStyleBackColor = true;
			// 
			// BtnValidation
			// 
			this->BtnValidation->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnValidation->Location = System::Drawing::Point(309, 384);
			this->BtnValidation->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->BtnValidation->Name = L"BtnValidation";
			this->BtnValidation->Size = System::Drawing::Size(93, 34);
			this->BtnValidation->TabIndex = 4;
			this->BtnValidation->Text = L"Valider";
			this->BtnValidation->UseVisualStyleBackColor = true;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(118, 44);
			this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(205, 28);
			this->Title->TabIndex = 5;
			this->Title->Text = L"Recherche client";
			// 
			// LbIdClient
			// 
			this->LbIdClient->AutoSize = true;
			this->LbIdClient->Location = System::Drawing::Point(208, 314);
			this->LbIdClient->Name = L"LbIdClient";
			this->LbIdClient->Size = System::Drawing::Size(24, 19);
			this->LbIdClient->TabIndex = 6;
			this->LbIdClient->Text = L"ID";
			// 
			// fastClientCatalog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(451, 445);
			this->Controls->Add(this->LbIdClient);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->BtnValidation);
			this->Controls->Add(this->BtnReturn);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->TbPostalCode);
			this->Controls->Add(this->TbSurname);
			this->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"fastClientCatalog";
			this->Text = L"fastClientCatalog";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
