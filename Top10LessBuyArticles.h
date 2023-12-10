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
	/// Description résumée de Top10LessBuyArticles
	/// </summary>
	public ref class Top10LessBuyArticles : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		Top10LessBuyArticles(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			LoadData();

		}
		void LoadData()
		{

			String^ query = "SELECT TOP 10 ID_Article, NameArticle, SUM(QuantityArticle) AS QuantiteVendue FROM Article_Order GROUP BY ID_Article, NameArticle ORDER BY QuantiteVendue ASC;";

			DataTable^ dt = mabdd->executeQuery(query)->Tables[0];

			DGVLessBuyArticles->DataSource = dt;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Top10LessBuyArticles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ DGVLessBuyArticles;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->DGVLessBuyArticles = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVLessBuyArticles))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(130, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(252, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Les 10 articles les moins vendus";
			// 
			// DGVLessBuyArticles
			// 
			this->DGVLessBuyArticles->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DGVLessBuyArticles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVLessBuyArticles->Location = System::Drawing::Point(23, 78);
			this->DGVLessBuyArticles->Name = L"DGVLessBuyArticles";
			this->DGVLessBuyArticles->Size = System::Drawing::Size(482, 340);
			this->DGVLessBuyArticles->TabIndex = 1;
			// 
			// Top10LessBuyArticles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(526, 467);
			this->Controls->Add(this->DGVLessBuyArticles);
			this->Controls->Add(this->label1);
			this->Name = L"Top10LessBuyArticles";
			this->Text = L"Top10LessBuyArticles";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVLessBuyArticles))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}