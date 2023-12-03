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
			article->setDel((bool)row[9]);
			article->setIdArticle((String^)row[0]);
			article->setName((String^)row[1]);
			article->setPriceWT((Decimal^)row[6]);
			article->setVAT((int)row[8]);
			article->setPriceATI((Decimal^)row[7]);
			article->setRestockingLimit((long long)row[4]);
			article->setRestockingDate(((DateTime^)row[5])->ToString());
			list->Add(article);
		}

		return list;
	}

	void editArticle(Article^ article) {
		bdd->executeNonQuery("UPDATE [Article] SET (ID_Article, NameArticle, Kind, Quantity_Stock, RestockingTreshold, DateRestocking, PriceWT, PriceATI, VATValue, Del)  = '('" + article->getIdArticle() + "', '" + article->getName() + "', '" + article->getKind() + "', '" + article->getStock() + "', '" + article->getRestockingLimit() + "', '" + article->getRestockingDate() + "', '" + article->getPriceWT() + "', '" + article->getPriceATI() + "', '" + article->getVAT() + "', '" + false + "')' WHERE [ID_Article] = '" + article->getIdArticle()) + "'";
	}

	void deleteArticle(Article^ article) {
		bdd->executeNonQuery("UPDATE [Article] SET Del = 1 WHERE [ID_Article] = '" + article->getIdArticle() + "'");
	}

	void insertArticle(Article^ article) {
		bdd->executeInsert("INSERT INTO [Article] (ID_Article, NameArticle, Kind, Quantity_Stock, RestockingTreshold, DateRestocking, PriceWT, PriceATI, VATValue, Del) VALUES ('" + article->getIdArticle() + "', '" + article->getName() + "', '" + article->getKind() + "', '" + article->getStock() + "', '" + article->getRestockingLimit() + "', '" + article->getRestockingDate() + "', '" + article->getPriceWT() + "', '" + article->getPriceATI() + "', '" + article->getVAT() + "', '" + false + "')",0);
		//Enregistrer ses adresses
		//AdresseRepo ar=  ...
			//boucler sur les adresses a
			//ar.insert(a)
	}
};