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
        DataSet^ ds = bdd->executeQuery("SELECT c.*, a.*, ac.* FROM [Client] c LEFT JOIN [address_Client] ac ON c.ID_Client = c.ID_Client LEFT JOIN [Address] a ON ac.ID_Address = a.ID_Address" + (/*delState*/false ? "" : " WHERE c.Del = 0"));

        List<Client^>^ list = gcnew List<Client^>();
        List<Client^>^ listAddressDelivery = gcnew List<Client^>();;
        List<Client^>^ listAddressBilling = gcnew List<Client^>();;
        Client^ c = nullptr;
        Client^ listAddressDelivery = nullptr;
        Client^ listAddressBilling = nullptr;

        for each (DataRow ^ row in ds->Tables[0]->Rows)
        {
                c = gcnew Client();
                c->setID_Client((int)row["ID_Client"]);
				c->setFirstName((String^)row["FirstName"]);
				c->setLastName((String^)row["LastName"]);
				c->setTypeClient((String^)row["TypeClient"]);
				c->setBirthday((DateTime^)row["Birthday"]);
                c->setID_AddressDelivery((int)row["ID_Address"]);
                c->setNumberDelivery((String^)row["Number"]);
                c->setNameStreetDelivery((String^)row["NameStreet"]);
                c->setNameCityDelivery((String^)row["NameCity"]);
                c->setPostalCodeDelivery((String^)row["PostalCode"]);
                c->setAdditionDelivery((String^)row["Addition"]);
                c->setID_AddressBilling((int)row["ID_Address"]);
                c->setNumberBilling((String^)row["Number"]);
                c->setNameStreetBilling((String^)row["NameStreet"]);
                c->setNameCityBilling((String^)row["NameCity"]);
                c->setPostalCodeBilling((String^)row["PostalCode"]);
                c->setAdditionBilling((String^)row["Addition"]);
                list->Add(c);
			
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
		//for each (Address ^ address in client->getAddressDelivery())
            //bdd->executeInsert("INSERT INTO [Address] (Number, Adddition, NameStreet , NameCity, PostalCode) VALUES('" + address->getNumber() + "', '" + address->getAddition() + "', '" + address->getNameStreet() + "', '" + address->getNameCity() + "', '" + address->getPostalCode() + false + "')", 1);
        //for each (Address ^ address in client->getAddressBilling())
            //bdd->executeInsert("INSERT INTO [Address] (Number, Adddition, NameStreet , NameCity, PostalCode) VALUES('" + address->getNumber() + "', '" + address->getAddition() + "', '" + address->getNameStreet() + "', '" + address->getNameCity() + "', '" + address->getPostalCode() + false + "')", 1);
    }
};