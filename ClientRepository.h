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
        DataSet^ ds = bdd->executeQuery("SELECT c.*, \
    acd.TypeAddress AS del_TypeAddress, \
    acb.TypeAddress AS bil_TypeAddress, \
    ad.ID_Address AS del_ID_Address, \
    ad.Number AS del_Number, \
    ad.Addition AS del_Addition, \
    ad.NameStreet AS del_NameStreet, \
    ad.NameCity AS del_NameCity, \
    ad.PostalCode AS del_PostalCode, \
    ab.ID_Address AS bil_ID_Address, \
    ab.Number AS bil_Number, \
    ab.Addition AS bil_Addition, \
    ab.NameStreet AS bil_NameStreet, \
    ab.NameCity AS bil_NameCity, \
    ab.PostalCode AS bil_PostalCode \
    FROM [Client] c \
    LEFT JOIN [address_Client] acd ON c.ID_Client = acd.ID_Client AND acd.TypeAddress = 'Adresse de livraison' \
    LEFT JOIN [Address] ad ON acd.ID_Address = ad.ID_Address \
    LEFT JOIN [address_Client] acb ON c.ID_Client = acb.ID_Client AND acb.TypeAddress = 'Adresse de Facturation' \
    LEFT JOIN [Address] ab ON acb.ID_Address = ab.ID_Address \
    WHERE c.Del = 0");


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

            if (!row->IsNull("del_typeAddress") && !row->IsNull("bil_typeAddress")) {
                c->setTypeAddressDelivery((String^)row["del_TypeAddress"]);
                c->setID_AddressDelivery((int)row["del_ID_Address"]);
                c->setNumberDelivery((String^)row["del_Number"]);
                c->setNameStreetDelivery((String^)row["del_NameStreet"]);
                c->setNameCityDelivery((String^)row["del_NameCity"]);
                c->setPostalCodeDelivery((String^)row["del_PostalCode"]);
                c->setAdditionDelivery((String^)row["del_Addition"]);
                c->setTypeAddressDelivery((String^)row["del_TypeAddress"]);


               
                c->setTypeAddressBilling((String^)row["bil_TypeAddress"]);
                c->setID_AddressBilling((int)row["bil_ID_Address"]);
                c->setNumberBilling((String^)row["bil_Number"]);
                c->setNameStreetBilling((String^)row["bil_NameStreet"]);
                c->setNameCityBilling((String^)row["bil_NameCity"]);
                c->setPostalCodeBilling((String^)row["bil_PostalCode"]);
                c->setAdditionBilling((String^)row["bil_Addition"]);
                c->setTypeAddressBilling((String^)row["bil_typeAddress"]);


            }

            list->Add(c);
        }
        return list;
    }

    void editClient(Client^ client) {
        bdd->executeNonQuery("UPDATE [Client] SET  FirstName = '" + client->getFirstName() + "', LastName = '" + client->getLastName() + "', Birthday = '" + client->getBirthday() + "', TypeClient = '" + client->getTypeClient() + "' WHERE[ID_Client] = " + client->getID_Client());
        //bdd->executeNonQuery("UPDATE [address] SET Number = '" + client->getNumberDelivery() + "', Addition = '" + client->getAdditionDelivery() + "', NameStreet = '" + client->getNameStreetDelivery() + "', NameCity = '" + client->getNameCityDelivery() + "', PostalCode = '" + client->getPostalCodeDelivery() + "' WHERE[ID_Address] = " + client->getID_AddressDelivery());
        //bdd->executeNonQuery("UPDATE [address] SET Number = '" + client->getNumberBilling() + "', Addition = '" + client->getAdditionBilling() + "', NameStreet = '" + client->getNameStreetBilling() + "', NameCity = '" + client->getNameCityBilling() + "', PostalCode = '" + client->getPostalCodeBilling() + "' WHERE[ID_Address] = " + client->getID_AddressBilling());
    
        bdd->executeNonQuery("UPDATE [Address] SET Number = '" + client->getNumberDelivery() + "', Addition = '" + client->getAdditionDelivery() + "', NameStreet = '" + client->getNameStreetDelivery() + "', NameCity = '" + client->getNameCityDelivery() + "', PostalCode = '" + client->getPostalCodeDelivery() + "' WHERE ID_Address = " + client->getID_AddressDelivery());
        bdd->executeNonQuery("UPDATE [Address] SET Number = '" + client->getNumberBilling() + "', Addition = '" + client->getAdditionBilling() + "', NameStreet = '" + client->getNameStreetBilling() + "', NameCity = '" + client->getNameCityBilling() + "', PostalCode = '" + client->getPostalCodeBilling() + "' WHERE ID_Address = " + client->getID_AddressBilling());
    
    }

    void deleteClient(Client^ client, int delOrRestore) {
        bdd->executeNonQuery("UPDATE [Client] SET Del = "+ delOrRestore + " WHERE [ID_Client] = " + client->getID_Client());
        bdd->executeNonQuery("UPDATE [Address] SET Del = " + delOrRestore + " WHERE [ID_Address] = " + client->getID_AddressDelivery());
        bdd->executeNonQuery("UPDATE [Address] SET Del = " + delOrRestore + " WHERE [ID_Address] = " + client->getID_AddressBilling());
        
    }

    void insertClient(Client^ client) {
        int ID_Client = bdd->executeInsert("INSERT INTO [Client] (FirstName, LastName, TypeClient, Birthday, Del) VALUES ('" + client->getFirstName() + "','" + client->getLastName() + "','" + client->getTypeClient() + "','" + client->getBirthday() + "'," + 0 + ")", 1);
        int ID_Address = bdd->executeInsert("INSERT INTO [Address] (Number, Addition, NameStreet , NameCity, PostalCode, Del) VALUES('" + client->getNumberDelivery() + "', '" + client->getAdditionDelivery() + "', '" + client->getNameStreetDelivery() + "', '" + client->getNameCityDelivery() + "', '" + client->getPostalCodeDelivery() + "', " + 0 + ")", 1);
        bdd->executeInsert("INSERT INTO [Address_Client] (ID_Address, ID_Client, TypeAddress) VALUES('" + ID_Address + "', '" + ID_Client + "', '" + client->getTypeAddressDelivery() + "')", 1);

        int ID_Address2 = bdd->executeInsert("INSERT INTO [Address] (Number, Addition, NameStreet , NameCity, PostalCode, Del) VALUES('" + client->getNumberBilling() + "', '" + client->getAdditionBilling() + "', '" + client->getNameStreetBilling() + "', '" + client->getNameCityBilling() + "', '" + client->getPostalCodeBilling() + "', " + 0 + ")", 1);
        bdd->executeInsert("INSERT INTO [Address_Client] (ID_Address, ID_Client, TypeAddress) VALUES('" + ID_Address2 + "', '" + ID_Client + "', '" + client->getTypeAddressBilling() + "')", 1);

    }
};
