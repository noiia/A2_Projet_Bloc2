#pragma once
using namespace System;

ref class Staff
{
private:
	int ID_Staff;
	String^ lastName;
	String^ firstName;
	DateTime^ hiringDate;
	String^ ID_Supervisor;
	bool del;

public:
	void setIdStaff(int idStaff) {
		this->ID_Staff = idStaff;
	}
	int getIdStaff() {
		return this->ID_Staff;
	}
	void setLastName(String^ lastName) {
		this->lastName = lastName;
	}
	String^ getLastName() {
		return this->lastName;
	}

	void setFirstName(String^ firstName) {
		this->firstName = firstName;
	}
	String^ getFirstName() {
		return this->firstName;
	}

	void setHiringDate(DateTime^ hiringDate) {
		this->hiringDate = hiringDate;
	}
	DateTime^ getHiringDate() {
		return this->hiringDate;
	}

	void setIdSupervisor(String^ ID_Supervisor) {
		this->ID_Supervisor = ID_Supervisor;
	}
	String^ getIdSupervisor() {
		return this->ID_Supervisor;
	}

	void setDel(bool deleted) {
		this->del = deleted;
	}
	bool getDel() {
		return this->del;
	}

	String^ ToString() override {
		return " Staff id: " + this->ID_Staff + "lastName: " + this->lastName + "firstName" + this->firstName;
	}
};