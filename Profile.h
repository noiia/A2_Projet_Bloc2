#pragma once

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de Profile
	/// </summary>
	public ref class Profile : public System::Windows::Forms::Form
	{
	public:
		Profile(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~Profile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtModify;
	private: System::Windows::Forms::DataGridView^ DGVProfile;
	private: System::Windows::Forms::Label^ LbProfile;

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
			this->BtModify = (gcnew System::Windows::Forms::Button());
			this->DGVProfile = (gcnew System::Windows::Forms::DataGridView());
			this->LbProfile = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVProfile))->BeginInit();
			this->SuspendLayout();
			// 
			// BtModify
			// 
			this->BtModify->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtModify->Location = System::Drawing::Point(280, 384);
			this->BtModify->Name = L"BtModify";
			this->BtModify->Size = System::Drawing::Size(117, 46);
			this->BtModify->TabIndex = 0;
			this->BtModify->Text = L"Modifier";
			this->BtModify->UseVisualStyleBackColor = true;
			// 
			// DGVProfile
			// 
			this->DGVProfile->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVProfile->Location = System::Drawing::Point(50, 79);
			this->DGVProfile->Name = L"DGVProfile";
			this->DGVProfile->Size = System::Drawing::Size(566, 270);
			this->DGVProfile->TabIndex = 10;
			// 
			// LbProfile
			// 
			this->LbProfile->AutoSize = true;
			this->LbProfile->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbProfile->Location = System::Drawing::Point(262, 21);
			this->LbProfile->Name = L"LbProfile";
			this->LbProfile->Size = System::Drawing::Size(146, 28);
			this->LbProfile->TabIndex = 11;
			this->LbProfile->Text = L"Votre Profil";
			// 
			// Profile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(668, 467);
			this->Controls->Add(this->LbProfile);
			this->Controls->Add(this->DGVProfile);
			this->Controls->Add(this->BtModify);
			this->Name = L"Profile";
			this->Text = L"Profile";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVProfile))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	};
}
