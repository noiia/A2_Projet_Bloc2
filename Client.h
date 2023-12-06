#pragma once
using namespace System;

ref class Client
{
private:

	int ID_Client;
	String^ firstName;
	String^ lastName;
	DateTime^ Birthday;
	String^ TypeClient;
	bool del;


public:
	void setID_Client(int ID_Client) {
		this->ID_Client = ID_Client;
	}
	int getID_Client() {
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
	void setBirthday(DateTime^ Birthday) {
		this->Birthday = Birthday;
	}
	DateTime^ getBirthday() {
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