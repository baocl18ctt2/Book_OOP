#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "List_Book.h"
using namespace std;
class fileInvoice
{
protected:
	string mCode;
	string mName;
	long long mPrice;
	float mQuantity;
public:
	vector<fileInvoice*> listInvoice;
	fileInvoice();
	fileInvoice(vector<fileInvoice*> list);
	fileInvoice(string, string, long long, float);
	~fileInvoice();
	void read_1_invoice(ifstream& FileInvoice);
	void read_invoice(ifstream& FileInvoice);
	void set_code(string code);
	string get_code();
	void set_name(string name);
	string get_name();
	void set_price(long long price);
	long long get_price();
	void set_quantity(float quantity);
	float get_quantity();
	void display_invoice();
	void find_invoice_max(ifstream& FileBook);
	void print_total_max();
	void print_menu(ifstream& FileInvoice, ifstream& FileBook);
};

