#pragma once
#include "BDD.h"
#include "address_Client.h"
using namespace  System::Collections::Generic;
using namespace System;
using namespace System::Data;

ref class address_ClientRepository

{
private:
	BDD^ bdd;

public:
	address_ClientRepository(BDD^ bdd) :bdd(bdd) {
	}
	List<Address_Client^>^ getAddress_Client() {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [address_Client]");

		List<Address_Client^>^ list = gcnew List<Address_Client^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Address_Client^ address_client = gcnew Address_Client();
			address_client->setID_Address((int)row[0]);
			address_client->setID_Client((int)row[1]);
			address_client->setTypeAddress((String^)row[2]);
			list->Add(address_client);
		}
		return list;
	}
};