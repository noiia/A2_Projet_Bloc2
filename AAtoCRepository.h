#pragma once
#include "BDD.h"
#include "Article.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class AAtoCRepository
{
private:
	BDD^ bdd;

public:
	AAtoCRepository(BDD^ bdd) : bdd(bdd) {
	}
	List<Article^>^ getArticle(String^ researchValue, int research) {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [Article] " + (research == 1 ? " WHERE ID_Article = '" + researchValue + "' AND " : (research == 2 ? " WHERE NameArticle = '" + researchValue + "' AND " : " WHERE")) + " Del = 0");

		List<Article^>^ list = gcnew List<Article^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Article^ article = gcnew Article();
			article->setIdArticle((String^)row[0]);
			article->setName((String^)row[1]);
			article->setKind((String^)row[2]);
			article->setPriceWT((Decimal^)row[6]);
			article->setVAT((int)row[8]);
			article->setPriceATI((Decimal^)row[7]);
			article->setStock((long long)row[3]);
			article->setRestockingLimit((long long)row[4]);
			article->setRestockingDate((DateTime^)row[5]);
			list->Add(article);
		}
		return list;
	}
};