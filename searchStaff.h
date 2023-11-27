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
	/// Description r�sum�e de searchStaff
	/// </summary>
	public ref class SearchStaff : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		SearchStaff(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			DataGridViewTextBoxColumn^ dgvtbcReferences = gcnew DataGridViewTextBoxColumn();
			dgvtbcReferences->Name = "Référence";
			this->DGVSearchStaff->Columns->Add(dgvtbcReferences);
			DataGridViewTextBoxColumn^ dgvtbcQuantity = gcnew DataGridViewTextBoxColumn();
			dgvtbcQuantity->Name = "Quantité";
			this->DGVSearchStaff->Columns->Add(dgvtbcQuantity);
			DataGridViewTextBoxColumn^ dgvtbcRestock = gcnew DataGridViewTextBoxColumn();
			dgvtbcRestock->Name = "Date de restock";
			this->DGVSearchStaff->Columns->Add(dgvtbcRestock);

			DataSet^ ds = mabdd->executeQuery("SELECT * FROM Stock");

			for each (DataRow ^ row in ds->Tables[0]->Rows)
			{
				String^ references = (String^)row[0];
				System::Diagnostics::Debug::WriteLine("nom " + references);
				int quantity = (int)row[1];
				System::Diagnostics::Debug::WriteLine("quantity " + quantity);
				String^ restock = (String^)row[2];
				System::Diagnostics::Debug::WriteLine("restock date " + restock);

				DataGridViewRow^ dgvr = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ dgvcReferences = gcnew DataGridViewTextBoxCell();
				dgvcReferences->Value = references;
				dgvr->Cells->Add(dgvcReferences);
				DataGridViewTextBoxCell^ dgvcQuantity = gcnew DataGridViewTextBoxCell();
				dgvcQuantity->Value = Convert::ToString(quantity);
				dgvr->Cells->Add(dgvcQuantity);
				DataGridViewTextBoxCell^ dgvcRestock = gcnew DataGridViewTextBoxCell();
				dgvcRestock->Value = restock;
				dgvr->Cells->Add(dgvcRestock);
				this->DGVSearchStaff->Rows->Add(dgvr);
			}
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
	~SearchStaff()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LbSearchStaff;
	private: System::Windows::Forms::Label^ LbName;
	private: System::Windows::Forms::Label^ LbPostalCode;

	private: System::Windows::Forms::Label^ LbFirstName;
	private: System::Windows::Forms::Label^ LbCity;
	private: System::Windows::Forms::TextBox^ TbName;




	private: System::Windows::Forms::TextBox^ TbFirstName;

	private: System::Windows::Forms::TextBox^ TbPostalCode;


	private: System::Windows::Forms::TextBox^ TbCity;
	private: System::Windows::Forms::DataGridView^ DGVSearchStaff;
	private: System::Windows::Forms::Button^ BtnValidate;
	private: System::Windows::Forms::Button^ BtnNewStaff;



	protected:

	protected:

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
			this->LbSearchStaff = (gcnew System::Windows::Forms::Label());
			this->LbName = (gcnew System::Windows::Forms::Label());
			this->LbPostalCode = (gcnew System::Windows::Forms::Label());
			this->LbFirstName = (gcnew System::Windows::Forms::Label());
			this->LbCity = (gcnew System::Windows::Forms::Label());
			this->TbName = (gcnew System::Windows::Forms::TextBox());
			this->TbFirstName = (gcnew System::Windows::Forms::TextBox());
			this->TbPostalCode = (gcnew System::Windows::Forms::TextBox());
			this->TbCity = (gcnew System::Windows::Forms::TextBox());
			this->DGVSearchStaff = (gcnew System::Windows::Forms::DataGridView());
			this->BtnValidate = (gcnew System::Windows::Forms::Button());
			this->BtnNewStaff = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->BeginInit();
			this->SuspendLayout();
			// 
			// LbSearchStaff
			// 
			this->LbSearchStaff->AutoSize = true;
			this->LbSearchStaff->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSearchStaff->Location = System::Drawing::Point(194, 9);
			this->LbSearchStaff->Name = L"LbSearchStaff";
			this->LbSearchStaff->Size = System::Drawing::Size(290, 28);
			this->LbSearchStaff->TabIndex = 0;
			this->LbSearchStaff->Text = L"Recherche d\'un employé";
			// 
			// LbName
			// 
			this->LbName->AutoSize = true;
			this->LbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbName->Location = System::Drawing::Point(21, 78);
			this->LbName->Name = L"LbName";
			this->LbName->Size = System::Drawing::Size(44, 19);
			this->LbName->TabIndex = 1;
			this->LbName->Text = L"Nom";
			// 
			// LbPostalCode
			// 
			this->LbPostalCode->AutoSize = true;
			this->LbPostalCode->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPostalCode->Location = System::Drawing::Point(21, 221);
			this->LbPostalCode->Name = L"LbPostalCode";
			this->LbPostalCode->Size = System::Drawing::Size(97, 19);
			this->LbPostalCode->TabIndex = 2;
			this->LbPostalCode->Text = L"Code Postal";
			// 
			// LbFirstName
			// 
			this->LbFirstName->AutoSize = true;
			this->LbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbFirstName->Location = System::Drawing::Point(21, 152);
			this->LbFirstName->Name = L"LbFirstName";
			this->LbFirstName->Size = System::Drawing::Size(65, 19);
			this->LbFirstName->TabIndex = 3;
			this->LbFirstName->Text = L"Prénom";
			// 
			// LbCity
			// 
			this->LbCity->AutoSize = true;
			this->LbCity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbCity->Location = System::Drawing::Point(21, 291);
			this->LbCity->Name = L"LbCity";
			this->LbCity->Size = System::Drawing::Size(43, 19);
			this->LbCity->TabIndex = 4;
			this->LbCity->Text = L"Ville";
			// 
			// TbName
			// 
			this->TbName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbName->Location = System::Drawing::Point(25, 100);
			this->TbName->Name = L"TbName";
			this->TbName->Size = System::Drawing::Size(211, 26);
			this->TbName->TabIndex = 5;
			// 
			// TbFirstName
			// 
			this->TbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbFirstName->Location = System::Drawing::Point(25, 174);
			this->TbFirstName->Name = L"TbFirstName";
			this->TbFirstName->Size = System::Drawing::Size(211, 26);
			this->TbFirstName->TabIndex = 6;
			// 
			// TbPostalCode
			// 
			this->TbPostalCode->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPostalCode->Location = System::Drawing::Point(25, 243);
			this->TbPostalCode->Name = L"TbPostalCode";
			this->TbPostalCode->Size = System::Drawing::Size(211, 26);
			this->TbPostalCode->TabIndex = 7;
			// 
			// TbCity
			// 
			this->TbCity->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbCity->Location = System::Drawing::Point(25, 313);
			this->TbCity->Name = L"TbCity";
			this->TbCity->Size = System::Drawing::Size(211, 26);
			this->TbCity->TabIndex = 8;
			// 
			// DGVSearchStaff
			// 
			this->DGVSearchStaff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVSearchStaff->Location = System::Drawing::Point(283, 100);
			this->DGVSearchStaff->Name = L"DGVSearchStaff";
			this->DGVSearchStaff->Size = System::Drawing::Size(378, 365);
			this->DGVSearchStaff->TabIndex = 9;
			this->DGVSearchStaff->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SearchStaff::DGVSearchStaff_CellContentClick);
			// 
			// BtnValidate
			// 
			this->BtnValidate->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnValidate->Location = System::Drawing::Point(59, 381);
			this->BtnValidate->Name = L"BtnValidate";
			this->BtnValidate->Size = System::Drawing::Size(135, 48);
			this->BtnValidate->TabIndex = 10;
			this->BtnValidate->Text = L"Valider";
			this->BtnValidate->UseVisualStyleBackColor = true;
			// 
			// BtnNewStaff
			// 
			this->BtnNewStaff->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnNewStaff->Location = System::Drawing::Point(283, 508);
			this->BtnNewStaff->Name = L"BtnNewStaff";
			this->BtnNewStaff->Size = System::Drawing::Size(378, 48);
			this->BtnNewStaff->TabIndex = 11;
			this->BtnNewStaff->Text = L"Enregistrer un nouvel employé";
			this->BtnNewStaff->UseVisualStyleBackColor = true;
			// 
			// SearchStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 587);
			this->Controls->Add(this->BtnNewStaff);
			this->Controls->Add(this->BtnValidate);
			this->Controls->Add(this->DGVSearchStaff);
			this->Controls->Add(this->TbCity);
			this->Controls->Add(this->TbPostalCode);
			this->Controls->Add(this->TbFirstName);
			this->Controls->Add(this->TbName);
			this->Controls->Add(this->LbCity);
			this->Controls->Add(this->LbFirstName);
			this->Controls->Add(this->LbPostalCode);
			this->Controls->Add(this->LbName);
			this->Controls->Add(this->LbSearchStaff);
			this->Name = L"SearchStaff";
			this->Text = L"SearchStaff";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void DGVSearchStaff_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
};
}
