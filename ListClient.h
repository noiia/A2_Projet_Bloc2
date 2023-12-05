#pragma once
#include <thread>
#include <mutex>
#include "BDD.h"
#include "AddClient.h"
#include "ClientRepository.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Description résumée de ListClient
	/// </summary>
	public ref class ListClient : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		Client^ sharedC;
		ClientRepository^ clientRepository;
		Thread^ reloadThread;
	private: System::Windows::Forms::Button^ BtnDelete;
	private: System::Windows::Forms::CheckBox^ CBoxDeletedElements;

		   System::Threading::Mutex^ reloadMutex;

	public:
		ListClient(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			reloadMutex = gcnew System::Threading::Mutex();
			DataGridViewTextBoxColumn^ dgvtbcIdClient = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdClient->Name = "ID Client";
			this->DGVListClient->Columns->Add(dgvtbcIdClient);
			DataGridViewTextBoxColumn^ dgvtbcFirstName = gcnew DataGridViewTextBoxColumn();
			dgvtbcFirstName->Name = "FirstName";
			this->DGVListClient->Columns->Add(dgvtbcFirstName);
			DataGridViewTextBoxColumn^ dgvtbcLastName = gcnew DataGridViewTextBoxColumn();
			dgvtbcLastName->Name = "LastName";
			this->DGVListClient->Columns->Add(dgvtbcLastName);
			DataGridViewTextBoxColumn^ dgvtbcBirthDay = gcnew DataGridViewTextBoxColumn();
			dgvtbcBirthDay->Name = "BirthDay";
			this->DGVListClient->Columns->Add(dgvtbcBirthDay);
			DataGridViewTextBoxColumn^ dgvtbcTypeClient = gcnew DataGridViewTextBoxColumn();
			dgvtbcTypeClient->Name = "TypeClient";
			this->DGVListClient->Columns->Add(dgvtbcTypeClient);

			clientRepository = gcnew ClientRepository(mabdd);
			this->reload();

		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Client^>^ clients = clientRepository->getClient(this->CBoxDeletedElements->Checked);
				this->DGVListClient->Rows->Clear();
				for each (Client ^ c in clients) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdClient = gcnew DataGridViewTextBoxCell();
					dgvcIdClient->Value = c->getID_Client();
					dgvr->Cells->Add(dgvcIdClient);
					DataGridViewTextBoxCell^ dgvcFirstName = gcnew DataGridViewTextBoxCell();
					dgvcFirstName->Value = c->getFirstName();
					dgvr->Cells->Add(dgvcFirstName);
					DataGridViewTextBoxCell^ dgvcLastName = gcnew DataGridViewTextBoxCell();
					dgvcLastName->Value = c->getLastName();
					dgvr->Cells->Add(dgvcLastName);
					DataGridViewTextBoxCell^ dgvcBirthDay = gcnew DataGridViewTextBoxCell();
					DateTime^ birthday = c->getBirthday();
					dgvcBirthDay->Value = birthday->ToString("yyyy-MM-dd");
					dgvr->Cells->Add(dgvcBirthDay);
					DataGridViewTextBoxCell^ dgvcTypeClient = gcnew DataGridViewTextBoxCell();
					dgvcTypeClient->Value = c->getTypeClient();
					dgvr->Cells->Add(dgvcTypeClient);
					dgvr->Tag = c;
					this->DGVListClient->Rows->Add(dgvr);
				}
				reloadMutex->ReleaseMutex();
			}
		}
		void launchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &ListClient::reload));
			reloadThread->Start();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ListClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnModify;
	private: System::Windows::Forms::Button^ BtnAddClient;
	private: System::Windows::Forms::DataGridView^ DGVListClient;
	protected:


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
			this->BtnAddClient = (gcnew System::Windows::Forms::Button());
			this->DGVListClient = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BtnDelete = (gcnew System::Windows::Forms::Button());
			this->CBoxDeletedElements = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVListClient))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(691, 466);
			this->BtnModify->Name = L"BtnModify";
			this->BtnModify->Size = System::Drawing::Size(135, 48);
			this->BtnModify->TabIndex = 27;
			this->BtnModify->Text = L"Modifier";
			this->BtnModify->UseVisualStyleBackColor = true;
			this->BtnModify->Click += gcnew System::EventHandler(this, &ListClient::BtnModify_Click);
			// 
			// BtnAddClient
			// 
			this->BtnAddClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddClient->Location = System::Drawing::Point(691, 114);
			this->BtnAddClient->Name = L"BtnAddClient";
			this->BtnAddClient->Size = System::Drawing::Size(135, 48);
			this->BtnAddClient->TabIndex = 26;
			this->BtnAddClient->Text = L"Ajouter";
			this->BtnAddClient->UseVisualStyleBackColor = true;
			this->BtnAddClient->Click += gcnew System::EventHandler(this, &ListClient::BtnAddClient_Click);
			// 
			// DGVListClient
			// 
			this->DGVListClient->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVListClient->Location = System::Drawing::Point(26, 56);
			this->DGVListClient->Name = L"DGVListClient";
			this->DGVListClient->Size = System::Drawing::Size(603, 526);
			this->DGVListClient->TabIndex = 25;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(317, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(201, 28);
			this->Title->TabIndex = 24;
			this->Title->Text = L"Liste des clients";
			// 
			// BtnDelete
			// 
			this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnDelete->Location = System::Drawing::Point(690, 537);
			this->BtnDelete->Name = L"BtnDelete";
			this->BtnDelete->Size = System::Drawing::Size(136, 45);
			this->BtnDelete->TabIndex = 28;
			this->BtnDelete->Text = L"Supprimer";
			this->BtnDelete->UseVisualStyleBackColor = true;
			this->BtnDelete->Click += gcnew System::EventHandler(this, &ListClient::BtnDelete_Click);
			// 
			// CBoxDeletedElements
			// 
			this->CBoxDeletedElements->AutoSize = true;
			this->CBoxDeletedElements->Location = System::Drawing::Point(721, 424);
			this->CBoxDeletedElements->Name = L"CBoxDeletedElements";
			this->CBoxDeletedElements->Size = System::Drawing::Size(80, 17);
			this->CBoxDeletedElements->TabIndex = 29;
			this->CBoxDeletedElements->Text = L"checkBox1";
			this->CBoxDeletedElements->UseVisualStyleBackColor = true;
			// 
			// ListClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 623);
			this->Controls->Add(this->CBoxDeletedElements);
			this->Controls->Add(this->BtnDelete);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddClient);
			this->Controls->Add(this->DGVListClient);
			this->Controls->Add(this->Title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"ListClient";
			this->Text = L"ListClient";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVListClient))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnAddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		Client^ client = gcnew Client();
		AddClient^ addClientForm = gcnew AddClient(client);
		addClientForm->ShowDialog();
		System::Diagnostics::Debug::WriteLine(client->ToString());
		clientRepository->insertClient(client);
		//this->Close();
		this->reload();
	}
	private: System::Void DGVListClient_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVListClient->Rows[e->RowIndex];
			sharedC = (Client^)sharedDgvrRow->Tag;
			System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedC->ToString());
		}
	}

	private: System::Void BtnModify_Click(System::Object^ sender, System::EventArgs^ e) {
		AddClient^ formModifClient = gcnew AddClient(sharedC);
		formModifClient->ShowDialog();
		clientRepository->editClient(sharedC);

		int selected = this->DGVListClient->SelectedRows[0]->Index;
		this->reload();
		this->DGVListClient->Rows[selected]->Selected = true;
	}
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Debug::WriteLine(sharedC + " voilà c");
		clientRepository->deleteClient(sharedC);
		this->reload();
	}

	};
}