#pragma once
#include "BDD.h"
#include "Client.h"

using namespace System::Collections::Generic;
using namespace System;
using namespace System::Data;

ref class ClientRepository
{
private:
    BDD^ bdd;

public:
    ClientRepository(BDD^ bdd) : bdd(bdd) {
    }
    List<Client^>^ getClient(bool delState) {
        DataSet^ ds = bdd->executeQuery("SELECT c.*, a.*, ac.* FROM [Client] c LEFT JOIN [address_Client] ac ON c.ID_Client = ac.ID_Client LEFT JOIN [Address] a ON ac.ID_Address = a.ID_Address" + (delState ? "" : " WHERE c.Del = 0 AND a.Del=0"));

        List<Client^>^ list = gcnew List<Client^>();
        Client^ c = nullptr;

        for each (DataRow ^ row in ds->Tables[0]->Rows) {
            c = gcnew Client();

            c->setID_Client((int)row["ID_Client"]);
            c->setFirstName((String^)row["FirstName"]);
            c->setLastName((String^)row["LastName"]);
            c->setTypeClient((String^)row["TypeClient"]);
            c->setBirthday((DateTime^)row["Birthday"]);
            c->setDel((bool)row["Del"]);

            if (!row->IsNull("typeAddress")) {
                c->setTypeAddrress((String^)row["typeAddress"]);
                c->setID_Address((int)row["ID_Address"]);
                c->setNumberDelivery((String^)row["Number"]);
                c->setNameStreetDelivery((String^)row["NameStreet"]);
                c->setNameCityDelivery((String^)row["NameCity"]);
                c->setPostalCodeDelivery((String^)row["PostalCode"]);
                c->setAdditionDelivery((String^)row["Addition"]);
                c->setDel((bool)row["Del"]);


                c->setTypeAddrress((String^)row["typeAddress"]);
                c->setID_Address((int)row["ID_Address"]);
                c->setNumberBilling((String^)row["Number"]);
                c->setNameStreetBilling((String^)row["NameStreet"]);
                c->setNameCityBilling((String^)row["NameCity"]);
                c->setPostalCodeBilling((String^)row["PostalCode"]);
                c->setAdditionBilling((String^)row["Addition"]);
                c->setDel((bool)row["Del"]);

            }

            list->Add(c);
        }
        return list;
    }

    void editClient(Client^ client) {
        bdd->executeNonQuery("UPDATE [Client] SET FirstName = '" + client->getFirstName() + "' WHERE [ID_Client] = " + client->getID_Client());
    }

    void deleteClient(Client^ client) {
        bdd->executeNonQuery("UPDATE [Client] SET Del = true WHERE [ID_Client] = " + client->getID_Client());
    }

    void insertClient(Client^ client) {
        bdd->executeInsert("INSERT INTO [Client] (FirstName, LastName, TypeClient, Birthday, Del) VALUES ('" + client->getFirstName() + "','" + client->getLastName() + "','" + client->getTypeClient() + "','" + client->getBirthday() + "'," + 0 + ")", 1);
        bdd->executeInsert("INSERT INTO [Address] (Number, Addition, NameStreet , NameCity, PostalCode, Del) VALUES('" + client->getNumberDelivery() + "', '" + client->getAdditionDelivery() + "', '" + client->getNameStreetDelivery() + "', '" + client->getNameCityDelivery() + "', '" + client->getPostalCodeDelivery() + "', " + 0 + ")", 1);
        bdd->executeInsert("INSERT INTO [Address] (Number, Addition, NameStreet , NameCity, PostalCode, Del) VALUES('" + client->getNumberBilling() + "', '" + client->getAdditionBilling() + "', '" + client->getNameStreetBilling() + "', '" + client->getNameCityBilling() + "', '" + client->getPostalCodeBilling() + "', " + 0 + ")", 1);
    }
};