#pragma once
using namespace System;

ref class Article
{
private:
	String^ idArticle;
	String^ name;
	String^ kind;
	int stock;
	int restockLimit;
	Decimal^ priceWT;
	Decimal^ VAT;
	Decimal^ priceATI;
	String^ restockingDate; 

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
	void setVAT(Decimal^ VAT) {
		this->VAT = VAT;
	}
	Decimal^ getVAT() {
		return this->VAT;
	}
	void setPriceATI(Decimal^ priceATI) {
		this->priceATI = priceATI;
	}
	Decimal^ getPriceATI() {
		return this->priceATI;
	}
	void setStock(int stock) {
		this->stock = stock;
	}
	int getStock() {
		return this->stock;
	}	
	void setRestockingLimit(int restockLimit) {
		this->restockLimit = restockLimit;
	}
	int getRestockingLimit() {
		return this->restockLimit;
	}
	void setRestockingDate(String^ restockingDate) {
		this->restockingDate = restockingDate;
	}
	String^ getRestockingDate() {
		return this->restockingDate;
	}


	String^ ToString() override {
		return "User id: " + this->idArticle + " name: " + this->name + " priceWT : " + this->priceWT;
	}
};