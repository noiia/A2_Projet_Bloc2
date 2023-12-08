#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "BDD.h"
#include "Command.h"
#include "AddressToCommandRepository.h"
namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	/// <summary>
	/// Description résumée de AddAddressToCommand
	/// </summary>
	public ref class AddAddressToCommand : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		AddressToCommandRepository^ addressToCommandRepository;
		Article^ article;
		Thread^ reloadThread;
		String^ sharedSearchedValue = "";
		String^ sharedSearchedValue2 = "";
		Article^ clickedArticle;
		Command^ command;
		bool clicked = false;
		int research = 0;
	private: System::Windows::Forms::Label^ LbOr;
		   System::Threading::Mutex^ reloadMutex;
	public:
		AddAddressToCommand(BDD^ mabdd, Command^ command)
		{
			this->mabdd = mabdd;
			this->command = command;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			reloadMutex = gcnew System::Threading::Mutex();

			DGVDelivery->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcIdAddress = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdAddress->Name = "ID Adresse";
			this->DGVDelivery->Columns->Add(dgvtbcIdAddress);
			DataGridViewTextBoxColumn^ dgvtbcNumber = gcnew DataGridViewTextBoxColumn();
			dgvtbcNumber->Name = "Numéro";
			this->DGVDelivery->Columns->Add(dgvtbcNumber);
			DataGridViewTextBoxColumn^ dgvtbcNameStreet = gcnew DataGridViewTextBoxColumn();
			dgvtbcNameStreet->Name = "Nom de la rue";
			this->DGVDelivery->Columns->Add(dgvtbcNameStreet);
			DataGridViewTextBoxColumn^ dgvtbcNameCity = gcnew DataGridViewTextBoxColumn();
			dgvtbcNameCity->Name = "Ville";
			this->DGVDelivery->Columns->Add(dgvtbcNameCity);
			DataGridViewTextBoxColumn^ dgvtbcPostalCode = gcnew DataGridViewTextBoxColumn();
			dgvtbcPostalCode->Name = "Code postal";
			this->DGVDelivery->Columns->Add(dgvtbcPostalCode);
			DataGridViewTextBoxColumn^ dgvtbcAddition = gcnew DataGridViewTextBoxColumn();
			dgvtbcAddition->Name = "Complément d'adresse";
			this->DGVDelivery->Columns->Add(dgvtbcAddition);			
			
			DGVBilling->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcIdAddress2 = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdAddress2->Name = "ID Adresse";
			this->DGVBilling->Columns->Add(dgvtbcIdAddress2);
			DataGridViewTextBoxColumn^ dgvtbcNumber2 = gcnew DataGridViewTextBoxColumn();
			dgvtbcNumber2->Name = "Numéro";
			this->DGVBilling->Columns->Add(dgvtbcNumber2);
			DataGridViewTextBoxColumn^ dgvtbcNameStreet2 = gcnew DataGridViewTextBoxColumn();
			dgvtbcNameStreet2->Name = "Nom de la rue";
			this->DGVBilling->Columns->Add(dgvtbcNameStreet2);
			DataGridViewTextBoxColumn^ dgvtbcNameCity2 = gcnew DataGridViewTextBoxColumn();
			dgvtbcNameCity2->Name = "Ville";
			this->DGVBilling->Columns->Add(dgvtbcNameCity2);
			DataGridViewTextBoxColumn^ dgvtbcPostalCode2 = gcnew DataGridViewTextBoxColumn();
			dgvtbcPostalCode2->Name = "Code postal";
			this->DGVBilling->Columns->Add(dgvtbcPostalCode2);
			DataGridViewTextBoxColumn^ dgvtbcAddition2 = gcnew DataGridViewTextBoxColumn();
			dgvtbcAddition2->Name = "Complément d'adresse";
			this->DGVBilling->Columns->Add(dgvtbcAddition2);

			addressToCommandRepository = gcnew AddressToCommandRepository(mabdd);

			this->reload();

		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Address^>^ addresses = addressToCommandRepository->getAddressToCommand(sharedSearchedValue, sharedSearchedValue2, research);
				this->DGVDelivery->Rows->Clear();
				for each (Address ^ addr in addresses) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdAddress = gcnew DataGridViewTextBoxCell();
					dgvcIdAddress->Value = addr->getID_Address();
					dgvr->Cells->Add(dgvcIdAddress);
					DataGridViewTextBoxCell^ dgvcNumber = gcnew DataGridViewTextBoxCell();
					dgvcNumber->Value = addr->getNumber();
					dgvr->Cells->Add(dgvcNumber);
					DataGridViewTextBoxCell^ dgvcNameStreet = gcnew DataGridViewTextBoxCell();
					dgvcNameStreet->Value = addr->getNameStreet();
					dgvr->Cells->Add(dgvcNameStreet);
					DataGridViewTextBoxCell^ dgvcNameCity = gcnew DataGridViewTextBoxCell();
					dgvcNameCity->Value = addr->getNameCity();
					dgvr->Cells->Add(dgvcNameCity);
					DataGridViewTextBoxCell^ dgvcPostalCode = gcnew DataGridViewTextBoxCell();
					dgvcPostalCode->Value = addr->getPostalCode();
					dgvr->Cells->Add(dgvcPostalCode);
					DataGridViewTextBoxCell^ dgvcAddition = gcnew DataGridViewTextBoxCell();
					dgvcAddition->Value = addr->getAddition();
					dgvr->Cells->Add(dgvcAddition);
					dgvr->Tag = addr;

					DataGridViewRow^ dgvr2 = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvcIdAddress2 = gcnew DataGridViewTextBoxCell();
					dgvcIdAddress2->Value = addr->getID_Address();
					dgvr2->Cells->Add(dgvcIdAddress2);
					DataGridViewTextBoxCell^ dgvcNumber2 = gcnew DataGridViewTextBoxCell();
					dgvcNumber2->Value = addr->getNumber();
					dgvr2->Cells->Add(dgvcNumber2);
					DataGridViewTextBoxCell^ dgvcNameStreet2 = gcnew DataGridViewTextBoxCell();
					dgvcNameStreet2->Value = addr->getNameStreet();
					dgvr2->Cells->Add(dgvcNameStreet2);
					DataGridViewTextBoxCell^ dgvcNameCity2 = gcnew DataGridViewTextBoxCell();
					dgvcNameCity2->Value = addr->getNameCity();
					dgvr2->Cells->Add(dgvcNameCity2);
					DataGridViewTextBoxCell^ dgvcPostalCode2 = gcnew DataGridViewTextBoxCell();
					dgvcPostalCode2->Value = addr->getPostalCode();
					dgvr2->Cells->Add(dgvcPostalCode2);
					DataGridViewTextBoxCell^ dgvcAddition2 = gcnew DataGridViewTextBoxCell();
					dgvcAddition2->Value = addr->getAddition();
					dgvr2->Cells->Add(dgvcAddition2);

					dgvr2->Tag = addr;
					this->DGVDelivery->Rows->Add(dgvr);
					this->DGVBilling->Rows->Add(dgvr2);
				}
				reloadMutex->ReleaseMutex();
			}
		}
		void launchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &AddAddressToCommand::reload));
			reloadThread->Start();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~AddAddressToCommand()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ DGVDelivery;
		   System::Windows::Forms::DataGridView^ DGVBilling;
		   System::Windows::Forms::Label^ label1;
		   System::Windows::Forms::Label^ LbDeliveryRef;
		   System::Windows::Forms::Label^ label3;
		   System::Windows::Forms::Label^ LbBillingRef;
		   System::Windows::Forms::Button^ BtnAddAddress;
		   System::Windows::Forms::CheckBox^ CBoxSameAddress;
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
			   this->DGVDelivery = (gcnew System::Windows::Forms::DataGridView());
			   this->DGVBilling = (gcnew System::Windows::Forms::DataGridView());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->LbDeliveryRef = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->LbBillingRef = (gcnew System::Windows::Forms::Label());
			   this->BtnAddAddress = (gcnew System::Windows::Forms::Button());
			   this->CBoxSameAddress = (gcnew System::Windows::Forms::CheckBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVDelivery))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVBilling))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // DGVDelivery
			   // 
			   this->DGVDelivery->AllowUserToAddRows = false;
			   this->DGVDelivery->AllowUserToDeleteRows = false;
			   this->DGVDelivery->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->DGVDelivery->Location = System::Drawing::Point(41, 70);
			   this->DGVDelivery->Name = L"DGVDelivery";
			   this->DGVDelivery->ReadOnly = true;
			   this->DGVDelivery->Size = System::Drawing::Size(925, 136);
			   this->DGVDelivery->TabIndex = 31;
			   this->DGVDelivery->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &AddAddressToCommand::DGVDelivery_CellMouseDoubleClick);
			   // 
			   // DGVBilling
			   // 
			   this->DGVBilling->AllowUserToAddRows = false;
			   this->DGVBilling->AllowUserToDeleteRows = false;
			   this->DGVBilling->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->DGVBilling->Location = System::Drawing::Point(41, 304);
			   this->DGVBilling->Name = L"DGVBilling";
			   this->DGVBilling->ReadOnly = true;
			   this->DGVBilling->Size = System::Drawing::Size(925, 145);
			   this->DGVBilling->TabIndex = 32;
			   this->DGVBilling->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &AddAddressToCommand::DGVBilling_CellMouseDoubleClick);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(191, 27);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(187, 23);
			   this->label1->TabIndex = 33;
			   this->label1->Text = L"Adresse de livraison";
			   // 
			   // LbDeliveryRef
			   // 
			   this->LbDeliveryRef->AutoSize = true;
			   this->LbDeliveryRef->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbDeliveryRef->Location = System::Drawing::Point(105, 227);
			   this->LbDeliveryRef->Name = L"LbDeliveryRef";
			   this->LbDeliveryRef->Size = System::Drawing::Size(192, 19);
			   this->LbDeliveryRef->TabIndex = 34;
			   this->LbDeliveryRef->Text = L"Référence sélectionnée : ";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(191, 270);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(207, 23);
			   this->label3->TabIndex = 35;
			   this->label3->Text = L"Adresse de facturation";
			   // 
			   // LbBillingRef
			   // 
			   this->LbBillingRef->AutoSize = true;
			   this->LbBillingRef->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->LbBillingRef->Location = System::Drawing::Point(105, 493);
			   this->LbBillingRef->Name = L"LbBillingRef";
			   this->LbBillingRef->Size = System::Drawing::Size(192, 19);
			   this->LbBillingRef->TabIndex = 36;
			   this->LbBillingRef->Text = L"Référence sélectionnée : ";
			   // 
			   // BtnAddAddress
			   // 
			   this->BtnAddAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnAddAddress->Location = System::Drawing::Point(789, 509);
			   this->BtnAddAddress->Name = L"BtnAddAddress";
			   this->BtnAddAddress->Size = System::Drawing::Size(144, 39);
			   this->BtnAddAddress->TabIndex = 37;
			   this->BtnAddAddress->Text = L"Ajouter";
			   this->BtnAddAddress->UseVisualStyleBackColor = true;
			   // 
			   // CBoxSameAddress
			   // 
			   this->CBoxSameAddress->AutoSize = true;
			   this->CBoxSameAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->CBoxSameAddress->Location = System::Drawing::Point(829, 248);
			   this->CBoxSameAddress->Name = L"CBoxSameAddress";
			   this->CBoxSameAddress->Size = System::Drawing::Size(137, 23);
			   this->CBoxSameAddress->TabIndex = 38;
			   this->CBoxSameAddress->Text = L"Même adresse";
			   this->CBoxSameAddress->UseVisualStyleBackColor = true;
			   // 
			   // AddAddressToCommand
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(998, 584);
			   this->Controls->Add(this->CBoxSameAddress);
			   this->Controls->Add(this->BtnAddAddress);
			   this->Controls->Add(this->LbBillingRef);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->LbDeliveryRef);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->DGVBilling);
			   this->Controls->Add(this->DGVDelivery);
			   this->Name = L"AddAddressToCommand";
			   this->Text = L"AddAddressToCommand";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVDelivery))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVBilling))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void DGVDelivery_CellMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
	}
	private: System::Void DGVBilling_CellMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
	}
	};
}
