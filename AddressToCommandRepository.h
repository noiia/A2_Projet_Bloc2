#pragma once
#include "BDD.h"
#include "Address.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class AddressToCommandRepository
{
private:
	BDD^ bdd;

public:
	AddressToCommandRepository(BDD^ bdd) :bdd(bdd) {
	}
	List<Address^>^ getAddressToCommand(String^ researchValue, String^ researchValue2, int research, int ID_Client) {
		DataSet^ ds = bdd->executeQuery("SELECT adr.*, acd.* FROM [Address] adr LEFT JOIN [address_Client] acd ON acd.ID_Address = adr.ID_Address" + (research == 1 ? " WHERE ID_Address = '" + researchValue + "' AND Del = 0" : (research == 2 ? " WHERE PostalCode = '" + researchValue + "' AND Del = 0" : (research == 3 ? " WHERE NameStreet = '" + researchValue2 + "' AND Del = 0" : (research == 4 ? " WHERE PostalCode = '" + researchValue + "' AND NameStreet = '" + researchValue2 + "' AND Del = 0" : " WHERE Del = 0 AND ID_Client = '" + ID_Client + "'")))));

		List<Address^>^ list = gcnew List<Address^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Address^ address = gcnew Address();
			address->setID_Address((int)row[0]);
			address->setNumber((String^)row[1]);
			if (!row->IsNull("Addition")) {
				address->setAddition((String^)row[2]);
			}
			address->setNameStreet((String^)row[3]);
			address->setNameCity((String^)row[4]);
			address->setPostalCode((String^)row[5]);
			list->Add(address);
		}
		return list;
	}
};