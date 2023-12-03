#pragma once
using namespace System;

ref class Client
{
private:

	String^ ID_Client;
	String^ firstName;
	String^ lastName;
	DateTime^ Birthday;
	String^ NumeroAdressDelivery;
	String^ StreetAdressDelivery;
	String^ StreetDelivery;
	String^ PostalCodeDelivery;
	String^ CityDelivery;
	String^ NumeroBilling;
	String^ StreetBilling;
	String^ PostalCodeBilling;
	String^ CityBilling;
	String^ TypeClient;


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
	void setBirthday(DateTime^ Birthday) {
		this->Birthday = Birthday;
	}
	DateTime^ getBirthday() {
		return this->Birthday;
	}
	void setNumeroAdressDelivery(String^ NumeroAdressDelivery) {
		this->NumeroAdressDelivery = NumeroAdressDelivery;
	}
	String^ getNumeroAdressDelivery() {
		return this->NumeroAdressDelivery;
	}
	void setStreetAdressDelivery(String^ StreetAdressDelivery) {
		this->StreetAdressDelivery = StreetAdressDelivery;
	}
	String^ getStreetAdressDelivery() {
		return this->StreetAdressDelivery;
	}
	void setStreetDelivery(String^ StreetDelivery) {
		this->StreetDelivery = StreetDelivery;
	}
	String^ getStreetDelivery() {
		return this->StreetDelivery;
	}
	void setPostalCodeDelivery(String^ PostalCodeDelivery) {
		this->PostalCodeDelivery = PostalCodeDelivery;
	}
	String^ getPostalCodeDelivery() {
		return this->PostalCodeDelivery;
	}
	void setCityDelivery(String^ CityDelivery) {
		this->CityDelivery = CityDelivery;
	}
	String^ getCityDelivery() {
		return this->CityDelivery;
	}
	void setNumeroBilling(String^ NumeroBilling) {
		this->NumeroBilling = NumeroBilling;
	}
	String^ getNumeroBilling() {
		return this->NumeroBilling;
	}
	void setBillingStreet(String^ StreetBilling) {
		this->StreetBilling = StreetBilling;
	}
	String^ getBillingStreet() {
		return this->StreetBilling;
	}
	void setPostalCodeBilling(String^ PostalCodeBilling) {
		this->PostalCodeBilling = PostalCodeBilling;
	}
	String^ getPostalCodeBilling() {
		return this->PostalCodeBilling;
	}
	void setCityBilling(String^ CityBilling) {
		this->CityBilling = CityBilling;
	}
	String^ getCityBilling() {
		return this->CityBilling;
	}
	void setStreetBilling(String^ StreetBilling) {
		this->StreetBilling = StreetBilling;
	}
	String^ getStreetBilling() {
		return this->StreetBilling;
	}
	void setTypeClient(String^ TypeClient) {
		this->TypeClient = TypeClient;
	}
	String^ getTypeClient() {
		return this->TypeClient;
	}

};