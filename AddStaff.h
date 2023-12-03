#pragma once
#include "Staff.h"
namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de AddStaff
	/// </summary>
	public ref class AddStaff : public System::Windows::Forms::Form
	{
		Staff^ staff;
	public:
		AddStaff(Staff^ staff)
		{
			this->staff = staff;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~AddStaff()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ LbLastName;


	private: System::Windows::Forms::Label^ LbAddress;
	private: System::Windows::Forms::Label^ LbFirstName;

	private: System::Windows::Forms::TextBox^ TbLastName;
	private: System::Windows::Forms::TextBox^ TbFirstName;


	private: System::Windows::Forms::Button^ BtnAddStaff;
	private: System::Windows::Forms::Button^ BtnCancel;
	private: System::Windows::Forms::TextBox^ Tbaddress;
	private: System::Windows::Forms::TextBox^ TbSupervisor;
	private: System::Windows::Forms::Label^ LbSupervisor;




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
			this->LbLastName = (gcnew System::Windows::Forms::Label());
			this->LbAddress = (gcnew System::Windows::Forms::Label());
			this->LbFirstName = (gcnew System::Windows::Forms::Label());
			this->TbLastName = (gcnew System::Windows::Forms::TextBox());
			this->TbFirstName = (gcnew System::Windows::Forms::TextBox());
			this->BtnAddStaff = (gcnew System::Windows::Forms::Button());
			this->BtnCancel = (gcnew System::Windows::Forms::Button());
			this->Tbaddress = (gcnew System::Windows::Forms::TextBox());
			this->TbSupervisor = (gcnew System::Windows::Forms::TextBox());
			this->LbSupervisor = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(16, 27);
			this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(322, 29);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Ajouter un nouvel employé";
			// 
			// LbLastName
			// 
			this->LbLastName->AutoSize = true;
			this->LbLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbLastName->Location = System::Drawing::Point(16, 85);
			this->LbLastName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbLastName->Name = L"LbLastName";
			this->LbLastName->Size = System::Drawing::Size(42, 20);
			this->LbLastName->TabIndex = 1;
			this->LbLastName->Text = L"Nom";

			// 
			// LbAddress
			// 
			this->LbAddress->AutoSize = true;
			this->LbAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbAddress->Location = System::Drawing::Point(16, 265);
			this->LbAddress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbAddress->Name = L"LbAddress";
			this->LbAddress->Size = System::Drawing::Size(68, 20);
			this->LbAddress->TabIndex = 4;
			this->LbAddress->Text = L"Adresse";
			// 
			// LbFirstName
			// 
			this->LbFirstName->AutoSize = true;
			this->LbFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbFirstName->Location = System::Drawing::Point(16, 174);
			this->LbFirstName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbFirstName->Name = L"LbFirstName";
			this->LbFirstName->Size = System::Drawing::Size(64, 20);
			this->LbFirstName->TabIndex = 5;
			this->LbFirstName->Text = L"Prénom";
			// 
			// TbLastName
			// 
			this->TbLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbLastName->Location = System::Drawing::Point(21, 112);
			this->TbLastName->Margin = System::Windows::Forms::Padding(4);
			this->TbLastName->Name = L"TbLastName";
			this->TbLastName->Size = System::Drawing::Size(419, 26);
			this->TbLastName->TabIndex = 7;

			// 
			// TbFirstName
			// 
			this->TbFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbFirstName->Location = System::Drawing::Point(21, 201);
			this->TbFirstName->Margin = System::Windows::Forms::Padding(4);
			this->TbFirstName->Name = L"TbFirstName";
			this->TbFirstName->Size = System::Drawing::Size(419, 26);
			this->TbFirstName->TabIndex = 8;
			// 
			// BtnAddStaff
			// 
			this->BtnAddStaff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddStaff->Location = System::Drawing::Point(57, 496);
			this->BtnAddStaff->Margin = System::Windows::Forms::Padding(4);
			this->BtnAddStaff->Name = L"BtnAddStaff";
			this->BtnAddStaff->Size = System::Drawing::Size(148, 52);
			this->BtnAddStaff->TabIndex = 13;
			this->BtnAddStaff->Text = L"Ajouter";
			this->BtnAddStaff->UseVisualStyleBackColor = true;
			this->BtnAddStaff->Click += gcnew System::EventHandler(this, &AddStaff::BtnAddStaff_Click);
			// 
			// BtnCancel
			// 
			this->BtnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCancel->Location = System::Drawing::Point(269, 496);
			this->BtnCancel->Margin = System::Windows::Forms::Padding(4);
			this->BtnCancel->Name = L"BtnCancel";
			this->BtnCancel->Size = System::Drawing::Size(148, 52);
			this->BtnCancel->TabIndex = 14;
			this->BtnCancel->Text = L"Annuler";
			this->BtnCancel->UseVisualStyleBackColor = true;
			this->BtnCancel->Click += gcnew System::EventHandler(this, &AddStaff::BtnCancel_Click);
			// 
			// Tbaddress
			// 
			this->Tbaddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Tbaddress->Location = System::Drawing::Point(21, 305);
			this->Tbaddress->Margin = System::Windows::Forms::Padding(4);
			this->Tbaddress->Name = L"Tbaddress";
			this->Tbaddress->Size = System::Drawing::Size(419, 26);
			this->Tbaddress->TabIndex = 15;
			// 
			// TbSupervisor
			// 
			this->TbSupervisor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbSupervisor->Location = System::Drawing::Point(21, 409);
			this->TbSupervisor->Margin = System::Windows::Forms::Padding(4);
			this->TbSupervisor->Name = L"TbSupervisor";
			this->TbSupervisor->Size = System::Drawing::Size(419, 26);
			this->TbSupervisor->TabIndex = 17;
			this->TbSupervisor->TextChanged += gcnew System::EventHandler(this, &AddStaff::TbTresholdDate_TextChanged);
			// 
			// LbSupervisor
			// 
			this->LbSupervisor->AutoSize = true;
			this->LbSupervisor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSupervisor->Location = System::Drawing::Point(16, 382);
			this->LbSupervisor->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbSupervisor->Name = L"LbSupervisor";
			this->LbSupervisor->Size = System::Drawing::Size(169, 20);
			this->LbSupervisor->TabIndex = 16;
			this->LbSupervisor->Text = L"Supérieur hiérarchique";
			this->LbSupervisor->Click += gcnew System::EventHandler(this, &AddStaff::LbTresholdDate_Click);
			// 
			// AddStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 598);
			this->Controls->Add(this->TbSupervisor);
			this->Controls->Add(this->LbSupervisor);
			this->Controls->Add(this->Tbaddress);
			this->Controls->Add(this->BtnCancel);
			this->Controls->Add(this->BtnAddStaff);
			this->Controls->Add(this->TbFirstName);
			this->Controls->Add(this->TbLastName);
			this->Controls->Add(this->LbFirstName);
			this->Controls->Add(this->LbAddress);
			this->Controls->Add(this->LbLastName);
			this->Controls->Add(this->Title);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AddStaff";
			this->Text = L"AddStaff";
			this->Load += gcnew System::EventHandler(this, &AddStaff::AddStaff_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LbTresholdDate_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TbTresholdDate_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void BtnAddStaff_Click(System::Object^ sender, System::EventArgs^ e) {
		this->staff->setLastName(this->TbLastName->Text);
		this->staff->setFirstName(this->TbFirstName->Text);
		this->staff->setAddress(this->Tbaddress->Text);
		//this->staff->setSupervisor(this->TbSupervisor->Text);
		this->Close();

	}

	private: System::Void AddStaff_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}