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
	int idArticleInCart;

	int IdClient;
	String^ FirstNameClient;
	String^ LastNameClient;
	DateTime^ orderDate;
	DateTime^ deliveryDate;
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

	String^ paymentMode;
	int numberOfPayment;
	float commandAmount;
	float firstAmount;
	float secondAmount;
	float thirdAmount;
	DateTime^ firstPayment;
	DateTime^ secondPayment;
	DateTime^ thirdPayment;
	DateTime^ firstPaymentReception;
	DateTime^ secondPaymentReception;
	DateTime^ thirdPaymentReception;

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
	void setIdArticleInCart(int idArticleInCart) {
		this->idArticleInCart = idArticleInCart;
	}
	int getIdArticleInCart() {
		return this->idArticleInCart;
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
	void setOrderDate(DateTime^ orderDate) {
		this->orderDate = orderDate;
	}
	DateTime^ getOrderDate() {
		return this->orderDate;
	}
	void setDeliveryDate(DateTime^ deliveryDate) {
		this->deliveryDate = deliveryDate;
	}
	DateTime^ getDeliveryDate() {
		return this->deliveryDate;
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

	void setPaymentMode(String^ paymentMode) {
		this->paymentMode = paymentMode;
	}
	String^ getPaymentMode() {
		return this->paymentMode;
	}
	void setNumberOfPayment(int numberOfPayment) {
		this->numberOfPayment = numberOfPayment;
	}
	int getNumberOfPayment() {
		return this->numberOfPayment;
	}
	void setFirstPayment(DateTime^ firstPayment) {
		this->firstPayment = firstPayment;
	}
	DateTime^ getFirstPayment() {
		return this->firstPayment;
	}
	void setSecondPayment(DateTime^ secondPayment) {
		this->secondPayment = secondPayment;
	}
	DateTime^ getSecondPayment() {
		return this->secondPayment;
	}
	void setThirdPayment(DateTime^ thirdPayment) {
		this->thirdPayment = thirdPayment;
	}
	DateTime^ getThirdPayment() {
		return this->thirdPayment;
	}
	void setFirstPaymentReception(DateTime^ firstPaymentReception) {
		this->firstPaymentReception = firstPaymentReception;
	}
	DateTime^ getFirstPaymentReception() {
		return this->firstPaymentReception;
	}
	void setSecondPaymentReception(DateTime^ secondPaymentReception) {
		this->secondPaymentReception = secondPaymentReception;
	}
	DateTime^ getSecondPaymentReception() {
		return this->secondPaymentReception;
	}
	void setThirdPaymentReception(DateTime^ thirdPaymentReception) {
		this->thirdPaymentReception = thirdPaymentReception;
	}
	DateTime^ getThirdPaymentReception() {
		return this->thirdPaymentReception;
	}
	void setFirstAmount(float firstAmount) {
		this->firstAmount = firstAmount;
	}
	float getFirstAmount() {
		return firstAmount;
	}
	void setSecondAmount(float secondAmount) {
		this->secondAmount = secondAmount;
	}
	float getSecondAmount() {
		return secondAmount;
	}
	void setThirdAmount(float thirdAmount) {
		this->thirdAmount = thirdAmount;
	}
	float getThirdAmount() {
		return thirdAmount;
	}
	void setCommandAmount(float commandAmount) {
		this->commandAmount = commandAmount;
	}
	float getCommandAmount() {
		return commandAmount;
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