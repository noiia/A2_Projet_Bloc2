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
	/// Description résumée de SalesOverMonth
	/// </summary>
	public ref class SalesOverMonth : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		SalesOverMonth(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~SalesOverMonth()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:

	protected:

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
			this->Title = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(70, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(332, 28);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Chiffre d\'affaire sur un mois";
			// 
			// SalesOverMonth
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 514);
			this->Controls->Add(this->Title);
			this->Name = L"SalesOverMonth";
			this->Text = L"SalesOverMonth";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}