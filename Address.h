#pragma once
using namespace System;

ref class Address
{
private:
	int ID_Adress;
	String^ Number;
	String^ Addition;
	String^ NameStreet;
	String^ NameCity;
	String^ PostalCode;
	bool del;

public:
	void setID_Address(int ID_Address) {
		this->ID_Adress = ID_Address;
	}
	int getID_Address() {
		return this->ID_Adress;
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
