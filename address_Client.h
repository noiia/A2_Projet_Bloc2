#pragma once

using namespace System;

ref class Address_Client
{
private:
	int ID_Address;
	int ID_Client;
	String^ typeAddress;
public:
	void setID_Address(int ID_Address) {
		this->ID_Address = ID_Address;
	}
	int getID_Address() {
		return this->ID_Address;
	}
	void setID_Client(int ID_Client) {
		this->ID_Client = ID_Client;
	}
	int getID_Client() {
		return this->ID_Client;
	}
	void setTypeAddress(String^ typeAddress) {
		this->typeAddress = typeAddress;
	}
	String^ getTypeAddress() {
		return this->typeAddress;
	}
};

