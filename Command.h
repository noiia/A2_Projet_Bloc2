#pragma once
#include "Article.h"
using namespace System;
using namespace System::Collections::Generic;

ref class Command
{
private:
	String^ reference;
	String^ idArticle;
	int quantity;
	List<Article^>^ articles = gcnew List<Article^>();
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
	List<Article^>^ getArticle() {
		return this->articles;
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