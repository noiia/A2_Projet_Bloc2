#pragma once
#include "BDD.h"
#include "Cart.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de CommandHistory
	/// </summary>
	public ref class CommandHistory : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		CommandHistory(BDD^ mabdd)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			DataGridViewTextBoxColumn^ dgvtbcReference = gcnew DataGridViewTextBoxColumn();
			dgvtbcReference->Name = "Référence";
			this->DGVOrderHistory->Columns->Add(dgvtbcReference);
			DataGridViewTextBoxColumn^ dgvtbcClient = gcnew DataGridViewTextBoxColumn();
			dgvtbcClient->Name = "Client";
			this->DGVOrderHistory->Columns->Add(dgvtbcClient);
			DataGridViewTextBoxColumn^ dgvtbcPriceATI = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceATI->Name = "Prix T.T.C.";
			this->DGVOrderHistory->Columns->Add(dgvtbcPriceATI);

			DataSet^ ds = mabdd->executeQuery("SELECT * FROM Ordering");

			for each (DataRow ^ row in ds->Tables[0]->Rows)
			{

				String^ Name = (String^)row[0];
				//System::Diagnostics::Debug::WriteLine("Nom " + Name);
				int Hp = (int)row[1];
				//System::Diagnostics::Debug::WriteLine("Pv " + Hp);
				int Atk = (int)row[2];
				//System::Diagnostics::Debug::WriteLine("Atk " + Atk);
				int Lv = (int)row[3];
				//System::Diagnostics::Debug::WriteLine("Lv " + Lv);
				int ID = (int)row[4];
				//System::Diagnostics::Debug::WriteLine("ID " + ID);

				DataGridViewRow^ dgvr = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ dgvtbcName = gcnew DataGridViewTextBoxCell();
				dgvtbcName->Value = Name;
				dgvr->Cells->Add(dgvtbcName);

				DataGridViewTextBoxCell^ dgvtbcHp = gcnew DataGridViewTextBoxCell();
				dgvtbcHp->Value = Hp;
				dgvr->Cells->Add(dgvtbcHp);

				DataGridViewTextBoxCell^ dgvtbcAtk = gcnew DataGridViewTextBoxCell();
				dgvtbcAtk->Value = Atk;
				dgvr->Cells->Add(dgvtbcAtk);

				DataGridViewTextBoxCell^ dgvtbcLv = gcnew DataGridViewTextBoxCell();
				dgvtbcLv->Value = Lv;
				dgvr->Cells->Add(dgvtbcLv);

				DataGridViewTextBoxCell^ dgvtbcID = gcnew DataGridViewTextBoxCell();
				dgvtbcID->Value = ID;
				dgvr->Cells->Add(dgvtbcID);

				this->DGVOrderHistory->Rows->Add(dgvr);


			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~CommandHistory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnModify;
	private: System::Windows::Forms::Button^ BtnAddCommand;
	protected:

	private: System::Windows::Forms::DataGridView^ DGVOrderHistory;
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
			this->BtnAddCommand = (gcnew System::Windows::Forms::Button());
			this->DGVOrderHistory = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVOrderHistory))->BeginInit();
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
			// BtnAddCommand
			// 
			this->BtnAddCommand->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddCommand->Location = System::Drawing::Point(691, 81);
			this->BtnAddCommand->Name = L"BtnAddCommand";
			this->BtnAddCommand->Size = System::Drawing::Size(135, 48);
			this->BtnAddCommand->TabIndex = 26;
			this->BtnAddCommand->Text = L"Ajouter";
			this->BtnAddCommand->UseVisualStyleBackColor = true;
			this->BtnAddCommand->Click += gcnew System::EventHandler(this, &CommandHistory::BtnAddCommand_Click);
			// 
			// DGVSearchStaff
			// 
			this->DGVOrderHistory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVOrderHistory->Location = System::Drawing::Point(26, 56);
			this->DGVOrderHistory->Name = L"DGVSearchStaff";
			this->DGVOrderHistory->Size = System::Drawing::Size(603, 526);
			this->DGVOrderHistory->TabIndex = 25;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(317, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(262, 28);
			this->Title->TabIndex = 24;
			this->Title->Text = L"Liste des commandes";
			// 
			// ListCommand
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 623);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->BtnAddCommand);
			this->Controls->Add(this->DGVOrderHistory);
			this->Controls->Add(this->Title);
			this->Name = L"ListCommand";
			this->Text = L"ListCommand";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVOrderHistory))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnAddCommand_Click(System::Object^ sender, System::EventArgs^ e) {
		Cart^ cartForm = gcnew Cart(mabdd);
		cartForm->ShowDialog();
	}
};
}
