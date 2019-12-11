#pragma once
#include "Invoice.h"
#include "List_Book.h"
#include <vector>
class List_Invoice
{
protected:
	vector<Invoice> list_invoice;
public:
	List_Invoice();
	virtual ~List_Invoice();
	void input_data(List_Book& lbook);
	void output_data();
	void edit_invoice();
	Invoice search_book_invoice();
	void modify_quanity();
	void delete_book_invoice();
	void display_file_invoice();
};

