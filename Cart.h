#pragma once
#include "BDD.h"
#include "AddArticleToCommand.h"
namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de Cart
	/// </summary>
	public ref class Cart : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		Cart(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~Cart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
			 System::Windows::Forms::Button^ BtnAddCommand;
			 System::Windows::Forms::Button^ BtnDelete;
			 System::Windows::Forms::DataGridView^ dataGridView1;
			 System::Windows::Forms::Button^ button1;
			 System::Windows::Forms::Button^ BtnModify;
	private: System::Windows::Forms::Label^ LbTotal;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Cart::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BtnAddCommand = (gcnew System::Windows::Forms::Button());
			this->BtnDelete = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->BtnModify = (gcnew System::Windows::Forms::Button());
			this->LbTotal = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(101, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(359, 28);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Créer une nouvelle commande";
			// 
			// BtnAddCommand
			// 
			this->BtnAddCommand->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnAddCommand->Location = System::Drawing::Point(25, 453);
			this->BtnAddCommand->Name = L"BtnAddCommand";
			this->BtnAddCommand->Size = System::Drawing::Size(111, 42);
			this->BtnAddCommand->TabIndex = 13;
			this->BtnAddCommand->Text = L"Ajouter";
			this->BtnAddCommand->UseVisualStyleBackColor = true;
			this->BtnAddCommand->Click += gcnew System::EventHandler(this, &Cart::BtnAddCommand_Click);
			// 
			// BtnDelete
			// 
			this->BtnDelete->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnDelete->Location = System::Drawing::Point(231, 520);
			this->BtnDelete->Name = L"BtnDelete";
			this->BtnDelete->Size = System::Drawing::Size(111, 42);
			this->BtnDelete->TabIndex = 14;
			this->BtnDelete->Text = L"Supprimer";
			this->BtnDelete->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(25, 56);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(514, 381);
			this->dataGridView1->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(428, 520);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 42);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Payer";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// BtnModify
			// 
			this->BtnModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModify->Location = System::Drawing::Point(25, 520);
			this->BtnModify->Name = L"BtnModify";
			this->BtnModify->Size = System::Drawing::Size(111, 42);
			this->BtnModify->TabIndex = 17;
			this->BtnModify->Text = L"Modifier";
			this->BtnModify->UseVisualStyleBackColor = true;
			// 
			// LbTotal
			// 
			this->LbTotal->AutoSize = true;
			this->LbTotal->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbTotal->Location = System::Drawing::Point(216, 465);
			this->LbTotal->Name = L"LbTotal";
			this->LbTotal->Size = System::Drawing::Size(88, 19);
			this->LbTotal->TabIndex = 18;
			this->LbTotal->Text = L"Prix total : ";
			// 
			// Cart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(567, 585);
			this->Controls->Add(this->LbTotal);
			this->Controls->Add(this->BtnModify);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->BtnDelete);
			this->Controls->Add(this->BtnAddCommand);
			this->Controls->Add(this->Title);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Cart";
			this->Text = L"AddCommand";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnAddCommand_Click(System::Object^ sender, System::EventArgs^ e) {
		AddArticleToCommand^ formAddArticleToCommand = gcnew AddArticleToCommand(mabdd);
		formAddArticleToCommand->ShowDialog();
	}
};
}