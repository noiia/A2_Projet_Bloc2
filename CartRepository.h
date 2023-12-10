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
			}

			if (!row->IsNull("PriceATI")) {
				Article^ article = gcnew Article();
				article->setName((String^)row["NameArticle"]);
				article->setPriceATI((Decimal^)row["PriceATI"]);
				cmd->getArticle()->Add(article);
			}
		}
		return list;
	}

	void insertArticle(Command^ command) {
		command->setIdArticleInCart(bdd->executeInsert("INSERT INTO [Article_Order] (Reference, ID_Article, QuantityArticle) VALUES ('" + command->getReference() + "', '" + command->getIdArticle() + "', '" + command->getQuantity() + "');", 1));
	}
	void editCommand(Command^ command) {
		bdd->executeQuery("UPDATE FROM [Article_Order] WHERE ID_Article = '" + command->getIdArticle() + "' SET QuantityArticle = " + command->getQuantity() + "'");
	}
	void dropCommand(Command^ command) {
		bdd->executeQuery("DELETE FROM [Ordering] WHERE Reference = '" + command->getReference() + "'");
	}
	void delArticle(Command^ command) {
		bdd->executeQuery("DELETE FROM [Article_Order] WHERE [ID_Article] = '" + command->getIdArticle() + "'");
	}
};