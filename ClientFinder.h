#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "Client.h"
#include "Cart.h"
#include "ClientFinderRepository.h"
#include "Command.h"
#include "BDD.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Description résumée de ClientFinder
	/// </summary>
	public ref class ClientFinder : public System::Windows::Forms::Form
	{
	private:
		BDD^ mabdd;
		Thread^ reloadThread;
		Client^ clickedClient;
		bool clicked;
		ClientFinderRepository^ clientToCommand;
		String^ sharedSearchedValue;
		String^ sharedSearchedValue2;
		int research;
		Command^ command;

		System::Threading::Mutex^ reloadMutex;

	public:
		ClientFinder(BDD^ mabdd, Command^ command)
		{
			this->command = command;
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			reloadMutex = gcnew System::Threading::Mutex();

			DGVSearchClient->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcIdClient = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdClient->Name = "Références";
			this->DGVSearchClient->Columns->Add(dgvtbcIdClient);
			DataGridViewTextBoxColumn^ dgvtbcLastName = gcnew DataGridViewTextBoxColumn();
			dgvtbcLastName->Name = "Nom";
			this->DGVSearchClient->Columns->Add(dgvtbcLastName);
			DataGridViewTextBoxColumn^ dgvtbcFirstName = gcnew DataGridViewTextBoxColumn();
			dgvtbcFirstName->Name = "Prénom";
			this->DGVSearchClient->Columns->Add(dgvtbcFirstName);
			DataGridViewTextBoxColumn^ dgvtbcTypeClient = gcnew DataGridViewTextBoxColumn();
			dgvtbcTypeClient->Name = "Type de clients";
			this->DGVSearchClient->Columns->Add(dgvtbcTypeClient);
			DataGridViewTextBoxColumn^ dgvtbcBirthday = gcnew DataGridViewTextBoxColumn();
			dgvtbcBirthday->Name = "Anniversaire du client";
			this->DGVSearchClient->Columns->Add(dgvtbcBirthday);

			clientToCommand = gcnew ClientFinderRepository(mabdd);

			this->reload();

		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Diagnostics::Debug::WriteLine(sharedSearchedValue);
				System::Collections::Generic::List<Client^>^ clients = clientToCommand->getClient(sharedSearchedValue,sharedSearchedValue2, research);
				this->DGVSearchClient->Rows->Clear();
				for each (Client ^ c in clients) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdClient = gcnew DataGridViewTextBoxCell();
					dgvcIdClient->Value = c->getID_Client();
					dgvr->Cells->Add(dgvcIdClient);
					DataGridViewTextBoxCell^ dgvcLastName = gcnew DataGridViewTextBoxCell();
					dgvcLastName->Value = c->getLastName();
					dgvr->Cells->Add(dgvcLastName);
					DataGridViewTextBoxCell^ dgvcFirstName = gcnew DataGridViewTextBoxCell();
					dgvcFirstName->Value = c->getFirstName();
					dgvr->Cells->Add(dgvcFirstName);
					DataGridViewTextBoxCell^ dgvcTypeClient = gcnew DataGridViewTextBoxCell();
					dgvcTypeClient->Value = Convert::ToString(c->getTypeClient());
					dgvr->Cells->Add(dgvcTypeClient);
					DataGridViewTextBoxCell^ dgvcBirthday = gcnew DataGridViewTextBoxCell();
					DateTime^ Birthday = c->getBirthday();
					if (Birthday != nullptr) {
						dgvcBirthday->Value = Birthday->ToString("yyyy-MM-dd");
					}
					else {
						dgvcBirthday->Value = "";
					}
					dgvr->Cells->Add(dgvcBirthday);
					dgvr->Tag = c;
					this->DGVSearchClient->Rows->Add(dgvr);
				}
				reloadMutex->ReleaseMutex();
			}
		}
		void launchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &ClientFinder::reload));
			reloadThread->Start();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ClientFinder()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ DGVSearchClient;
		   System::Windows::Forms::Label^ Title;
		   System::Windows::Forms::Label^ LbClientSelected;
		   System::Windows::Forms::Button^ BtnResearchClient;
		   System::Windows::Forms::TextBox^ TboxLastName;
		   System::Windows::Forms::Label^ LbLastNameClient;
		   System::Windows::Forms::Button^ BtnAddCommand;
		   System::Windows::Forms::TextBox^ TboxIDClient;
		   System::Windows::Forms::Label^ LbIdClient;
		   System::Windows::Forms::TextBox^ TboxFirstName;
		   System::Windows::Forms::Label^ LbFirstNameClient;
		   System::Windows::Forms::Label^ LbOr;
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
			   this->DGVSearchClient = (gcnew System::Windows::Forms::DataGridView());
			   this->Title = (gcnew System::Windows::Forms::Label());
			   this->LbClientSelected = (gcnew System::Windows::Forms::Label());
			   this->BtnResearchClient = (gcnew System::Windows::Forms::Button());
			   this->TboxLastName = (gcnew System::Windows::Forms::TextBox());
			   this->LbLastNameClient = (gcnew System::Windows::Forms::Label());
			   this->BtnAddCommand = (gcnew System::Windows::Forms::Button());
			   this->TboxIDClient = (gcnew System::Windows::Forms::TextBox());
			   this->LbIdClient = (gcnew System::Windows::Forms::Label());
			   this->TboxFirstName = (gcnew System::Windows::Forms::TextBox());
			   this->LbFirstNameClient = (gcnew System::Windows::Forms::Label());
			   this->LbOr = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchClient))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // DGVSearchClient
			   // 
			   this->DGVSearchClient->AllowUserToAddRows = false;
			   this->DGVSearchClient->AllowUserToDeleteRows = false;
			   this->DGVSearchClient->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->DGVSearchClient->Location = System::Drawing::Point(382, 60);
			   this->DGVSearchClient->Name = L"DGVSearchClient";
			   this->DGVSearchClient->ReadOnly = true;
			   this->DGVSearchClient->Size = System::Drawing::Size(604, 430);
			   this->DGVSearchClient->TabIndex = 0;
			   this->DGVSearchClient->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &ClientFinder::DGVSearchClient_CellMouseDoubleClick);

			   // 
			   // Title
			   // 
			   this->Title->AutoSize = true;
			   this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Title->Location = System::Drawing::Point(407, 9);
			   this->Title->Name = L"Title";
			   this->Title->Size = System::Drawing::Size(227, 29);
			   this->Title->TabIndex = 2;
			   this->Title->Text = L"Recherche du client";
			   // 
			   // LbClientSelected
			   // 
			   this->LbClientSelected->AutoSize = true;
			   this->LbClientSelected->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbClientSelected->Location = System::Drawing::Point(20, 417);
			   this->LbClientSelected->Name = L"LbClientSelected";
			   this->LbClientSelected->Size = System::Drawing::Size(150, 19);
			   this->LbClientSelected->TabIndex = 38;
			   this->LbClientSelected->Text = L"Client sélectionné :";
			   // 
			   // BtnResearchClient
			   // 
			   this->BtnResearchClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnResearchClient->Location = System::Drawing::Point(125, 341);
			   this->BtnResearchClient->Name = L"BtnResearchClient";
			   this->BtnResearchClient->Size = System::Drawing::Size(111, 42);
			   this->BtnResearchClient->TabIndex = 37;
			   this->BtnResearchClient->Text = L"Rechercher";
			   this->BtnResearchClient->UseVisualStyleBackColor = true;
			   this->BtnResearchClient->Click += gcnew System::EventHandler(this, &ClientFinder::BtnResearchClient_Click);

			   // 
			   // TboxLastName
			   // 
			   this->TboxLastName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TboxLastName->Location = System::Drawing::Point(24, 183);
			   this->TboxLastName->Name = L"TboxLastName";
			   this->TboxLastName->Size = System::Drawing::Size(315, 26);
			   this->TboxLastName->TabIndex = 36;
			   // 
			   // LbLastNameClient
			   // 
			   this->LbLastNameClient->AutoSize = true;
			   this->LbLastNameClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbLastNameClient->Location = System::Drawing::Point(20, 161);
			   this->LbLastNameClient->Name = L"LbLastNameClient";
			   this->LbLastNameClient->Size = System::Drawing::Size(112, 19);
			   this->LbLastNameClient->TabIndex = 35;
			   this->LbLastNameClient->Text = L"Nom du client";
			   // 
			   // BtnAddCommand
			   // 
			   this->BtnAddCommand->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnAddCommand->Location = System::Drawing::Point(842, 510);
			   this->BtnAddCommand->Name = L"BtnAddCommand";
			   this->BtnAddCommand->Size = System::Drawing::Size(111, 42);
			   this->BtnAddCommand->TabIndex = 34;
			   this->BtnAddCommand->Text = L"Ajouter";
			   this->BtnAddCommand->UseVisualStyleBackColor = true;
			   this->BtnAddCommand->Click += gcnew System::EventHandler(this, &ClientFinder::BtnAddClient_Click);

			   // 
			   // TboxIDClient
			   // 
			   this->TboxIDClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TboxIDClient->Location = System::Drawing::Point(24, 82);
			   this->TboxIDClient->Name = L"TboxIDClient";
			   this->TboxIDClient->Size = System::Drawing::Size(315, 26);
			   this->TboxIDClient->TabIndex = 33;
			   // 
			   // LbIdClient
			   // 
			   this->LbIdClient->AutoSize = true;
			   this->LbIdClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbIdClient->Location = System::Drawing::Point(20, 60);
			   this->LbIdClient->Name = L"LbIdClient";
			   this->LbIdClient->Size = System::Drawing::Size(79, 19);
			   this->LbIdClient->TabIndex = 32;
			   this->LbIdClient->Text = L"ID_Client";
			   // 
			   // TboxFirstName
			   // 
			   this->TboxFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TboxFirstName->Location = System::Drawing::Point(24, 263);
			   this->TboxFirstName->Name = L"TboxFirstName";
			   this->TboxFirstName->Size = System::Drawing::Size(315, 26);
			   this->TboxFirstName->TabIndex = 40;
			   // 
			   // LbFirstNameClient
			   // 
			   this->LbFirstNameClient->AutoSize = true;
			   this->LbFirstNameClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbFirstNameClient->Location = System::Drawing::Point(20, 241);
			   this->LbFirstNameClient->Name = L"LbFirstNameClient";
			   this->LbFirstNameClient->Size = System::Drawing::Size(133, 19);
			   this->LbFirstNameClient->TabIndex = 39;
			   this->LbFirstNameClient->Text = L"Prénom du client";
			   // 
			   // LbOr
			   // 
			   this->LbOr->AutoSize = true;
			   this->LbOr->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbOr->Location = System::Drawing::Point(163, 126);
			   this->LbOr->Name = L"LbOr";
			   this->LbOr->Size = System::Drawing::Size(32, 19);
			   this->LbOr->TabIndex = 41;
			   this->LbOr->Text = L"Ou";
			   // 
			   // ClientFinder
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->MaximizeBox = false;
			   this->ClientSize = System::Drawing::Size(1015, 589);
			   this->Controls->Add(this->LbOr);
			   this->Controls->Add(this->TboxFirstName);
			   this->Controls->Add(this->LbFirstNameClient);
			   this->Controls->Add(this->LbClientSelected);
			   this->Controls->Add(this->BtnResearchClient);
			   this->Controls->Add(this->TboxLastName);
			   this->Controls->Add(this->LbLastNameClient);
			   this->Controls->Add(this->BtnAddCommand);
			   this->Controls->Add(this->TboxIDClient);
			   this->Controls->Add(this->LbIdClient);
			   this->Controls->Add(this->Title);
			   this->Controls->Add(this->DGVSearchClient);
			   this->Name = L"ClientFinder";
			   this->Text = L"ClientFinder";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVSearchClient))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void BtnResearchClient_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->TboxIDClient->Text != "" && (this->TboxFirstName->Text == "" && this->TboxLastName->Text == "")) {
			System::Diagnostics::Debug::WriteLine(this->TboxIDClient->Text);
			sharedSearchedValue = this->TboxIDClient->Text;
			research = 1;
			this->reload();
		}
		else if (this->TboxIDClient->Text == "" && (this->TboxFirstName->Text == "" && this->TboxLastName->Text != "")) {
			System::Diagnostics::Debug::WriteLine(this->TboxLastName->Text);
			sharedSearchedValue = this->TboxLastName->Text;
			research = 2;
			this->reload();
		}else if (this->TboxIDClient->Text == "" && (this->TboxFirstName->Text != "" && this->TboxLastName->Text == "")) {
			System::Diagnostics::Debug::WriteLine(this->TboxFirstName->Text);
			sharedSearchedValue2 = this->TboxFirstName->Text;
			research = 3;
			this->reload();
		}
		else if (this->TboxIDClient->Text == "" && (this->TboxFirstName->Text != "" && this->TboxLastName->Text != "")) {
			System::Diagnostics::Debug::WriteLine(this->TboxFirstName->Text);
			System::Diagnostics::Debug::WriteLine(this->TboxLastName->Text);
			sharedSearchedValue = this->TboxLastName->Text;
			sharedSearchedValue2 = this->TboxFirstName->Text;
			research = 4;
			this->reload();
		}
		else {
			research = 0;
		}
	}
	private: System::Void DGVSearchClient_CellMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ sharedDgvrRow = DGVSearchClient->Rows[e->RowIndex];
			clickedClient = (Client^)sharedDgvrRow->Tag;
			this->LbClientSelected->Text = "Client sélectionnée :\n " + clickedClient->getID_Client() + "\n" + clickedClient->getLastName() + "\n" + clickedClient->getFirstName() + "\n" + clickedClient->getTypeClient();
			clicked = true;
		}

	}
	private: System::Void BtnAddClient_Click(System::Object^ sender, System::EventArgs^ e) {
		if (clicked) {
			this->command->setIdClient(this->clickedClient->getID_Client());
			this->command->setLastNameClient(this->clickedClient->getLastName());
			this->command->setFirstNameClient(this->clickedClient->getFirstName());
			//this->command->setReference("");
			//this->command->setQuantity(Convert::ToInt32(this->NudQuantity->Value));
			this->Close();
		}
	}
	};
}
