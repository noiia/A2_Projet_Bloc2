#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "BDD.h"
#include "AddStaff.h"
#include "StaffRepository.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Description résumée de ListStaff
	/// </summary>
	public ref class ListStaff : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		Staff^ sharedS;
		bool delOrRestore;
		Thread^ reloadThread;
		StaffRepository^ staffRepository;
	private: System::Threading::Mutex^ reloadMutex;
	private: System::Windows::Forms::CheckBox^ CBoxDeletedLines;

	private: System::Windows::Forms::Label^ TitleListStaff;


	private: System::Windows::Forms::Button^ BtnDelete;
		  

	public:
		ListStaff(BDD^ mabdd)
		{
			this->mabdd = mabdd; 
			InitializeComponent();

			reloadMutex = gcnew System::Threading::Mutex();

			DGVSearchStaff->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcLastName = gcnew DataGridViewTextBoxColumn();
			dgvtbcLastName->Name = "Nom";
			this->DGVSearchStaff->Columns->Add(dgvtbcLastName);
			DataGridViewTextBoxColumn^ dgvtbcFirstName = gcnew DataGridViewTextBoxColumn();
			dgvtbcFirstName->Name = "Prenom";
			this->DGVSearchStaff->Columns->Add(dgvtbcFirstName);
			DataGridViewTextBoxColumn^ dgvtbcHiringDate = gcnew DataGridViewTextBoxColumn();
			dgvtbcHiringDate->Name = "Date d'embauche";
			this->DGVSearchStaff->Columns->Add(dgvtbcHiringDate);
			DataGridViewTextBoxColumn^ dgvtbcSupervisor = gcnew DataGridViewTextBoxColumn();
			dgvtbcSupervisor->Name = "Supérieur hiérarchique";
			this->DGVSearchStaff->Columns->Add(dgvtbcSupervisor);
			
			staffRepository = gcnew StaffRepository(mabdd);
			this->reload();
		}

		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Staff^>^ staff = staffRepository->getStaff(this->CBoxDeletedLines->Checked);
				this->DGVSearchStaff->Rows->Clear();
				for each (Staff ^ s in staff) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdStaff = gcnew DataGridViewTextBoxCell();
					dgvcIdStaff->Value = s->getIdStaff();
					DataGridViewTextBoxCell^ dgvcLastName = gcnew DataGridViewTextBoxCell();
					dgvcLastName->Value = s->getLastName();
					dgvr->Cells->Add(dgvcLastName);
					DataGridViewTextBoxCell^ dgvcFirstName = gcnew DataGridViewTextBoxCell();
					dgvcFirstName->Value = s->getFirstName();
					dgvr->Cells->Add(dgvcFirstName);
					DataGridViewTextBoxCell^ dgvtbcHiringDate = gcnew DataGridViewTextBoxCell();
					DateTime^ hiringDate = s->getHiringDate();
					dgvtbcHiringDate->Value = hiringDate->ToString("yyyy-MM-dd");
					dgvr->Cells->Add(dgvtbcHiringDate);
					DataGridViewTextBoxCell^ dgvtbcIdSupervisor = gcnew DataGridViewTextBoxCell();
					dgvtbcIdSupervisor->Value = s->getIdSupervisor();
					dgvr->Cells->Add(dgvtbcIdSupervisor);

					dgvr->Tag = s;
					this->DGVSearchStaff->Rows->Add(dgvr);

					if (this->CBoxDeletedLines->Checked) {
						this->BtnDelete->Text = L"Restaurer";
						this->BtnDelete->Location = System::Drawing::Point(690, 537);
						System::Diagnostics::Debug::WriteLine("restaurer");
						delOrRestore = 0;
					}
					else {
						this->BtnDelete->Text = L"Supprimer";
						this->BtnDelete->Location = System::Drawing::Point(690, 537);
						System::Diagnostics::Debug::WriteLine("supprimer");
						delOrRestore = 1;
					}
				}

				reloadMutex->ReleaseMutex();
			}
		}
		void lauchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &ListStaff::reload));
			reloadThread->Start();
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ListStaff::typeid));
			this->BtnModify = (gcnew System::Windows::Forms::Button());
			this->BtnAddStaff = (gcnew System::Windows::Forms::Button());
			this->DGVSearchStaff = (gcnew System::Windows::Forms::DataGridView());
			this->BtnDelete = (gcnew System::Windows::Forms::Button());
			this->CBoxDeletedLines = (gcnew System::Windows::Forms::CheckBox());
			this->TitleListStaff = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(691, 466);
			this->BtnModify->Margin = System::Windows::Forms::Padding(9);
			this->BtnModify->Name = L"BtnModify";
			this->BtnModify->Size = System::Drawing::Size(135, 48);
			this->BtnModify->TabIndex = 27;
			this->BtnModify->Text = L"Modifier";
			this->BtnModify->UseVisualStyleBackColor = true;
			this->BtnModify->Click += gcnew System::EventHandler(this, &ListStaff::BtnModify_Click);
			// 
			// BtnAddStaff
			// 
			this->BtnAddStaff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddStaff->Location = System::Drawing::Point(691, 114);
			this->BtnAddStaff->Margin = System::Windows::Forms::Padding(9);
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
			this->DGVSearchStaff->ReadOnly = true;
			this->DGVSearchStaff->RowHeadersWidth = 51;
			this->DGVSearchStaff->Size = System::Drawing::Size(652, 526);
			this->DGVSearchStaff->TabIndex = 25;
			this->DGVSearchStaff->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ListStaff::DGVSearchStaff_RowEnter);
			// 
			// BtnDelete
			// 
			this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnDelete->Location = System::Drawing::Point(690, 537);
			this->BtnDelete->Margin = System::Windows::Forms::Padding(9);
			this->BtnDelete->Name = L"BtnDelete";
			this->BtnDelete->Size = System::Drawing::Size(135, 48);
			this->BtnDelete->TabIndex = 28;
			this->BtnDelete->Text = L"Supprimer";
			this->BtnDelete->UseVisualStyleBackColor = true;
			this->BtnDelete->Click += gcnew System::EventHandler(this, &ListStaff::BtnDelete_Click);
			// 
			// CBoxDeletedLines
			// 
			this->CBoxDeletedLines->AutoSize = true;
			this->CBoxDeletedLines->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CBoxDeletedLines->Location = System::Drawing::Point(690, 412);
			this->CBoxDeletedLines->Margin = System::Windows::Forms::Padding(7);
			this->CBoxDeletedLines->Name = L"CBoxDeletedLines";
			this->CBoxDeletedLines->Size = System::Drawing::Size(229, 24);
			this->CBoxDeletedLines->TabIndex = 29;
			this->CBoxDeletedLines->Text = L"Afficher les lignes supprimés";
			this->CBoxDeletedLines->UseVisualStyleBackColor = true;
			this->CBoxDeletedLines->CheckedChanged += gcnew System::EventHandler(this, &ListStaff::CBoxDeletedLines_CheckedChanged);
			// 
			// TitleListStaff
			// 
			this->TitleListStaff->AutoSize = true;
			this->TitleListStaff->Location = System::Drawing::Point(317, 9);
			this->TitleListStaff->Name = L"TitleListStaff";
			this->TitleListStaff->Size = System::Drawing::Size(241, 29);
			this->TitleListStaff->TabIndex = 30;
			this->TitleListStaff->Text = L"Liste des Employés";
			// 
			// ListStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1157, 623);
			this->Controls->Add(this->TitleListStaff);
			this->Controls->Add(this->CBoxDeletedLines);
			this->Controls->Add(this->BtnDelete);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddStaff);
			this->Controls->Add(this->DGVSearchStaff);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(423, 11);
			this->Margin = System::Windows::Forms::Padding(9);
			this->MaximizeBox = false;
			this->Name = L"ListStaff";
			this->Text = L"ListStaff";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void BtnAddStaff_Click(System::Object^ sender, System::EventArgs^ e) {
		Staff^ newStaff = gcnew Staff();
		AddStaff^ addStaffForm = gcnew AddStaff(newStaff, false);
		addStaffForm->ShowDialog();
		System::Diagnostics::Debug::WriteLine(newStaff->ToString());
		staffRepository->insertStaff(newStaff);
		this->reload();
	}

	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Debug::WriteLine(sharedS + " voilà s");
		staffRepository->deleteStaff(sharedS, delOrRestore);
		this->reload();
	}

	private: System::Void BtnModify_Click(System::Object^ sender, System::EventArgs^ e) {
		AddStaff^ formModifStaff = gcnew AddStaff(sharedS, true);
		formModifStaff->ShowDialog();
		staffRepository->editStaff(sharedS);

		int selected = this->DGVSearchStaff->SelectedRows[0]->Index;
		this->reload();
		this->DGVSearchStaff->Rows[selected]->Selected = true;
	}
	
	private: System::Void CBoxDeletedLines_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->reload();
	}
		   	
	private: System::Void DGVSearchStaff_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0) {
		DataGridViewRow^ sharedDgvrRow = DGVSearchStaff->Rows[e->RowIndex];
		sharedS = (Staff^)sharedDgvrRow->Tag;
		System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedS->ToString());
	}
}
};
}