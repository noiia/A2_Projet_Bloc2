#pragma once
#include "BDD.h"
#include "Command.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class CommandRepository
{
private:
	BDD^ bdd;
public:
	CommandRepository(BDD^ bdd) : bdd(bdd) {
	}
	List<Command^>^ getArticle() {
		DataSet^ ds = bdd->executeQuery("SELECT ao.*,art.* FROM [Article_Order] ao LEFT JOIN [Article] art ON ao.[Reference] = art.[Reference]");

		List<Command^>^ list = gcnew List<Command^>();
		Command^ cmd = nullptr;
		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			if (cmd == nullptr || !cmd->getIdCommand()->Equals(row["Reference"])) {
				cmd = gcnew Command();
				cmd->setIdCommand((String^)row["Reference"]);
				cmd->setOrderDate((DateTime^)row["OrderDate"]);
				cmd->setDeliveryDate((DateTime^)row["DeliveryDate"]);

				//TODO addresse livraison + factu
				list->Add(cmd);
			}

			if (!row->IsNull("InstallmentNumber")) {
				InstallmentPayment^ payment = gcnew InstallmentPayment();
				payment->setInstallmentNumber((int)row["InstallmentNumber"]);
				payment->setBalancePaymentDate((DateTime^)row["BalancePaymentDate"]);
				payment->setPaymentDate((DateTime^)row["DatePayment"]);
				payment->setPaymentMode((String^)row["ModePayment"]);
				payment->setAmount((Decimal)row["Amount"]);
				cmd->getPayments()->Add(payment);
			}
		}
		return list;
	}
};