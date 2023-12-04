#pragma once
using namespace System;

ref class Article
{
private:
	String^ idArticle;
	String^ name;
	String^ kind;
	long long stock;
	long long restockLimit;
	Decimal^ priceWT;
	int VAT;
	Decimal^ priceATI;
	DateTime^ restockingDate; 
	bool deleteState;

public:
	void setIdArticle(String^ idArticle) {
		this->idArticle = idArticle;
	}
	String^ getIdArticle() {
		return this->idArticle;
	}
	void setName(String^ name) {
		this->name = name;
	}
	String^ getName() {
		return this->name;
	}
	void setKind(String^ kind) {
		this->kind = kind;
	}
	String^ getKind() {
		return this->kind;
	}
	void setPriceWT(Decimal^ priceWT) {
		this->priceWT = priceWT;
	}
	Decimal^ getPriceWT() {
		return this->priceWT;
	}
	void setVAT(int VAT) {
		this->VAT = VAT;
	}
	int getVAT() {
		return this->VAT;
	}
	void setPriceATI(Decimal^ priceATI) {
		this->priceATI = priceATI;
	}
	Decimal^ getPriceATI() {
		return this->priceATI;
	}
	void setStock(long long stock) {
		this->stock = stock;
	}
	long long getStock() {
		return this->stock;
	}	
	void setRestockingLimit(long long restockLimit) {
		this->restockLimit = restockLimit;
	}
	long long getRestockingLimit() {
		return this->restockLimit;
	}
	void setRestockingDate(DateTime^ restockingDate) {
		this->restockingDate = restockingDate;
	}
	DateTime^ getRestockingDate() {
		return this->restockingDate;
	}

	void setDel(bool deleted) {
		this->deleteState = deleted;
	}
	bool getDel() {
		return this->deleteState;
	}
	String^ ToString() override {
		return "User id: " + this->idArticle + " name: " + this->name + " priceWT : " + this->priceWT;
	}
};