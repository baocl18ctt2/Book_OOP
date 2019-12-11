
#include "Book.h"
#include <iostream>
using namespace std;
Book::Book()
{
}


Book::~Book()
{
}

Book::Book(string name, string code, double price, string author, string publisher)
{
	mName = name;
	mCode = code;
	mPrice = price;
	mAuthor = author;
	mPublisher = publisher;
}

void Book::set_name(string name)
{
	mName = name;
}

string Book::get_name()
{
	return mName;
}

void Book::set_code(string code)
{
	mCode = code;
}

string Book::get_code()
{
	return mCode;
}

void Book::set_price(double price)
{
	mPrice = price;
}

double Book::get_price()
{
	return mPrice;
}

string Book::set_code()
{
	return mCode;
}

void Book::set_author(string author)
{
	mAuthor = author;
}

string Book::get_author()
{
	return mAuthor;
}

void Book::set_publisher(string publisher)
{
	mPublisher = publisher;
}

string Book::get_publisher()
{
	return mPublisher;
}

void Book::read_book_file(ifstream& FileIn)
{
	getline(FileIn, mName, ',');
	FileIn.seekg(1, 1);
	getline(FileIn, mCode, ',');
	FileIn.seekg(1, 1);
	FileIn >> mPrice;
	string temp;
	getline(FileIn, temp, ',');
	FileIn.seekg(1, 1);
	getline(FileIn, mAuthor, ',');
	FileIn.seekg(1, 1);
	getline(FileIn, mPublisher);
}

void Book::set_hidebook(bool hide)
{
	HideBook = hide;
}

bool Book::get_hidebook()
{
	return HideBook;
}
