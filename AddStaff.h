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
	/// Description r�sum�e de AddStaff
	/// </summary>
	public ref class AddStaff : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		AddStaff(BDD^ mabdd)
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
		~AddStaff()
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



	private: System::Windows::Forms::Label^ LbAddress;
	private: System::Windows::Forms::Label^ LbName;



	private: System::Windows::Forms::TextBox^ TbSurname;
	private: System::Windows::Forms::TextBox^ TbName;











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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LbAddress = (gcnew System::Windows::Forms::Label());
			this->LbName = (gcnew System::Windows::Forms::Label());
			this->TbSurname = (gcnew System::Windows::Forms::TextBox());
			this->TbName = (gcnew System::Windows::Forms::TextBox());
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
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(12, 22);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(327, 28);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Ajouter un nouvel employé";
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
			// LbAddress
			// 
			this->LbAddress->AutoSize = true;
			this->LbAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbAddress->Location = System::Drawing::Point(12, 215);
			this->LbAddress->Name = L"LbAddress";
			this->LbAddress->Size = System::Drawing::Size(71, 19);
			this->LbAddress->TabIndex = 4;
			this->LbAddress->Text = L"Adresse";
			// 
			// LbName
			// 
			this->LbName->AutoSize = true;
			this->LbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbName->Location = System::Drawing::Point(12, 141);
			this->LbName->Name = L"LbName";
			this->LbName->Size = System::Drawing::Size(65, 19);
			this->LbName->TabIndex = 5;
			this->LbName->Text = L"Prénom";
			// 
			// TbSurname
			// 
			this->TbSurname->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbSurname->Location = System::Drawing::Point(16, 91);
			this->TbSurname->Name = L"TbSurname";
			this->TbSurname->Size = System::Drawing::Size(315, 26);
			this->TbSurname->TabIndex = 7;
			// 
			// TbName
			// 
			this->TbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbName->Location = System::Drawing::Point(16, 163);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(315, 26);
			this->TbName->TabIndex = 8;
			// 
			// BtnAddStaff
			// 
			this->BtnAddStaff->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddStaff->Location = System::Drawing::Point(43, 403);
			this->BtnAddStaff->Name = L"BtnAddStaff";
			this->BtnAddStaff->Size = System::Drawing::Size(111, 42);
			this->BtnAddStaff->TabIndex = 13;
			this->BtnAddStaff->Text = L"Ajouter";
			this->BtnAddStaff->UseVisualStyleBackColor = true;
			// 
			// BtnCancel
			// 
			this->BtnCancel->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCancel->Location = System::Drawing::Point(202, 403);
			this->BtnCancel->Name = L"BtnCancel";
			this->BtnCancel->Size = System::Drawing::Size(111, 42);
			this->BtnCancel->TabIndex = 14;
			this->BtnCancel->Text = L"Annuler";
			this->BtnCancel->UseVisualStyleBackColor = true;
			this->BtnCancel->Click += gcnew System::EventHandler(this, &AddStaff::BtnCancel_Click);
			// 
			// Tbaddress
			// 
			this->Tbaddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Tbaddress->Location = System::Drawing::Point(16, 248);
			this->Tbaddress->Name = L"Tbaddress";
			this->Tbaddress->Size = System::Drawing::Size(315, 26);
			this->Tbaddress->TabIndex = 15;
			// 
			// TbSupervisor
			// 
			this->TbSupervisor->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbSupervisor->Location = System::Drawing::Point(16, 332);
			this->TbSupervisor->Name = L"TbSupervisor";
			this->TbSupervisor->Size = System::Drawing::Size(315, 26);
			this->TbSupervisor->TabIndex = 17;
			this->TbSupervisor->TextChanged += gcnew System::EventHandler(this, &AddStaff::TbTresholdDate_TextChanged);
			// 
			// LbSupervisor
			// 
			this->LbSupervisor->AutoSize = true;
			this->LbSupervisor->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSupervisor->Location = System::Drawing::Point(12, 310);
			this->LbSupervisor->Name = L"LbSupervisor";
			this->LbSupervisor->Size = System::Drawing::Size(179, 19);
			this->LbSupervisor->TabIndex = 16;
			this->LbSupervisor->Text = L"Supérieur hiérarchique";
			this->LbSupervisor->Click += gcnew System::EventHandler(this, &AddStaff::LbTresholdDate_Click);
			// 
			// AddStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 486);
			this->Controls->Add(this->TbSupervisor);
			this->Controls->Add(this->LbSupervisor);
			this->Controls->Add(this->Tbaddress);
			this->Controls->Add(this->BtnCancel);
			this->Controls->Add(this->BtnAddStaff);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->TbSurname);
			this->Controls->Add(this->LbName);
			this->Controls->Add(this->LbAddress);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Title);
			this->Name = L"AddStaff";
			this->Text = L"AddStaff";
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
};
}