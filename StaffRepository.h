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

	List<Staff^>^ getStaff() {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [Staff]WHERE Del=0"); // récup code edwin

		List<Staff^>^ list = gcnew List<Staff^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			Staff^ staff = gcnew Staff();
			staff->setIdStaff((int)row[0]);
			staff->setFirstName((String^)row[1]);
			staff->setLastName((String^)row[2]);
			if (!row->IsNull("HiringDate")) {
				staff->setHiringDate(((DateTime^)row[3])->ToString("yyyy-MM-dd"));
			}
			list->Add(staff);
		}

		return list;
	}

	void editStaff(Staff^ staff) {
		bdd->executeNonQuery("UPDATE [Staff] SET LastNameStaff = '" + staff->getLastName() + "' WHERE [ID_Staff] = " + staff->getIdStaff());
	}

	void deleteStaff(Staff^ staff) {
		bdd->executeNonQuery("UPDATE [Staff] SET del = true WHERE [ID_Staff] = " + staff->getIdStaff());
	}

	void insertStaff(Staff^ staff) {
		uint32_t idStaff = bdd->executeInsert("INSERT INTO [Staff] (LastName, FirstName, Del) VALUES ('" + staff->getLastName() + "', '" + staff->getFirstName() + "', '" + false + "')", 1);
		System::Diagnostics::Debug::WriteLine(idStaff);
		staff->setIdStaff(idStaff);
		//Enregistrer ses adresses "')");
	}
};