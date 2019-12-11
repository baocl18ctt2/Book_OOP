#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Book
{
protected:
	string mName;
	string mCode;
	double mPrice;
	string mAuthor;
	string mPublisher;
	bool HideBook;
public:
	Book();
	virtual ~Book();
	Book(string, string, double, string, string);
	void set_name(string name);
	string get_name();
	void set_code(string code);
	string get_code();
	void set_price(double price);
	double get_price();
	string set_code();
	void set_author(string author);
	string get_author();
	void set_publisher(string publisher);
	string get_publisher();
	void read_book_file(ifstream& FileIn);
	void set_hidebook(bool hide);
	bool get_hidebook();
};

