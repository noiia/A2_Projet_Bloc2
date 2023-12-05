#pragma once
#include "BDD.h"
#include "Address.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class AddressRepository
{
private:
	BDD^ bdd;

public:
	AddressRepository(BDD^ bdd) :bdd(bdd) {
	}
	List<Address^>^ getAddress() {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [Address]");

		List<Address^>^ list = gcnew List<Address^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Address^ address = gcnew Address();
			address->setID_Address((int)row[0]);
			address->setNumber((String^)row[1]);
			address->setAddition((String^)row[2]);
			address->setNameStreet((String^)row[3]);
			address->setNameCity((String^)row[4]);
			address->setPostalCode((String^)row[5]);
			list->Add(address);
		}
		return list;
	}

	void insertAddress(Address^ address) {
		bdd->executeInsert("INSERT INTO [Address] (ID_Address, number, adddition, nameStreet , nameCity, postalCode) VALUES('" + address->getID_Address() + "', '" + address->getNumber() + "', '" + address->getAddition() + "', '" + address->getNameStreet() + "', '" + address->getNameCity() + "', '" + address->getPostalCode() + false + "')", 1);
	}
};