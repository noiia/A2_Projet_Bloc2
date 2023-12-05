#pragma once
using namespace System;

ref class Address
{
private:
	int ID_Adress;
	String^ number;
	String^ addition;
	String^ nameStreet;
	String^ nameCity;
	String^ postalCode;
	bool del;

public:
	void setID_Address(int ID_Address) {
		this->ID_Adress = ID_Address;
	}
	int getID_Address() {
		return this->ID_Adress;
	}
	void setNumber(String^ number) {
		this->number = number;
	}
	String^ getNumber() {
		return this->number;
	}
	void setAddition(String^ addition) {
		this->addition = addition;
	}
	String^ getAddition() {
		return this->addition;
	}
	void setNameStreet(String^ nameStreet) {
		this->nameStreet = nameStreet;
	}
	String^ getNameStreet() {
		return this->nameStreet;
	}
	void setNameCity(String^ nameCity) {
		this->nameCity = nameCity;
	}
	String^ getNameCity() {
		return this->nameCity;
	}
	void setPostalCode(String^ postalCode) {
		this->postalCode = postalCode;
	}
	String^ getPostalCode() {
		return this->postalCode;
	}

};
