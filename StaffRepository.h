#pragma once
#include "BDD.h"
#include "Staff.h"

using namespace  System::Collections::Generic;
using namespace System;
using namespace System::Data;

ref class StaffRepository
{
private:
	BDD^ bdd;

public:
	StaffRepository(BDD^ bdd) :bdd(bdd) {

	}

	List<Staff^>^ getStaff(bool delState) {
		DataSet^ ds = bdd->executeQuery("SELECT s.FirstName, s.LastName, s.HiringDate, s.ID_Supervisor, a.Number, a.Addition, a.NameStreet, a.NameCity,a.PostalCode, astaff.*\
			FROM Staff s\
			LEFT JOIN address_Staff astaff ON s.ID_Staff = astaff.ID_Staff\
			LEFT JOIN Address a ON astaff.ID_Address = a.ID_Address\
			WHERE s.Del = '" + delState + "'");


		List<Staff^>^ list = gcnew List<Staff^>();
		Staff^ s = nullptr;

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			s = gcnew Staff();
			if (!row->IsNull("Number")) {
				s->setIdStaff((int)row["ID_Staff"]);
				s->setFirstName((String^)row["FirstName"]);
				s->setLastName((String^)row["LastName"]);
				s->setHiringDate((DateTime^)row["HiringDate"]);
			}

			if (!row->IsNull("Number")) {
				s->setID_Address((int)row["ID_Address"]);
				s->setNumber((String^)row["Number"]);
				s->setNameStreet((String^)row["NameStreet"]);
				s->setNameCity((String^)row["NameCity"]);
				s->setPostalCode((String^)row["PostalCode"]);
				s->setAddition((String^)row["Addition"]);
			}

			list->Add(s);

		}

		return list;
	}

	void editStaff(Staff^ staff) {
		bdd->executeNonQuery("UPDATE [Staff] SET FirstName = '" + staff->getFirstName() + "', LastName = '" + staff->getLastName() + "', HiringDate = '" + staff->getHiringDate() + "', Del = '" + false + "' WHERE ID_Staff = '" + staff->getIdStaff() + "'");
	}

	void deleteStaff(Staff^ staff, int delOrRestore) {
		bdd->executeNonQuery("UPDATE [Staff] SET Del = " + delOrRestore + " WHERE [ID_Staff] = '" + staff->getIdStaff() + "'");
		bdd->executeNonQuery("UPDATE [Address] SET Del = " + delOrRestore + " WHERE [ID_Address] = " + staff->getID_Address());
	}

	void insertStaff(Staff^ staff) {
		int ID_Staff = bdd->executeInsert("INSERT INTO [Staff] (LastName, FirstName, HiringDate, Del) VALUES ('" + staff->getLastName() + "','" + staff->getFirstName() + "','" + staff->getHiringDate() + "'," + 0 + ")", 1);
		int ID_Address = bdd->executeInsert("INSERT INTO [Address] (Number, Addition, NameStreet , NameCity, PostalCode, Del) VALUES('" + staff->getNumber() + "', '" + staff->getAddition() + "', '" + staff->getNameStreet() + "', '" + staff->getNameCity() + "', '" + staff->getPostalCode() + "', " + 0 + ")", 1);
		bdd->executeInsert("INSERT INTO [Address_Staff] (ID_Address, ID_Staff) VALUES('" + ID_Address + "', '" + ID_Staff + "')", 1);
	}
};





//	void insertStaff(Staff^ staff) {
//	uint32_t idStaff = bdd->executeInsert("INSERT INTO [Staff] (LastName, FirstName, Del) VALUES ('" + staff->getLastName() + "', '" + staff->getFirstName() + "', '" + false + "')", 1);
//	System::Diagnostics::Debug::WriteLine(idStaff);
//	staff->setIdStaff(idStaff);
//	//Enregistrer ses adresses "')");
//}