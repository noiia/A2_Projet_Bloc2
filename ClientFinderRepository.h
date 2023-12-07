#pragma once
#include "BDD.h"
#include "Client.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class ClientFinderRepository
{
private:
	BDD^ bdd;

public:
	ClientFinderRepository(BDD^ bdd) : bdd(bdd) {
	}
	List<Client^>^ getClient(String^ researchValue, String^ researchValue2, int research) {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [Client] " + (research == 1 ? " WHERE ID_Client = '" + researchValue + "' AND Del = 0" : (research == 2 ? " WHERE LastName = '" + researchValue + "' AND Del = 0" : (research == 3 ? " WHERE FirstName = '" + researchValue2 + "' AND Del = 0" : (research == 4 ? " WHERE LastName = '" + researchValue + "' AND FirstName = '" + researchValue2 + "' AND Del = 0" : " WHERE Del = 0")))));

		List<Client^>^ list = gcnew List<Client^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Client^ client = gcnew Client();
			client->setID_Client((int)row["ID_Client"]);
			client->setFirstName((String^)row["FirstName"]);
			client->setLastName((String^)row["LastName"]);
			client->setTypeClient((String^)row["TypeClient"]);
			if (!row->IsNull("Birthday")) {
				client->setBirthday((DateTime^)row["Birthday"]);
			}
			list->Add(client);
		}
		return list;
	}
};