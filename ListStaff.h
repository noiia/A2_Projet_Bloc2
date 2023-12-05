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
		Thread^ reloadThread;
	private: System::Threading::Mutex^ reloadMutex;
	private: System::Windows::Forms::Button^ BtnDelete;
		   StaffRepository^ staffRepository;

	public:
		ListStaff(BDD^ mabdd)
		{
			InitializeComponent();

			reloadMutex = gcnew System::Threading::Mutex();

			DGVSearchStaff->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcLastName = gcnew DataGridViewTextBoxColumn();
			dgvtbcLastName->Name = "Nom";
			this->DGVSearchStaff->Columns->Add(dgvtbcLastName);
			DataGridViewTextBoxColumn^ dgvtbcFirstName = gcnew DataGridViewTextBoxColumn();
			dgvtbcFirstName->Name = "Prenom";
			this->DGVSearchStaff->Columns->Add(dgvtbcFirstName);
			DataGridViewTextBoxColumn^ dgvtbcAddress = gcnew DataGridViewTextBoxColumn();
			dgvtbcAddress->Name = "Adresse";
			this->DGVSearchStaff->Columns->Add(dgvtbcAddress);
			DataGridViewTextBoxColumn^ dgvtbcSupervisor = gcnew DataGridViewTextBoxColumn();
			dgvtbcSupervisor->Name = "Supérieur hierarchique ";
			this->DGVSearchStaff->Columns->Add(dgvtbcSupervisor);

			staffRepository = gcnew StaffRepository(mabdd);
			this->reload();
		}

		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Staff^>^ staff = staffRepository->getStaff();
				this->DGVSearchStaff->Rows->Clear();
				for each (Staff ^ s in staff) {
					if (s->getDel() == false) {
						DataGridViewRow^ dgvr = gcnew DataGridViewRow();
						DataGridViewTextBoxCell^ dgvcLastName = gcnew DataGridViewTextBoxCell();
						dgvcLastName->Value = s->getLastName();
						dgvr->Cells->Add(dgvcLastName);
						DataGridViewTextBoxCell^ dgvcFirstName = gcnew DataGridViewTextBoxCell();
						dgvcFirstName->Value = s->getFirstName();
						dgvr->Cells->Add(dgvcFirstName);
						DataGridViewTextBoxCell^ dgvcAddress = gcnew DataGridViewTextBoxCell();
						dgvcAddress->Value = s->getAddress();
						dgvr->Cells->Add(dgvcAddress);
						DataGridViewTextBoxCell^ dgvcSupervisor = gcnew DataGridViewTextBoxCell();
						dgvcSupervisor->Value = s->getSupervisor();
						dgvr->Cells->Add(dgvcSupervisor);

						dgvr->Tag = s;
						this->DGVSearchStaff->Rows->Add(dgvr);
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
			this->BtnModify = (gcnew System::Windows::Forms::Button());
			this->BtnAddStaff = (gcnew System::Windows::Forms::Button());
			this->DGVSearchStaff = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchStaff))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(921, 561);
			this->BtnModify->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->BtnModify->Name = L"BtnModify";
			this->BtnModify->Size = System::Drawing::Size(180, 59);
			this->BtnModify->TabIndex = 27;
			this->BtnModify->Text = L"Modifier";
			this->BtnModify->UseVisualStyleBackColor = true;
			// 
			// BtnAddStaff
			// 
			this->BtnAddStaff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddStaff->Location = System::Drawing::Point(921, 100);
			this->BtnAddStaff->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->BtnAddStaff->Name = L"BtnAddStaff";
			this->BtnAddStaff->Size = System::Drawing::Size(180, 59);
			this->BtnAddStaff->TabIndex = 26;
			this->BtnAddStaff->Text = L"Ajouter";
			this->BtnAddStaff->UseVisualStyleBackColor = true;
			this->BtnAddStaff->Click += gcnew System::EventHandler(this, &ListStaff::BtnAddStaff_Click);
			// 
			// DGVSearchStaff
			// 
			this->DGVSearchStaff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVSearchStaff->Location = System::Drawing::Point(35, 69);
			this->DGVSearchStaff->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->DGVSearchStaff->Name = L"DGVSearchStaff";
			this->DGVSearchStaff->Size = System::Drawing::Size(804, 647);
			this->DGVSearchStaff->TabIndex = 25;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(423, 11);
			this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(239, 29);
			this->Title->TabIndex = 24;
			this->Title->Text = L"Liste des employés";
			// 
			// ListStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1185, 767);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddStaff);
			this->Controls->Add(this->DGVSearchStaff);
			this->Controls->Add(this->Title);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"ListStaff";
			this->Text = L"ListStaff";
			this->Load += gcnew System::EventHandler(this, &ListStaff::ListStaff_Load);
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

	private: System::Void DGVSearchStaff_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVSearchStaff->Rows[e->RowIndex];
			sharedS = (Staff^)sharedDgvrRow->Tag;
			System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedS);

		}
	}

	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Debug::WriteLine(sharedS + " voilà s");
		staffRepository->deleteStaff(sharedS);
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

	private: System::Void ListStaff_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}