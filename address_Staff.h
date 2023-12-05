#pragma once
using namespace System;

ref class Address_Staff
{
public:
	int ID_Address;
	int  ID_Staff;

private:
	void setID_Address(int ID_Adress) {
		this->ID_Address = ID_Adress;
	}
	int getID_Address() {
		return this->ID_Address;
	}
	void setID_Staff(int ID_Staff) {
		this->ID_Staff = ID_Staff;
	}
	int getID_Staff() {
		return this->ID_Staff;
	}
};

