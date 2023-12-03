#pragma once
#include "BDD.h"
#include "Client.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class ClientRepository {
private:
    BDD^ bdd;
public:
    ClientRepository(BDD^ bdd) :bdd(bdd) {
    }
    List<Client^>^ getClient() {
        DataSet^ ds = bdd->executeQuery("SELECT * FROM [Client]");
        List<Client^>^ list = gcnew List<Client^>();
        for each (DataRow ^ row in ds->Tables[0]->Rows) {
            Client^ c = gcnew Client();
            c->setID_Client((String^)row[0]);
            c->setFirstName((String^)row[1]);
            c->setLastName((String^)row[2]);
            c->setTypeClient((String^)row[3]);
            c->setBirthday((DateTime^)row[4]);
            list->Add(c);
        }
        return list;
    }
    void editClient(Client^ client) {
        bdd->executeNonQuery("UPDATE [Client] SET FirstName = '" + client->getFirstName() + "' WHERE [ID_Client] = " + client->getID_Client());
    }

    void deleteClient(Client^ client) {
        bdd->executeNonQuery("UPDATE [Client] SET del = true WHERE [ID_Client] = " + client->getID_Client());
    }

    void insertClient(Client^ client) {
        bdd->executeInsert("INSERT INTO [Client] (ID_Client, firstName, name, TypeClient, birthday,del) VALUES (" + client->getID_Client() + "','" + client->getFirstName() + "','" + client->getLastName() + "','" + client->getTypeClient() + "','" + client->getBirthday() + "','" + false + "')");
    }
};
