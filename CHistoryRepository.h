#pragma once
#include "BDD.h"
#include "CHistory.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class CHistoryRepository
{
private:
	BDD^ bdd;
public:
	CHistoryRepository(BDD^ bdd) :bdd(bdd) {
	}
	List<CHistory^>^ getCommand(/*bool delState*/) {
		DataSet^ ds = bdd->executeQuery("SELECT o.*,ip.* FROM [Ordering] o LEFT JOIN [InstallmentPayment] ip ON o.[Reference] = ip.[Reference]" + (/*delState*/false ? "" : " WHERE o.Del = 0"));

		List<CHistory^>^ list = gcnew List<CHistory^>();
		CHistory^ cmd = nullptr;
		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			if (cmd == nullptr || !cmd->getIdCommand()->Equals(row["Reference"])) {
				cmd = gcnew CHistory();
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

	void editArticle(CHistory^ cHistory) {
		bdd->executeNonQuery("UPDATE [Ordering] SET OrderDate = '" + cHistory->getOrderDate() + "', DeliveryDate = '" + cHistory->getDeliveryDate() + "', Del = '" + false + "' WHERE Reference = '" + cHistory->getIdCommand() + "'");
		for each (InstallmentPayment ^ ip in cHistory->getPayments())
			bdd->executeNonQuery("UPDATE [InstallmentPayment] SET InstallmentNumber = '" + ip->getInstallmentNumber() + "', BalancePaymentDate = '" + ip->getBalancePaymentDate() + "', DatePayment = '" + ip->getPaymentDate() + "', ModePayment = '" + ip->getPaymentMode() + "', Amount = '" + ip->getAmount() + "' WHERE Reference = '" + cHistory->getIdCommand() + "' AND InstallmentNumber = " + ip->getInstallmentNumber());
	}

	void deleteArticle(CHistory^ cHistory, int delOrRestore) {
		bdd->executeNonQuery("UPDATE [Ordering] SET Del = " + delOrRestore + " WHERE [ID_Article] = '" + cHistory->getIdCommand() + "'");
	}

	void insertArticle(CHistory^ cHistory) {
		bdd->executeInsert("INSERT INTO [Ordering] (Reference, OrderDate, DeliveryDate, Del) VALUES ('" + cHistory->getIdCommand() + "', '" + cHistory->getOrderDate() + "', '" + cHistory->getDeliveryDate() + "', '" + false + "');", 1);
		for each (InstallmentPayment ^ ip in cHistory->getPayments())
			bdd->executeInsert("INSERT INTO [InstallmentPayment] (Reference, InstallmentNumber, BalancePaymentDate, DatePayment, ModePayment, Amount Del) VALUES ('" + cHistory->getIdCommand() + "', '" + ip->getInstallmentNumber() + "', '" + ip->getBalancePaymentDate() + "', '" + ip->getPaymentDate() + "', '" + ip->getPaymentMode() + "', '" + ip->getAmount() + "', '" + 0 + "');", 2);
	}
	bool referenceAlreadyExist(String^ reference) {
		int valueInBDD = bdd->searchQuery("SELECT COUNT(*) FROM [Ordering] WHERE Reference = '" + reference + "'");

		if (valueInBDD > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void insertOrdering(Command^ command) {
		bdd->executeInsert("INSERT INTO [Ordering] (Reference, OrderDate, DeliveryDate, ID_Address_Delivery, ID_Address_Order, Del) VALUES ('" + command->getReference() + "', '" + command->getOrderDate() + "', '" + command->getDeliveryDate() + "', '" + command->getID_AddressDelivery() + "', '" + command->getID_AddressBilling()  + "', '" + 0 + "');", 2);
	}
};