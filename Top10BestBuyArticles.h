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
	/// Description résumée de Top10BestBuyArticles
	/// </summary>
	public ref class Top10BestBuyArticles : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		Top10BestBuyArticles(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			LoadData();
		}
		void LoadData()
		{

			String^ query = "SELECT TOP 10 ID_Article, NameArticle, SUM(QuantityArticle) AS QuantiteVendue FROM Article_Order GROUP BY ID_Article, NameArticle ORDER BY QuantiteVendue DESC;";

			DataTable^ dt = mabdd->executeQuery(query)->Tables[0];

			DGVTop10BestBuyArticles->DataSource = dt;
		}



	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Top10BestBuyArticles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LbBestBuy;
	protected:

	private: System::Windows::Forms::DataGridView^ DGVTop10BestBuyArticles;
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
			this->LbBestBuy = (gcnew System::Windows::Forms::Label());
			this->DGVTop10BestBuyArticles = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVTop10BestBuyArticles))->BeginInit();
			this->SuspendLayout();
			// 
			// LbBestBuy
			// 
			this->LbBestBuy->AutoSize = true;
			this->LbBestBuy->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbBestBuy->Location = System::Drawing::Point(179, 9);
			this->LbBestBuy->Name = L"LbBestBuy";
			this->LbBestBuy->Size = System::Drawing::Size(355, 28);
			this->LbBestBuy->TabIndex = 0;
			this->LbBestBuy->Text = L"Les 10 articles les plus vendus";
			// 
			// DGVTop10BestBuyArticles
			// 
			this->DGVTop10BestBuyArticles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVTop10BestBuyArticles->Location = System::Drawing::Point(66, 71);
			this->DGVTop10BestBuyArticles->Name = L"DGVTop10BestBuyArticles";
			this->DGVTop10BestBuyArticles->Size = System::Drawing::Size(548, 356);
			this->DGVTop10BestBuyArticles->TabIndex = 31;
			// 
			// Top10BestBuyArticles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(689, 465);
			this->Controls->Add(this->DGVTop10BestBuyArticles);
			this->Controls->Add(this->LbBestBuy);
			this->Name = L"Top10BestBuyArticles";
			this->Text = L"Top10BestBuyArticles";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVTop10BestBuyArticles))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		};
#pragma endregion


	};
}