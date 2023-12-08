#pragma once
#include "Article.h"
#include "Client.h"
using namespace System;
using namespace System::Collections::Generic;

ref class Command
{
private:
	String^ reference;
	String^ idArticle;
	int IdClient;
	String^ FirstNameClient;
	String^ LastNameClient;
	String^ addressDeliveryClient;
	String^ addressBillingClient;
	int quantity;
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
	List<Article^>^ articles = gcnew List<Article^>();
	List<Client^>^ clients = gcnew List<Client^>();
public:
	void setReference(String^ reference) {
		this->reference = reference;
	}
	String^ getReference() {
		return this->reference;
	}
	void setIdArticle(String^ idArticle) {
		this->idArticle = idArticle;
	}
	String^ getIdArticle() {
		return this->idArticle;
	}
	void setQuantity(int quantity) {
		this->quantity = quantity;
	}
	int getQuantity() {
		return this->quantity;
	}

	void setIdClient(int idClient) {
		this->IdClient = idClient;
	}
	int getIdClient() {
		return this->IdClient;
	}
	void setFirstNameClient(String^ FirstNameClient) {
		this->FirstNameClient = FirstNameClient;
	}
	String^ getFirstNameClient() {
		return this->FirstNameClient;
	}
	void setLastNameClient(String^ LastNameClient) {
		this->LastNameClient = LastNameClient;
	}
	String^ getLastNameClient() {
		return this->LastNameClient;
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

	List<Article^>^ getArticle() {
		return this->articles;
	}
	List<Client^>^ getClient() {
		return this->clients;
	}
	String^ ToString() override {
		String^ s = "idArticle: " + this->idArticle + " quantity : " + this->quantity;
		s += "\n\t" + articles->Count + " Article :";
		for each (Article ^ ip in articles) {
			s += "\n\t\t" + ip->ToString();
		}
		return s;
	}

};