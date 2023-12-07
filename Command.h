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
	void setAddressDeliveryClient(String^ AddressDeliveryClient) {
		this->addressDeliveryClient = AddressDeliveryClient;
	}
	String^ getAddressDeliveryClient() {
		return this->addressDeliveryClient;
	}
	void setAddressBillingClient(String^ AddressBillingClient) {
		this->addressBillingClient = AddressBillingClient;
	}
	String^ getAddressBillingClient() {
		return this->addressBillingClient;
	}
	void setQuantity(int quantity) {
		this->quantity = quantity;
	}
	int getQuantity() {
		return this->quantity;
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