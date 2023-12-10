#pragma once
#include "BDD.H"
#include "TotalValuePurchaseClient.h"
#include "Top10BestBuyArticles.h"
#include "Top10LessBuyArticles.h"
#include "ArticlesBelowRestockingTreshold.h"
#include "SalesOverMonth.h"

namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Stats
	/// </summary>
	public ref class ListStats : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		ListStats(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			LoadAverageCart();
			LoadCommercialValue();
			LoadSellStockValue();
		}

		void LoadAverageCart()
		{
			String^ query = "SELECT AVG(PriceATI) AS PanierMoyenApresRemise FROM Article_Order JOIN Article ON Article_Order.ID_Article = Article.ID_Article;";
			DataSet^ ds = mabdd->executeQuery(query);
			String^ s = ds->Tables[0]->Rows[0]->ItemArray[0]->ToString();
			LbAverageCart->Text = L"Prix panier moyen (après remise) : " + s;
		}

		void LoadCommercialValue()
		{
			String^ query = "SELECT SUM(PriceWT * QuantityStock) AS ValeurCommercialeStock FROM Article;";
			DataSet^ ds = mabdd->executeQuery(query);
			String^ s = ds->Tables[0]->Rows[0]->ItemArray[0]->ToString();
			LbSotckCommercialValue->Text = L"Valeur commerciale du stock : " + s;
		}

		void LoadSellStockValue()
		{
			String^ query = "SELECT SUM(PriceATI * QuantityStock) AS ValeurAchatStock FROM Article;";
			DataSet^ ds = mabdd->executeQuery(query);
			String^ s = ds->Tables[0]->Rows[0]->ItemArray[0]->ToString();
			LbStockSellValue->Text = L"Valeur d'achat du stock : " + s;
		}


	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ListStats()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
			 System::Windows::Forms::Label^ LbAverageCart;
			 System::Windows::Forms::DataGridView^ DGVTop10LessBuyArticles;
			 System::Windows::Forms::Label^ label4;
			 System::Windows::Forms::Button^ BtnTopBestBuyArticles;
			 System::Windows::Forms::Button^ BtnTopLessBuyArticles;
			 System::Windows::Forms::Button^ BtnArticlesBelowRestockingTreshold;
			 System::Windows::Forms::Button^ BtnTotalAmount4aClient;
			 System::Windows::Forms::Label^ LbSotckCommercialValue;
			 System::Windows::Forms::Label^ LbStockSellValue;
			 System::Windows::Forms::Button^ BtnSalesOverMonth;
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
			this->LbAverageCart = (gcnew System::Windows::Forms::Label());
			this->DGVTop10LessBuyArticles = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->BtnTopBestBuyArticles = (gcnew System::Windows::Forms::Button());
			this->BtnTopLessBuyArticles = (gcnew System::Windows::Forms::Button());
			this->BtnArticlesBelowRestockingTreshold = (gcnew System::Windows::Forms::Button());
			this->BtnTotalAmount4aClient = (gcnew System::Windows::Forms::Button());
			this->LbSotckCommercialValue = (gcnew System::Windows::Forms::Label());
			this->LbStockSellValue = (gcnew System::Windows::Forms::Label());
			this->BtnSalesOverMonth = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVTop10LessBuyArticles))->BeginInit();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(119, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(151, 28);
			this->Title->TabIndex = 25;
			this->Title->Text = L"Satistiques ";
			// 
			// LbAverageCart
			// 
			this->LbAverageCart->AutoSize = true;
			this->LbAverageCart->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbAverageCart->Location = System::Drawing::Point(21, 94);
			this->LbAverageCart->Name = L"LbAverageCart";
			this->LbAverageCart->Size = System::Drawing::Size(254, 19);
			this->LbAverageCart->TabIndex = 26;
			this->LbAverageCart->Text = L"Prix panier moyen (après remise)";
			// 
			// DGVTop10LessBuyArticles
			// 
			this->DGVTop10LessBuyArticles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVTop10LessBuyArticles->Location = System::Drawing::Point(463, 658);
			this->DGVTop10LessBuyArticles->Name = L"DGVTop10LessBuyArticles";
			this->DGVTop10LessBuyArticles->Size = System::Drawing::Size(361, 207);
			this->DGVTop10LessBuyArticles->TabIndex = 31;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(525, 636);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(245, 19);
			this->label4->TabIndex = 32;
			this->label4->Text = L"Les 10 articles les moins vendus";
			// 
			// BtnTopBestBuyArticles
			// 
			this->BtnTopBestBuyArticles->AutoSize = true;
			this->BtnTopBestBuyArticles->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnTopBestBuyArticles->Location = System::Drawing::Point(12, 299);
			this->BtnTopBestBuyArticles->Name = L"BtnTopBestBuyArticles";
			this->BtnTopBestBuyArticles->Size = System::Drawing::Size(362, 29);
			this->BtnTopBestBuyArticles->TabIndex = 33;
			this->BtnTopBestBuyArticles->Text = L"Top 10 des articles les plus vendus";
			this->BtnTopBestBuyArticles->UseVisualStyleBackColor = true;
			this->BtnTopBestBuyArticles->Click += gcnew System::EventHandler(this, &ListStats::BtnTopBestBuyArticles_Click);
			// 
			// BtnTopLessBuyArticles
			// 
			this->BtnTopLessBuyArticles->AutoSize = true;
			this->BtnTopLessBuyArticles->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnTopLessBuyArticles->Location = System::Drawing::Point(12, 348);
			this->BtnTopLessBuyArticles->Name = L"BtnTopLessBuyArticles";
			this->BtnTopLessBuyArticles->Size = System::Drawing::Size(362, 29);
			this->BtnTopLessBuyArticles->TabIndex = 34;
			this->BtnTopLessBuyArticles->Text = L"Top 10 des articles les moins vendus";
			this->BtnTopLessBuyArticles->UseVisualStyleBackColor = true;
			this->BtnTopLessBuyArticles->Click += gcnew System::EventHandler(this, &ListStats::BtnTopLessBuyArticles_Click);
			// 
			// BtnArticlesBelowRestockingTreshold
			// 
			this->BtnArticlesBelowRestockingTreshold->AutoSize = true;
			this->BtnArticlesBelowRestockingTreshold->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BtnArticlesBelowRestockingTreshold->Location = System::Drawing::Point(12, 197);
			this->BtnArticlesBelowRestockingTreshold->Name = L"BtnArticlesBelowRestockingTreshold";
			this->BtnArticlesBelowRestockingTreshold->Size = System::Drawing::Size(362, 29);
			this->BtnArticlesBelowRestockingTreshold->TabIndex = 35;
			this->BtnArticlesBelowRestockingTreshold->Text = L"Articles sous le seuil de reapprovisionnement";
			this->BtnArticlesBelowRestockingTreshold->UseVisualStyleBackColor = true;
			this->BtnArticlesBelowRestockingTreshold->Click += gcnew System::EventHandler(this, &ListStats::BtnArticlesBelowRestockingTreshold_Click);
			// 
			// BtnTotalAmount4aClient
			// 
			this->BtnTotalAmount4aClient->AutoSize = true;
			this->BtnTotalAmount4aClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnTotalAmount4aClient->Location = System::Drawing::Point(12, 248);
			this->BtnTotalAmount4aClient->Name = L"BtnTotalAmount4aClient";
			this->BtnTotalAmount4aClient->Size = System::Drawing::Size(362, 29);
			this->BtnTotalAmount4aClient->TabIndex = 36;
			this->BtnTotalAmount4aClient->Text = L"Calcul total des achats pour un client";
			this->BtnTotalAmount4aClient->UseVisualStyleBackColor = true;
			this->BtnTotalAmount4aClient->Click += gcnew System::EventHandler(this, &ListStats::BtnTotalAmount4aClient_Click);
			// 
			// LbSotckCommercialValue
			// 
			this->LbSotckCommercialValue->AutoSize = true;
			this->LbSotckCommercialValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSotckCommercialValue->Location = System::Drawing::Point(21, 415);
			this->LbSotckCommercialValue->Name = L"LbSotckCommercialValue";
			this->LbSotckCommercialValue->Size = System::Drawing::Size(212, 19);
			this->LbSotckCommercialValue->TabIndex = 37;
			this->LbSotckCommercialValue->Text = L"Valeur commercial du stock";
			// 
			// LbStockSellValue
			// 
			this->LbStockSellValue->AutoSize = true;
			this->LbStockSellValue->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbStockSellValue->Location = System::Drawing::Point(21, 472);
			this->LbStockSellValue->Name = L"LbStockSellValue";
			this->LbStockSellValue->Size = System::Drawing::Size(182, 19);
			this->LbStockSellValue->TabIndex = 38;
			this->LbStockSellValue->Text = L"Valeur d\'achat du stock";
			// 
			// BtnSalesOverMonth
			// 
			this->BtnSalesOverMonth->AutoSize = true;
			this->BtnSalesOverMonth->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnSalesOverMonth->Location = System::Drawing::Point(12, 151);
			this->BtnSalesOverMonth->Name = L"BtnSalesOverMonth";
			this->BtnSalesOverMonth->Size = System::Drawing::Size(362, 29);
			this->BtnSalesOverMonth->TabIndex = 39;
			this->BtnSalesOverMonth->Text = L"Chiffre d\'affaires sur un mois";
			this->BtnSalesOverMonth->UseVisualStyleBackColor = true;
			//this->BtnSalesOverMonth->Click += gcnew System::EventHandler(this, &ListStats::BtnSalesOverMonth_Click);
			// 
			// ListStats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(396, 531);
			this->Controls->Add(this->BtnSalesOverMonth);
			this->Controls->Add(this->LbStockSellValue);
			this->Controls->Add(this->LbSotckCommercialValue);
			this->Controls->Add(this->BtnTotalAmount4aClient);
			this->Controls->Add(this->BtnArticlesBelowRestockingTreshold);
			this->Controls->Add(this->BtnTopLessBuyArticles);
			this->Controls->Add(this->BtnTopBestBuyArticles);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->DGVTop10LessBuyArticles);
			this->Controls->Add(this->LbAverageCart);
			this->Controls->Add(this->Title);
			this->Name = L"ListStats";
			this->Text = L"Stats";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVTop10LessBuyArticles))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void BtnArticlesBelowRestockingTreshold_Click(System::Object^ sender, System::EventArgs^ e) {
		ArticlesBelowRestockingTreshold^ articlesBelowRestockingTresholdForm = gcnew ArticlesBelowRestockingTreshold(mabdd);
		articlesBelowRestockingTresholdForm->ShowDialog();
	}
	private: System::Void BtnTotalAmount4aClient_Click(System::Object^ sender, System::EventArgs^ e) {
		TotalValuePurchaseClient^ totalValuePurchaseClientForm = gcnew TotalValuePurchaseClient(mabdd);
		totalValuePurchaseClientForm->ShowDialog();
	}
	private: System::Void BtnTopBestBuyArticles_Click(System::Object^ sender, System::EventArgs^ e) {
		Top10BestBuyArticles^ top10BestBuyArticlesForm = gcnew Top10BestBuyArticles(mabdd);
		top10BestBuyArticlesForm->ShowDialog();

	}
	private: System::Void BtnTopLessBuyArticles_Click(System::Object^ sender, System::EventArgs^ e) {
		Top10LessBuyArticles^ top10LessBuyArticlesForm = gcnew Top10LessBuyArticles(mabdd);
		top10LessBuyArticlesForm->ShowDialog();
	}
	private: System::Void BtnSalesOverMonth_Click(System::Object^ sender, System::EventArgs^ e) {
		SalesOverMonth^ salesOverMonthForm = gcnew SalesOverMonth(mabdd);
		salesOverMonthForm->ShowDialog();
	}
	};
}