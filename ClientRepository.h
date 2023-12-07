#pragma once
#include "BDD.h"
#include "Client.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class ClientRepository
{
private:
    BDD^ bdd;
public:
    ClientRepository(BDD^ bdd) :bdd(bdd) {
    }
    List<Client^>^ getClient(bool delState) {
        DataSet^ ds = bdd->executeQuery("SELECT c.*, a.* FROM [Client] c LEFT JOIN [Address] a ON c.[ID_Client] = a.[ID_Address]" + (/*delState*/false ? "" : " WHERE c.Del = 0"));

        List<Client^>^ list = gcnew List<Client^>();
        Client^ c = nullptr;
        for each (DataRow ^ row in ds->Tables[0]->Rows)
        {
            if (c == nullptr) {
                c = gcnew Client();
                c->setID_Client((int)row["ID_Client"]);
				c->setFirstName((String^)row["FirstName"]);
				c->setLastName((String^)row["LastName"]);
				c->setTypeClient((String^)row["TypeClient"]);
				c->setBirthday((DateTime^)row["Birthday"]);

				list->Add(c);

            }
            if (!row->IsNull("ID_Address")) {
                Address^ address = gcnew Address();
                address->setID_Address((int)row["ID_Address"]);
                address->setNumber((String^)row["Number"]);
                address->setNameStreet((String^)row["NameStreet"]);
                address->setNameCity((String^)row["NameCity"]);
                address->setPostalCode((String^)row["PostalCode"]);
                address->setAddition((String^)row["Addition"]);
				c->getAddress()->Add(address);
            }
        }
		return list;
    }
    void editClient(Client^ client) {
       bdd->executeNonQuery("UPDATE [Client] SET FirstName = '" + client->getFirstName() + "' WHERE [ID_Client] = '" + client->getID_Client());
    }

    void deleteClient(Client^ client) {
      bdd->executeNonQuery("UPDATE [Client] SET del = true WHERE [ID_Client] = " + client->getID_Client());
    }

    void insertClient(Client^ client) {
        bdd->executeInsert("INSERT INTO [Client] (FirstName, LastName, TypeClient, Birthday, Del) VALUES ('" + client->getFirstName() + "','" + client->getLastName() + "','" + client->getTypeClient() + "','" + client->getBirthday() + "','" + false + "');", 1);
		//for each (Address ^ a in client->getAddress())
            //bdd->executeInsert("INSERT INTO [Address] (ID_Address, Number, Adddition, NameStreet , NameCity, PostalCode) VALUES('" + a->getID_Address() + "','" + a->getNumber() + "', '" + a->getAddition() + "', '" + a->getNameStreet() + "', '" + a->getNameCity() + "', '" + a->getPostalCode() + false + "')", 1);
    }
};