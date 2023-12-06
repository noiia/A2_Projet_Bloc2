#pragma once
#include "BDD.h"
#include "Command.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class CartRepository
{
private:
	BDD^ bdd;
public:
	CartRepository(BDD^ bdd) : bdd(bdd) {
	}
	List<Command^>^ getArticle() {
		DataSet^ ds = bdd->executeQuery("SELECT ao.*,art.* FROM [Article_Order] ao LEFT JOIN [Article] art ON ao.[ID_Article] = art.[ID_Article]");

		List<Command^>^ list = gcnew List<Command^>();
		Command^ cmd = nullptr;
		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			if (cmd == nullptr || !cmd->getReference()->Equals(row["Reference"])) {
				cmd = gcnew Command();
				cmd->setReference((String^)row["Reference"]);
				cmd->setIdArticle((String^)row["ID_Article"]);
				cmd->setQuantity((int)row["QuantityArticle"]);

				//TODO addresse livraison + factu
				list->Add(cmd);
			}

			if (!row->IsNull("PriceATI")) {
				Article^ article = gcnew Article();
				article->setPriceATI((Decimal^)row["PriceATI"]);
				cmd->getArticle()->Add(article);
			}
		}
		return list;
	}

	void insertArticle(Command^ command) {
		bdd->executeInsert("INSERT INTO [Article_Order] (Reference, ID_Article, QuantityArticle) VALUES ('" + command->getReference() + "', '" + command->getIdArticle() + "', '" + command->getQuantity() + "');", 1);
	}
};