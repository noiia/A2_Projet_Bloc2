#pragma once
#include <iostream>
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
	/// Description r�sum�e de ListClient
	/// </summary>
	public ref class ListClient : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		Client^ sharedC;
		bool cliked;
		bool delOrRestore;
		ClientRepository^ clientRepository;
		Thread^ reloadThread;

		System::Windows::Forms::CheckBox^ CboxDeletedLines;
	private: System::Windows::Forms::Button^ BtnDelete;




		   System::Threading::Mutex^ reloadMutex;

	public:
		ListClient(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			reloadMutex = gcnew System::Threading::Mutex();
			DGVListClient->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcIdClient = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdClient->Name = "ID Client";
			this->DGVListClient->Columns->Add(dgvtbcIdClient);
			
			DataGridViewTextBoxColumn^ dgvtbcCompanyName = gcnew DataGridViewTextBoxColumn();
			dgvtbcCompanyName->Name = "Nom de l'entreprise";
			this->DGVListClient->Columns->Add(dgvtbcCompanyName);

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

			DataGridViewTextBoxColumn^ dgvtbcIdAddressDelivery = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdAddressDelivery->Name = "ID AddressDelivery";
			this->DGVListClient->Columns->Add(dgvtbcIdAddressDelivery);

			DataGridViewTextBoxColumn^ dgvtbcNumberBilling = gcnew DataGridViewTextBoxColumn();
			dgvtbcNumberBilling->Name = "NumberBilling";
			this->DGVListClient->Columns->Add(dgvtbcNumberBilling);

			DataGridViewTextBoxColumn^ dgvtbcStreetBilling = gcnew DataGridViewTextBoxColumn();
			dgvtbcStreetBilling->Name = "StreetBilling";
			this->DGVListClient->Columns->Add(dgvtbcStreetBilling);

			DataGridViewTextBoxColumn^ dgvtbcCityBilling = gcnew DataGridViewTextBoxColumn();
			dgvtbcCityBilling->Name = "CityBilling";
			this->DGVListClient->Columns->Add(dgvtbcCityBilling);

			DataGridViewTextBoxColumn^ dgvtbcPostalCodeBilling = gcnew DataGridViewTextBoxColumn();
			dgvtbcPostalCodeBilling->Name = "PostalCodeBilling";
			this->DGVListClient->Columns->Add(dgvtbcPostalCodeBilling);

			DataGridViewTextBoxColumn^ dgvtbcAdditionBilling = gcnew DataGridViewTextBoxColumn();
			dgvtbcAdditionBilling->Name = "AdditionBilling";
			this->DGVListClient->Columns->Add(dgvtbcAdditionBilling);

			DataGridViewTextBoxColumn^ dgvtbcIdAddressBilling = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdAddressBilling->Name = "ID AddressBilling";
			this->DGVListClient->Columns->Add(dgvtbcIdAddressBilling);

			DataGridViewTextBoxColumn^ dgvtbcNumberDelivery = gcnew DataGridViewTextBoxColumn();
			dgvtbcNumberDelivery->Name = "NumberDelivery";
			this->DGVListClient->Columns->Add(dgvtbcNumberDelivery);

			DataGridViewTextBoxColumn^ dgvtbcStreetDelivery = gcnew DataGridViewTextBoxColumn();
			dgvtbcStreetDelivery->Name = "StreetDelivery";
			this->DGVListClient->Columns->Add(dgvtbcStreetDelivery);

			DataGridViewTextBoxColumn^ dgvtbcCityDelivery = gcnew DataGridViewTextBoxColumn();
			dgvtbcCityDelivery->Name = "CityDelivery";
			this->DGVListClient->Columns->Add(dgvtbcCityDelivery);

			DataGridViewTextBoxColumn^ dgvtbcPostalCodeDelivery = gcnew DataGridViewTextBoxColumn();
			dgvtbcPostalCodeDelivery->Name = "PostalCodeDelivery";
			this->DGVListClient->Columns->Add(dgvtbcPostalCodeDelivery);

			DataGridViewTextBoxColumn^ dgvtbcAdditionDelivery = gcnew DataGridViewTextBoxColumn();
			dgvtbcAdditionDelivery->Name = "AdditionDelivery";
			this->DGVListClient->Columns->Add(dgvtbcAdditionDelivery);



			clientRepository = gcnew ClientRepository(mabdd);
			this->reload();

		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Client^>^ clients = clientRepository->getClient(this->CboxDeletedLines->Checked);
				this->DGVListClient->Rows->Clear();
				for each (Client ^ c in clients) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdClient = gcnew DataGridViewTextBoxCell();
					dgvcIdClient->Value = c->getID_Client();
					dgvr->Cells->Add(dgvcIdClient);
					
					DataGridViewTextBoxCell^ dgvcCompanyName = gcnew DataGridViewTextBoxCell();
					dgvcCompanyName->Value = c->getCompanyName();
					dgvr->Cells->Add(dgvcCompanyName);

					DataGridViewTextBoxCell^ dgvcFirstName = gcnew DataGridViewTextBoxCell();
					dgvcFirstName->Value = c->getFirstName();
					dgvr->Cells->Add(dgvcFirstName);

					DataGridViewTextBoxCell^ dgvcLastName = gcnew DataGridViewTextBoxCell();
					dgvcLastName->Value = c->getLastName();
					dgvr->Cells->Add(dgvcLastName);

					DataGridViewTextBoxCell^ dgvcBirthDay = gcnew DataGridViewTextBoxCell();
					DateTime^ birthday = c->getBirthday();
					if (birthday != nullptr) {
						dgvcBirthDay->Value = birthday->ToString("yyyy-MM-dd");
					}
					else {
						dgvcBirthDay->Value = "";
					}
					dgvr->Cells->Add(dgvcBirthDay);


					DataGridViewTextBoxCell^ dgvcTypeClient = gcnew DataGridViewTextBoxCell();
					dgvcTypeClient->Value = c->getTypeClient();
					dgvr->Cells->Add(dgvcTypeClient);

					DataGridViewTextBoxCell^ dgvcIdAddressDelivery = gcnew DataGridViewTextBoxCell();
					dgvcIdAddressDelivery->Value = c->getID_AddressDelivery();
					dgvr->Cells->Add(dgvcIdAddressDelivery);

					DataGridViewTextBoxCell^ dgvcNumberBilling = gcnew DataGridViewTextBoxCell();
					dgvcNumberBilling->Value = c->getNumberBilling();
					dgvr->Cells->Add(dgvcNumberBilling);

					DataGridViewTextBoxCell^ dgvcNameStreetBilling = gcnew DataGridViewTextBoxCell();
					dgvcNameStreetBilling->Value = c->getNameStreetBilling();
					dgvr->Cells->Add(dgvcNameStreetBilling);

					DataGridViewTextBoxCell^ dgvcNameCityBilling = gcnew DataGridViewTextBoxCell();
					dgvcNameCityBilling->Value = c->getNameCityBilling();
					dgvr->Cells->Add(dgvcNameCityBilling);

					DataGridViewTextBoxCell^ dgvcPostalCodeBilling = gcnew DataGridViewTextBoxCell();
					dgvcPostalCodeBilling->Value = c->getPostalCodeBilling();
					dgvr->Cells->Add(dgvcPostalCodeBilling);

					DataGridViewTextBoxCell^ dgvcAdditionBilling = gcnew DataGridViewTextBoxCell();
					dgvcAdditionBilling->Value = c->getAdditionBilling();
					dgvr->Cells->Add(dgvcAdditionBilling);

					DataGridViewTextBoxCell^ dgvcIdAddressBilling = gcnew DataGridViewTextBoxCell();
					dgvcIdAddressBilling->Value = c->getID_AddressBilling();
					dgvr->Cells->Add(dgvcIdAddressBilling);

					DataGridViewTextBoxCell^ dgvcNumberDelivery = gcnew DataGridViewTextBoxCell();
					dgvcNumberDelivery->Value = c->getNumberDelivery();
					dgvr->Cells->Add(dgvcNumberDelivery);

					DataGridViewTextBoxCell^ dgvcNameStreetDelivery = gcnew DataGridViewTextBoxCell();
					dgvcNameStreetDelivery->Value = c->getNameStreetDelivery();
					dgvr->Cells->Add(dgvcNameStreetDelivery);

					DataGridViewTextBoxCell^ dgvcNameCityDelivery = gcnew DataGridViewTextBoxCell();
					dgvcNameCityDelivery->Value = c->getNameCityDelivery();
					dgvr->Cells->Add(dgvcNameCityDelivery);

					DataGridViewTextBoxCell^ dgvcPostalCodeDelivery = gcnew DataGridViewTextBoxCell();
					dgvcPostalCodeDelivery->Value = c->getPostalCodeDelivery();
					dgvr->Cells->Add(dgvcPostalCodeDelivery);

					DataGridViewTextBoxCell^ dgvcAdditionDelivery = gcnew DataGridViewTextBoxCell();
					dgvcAdditionDelivery->Value = c->getAdditionDelivery();
					dgvr->Cells->Add(dgvcAdditionDelivery);


					dgvr->Tag = c;
					this->DGVListClient->Rows->Add(dgvr);


					this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->BtnDelete->Size = System::Drawing::Size(135, 48);
					this->BtnDelete->TabIndex = 28;
					this->BtnDelete->UseVisualStyleBackColor = true;
					this->BtnDelete->Click += gcnew System::EventHandler(this, &ListClient::BtnDelete_Click);

					if (this->CboxDeletedLines->Checked) {
						this->BtnDelete->Text = L"Restaurer";
						this->BtnDelete->Location = System::Drawing::Point(691, 501);
						System::Diagnostics::Debug::WriteLine("restaurer");
						delOrRestore = 0;
					}
					else {
						this->BtnDelete->Text = L"Supprimer";
						this->BtnDelete->Location = System::Drawing::Point(691, 501);
						System::Diagnostics::Debug::WriteLine("supprimer");
						delOrRestore = 1;
					}

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
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~ListClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnModify;
		   System::Windows::Forms::Button^ BtnAddClient;
		   System::Windows::Forms::DataGridView^ DGVListClient;
		   System::Windows::Forms::Label^ Title;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ListClient::typeid));
			this->BtnModify = (gcnew System::Windows::Forms::Button());
			this->BtnAddClient = (gcnew System::Windows::Forms::Button());
			this->DGVListClient = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->CboxDeletedLines = (gcnew System::Windows::Forms::CheckBox());
			this->BtnDelete = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVListClient))->BeginInit();
			this->SuspendLayout();
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(691, 431);
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
			this->DGVListClient->ReadOnly = true;
			this->DGVListClient->Size = System::Drawing::Size(648, 526);
			this->DGVListClient->TabIndex = 25;
			this->DGVListClient->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &ListClient::DGVListClient_CellMouseClick);
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
			// CboxDeletedLines
			// 
			this->CboxDeletedLines->AutoSize = true;
			this->CboxDeletedLines->Font = (gcnew System::Drawing::Font(L"Orkney", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CboxDeletedLines->Location = System::Drawing::Point(691, 396);
			this->CboxDeletedLines->Name = L"CboxDeletedLines";
			this->CboxDeletedLines->Size = System::Drawing::Size(143, 20);
			this->CboxDeletedLines->TabIndex = 29;
			this->CboxDeletedLines->Text = L"Clients supprimées";
			this->CboxDeletedLines->UseVisualStyleBackColor = true;
			this->CboxDeletedLines->CheckedChanged += gcnew System::EventHandler(this, &ListClient::CBoxDeletedElements_CheckedChanged);
			// 
			// BtnDelete
			// 
			this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnDelete->Location = System::Drawing::Point(691, 501);
			this->BtnDelete->Name = L"BtnDelete";
			this->BtnDelete->Size = System::Drawing::Size(135, 48);
			this->BtnDelete->TabIndex = 30;
			this->BtnDelete->Text = L"Supprimer";
			this->BtnDelete->UseVisualStyleBackColor = true;
			// 
			// ListClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 623);
			this->Controls->Add(this->BtnDelete);
			this->Controls->Add(this->CboxDeletedLines);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddClient);
			this->Controls->Add(this->DGVListClient);
			this->Controls->Add(this->Title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ListClient";
			this->Text = L"TurboStock";
			this->Load += gcnew System::EventHandler(this, &ListClient::ListClient_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVListClient))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnAddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		Client^ client = gcnew Client();
		AddClient^ addClientForm = gcnew AddClient(client, false);
		addClientForm->ShowDialog();
		clientRepository->insertClient(client);
		this->reload();
	}
	private: System::Void BtnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Debug::WriteLine(sharedC + " voilà c");
		clientRepository->deleteClient(sharedC, delOrRestore);
		this->reload();
	}
	private: System::Void BtnModify_Click(System::Object^ sender, System::EventArgs^ e) {
		AddClient^ formModifClient = gcnew AddClient(sharedC, true);
		formModifClient->ShowDialog();
		clientRepository->editClient(sharedC);

		int selected = this->DGVListClient->SelectedRows[0]->Index;
		this->reload();
		this->DGVListClient->Rows[selected]->Selected = true;
	}
	private: System::Void CBoxDeletedElements_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->reload();


	}
	private: System::Void DGVListClient_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVListClient->Rows[e->RowIndex];
			sharedC = (Client^)sharedDgvrRow->Tag;
			System::Diagnostics::Debug::WriteLine("cliqué sur " + sharedC->ToString());

		}
	}
	private: System::Void ListClient_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}