#pragma once
#include "address.h"
using namespace System;
using namespace System::Collections::Generic;


ref class Client
{
private:

	int ID_Client;
	String^ firstName;
	String^ lastName;
	DateTime^ Birthday;
	String^ TypeClient;
	bool del;
	int ID_AddressDelivery;
	String^ NumberDelivery;
	String^ AdditionDelivery;
	String^ NameStreetDelivery;
	String^ NameCityDelivery;
	String^ PostalCodeDelivery;
	int ID_AddressBilling;
	String^ NumberBilling;
	String^ AdditionBilling;
	String^ NameStreetBilling;
	String^ NameCityBilling;
	String^ PostalCodeBilling;
	
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
	void setID_AddressDelivery(int ID_AddressDelivery) {
		this->ID_AddressDelivery = ID_AddressDelivery;
	}
	int getID_AddressDelivery() {
		return this->ID_AddressDelivery;
	}
	void setNumberDelivery(String^ NumberDelivery) {
		this->NumberDelivery = NumberDelivery;
	}
	String^ getNumberDelivery() {
		return this->NumberDelivery;
	}
	void setAdditionDelivery(String^ AdditionDelivery) {
		this->AdditionDelivery = AdditionDelivery;
	}
	String^ getAdditionDelivery() {
		return this->AdditionDelivery;
	}
	void setNameStreetDelivery(String^ NameStreetDelivery) {
		this->NameStreetDelivery = NameStreetDelivery;
	}
	String^ getNameStreetDelivery() {
		return this->NameStreetDelivery;
	}
	void setNameCityDelivery(String^ NameCityDelivery) {
		this->NameCityDelivery = NameCityDelivery;
	}
	String^ getNameCityDelivery() {
		return this->NameCityDelivery;
	}
	void setPostalCodeDelivery(String^ PostalCodeDelivery) {
		this->PostalCodeDelivery = PostalCodeDelivery;
	}
	String^ getPostalCodeDelivery() {
		return this->PostalCodeDelivery;
	}
	
	
	void setID_AddressBilling(int ID_AddressBilling) {
		this->ID_AddressBilling = ID_AddressBilling;
	}
	int getID_AddressBilling() {
		return this->ID_AddressBilling;
	}
	void setNumberBilling(String^ NumberBilling) {
		this->NumberBilling = NumberBilling;
	}
	String^ getNumberBilling() {
		return this->NumberBilling;
	}
	void setAdditionBilling(String^ AdditionBilling) {
		this->AdditionBilling = AdditionBilling;
	}
	String^ getAdditionBilling() {
		return this->AdditionBilling;
	}
	void setNameStreetBilling(String^ NameStreetBilling) {
		this->NameStreetBilling = NameStreetBilling;
	}
	String^ getNameStreetBilling() {
		return this->NameStreetBilling;
	}
	void setNameCityBilling(String^ NameCityBilling) {
		this->NameCityBilling = NameCityBilling;
	}
	String^ getNameCityBilling() {
		return this->NameCityBilling;
	}
	void setPostalCodeBilling(String^ PostalCodeBilling) {
		this->PostalCodeBilling = PostalCodeBilling;
	}
	String^ getPostalCodeBilling() {
		return this->PostalCodeBilling;
	}



};