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
	List<Address^>^ addressStaff = gcnew List<Address^>();

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

	List<Address^>^ getAddressStaff() {
		return this->addressStaff;
	}
	void addAddressDelivery(Address^ address) {
		this->addressStaff->Add(address);
	}

	String^ ToString() override {
		return " Staff id: " + this->ID_Staff + "lastName: " + this->lastName + "firstName" + this->firstName;
	}
};