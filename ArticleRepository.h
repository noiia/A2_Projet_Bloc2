#pragma once
#include "BDD.h"
#include "Article.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class ArticleRepository
{
private:
	BDD^ bdd;
public:
	ArticleRepository(BDD^ bdd) :bdd(bdd) {

	}

	List<Article^>^ getArticle() {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [Article]");

		List<Article^>^ list = gcnew List<Article^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Article^ article = gcnew Article();
			article->setIdArticle((String^)row[0]);
			article->setName((String^)row[1]);
			article->setPriceWT((Decimal^)row[6]);
			list->Add(article);
		}

		return list;
	}

	void editArticle(Article^ article) {
		bdd->executeNonQuery("UPDATE [Article] SET nameArticle = '" + article->getName() + "' WHERE [ID_Article] = " + article->getIdArticle());
	}

	void deleteArticle(Article^ article) {
		bdd->executeNonQuery("UPDATE [Article] SET del = true WHERE [ID_Article] = " + article->getIdArticle());
	}

	void insertArticle(Article^ article) {
		bdd->executeInsert("INSERT INTO [Article] (ID_Article, nameArticle, kind, quantity_Stock, restockingTreshold, dateRestocking, PriceWT, PriceVAT, PriceATI, del) VALUES ('" + article->getIdArticle() + "', '" + article->getName() + "', '" + article->getKind() + "', '" + article->getStock() + "', '" + article->getRestockingLimit() + "', '" + article->getTresholdDate() + "', '" + article->getPriceWT() + "', '" + article->getVAT() + "', '" + article->getPriceATI() + "', '" + false + "')");
		//Enregistrer ses adresses
		//AdresseRepo ar=  ...
			//boucler sur les adresses a
			//ar.insert(a)
	}
};