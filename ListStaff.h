#pragma once
#include "BDD.h"
#include "AddStaff.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de ListStaff
	/// </summary>
	public ref class ListStaff : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		ListStaff(BDD^ mabdd)
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
		~ListStaff()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnModify;
	private: System::Windows::Forms::Button^ BtnAddStaff;


	protected:

	private: System::Windows::Forms::DataGridView^ DGVSearchStaff;
	private: System::Windows::Forms::Label^ Title;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BtnModify = (gcnew System::Windows::Forms::Button());
			this->BtnAddStaff = (gcnew System::Windows::Forms::Button());
			this->DGVSearchStaff = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(691, 456);
			this->BtnModify->Name = L"BtnModify";
			this->BtnModify->Size = System::Drawing::Size(135, 48);
			this->BtnModify->TabIndex = 27;
			this->BtnModify->Text = L"Modifier";
			this->BtnModify->UseVisualStyleBackColor = true;
			// 
			// BtnAddStaff
			// 
			this->BtnAddStaff->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddStaff->Location = System::Drawing::Point(691, 81);
			this->BtnAddStaff->Name = L"BtnAddStaff";
			this->BtnAddStaff->Size = System::Drawing::Size(135, 48);
			this->BtnAddStaff->TabIndex = 26;
			this->BtnAddStaff->Text = L"Ajouter";
			this->BtnAddStaff->UseVisualStyleBackColor = true;
			this->BtnAddStaff->Click += gcnew System::EventHandler(this, &ListStaff::BtnAddStaff_Click);
			// 
			// DGVSearchStaff
			// 
			this->DGVSearchStaff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVSearchStaff->Location = System::Drawing::Point(26, 56);
			this->DGVSearchStaff->Name = L"DGVSearchStaff";
			this->DGVSearchStaff->Size = System::Drawing::Size(603, 526);
			this->DGVSearchStaff->TabIndex = 25;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(317, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(238, 28);
			this->Title->TabIndex = 24;
			this->Title->Text = L"Liste des employés";
			// 
			// ListStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 623);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddStaff);
			this->Controls->Add(this->DGVSearchStaff);
			this->Controls->Add(this->Title);
			this->Name = L"ListStaff";
			this->Text = L"ListStaff";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnAddStaff_Click(System::Object^ sender, System::EventArgs^ e) {
		AddStaff^ addStaffForm = gcnew AddStaff(mabdd);
		addStaffForm->ShowDialog();
	}
};
}
