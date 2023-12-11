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

	public ref class ListStaff : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		Staff^ sharedS;
		bool delOrRestore;
		Thread^ reloadThread;
		StaffRepository^ staffRepository;
	private: System::Threading::Mutex^ reloadMutex;
		   System::Windows::Forms::CheckBox^ CBoxDeletedLines;
		   System::Windows::Forms::Label^ TitleListStaff;
		   System::Windows::Forms::Button^ BtnDelete;


	public:
		ListStaff(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();

			reloadMutex = gcnew System::Threading::Mutex();

			DGVSearchStaff->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;

			DataGridViewTextBoxColumn^ dgvtbcIDStaff = gcnew DataGridViewTextBoxColumn();
			dgvtbcIDStaff->Name = "IdStaff";
			this->DGVSearchStaff->Columns->Add(dgvtbcIDStaff);
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

			DataGridViewTextBoxColumn^ dgvtbcIdAddress = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdAddress->Name = "ID Address";
			this->DGVSearchStaff->Columns->Add(dgvtbcIdAddress);

			DataGridViewTextBoxColumn^ dgvtbcNumber = gcnew DataGridViewTextBoxColumn();
			dgvtbcNumber->Name = "Number";
			this->DGVSearchStaff->Columns->Add(dgvtbcNumber);

			DataGridViewTextBoxColumn^ dgvtbcStreet = gcnew DataGridViewTextBoxColumn();
			dgvtbcStreet->Name = "Street";
			this->DGVSearchStaff->Columns->Add(dgvtbcStreet);

			DataGridViewTextBoxColumn^ dgvtbcCity = gcnew DataGridViewTextBoxColumn();
			dgvtbcCity->Name = "City";
			this->DGVSearchStaff->Columns->Add(dgvtbcCity);

			DataGridViewTextBoxColumn^ dgvtbcPostalCode = gcnew DataGridViewTextBoxColumn();
			dgvtbcPostalCode->Name = "PostalCode";
			this->DGVSearchStaff->Columns->Add(dgvtbcPostalCode);

			DataGridViewTextBoxColumn^ dgvtbcAddition = gcnew DataGridViewTextBoxColumn();
			dgvtbcAddition->Name = "Addition";
			this->DGVSearchStaff->Columns->Add(dgvtbcAddition);

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
					dgvr->Cells->Add(dgvcIdStaff);

					DataGridViewTextBoxCell^ dgvcLastName = gcnew DataGridViewTextBoxCell();
					dgvcLastName->Value = s->getLastName();
					dgvr->Cells->Add(dgvcLastName);

					DataGridViewTextBoxCell^ dgvcFirstName = gcnew DataGridViewTextBoxCell();
					dgvcFirstName->Value = s->getFirstName();
					dgvr->Cells->Add(dgvcFirstName);

					DataGridViewTextBoxCell^ dgvcHiringDate = gcnew DataGridViewTextBoxCell();
					if (s->getHiringDate() != nullptr) {
						DateTime^ hiringDate = s->getHiringDate();
						dgvcHiringDate->Value = hiringDate->ToString("yyyy-MM-dd");
						dgvr->Cells->Add(dgvcHiringDate);
					}

					DataGridViewTextBoxCell^ dgvtbcIdSupervisor = gcnew DataGridViewTextBoxCell();
					dgvtbcIdSupervisor->Value = s->getIdSupervisor();
					dgvr->Cells->Add(dgvtbcIdSupervisor);

					DataGridViewTextBoxCell^ dgvcIdAddress = gcnew DataGridViewTextBoxCell();
					dgvcIdAddress->Value = s->getID_Address();
					dgvr->Cells->Add(dgvcIdAddress);

					DataGridViewTextBoxCell^ dgvcNumber = gcnew DataGridViewTextBoxCell();
					dgvcNumber->Value = s->getNumber();
					dgvr->Cells->Add(dgvcNumber);

					DataGridViewTextBoxCell^ dgvcNameStreet = gcnew DataGridViewTextBoxCell();
					dgvcNameStreet->Value = s->getNameStreet();
					dgvr->Cells->Add(dgvcNameStreet);

					DataGridViewTextBoxCell^ dgvcNameCity = gcnew DataGridViewTextBoxCell();
					dgvcNameCity->Value = s->getNameCity();
					dgvr->Cells->Add(dgvcNameCity);

					DataGridViewTextBoxCell^ dgvcPostalCode = gcnew DataGridViewTextBoxCell();
					dgvcPostalCode->Value = s->getPostalCode();
					dgvr->Cells->Add(dgvcPostalCode);

					DataGridViewTextBoxCell^ dgvcAddition = gcnew DataGridViewTextBoxCell();
					dgvcAddition->Value = s->getAddition();
					dgvr->Cells->Add(dgvcAddition);


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
		/// Nettoyage des ressources utilis�es.
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->BtnModify->Location = System::Drawing::Point(1017, 351);
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
			this->BtnAddStaff->Location = System::Drawing::Point(1017, 56);
			this->BtnAddStaff->Name = L"BtnAddStaff";
			this->BtnAddStaff->Size = System::Drawing::Size(135, 48);
			this->BtnAddStaff->TabIndex = 26;
			this->BtnAddStaff->Text = L"Ajouter";
			this->BtnAddStaff->UseVisualStyleBackColor = true;
			this->BtnAddStaff->Click += gcnew System::EventHandler(this, &ListStaff::BtnAddStaff_Click);
			// 
			// DGVSearchStaff
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->DGVSearchStaff->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->DGVSearchStaff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVSearchStaff->Cursor = System::Windows::Forms::Cursors::Default;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->DGVSearchStaff->DefaultCellStyle = dataGridViewCellStyle2;
			this->DGVSearchStaff->Location = System::Drawing::Point(26, 56);
			this->DGVSearchStaff->Name = L"DGVSearchStaff";
			this->DGVSearchStaff->ReadOnly = true;
			this->DGVSearchStaff->RowHeadersWidth = 51;
			this->DGVSearchStaff->Size = System::Drawing::Size(944, 526);
			this->DGVSearchStaff->TabIndex = 25;
			this->DGVSearchStaff->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ListStaff::DGVSearchStaff_CellContentClick);
			// 
			// BtnDelete
			// 
			this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnDelete->Location = System::Drawing::Point(1017, 489);
			this->BtnDelete->Name = L"BtnDelete";
			this->BtnDelete->Size = System::Drawing::Size(135, 48);
			this->BtnDelete->TabIndex = 26;
			this->BtnDelete->Text = L"Supprimer";
			this->BtnDelete->UseVisualStyleBackColor = true;
			this->BtnDelete->Click += gcnew System::EventHandler(this, &ListStaff::BtnDelete_Click);
			// 
			// CBoxDeletedLines
			// 
			this->CBoxDeletedLines->AutoSize = true;
			this->CBoxDeletedLines->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CBoxDeletedLines->Location = System::Drawing::Point(985, 438);
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
			this->TitleListStaff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TitleListStaff->Location = System::Drawing::Point(497, 9);
			this->TitleListStaff->Name = L"TitleListStaff";
			this->TitleListStaff->Size = System::Drawing::Size(241, 29);
			this->TitleListStaff->TabIndex = 24;
			this->TitleListStaff->Text = L"Liste des Employés";
			// 
			// ListStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1215, 623);
			this->Controls->Add(this->TitleListStaff);
			this->Controls->Add(this->CBoxDeletedLines);
			this->Controls->Add(this->BtnDelete);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddStaff);
			this->Controls->Add(this->DGVSearchStaff);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"ListStaff";
			this->Text = L"TurboStock";
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
		System::Diagnostics::Debug::WriteLine(sharedS + " voila s");
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

	private: System::Void DGVSearchStaff_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVSearchStaff->Rows[e->RowIndex];
			sharedS = (Staff^)sharedDgvrRow->Tag;
			System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedS->ToString());
		}
	}
};
}