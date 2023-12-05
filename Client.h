#pragma once
using namespace System;

ref class Client
{
private:

	String^ ID_Client;
	String^ firstName;
	String^ lastName;
	String^ Birthday;
	String^ TypeClient;
	bool del;


public:
	void setID_Client(String^ ID_Client) {
		this->ID_Client = ID_Client;
	}
	String^ getID_Client() {
		return this->ID_Client;
	}
	void setFirstName(String^ firstName) {
		this->firstName = firstName;
	}
	String^ getFirstName() {
		return this->firstName;
	}
	void setLastName(String^ lastName) {
		this->lastName = lastName;
	}
	String^ getLastName() {
		return this->lastName;
	}
	void setBirthday(String^ Birthday) {
		this->Birthday = Birthday;
	}
	String^ getBirthday() {
		return this->Birthday;
	}
	void setTypeClient(String^ TypeClient) {
		this->TypeClient = TypeClient;
	}
	String^ getTypeClient() {
		return this->TypeClient;
	}
	void setDel(bool del) {
		this->del = del;
	}
	bool getDel() {
		return this->del;
	}
};