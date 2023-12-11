#pragma once
#include "BDD.h"
#include "Command.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class FormVisioCommandRepository
{
private:
	BDD^ bdd;
public:
	FormVisioCommandRepository(BDD^ bdd) : bdd(bdd) {
	}
	List<Command^>^ getArticle(String^ referenceCommand) {
		DataSet^ ds = bdd->executeQuery("SELECT ao.ID_Article, art.NameArticle, ao.QuantityArticle , art.PriceATI FROM [Article_Order] ao LEFT JOIN [Article] art ON ao.[ID_Article] = art.[ID_Article] WHERE Reference = '" + referenceCommand + "'");

		List<Command^>^ list = gcnew List<Command^>();
		Command^ cmd = nullptr;
		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			if (!row->IsNull("ID_Article")) {
				cmd = gcnew Command();
				cmd->setIdArticle((String^)row["ID_Article"]);
				cmd->setQuantity((int)row["QuantityArticle"]);
				list->Add(cmd);
				Article^ article = gcnew Article();
				article->setName((String^)row["NameArticle"]);
				article->setPriceATI((Decimal^)row["PriceATI"]);
				cmd->getArticle()->Add(article);
			}
		}
		return list;
	}
};