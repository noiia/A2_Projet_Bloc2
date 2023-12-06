#pragma once
using namespace System;

ref class Command
{
private:
	String^ reference;
	String^ idArticle;
	int quantity;
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

};