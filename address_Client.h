#pragma once

using namespace System;

ref class address_Client
{
private:
	int ID_Address;
	int ID_Client;
	String^ typeAddress;
public:
	void setTypeAddress(String^ typeAddress) {
		this->typeAddress = typeAddress;
	}
	String^ getTypeAddress() {
		return this->typeAddress;
	}
};

