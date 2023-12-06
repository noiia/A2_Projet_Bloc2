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
		bool addOrEdit; 

	private: System::Windows::Forms::Label^ LbNumber;
	private: System::Windows::Forms::Label^ LbStreetName;
	private: System::Windows::Forms::TextBox^ TbStreetName;
	private: System::Windows::Forms::TextBox^ TbPostalCode;
	private: System::Windows::Forms::TextBox^ TbCity;
	private: System::Windows::Forms::Label^ LbPostalCode;
	private: System::Windows::Forms::Label^ LbCity;
	private: System::Windows::Forms::Label^ LbAddressComplementary;
	private: System::Windows::Forms::TextBox^ TbAddressComplementary;
	private: System::Windows::Forms::DateTimePicker^ DtpHiringDate;
	private: System::Windows::Forms::Label^ LbHiringDate;

	public:
		AddStaff(Staff^ staff, bool addOrEdit)
		{
			this->staff = staff;
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
	private: System::Windows::Forms::TextBox^ TbNumber;
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
			this->TbNumber = (gcnew System::Windows::Forms::TextBox());
			this->TbSupervisor = (gcnew System::Windows::Forms::TextBox());
			this->LbSupervisor = (gcnew System::Windows::Forms::Label());
			this->LbNumber = (gcnew System::Windows::Forms::Label());
			this->LbStreetName = (gcnew System::Windows::Forms::Label());
			this->TbStreetName = (gcnew System::Windows::Forms::TextBox());
			this->TbPostalCode = (gcnew System::Windows::Forms::TextBox());
			this->TbCity = (gcnew System::Windows::Forms::TextBox());
			this->LbPostalCode = (gcnew System::Windows::Forms::Label());
			this->LbCity = (gcnew System::Windows::Forms::Label());
			this->LbAddressComplementary = (gcnew System::Windows::Forms::Label());
			this->TbAddressComplementary = (gcnew System::Windows::Forms::TextBox());
			this->DtpHiringDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->LbHiringDate = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(485, 9);
			this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(394, 36);
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
			this->LbLastName->Size = System::Drawing::Size(53, 25);
			this->LbLastName->TabIndex = 1;
			this->LbLastName->Text = L"Nom";
			// 
			// LbAddress
			// 
			this->LbAddress->AutoSize = true;
			this->LbAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbAddress->Location = System::Drawing::Point(589, 70);
			this->LbAddress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbAddress->Name = L"LbAddress";
			this->LbAddress->Size = System::Drawing::Size(85, 25);
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
			this->LbFirstName->Size = System::Drawing::Size(80, 25);
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
			this->TbLastName->Size = System::Drawing::Size(419, 30);
			this->TbLastName->TabIndex = 7;
			// 
			// TbFirstName
			// 
			this->TbFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbFirstName->Location = System::Drawing::Point(21, 201);
			this->TbFirstName->Margin = System::Windows::Forms::Padding(4);
			this->TbFirstName->Name = L"TbFirstName";
			this->TbFirstName->Size = System::Drawing::Size(419, 30);
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
			// TbNumber
			// 
			this->TbNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbNumber->Location = System::Drawing::Point(594, 145);
			this->TbNumber->Margin = System::Windows::Forms::Padding(4);
			this->TbNumber->Name = L"TbNumber";
			this->TbNumber->Size = System::Drawing::Size(419, 30);
			this->TbNumber->TabIndex = 15;
			// 
			// TbSupervisor
			// 
			this->TbSupervisor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbSupervisor->Location = System::Drawing::Point(21, 398);
			this->TbSupervisor->Margin = System::Windows::Forms::Padding(4);
			this->TbSupervisor->Name = L"TbSupervisor";
			this->TbSupervisor->Size = System::Drawing::Size(419, 30);
			this->TbSupervisor->TabIndex = 17;
			
			// 
			// LbSupervisor
			// 
			this->LbSupervisor->AutoSize = true;
			this->LbSupervisor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSupervisor->Location = System::Drawing::Point(16, 353);
			this->LbSupervisor->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbSupervisor->Name = L"LbSupervisor";
			this->LbSupervisor->Size = System::Drawing::Size(209, 25);
			this->LbSupervisor->TabIndex = 16;
			this->LbSupervisor->Text = L"Supérieur hiérarchique";
			
			// 
			// LbNumber
			// 
			this->LbNumber->AutoSize = true;
			this->LbNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbNumber->Location = System::Drawing::Point(589, 117);
			this->LbNumber->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbNumber->Name = L"LbNumber";
			this->LbNumber->Size = System::Drawing::Size(81, 25);
			this->LbNumber->TabIndex = 18;
			this->LbNumber->Text = L"Numero";
			// 
			// LbStreetName
			// 
			this->LbStreetName->AutoSize = true;
			this->LbStreetName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbStreetName->Location = System::Drawing::Point(589, 201);
			this->LbStreetName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbStreetName->Name = L"LbStreetName";
			this->LbStreetName->Size = System::Drawing::Size(120, 25);
			this->LbStreetName->TabIndex = 19;
			this->LbStreetName->Text = L"Nom de Rue";
			// 
			// TbStreetName
			// 
			this->TbStreetName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbStreetName->Location = System::Drawing::Point(594, 230);
			this->TbStreetName->Margin = System::Windows::Forms::Padding(4);
			this->TbStreetName->Name = L"TbStreetName";
			this->TbStreetName->Size = System::Drawing::Size(419, 30);
			this->TbStreetName->TabIndex = 20;
			// 
			// TbPostalCode
			// 
			this->TbPostalCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPostalCode->Location = System::Drawing::Point(594, 304);
			this->TbPostalCode->Margin = System::Windows::Forms::Padding(4);
			this->TbPostalCode->Name = L"TbPostalCode";
			this->TbPostalCode->Size = System::Drawing::Size(419, 30);
			this->TbPostalCode->TabIndex = 21;
			// 
			// TbCity
			// 
			this->TbCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbCity->Location = System::Drawing::Point(594, 382);
			this->TbCity->Margin = System::Windows::Forms::Padding(4);
			this->TbCity->Name = L"TbCity";
			this->TbCity->Size = System::Drawing::Size(419, 30);
			this->TbCity->TabIndex = 22;
			// 
			// LbPostalCode
			// 
			this->LbPostalCode->AutoSize = true;
			this->LbPostalCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPostalCode->Location = System::Drawing::Point(589, 275);
			this->LbPostalCode->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbPostalCode->Name = L"LbPostalCode";
			this->LbPostalCode->Size = System::Drawing::Size(119, 25);
			this->LbPostalCode->TabIndex = 23;
			this->LbPostalCode->Text = L"Code Postal";
			// 
			// LbCity
			// 
			this->LbCity->AutoSize = true;
			this->LbCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbCity->Location = System::Drawing::Point(589, 353);
			this->LbCity->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbCity->Name = L"LbCity";
			this->LbCity->Size = System::Drawing::Size(49, 25);
			this->LbCity->TabIndex = 24;
			this->LbCity->Text = L"Ville";
			// 
			// LbAddressComplementary
			// 
			this->LbAddressComplementary->AutoSize = true;
			this->LbAddressComplementary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->LbAddressComplementary->Location = System::Drawing::Point(589, 432);
			this->LbAddressComplementary->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbAddressComplementary->Name = L"LbAddressComplementary";
			this->LbAddressComplementary->Size = System::Drawing::Size(213, 25);
			this->LbAddressComplementary->TabIndex = 25;
			this->LbAddressComplementary->Text = L"Complement d\'adresse";
			// 
			// TbAddressComplementary
			// 
			this->TbAddressComplementary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TbAddressComplementary->Location = System::Drawing::Point(594, 461);
			this->TbAddressComplementary->Margin = System::Windows::Forms::Padding(4);
			this->TbAddressComplementary->Name = L"TbAddressComplementary";
			this->TbAddressComplementary->Size = System::Drawing::Size(419, 30);
			this->TbAddressComplementary->TabIndex = 26;
			// 
			// DtpHiringDate
			// 
			this->DtpHiringDate->Location = System::Drawing::Point(21, 304);
			this->DtpHiringDate->Name = L"DtpHiringDate";
			this->DtpHiringDate->Size = System::Drawing::Size(396, 22);
			this->DtpHiringDate->TabIndex = 27;
			// 
			// LbHiringDate
			// 
			this->LbHiringDate->AutoSize = true;
			this->LbHiringDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbHiringDate->Location = System::Drawing::Point(16, 269);
			this->LbHiringDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LbHiringDate->Name = L"LbHiringDate";
			this->LbHiringDate->Size = System::Drawing::Size(165, 25);
			this->LbHiringDate->TabIndex = 28;
			this->LbHiringDate->Text = L"Date d\'embauche";
			// 
			// AddStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1070, 598);
			this->Controls->Add(this->LbHiringDate);
			this->Controls->Add(this->DtpHiringDate);
			this->Controls->Add(this->TbAddressComplementary);
			this->Controls->Add(this->LbAddressComplementary);
			this->Controls->Add(this->LbCity);
			this->Controls->Add(this->LbPostalCode);
			this->Controls->Add(this->TbCity);
			this->Controls->Add(this->TbPostalCode);
			this->Controls->Add(this->TbStreetName);
			this->Controls->Add(this->LbStreetName);
			this->Controls->Add(this->LbNumber);
			this->Controls->Add(this->TbSupervisor);
			this->Controls->Add(this->LbSupervisor);
			this->Controls->Add(this->TbNumber);
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
	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void AddStaff_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void BtnAddStaff_Click(System::Object^ sender, System::EventArgs^ e) {
		this->staff->setLastName(this->TbLastName->Text);
		this->staff->setFirstName(this->TbFirstName->Text);
		String^ dateString = this->DtpHiringDate->Value.ToString("dd-MM-yyyy");
		DateTime HiringDate = DateTime::ParseExact(dateString, "dd-MM-yyyy", System::Globalization::CultureInfo::InvariantCulture);
		this->staff->setHiringDate(HiringDate);
		//this->staff->setSupervisor(this->TbSupervisor->Text);
		this->Close();

	}
};
}