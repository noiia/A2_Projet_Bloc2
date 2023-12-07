#pragma once
#include <iostream>
#using <System.dll>
#include "BDD.h"
#include "Client.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class ClientRepository
{
private:
    BDD^ bdd;
    Object^ test = DBNull::Value;
    
public:
    ClientRepository(BDD^ bdd) :bdd(bdd) {
    }
    List<Client^>^ getClient(bool delState) {
        DataSet^ ds = bdd->executeQuery("SELECT * FROM [Client]" + (delState ? "" : " WHERE Del = 0"));

        List<Client^>^ list = gcnew List<Client^>();

        for each (DataRow ^ row in ds->Tables[0]->Rows)
        {
            Client^ client = gcnew Client();
            client->setID_Client((int)row[0]);
            client->setFirstName((String^)row[1]);
            client->setLastName((String^)row[2]);
            client->setTypeClient((String^)row[3]);
            if (row[4] == test) {
            }
            else {
                client->setBirthday((DateTime^)row[4]);
            }
            list->Add(client);

        }
        return list;
    }
    void editClient(Client^ client) {
        bdd->executeNonQuery("UPDATE [Client] SET FirstName = '" + client->getFirstName() + "', LastName = '" + client->getLastName() +"', BirthDay = '" + client->getBirthday() +"', TypeClient ='" + client->getTypeClient() +"', Del = '" + false +"' WHERE [ID_Client] = '" + client->getID_Client() + "'");
    }

    void deleteClient(Client^ client, int delOrRestore) {
        bdd->executeNonQuery("UPDATE [Client] SET Del = " + delOrRestore + " WHERE [ID_Client] = '" + client->getID_Client() + "'");
    }
    void insertClient(Client^ client) {
        bdd->executeInsert("INSERT INTO [Client] (FirstName, LastName, TypeClient, Birthday, Del) VALUES ('" + client->getFirstName() + "','" + client->getLastName() + "','" + client->getTypeClient() + "','" + client->getBirthday()->ToString("yyyy-MM-dd") + "','" + false + "')", 1);
    }
    void insertClientCompany(Client^ client) {
        bdd->executeInsert("INSERT INTO [Client] (FirstName, LastName, TypeClient, Del) VALUES ('" + client->getFirstName() + "','" + client->getLastName() + "','" + client->getTypeClient() + "','" + false + "')", 1);
    }
};