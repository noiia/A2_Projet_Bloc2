#pragma once
using namespace System;

ref class Staff
{
private:
	int idStaff;
	String^ lastName;
	String^ firstName;
	String^ hiringDate;
	String^ Supervisor;
	String^ address;
	bool^ del;

public:
	void setIdStaff(int idStaff) {
		this->idStaff = idStaff;
	}
	int getIdStaff() {
		return this->idStaff;
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

	void setHiringDate(String^ hiringDate) {
		this->hiringDate = hiringDate;
	}
	String^ getHiringDate() {
		return this->hiringDate;
	}

	void setSupervisor(String^ Supervisor) {
		this->Supervisor = Supervisor;
	}
	String^ getSupervisor() {
		return this->Supervisor;
	}

	void setAddress(String^ address) {
		this->address = address;
	}
	String^ getAddress() {
		return this->address;
	}

	String^ ToString() override {
		return " Staff id: " + this->idStaff + "lastName: " + this->lastName + "firstName" + this->firstName;
	}
};
