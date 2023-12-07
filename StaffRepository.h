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
	Object^ test = DBNull::Value;
public:
	StaffRepository(BDD^ bdd) :bdd(bdd) {

	}

	List<Staff^>^ getStaff(bool delState) {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [Staff]" + (delState ? "" : " WHERE Del = 0"));

		List<Staff^>^ list = gcnew List<Staff^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Staff^ staff = gcnew Staff();
			staff->setIdStaff((int)row[0]);
			staff->setFirstName((String^)row[1]);
			staff->setLastName((String^)row[2]);
			if (row[3] == test) {
			}
			else {
				staff->setHiringDate((DateTime^)row[3]);
			}
			list->Add(staff);
		}

		return list;
	}

	void editStaff(Staff^ staff) {
		bdd->executeNonQuery("UPDATE [Staff] SET FirstName = '" + staff->getFirstName() + "', LastName = '" + staff->getLastName() + "', HiringDate = '" + staff->getHiringDate() + "', Del = '" + false + "' WHERE ID_Staff = '" + staff->getIdStaff() + "'");
	}

	void deleteStaff(Staff^ staff, int delOrRestore) {
		bdd->executeNonQuery("UPDATE [Staff] SET Del = " + delOrRestore + " WHERE [ID_Staff] = '" + staff->getIdStaff() + "'");
	}

	void insertStaff(Staff^ staff) {
		bdd->executeInsert("INSERT INTO [Staff] (FirstName, LastName, HiringDate, Del) VALUES ('" + staff->getFirstName() + "','" + staff->getLastName() + "','" + staff->getHiringDate() + "','" + false + "')", 1);
	}
};





//	void insertStaff(Staff^ staff) {
//	uint32_t idStaff = bdd->executeInsert("INSERT INTO [Staff] (LastName, FirstName, Del) VALUES ('" + staff->getLastName() + "', '" + staff->getFirstName() + "', '" + false + "')", 1);
//	System::Diagnostics::Debug::WriteLine(idStaff);
//	staff->setIdStaff(idStaff);
//	//Enregistrer ses adresses "')");
//}
