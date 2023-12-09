#pragma once
#include "InstallmentPayement.h"
using namespace System;
using namespace System::Collections::Generic;

ref class CHistory
{
private:
	String^ idCommand;
	DateTime^ deliveryDate;
	DateTime^ orderDate;
	int idAddressDelivery;
	int idAddressOrder;
	List<InstallmentPayment^>^ payments = gcnew List<InstallmentPayment^>();
	//Address^ addresseFacturation;
	//Address^ addresseLivraison;

public:
	void setIdCommand(String^ idCommand) {
		this->idCommand = idCommand;
	}
	String^ getIdCommand() {
		return this->idCommand;
	}
	void setDeliveryDate(DateTime^ deliveryDate) {
		this->deliveryDate = deliveryDate;
	}
	DateTime^ getDeliveryDate() {
		return this->deliveryDate;
	}
	void setOrderDate(DateTime^ orderDate) {
		this->orderDate = orderDate;
	}
	DateTime^ getOrderDate() {
		return this->orderDate;
	}
	void setIdAddressDelivery(int idAddressDelivery) {
		this->idAddressDelivery = idAddressDelivery;
	}
	int getIdAddressDelivery() {
		return idAddressDelivery;
	}
	void setIdAddressOrder(int idAddressOrder) {
		this->idAddressOrder = idAddressOrder;
	}
	int getIdAddressOrder() {
		return idAddressOrder;
	}

	List<InstallmentPayment^>^ getPayments() {
		return this->payments;
	}
	String^ ToString() override {
		String^ s = "idCommand: " + this->idCommand + " delivery date : " + this->deliveryDate;
		s += "\n\t" + payments->Count + " InstallmentPayment :";
		for each (InstallmentPayment ^ ip in payments) {
			s += "\n\t\t" + ip->ToString();
		}
		return s;
	}
};