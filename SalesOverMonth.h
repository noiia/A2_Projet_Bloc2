#pragma once
//#include <msclr\marshal_cppstd.h>
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
	private: System::Windows::Forms::DateTimePicker^ DtpMonthSelection;
	private: System::Windows::Forms::Label^ LbCA;
	private: System::Windows::Forms::Button^ BtnCalculate;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SalesOverMonth::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->DtpMonthSelection = (gcnew System::Windows::Forms::DateTimePicker());
			this->LbCA = (gcnew System::Windows::Forms::Label());
			this->BtnCalculate = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(70, 39);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(332, 28);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Chiffre d\'affaire sur un mois";
			// 
			// DtpMonthSelection
			// 
			this->DtpMonthSelection->CalendarFont = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DtpMonthSelection->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DtpMonthSelection->Location = System::Drawing::Point(87, 106);
			this->DtpMonthSelection->Name = L"DtpMonthSelection";
			this->DtpMonthSelection->Size = System::Drawing::Size(293, 26);
			this->DtpMonthSelection->TabIndex = 1;
			// 
			// LbCA
			// 
			this->LbCA->AutoSize = true;
			this->LbCA->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbCA->Location = System::Drawing::Point(140, 220);
			this->LbCA->Name = L"LbCA";
			this->LbCA->Size = System::Drawing::Size(31, 19);
			this->LbCA->TabIndex = 2;
			this->LbCA->Text = L"0€";
			// 
			// BtnCalculate
			// 
			this->BtnCalculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCalculate->Location = System::Drawing::Point(281, 209);
			this->BtnCalculate->Name = L"BtnCalculate";
			this->BtnCalculate->Size = System::Drawing::Size(121, 39);
			this->BtnCalculate->TabIndex = 3;
			this->BtnCalculate->Text = L"Calculer";
			this->BtnCalculate->UseVisualStyleBackColor = true;
			this->BtnCalculate->Click += gcnew System::EventHandler(this, &SalesOverMonth::BtnCalculate_Click);
			// 
			// SalesOverMonth
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 320);
			this->Controls->Add(this->BtnCalculate);
			this->Controls->Add(this->LbCA);
			this->Controls->Add(this->DtpMonthSelection);
			this->Controls->Add(this->Title);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SalesOverMonth";
			this->Text = L"SalesOverMonth";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnCalculate_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ yearMonthString = DtpMonthSelection->Value.ToString("yyyy-MM-dd");
	//std::string yearMonth = msclr::interop::marshal_as<std::string>(yearMonthString);
	//std::string yearMonthWithoutDays = yearMonth.substr(0, 7);

	//int totalSales = mabdd->executeNonQuery("SELECT SUM(Montant) FROM (SELECT IP.Reference, IP.Amount AS Montant FROM InstallmentPayment IP JOIN Ordering O ON IP.Reference = O.Reference WHERE CONVERT(VARCHAR(7), O.OrderDate, 120) = '" + yearMonthWithoutDays + "') AS Montant");
	//
	//// Mettre à jour le label avec le résultat
	//this->LbCA->Text = "Le chiffre d'affaires sur le mois que vous avez choisi est de : " + totalSales.ToString() + " €";
	}

};
}