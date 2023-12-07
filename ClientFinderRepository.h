#pragma once
#include "BDD.h"
#include "Client.h"

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
	List<Client^>^ getArticle(String^ researchValue, String^ researchValue2, int research) {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [Client] " + (research == 1 ? " WHERE ID_Article = '" + researchValue + "' AND " : (research == 2 ? " WHERE LastName = '" + researchValue + " AND WHERE FirstName = '" + researchValue2 +"' AND " : " WHERE")) + " Del = 0");

		List<Client^>^ list = gcnew List<Client^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Client^ article = gcnew Client();
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