#pragma once
#include "BDD.h"
namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
		BDD^ bdd;
	public:
		login(BDD^ bdd)
		{
			this->bdd = bdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ PicBoxSignIn;
	protected:





	private: System::Windows::Forms::Label^ LbSignIn;

	private: System::Windows::Forms::Label^ LbUsername;
	private: System::Windows::Forms::Label^ LbPassword;


	private: System::Windows::Forms::TextBox^ TbUsername;
	private: System::Windows::Forms::TextBox^ TbPassword;
	private: System::Windows::Forms::Button^ BtValidate;
	private: System::Windows::Forms::Button^ BtCancel;






	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(login::typeid));
			this->PicBoxSignIn = (gcnew System::Windows::Forms::PictureBox());
			this->LbSignIn = (gcnew System::Windows::Forms::Label());
			this->LbUsername = (gcnew System::Windows::Forms::Label());
			this->LbPassword = (gcnew System::Windows::Forms::Label());
			this->TbUsername = (gcnew System::Windows::Forms::TextBox());
			this->TbPassword = (gcnew System::Windows::Forms::TextBox());
			this->BtValidate = (gcnew System::Windows::Forms::Button());
			this->BtCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxSignIn))->BeginInit();
			this->SuspendLayout();
			// 
			// PicBoxSignIn
			// 
			this->PicBoxSignIn->BackColor = System::Drawing::Color::IndianRed;
			this->PicBoxSignIn->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PicBoxSignIn->Location = System::Drawing::Point(302, 156);
			this->PicBoxSignIn->Name = L"PicBoxSignIn";
			this->PicBoxSignIn->Size = System::Drawing::Size(285, 295);
			this->PicBoxSignIn->TabIndex = 1;
			this->PicBoxSignIn->TabStop = false;
			// 
			// LbSignIn
			// 
			this->LbSignIn->AutoSize = true;
			this->LbSignIn->BackColor = System::Drawing::Color::IndianRed;
			this->LbSignIn->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSignIn->Location = System::Drawing::Point(373, 165);
			this->LbSignIn->Name = L"LbSignIn";
			this->LbSignIn->Size = System::Drawing::Size(141, 23);
			this->LbSignIn->TabIndex = 2;
			this->LbSignIn->Text = L"Identifiez-vous";
			// 
			// LbUsername
			// 
			this->LbUsername->AutoSize = true;
			this->LbUsername->BackColor = System::Drawing::Color::IndianRed;
			this->LbUsername->Font = (gcnew System::Drawing::Font(L"Orkney", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbUsername->Location = System::Drawing::Point(309, 218);
			this->LbUsername->Name = L"LbUsername";
			this->LbUsername->Size = System::Drawing::Size(120, 16);
			this->LbUsername->TabIndex = 3;
			this->LbUsername->Text = L"Nom d\'utilisateur :";
			// 
			// LbPassword
			// 
			this->LbPassword->AutoSize = true;
			this->LbPassword->BackColor = System::Drawing::Color::IndianRed;
			this->LbPassword->Font = (gcnew System::Drawing::Font(L"Orkney", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPassword->Location = System::Drawing::Point(309, 292);
			this->LbPassword->Name = L"LbPassword";
			this->LbPassword->Size = System::Drawing::Size(93, 16);
			this->LbPassword->TabIndex = 4;
			this->LbPassword->Text = L"Mot de passe :";
			// 
			// TbUsername
			// 
			this->TbUsername->Location = System::Drawing::Point(312, 250);
			this->TbUsername->Name = L"TbUsername";
			this->TbUsername->Size = System::Drawing::Size(265, 20);
			this->TbUsername->TabIndex = 5;
			// 
			// TbPassword
			// 
			this->TbPassword->Location = System::Drawing::Point(312, 324);
			this->TbPassword->Name = L"TbPassword";
			this->TbPassword->Size = System::Drawing::Size(265, 20);
			this->TbPassword->TabIndex = 6;
			this->TbPassword->UseSystemPasswordChar = true;
			// 
			// BtValidate
			// 
			this->BtValidate->Location = System::Drawing::Point(335, 384);
			this->BtValidate->Name = L"BtValidate";
			this->BtValidate->Size = System::Drawing::Size(94, 30);
			this->BtValidate->TabIndex = 7;
			this->BtValidate->Text = L"Valider";
			this->BtValidate->UseVisualStyleBackColor = true;
			this->BtValidate->Click += gcnew System::EventHandler(this, &login::BtnValidate_Click);
			// 
			// BtCancel
			// 
			this->BtCancel->Location = System::Drawing::Point(452, 384);
			this->BtCancel->Name = L"BtCancel";
			this->BtCancel->Size = System::Drawing::Size(94, 30);
			this->BtCancel->TabIndex = 8;
			this->BtCancel->Text = L"Annuler";
			this->BtCancel->UseVisualStyleBackColor = true;
			this->BtCancel->Click += gcnew System::EventHandler(this, &login::BtnCancel_Click);
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(888, 556);
			this->Controls->Add(this->BtCancel);
			this->Controls->Add(this->BtValidate);
			this->Controls->Add(this->TbPassword);
			this->Controls->Add(this->TbUsername);
			this->Controls->Add(this->LbPassword);
			this->Controls->Add(this->LbUsername);
			this->Controls->Add(this->LbSignIn);
			this->Controls->Add(this->PicBoxSignIn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TurboStock";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxSignIn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void BtnValidate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TbUsername->Text == "test" && TbPassword->Text == "test")
		{
			MessageBox::Show("Connexion r�ussie");
		}
		else
		{
			MessageBox::Show("Erreur de connexion");
		}
	}
	};
}
