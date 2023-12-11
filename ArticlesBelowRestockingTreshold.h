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
	/// Description r�sum�e de ArticlesBelowRestockingTreshold
	/// </summary>
	public ref class ArticlesBelowRestockingTreshold : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		ArticlesBelowRestockingTreshold(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			LoadData();

		}
		void LoadData()
		{
			// D�finissez votre requ�te SQL
			String^ query = "SELECT * FROM Article WHERE QuantityStock < RestockingTreshold";

			// Ex�cutez la requ�te SQL et r�cup�rez les r�sultats dans un DataTable
			DataTable^ dt = mabdd->executeQuery(query)->Tables[0];

			// Remplissez le DataGridView avec les r�sultats
			DGVArticlesBelowRestockingTreshold->DataSource = dt;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~ArticlesBelowRestockingTreshold()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LbTitle;
	private: System::Windows::Forms::DataGridView^ DGVArticlesBelowRestockingTreshold;
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
			this->LbTitle = (gcnew System::Windows::Forms::Label());
			this->DGVArticlesBelowRestockingTreshold = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVArticlesBelowRestockingTreshold))->BeginInit();
			this->SuspendLayout();
			// 
			// LbTitle
			// 
			this->LbTitle->AutoSize = true;
			this->LbTitle->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbTitle->Location = System::Drawing::Point(100, 9);
			this->LbTitle->Name = L"LbTitle";
			this->LbTitle->Size = System::Drawing::Size(535, 28);
			this->LbTitle->TabIndex = 0;
			this->LbTitle->Text = L"Articles sous le seuil de reapprovisionnement";
			// 
			// DGVArticlesBelowRestockingTreshold
			// 
			this->DGVArticlesBelowRestockingTreshold->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVArticlesBelowRestockingTreshold->Location = System::Drawing::Point(27, 80);
			this->DGVArticlesBelowRestockingTreshold->Name = L"DGVArticlesBelowRestockingTreshold";
			this->DGVArticlesBelowRestockingTreshold->Size = System::Drawing::Size(639, 356);
			this->DGVArticlesBelowRestockingTreshold->TabIndex = 30;
			// 
			// ArticlesBelowRestockingTreshold
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 492);
			this->Controls->Add(this->DGVArticlesBelowRestockingTreshold);
			this->Controls->Add(this->LbTitle);
			this->Name = L"ArticlesBelowRestockingTreshold";
			this->Text = L"ArticlesBelowRestockingTreshold";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVArticlesBelowRestockingTreshold))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}