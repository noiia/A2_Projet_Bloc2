#pragma once
#include "BDD.h"
#include "address_Staff.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class address_StaffRepository
{
private:
	BDD^ bdd;

public:
	address_StaffRepository(BDD^ bdd) :bdd(bdd) {
	}
	List<Address_Staff^>^ getAddress_Staff() {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [address_Staff]");

		List<Address_Staff^>^ list = gcnew List<Address_Staff^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Address_Staff^ address_staff = gcnew Address_Staff();
			address_staff->setID_Address((int)row[0]);
			address_staff->setID_Staff((int)row[1]);
			list->Add(address_staff);
		}
		return list;
	}
};