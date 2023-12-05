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

			DataSet^ ds = mabdd->executeQuery("SELECT * FROM [Ordering]");

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CommandHistory::typeid));
			this->BtnModify = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(1728, 982);
			this->BtnModify->Margin = System::Windows::Forms::Padding(8, 6, 8, 6);
			this->BtnModify->Name = L"BtnModify";
			this->BtnModify->Size = System::Drawing::Size(338, 103);
			this->BtnModify->TabIndex = 27;
			this->BtnModify->Text = L"Modifier";
			this->BtnModify->UseVisualStyleBackColor = true;
			// 
			// CommandHistory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 28);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1924, 1061);
			this->Controls->Add(this->BtnModify);
			this->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(317, 9);
			this->Margin = System::Windows::Forms::Padding(8, 6, 8, 6);
			this->Name = L"CommandHistory";
			this->Text = L"ListCommand";
			this->Click += gcnew System::EventHandler(this, &CommandHistory::BtnAddCommand_Click);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BtnAddCommand_Click(System::Object^ sender, System::EventArgs^ e) {
		Cart^ cartForm = gcnew Cart(mabdd);
		cartForm->ShowDialog();
	}
};
}
