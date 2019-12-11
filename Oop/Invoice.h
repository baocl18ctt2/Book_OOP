#pragma once
#include "Book.h"
class Invoice
{
protected:
	Book boo;
	int mQuantity;
public:
	Invoice();
	virtual ~Invoice();
	Invoice(Book, int);
	Invoice(Book mboo);
	Book get_book();
	void set_quanity(int quanity);
	int get_quanity();
	void set_book(Book boo);
	void display_invoice();
};

