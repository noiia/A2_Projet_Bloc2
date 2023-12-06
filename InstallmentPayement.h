#pragma once
using namespace System;

ref class InstallmentPayment
{
	DateTime^ paymentDate;
	DateTime^ balancePaymentDate;
	String^ paymentMode;
	int installmentNumber;
	Decimal amount;
public:
	void setPaymentDate(DateTime^ paymentDate) {
		this->paymentDate = paymentDate;
	}
	DateTime^ getPaymentDate() {
		return this->paymentDate;
	}
	void setBalancePaymentDate(DateTime^ balancePaymentDate) {
		this->balancePaymentDate = balancePaymentDate;
	}
	DateTime^ getBalancePaymentDate() {
		return this->balancePaymentDate;
	}
	void setPaymentMode(String^ paymentMode) {
		this->paymentMode = paymentMode;
	}
	String^ getPaymentMode() {
		return this->paymentMode;
	}
	void setInstallmentNumber(int installmentNumber) {
		this->installmentNumber = installmentNumber;
	}
	int getInstallmentNumber() {
		return installmentNumber;
	}
	void setAmount(Decimal amount) {
		this->amount = amount;
	}
	Decimal getAmount() {
		return amount;
	}
	String^ ToString() override {
		return installmentNumber + " " + amount + " " + paymentMode;
	}
};

