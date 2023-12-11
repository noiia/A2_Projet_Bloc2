#pragma once
#include "address.h"
using namespace System;
using namespace System::Collections::Generic;

ref class Staff
{
private:
	int ID_Staff;
	String^ lastName;
	String^ firstName;
	DateTime^ hiringDate;
	int ID_Supervisor;
	bool del;

	int ID_Address;
	String^ Number;
	String^ Addition;
	String^ NameStreet;
	String^ NameCity;
	String^ PostalCode;

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

	void setIdSupervisor(int ID_Supervisor) {
		this->ID_Supervisor = ID_Supervisor;
	}
	int getIdSupervisor() {
		return this->ID_Supervisor;
	}

	void setDel(bool deleted) {
		this->del = deleted;
	}
	bool getDel() {
		return this->del;
	}

	void setID_Address(int ID_Address) {
		this->ID_Address = ID_Address;
	}
	int getID_Address() {
		return this->ID_Address;
	}

	void setNumber(String^ Number) {
		this->Number = Number;
	}

	String^ getNumber() {
		return this->Number;
	}

	void setAddition(String^ Addition) {
		this->Addition = Addition;
	}

	String^ getAddition() {
		return this->Addition;
	}

	void setNameStreet(String^ NameStreet) {
		this->NameStreet = NameStreet;
	}

	String^ getNameStreet() {
		return this->NameStreet;
	}

	void setNameCity(String^ NameCity) {
		this->NameCity = NameCity;
	}

	String^ getNameCity() {
		return this->NameCity;
	}

	void setPostalCode(String^ PostalCode) {
		this->PostalCode = PostalCode;
	}

	String^ getPostalCode() {
		return this->PostalCode;
	}

};