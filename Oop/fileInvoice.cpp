#include "fileInvoice.h"
#include <string>
#include <iomanip>
using namespace std;
fileInvoice::fileInvoice()
{
}

fileInvoice::fileInvoice(vector<fileInvoice*> list)
{
	listInvoice = list;
}

fileInvoice::fileInvoice(string code, string name, long long price, float quantity)
{
	mCode = code;
	mName = name;
	mPrice = price;
	mQuantity = quantity;
}

fileInvoice::~fileInvoice()
{
}

void fileInvoice::read_1_invoice(ifstream& FileInvoice)
{
	getline(FileInvoice, mCode, '\t');
	if (mCode.substr(0, 1) == "\n")
	{
		mCode.erase(mCode.begin(),mCode.begin()+1);
	}
	getline(FileInvoice, mName, '\t');
	FileInvoice >> mPrice;
	FileInvoice >> mQuantity;
}

void fileInvoice::read_invoice(ifstream& FileInvoice)
{
	while (FileInvoice.eof() == false)
	{
		fileInvoice* invoice = new fileInvoice;
		invoice->read_1_invoice(FileInvoice);
		if (invoice->get_name() == "")
		{
			break;
		}
		listInvoice.push_back(invoice);
	}
}

void fileInvoice::set_code(string code)
{
	mCode = code;
}

string fileInvoice::get_code()
{
	return mCode;
}

void fileInvoice::set_name(string name)
{
	mName = name;
}

string fileInvoice::get_name()
{
	return mName;
}

void fileInvoice::set_price(long long price)
{
	mPrice = price;
}

long long fileInvoice::get_price()
{
	return mPrice;
}

void fileInvoice::set_quantity(float quantity)
{
	mQuantity = quantity;
}

float fileInvoice::get_quantity()
{
	return mQuantity;
}

void fileInvoice::display_invoice()
{
	for (auto i : listInvoice)
	{
		if (i->get_name() != "Total money payment:" && i->get_code() != "-")
		{
			cout << right << i->get_code() << setw(30) << i->get_name() << setw(20) << i->get_price() << setw(20) << i->get_quantity() << endl;
		}
		else
		{
			cout << "\t\t----------------" << endl;
			cout << "\t" << i->get_name() << "\t" << i->get_price() << endl;
			cout << endl;
		}
	}
}

void fileInvoice::find_invoice_max(ifstream& FileBook)
{
	List_Book lSach;
	lSach.read_list_book(FileBook);
	float Max = 0;
	int k;
	for (int i = 0; i < lSach.list_book.size(); i++)
	{
		float Sum = 0;
		for (int j = 0; j < listInvoice.size(); j++)
		{
			if (lSach.list_book[i]->get_name() == listInvoice[j]->get_name())
			{
				Sum += listInvoice[j]->get_quantity();
			}
		}
		if (Sum > Max)
		{
			Max = Sum;
			k = i;
		}
	}
	cout << lSach.list_book[k]->get_code() << setw(30) << lSach.list_book[k]->get_name() << setw(20) << lSach.list_book[k]->get_price() << endl;
	cout << "Total amount book bought: " << Max;
}

void fileInvoice::print_total_max()
{
	long long Max = 0;
	int k = 0;
	for (int i = 0; i < listInvoice.size(); i++)
	{
		if (listInvoice[i]->get_code() == "-" && listInvoice[i]->get_name() == "Total money payment:")
		{
			if (listInvoice[i]->get_price() > Max)
			{
				Max = listInvoice[i]->get_price();
				k = i;
			}
		}
	}
	for (int i = k-1; i >= 0; i--)
	{
		if (listInvoice[i]->get_code() == "-" && listInvoice[i]->get_name() == "Total money payment:")
		{
			for (int j = i + 1; j < k; j++)
			{
				cout << listInvoice[j]->get_code() << setw(30) << listInvoice[j]->get_name() << setw(20) << listInvoice[j]->get_price() << setw(20) << listInvoice[j]->get_quantity() << endl;
			}
			cout << "\t\t----------------" << endl;
			cout << "\tTotal money payment:\t" << listInvoice[k]->get_price();
			return;
		}
	}
}

void fileInvoice::print_menu(ifstream& FileInvoice,ifstream& FileBook)
{
	this->read_invoice(FileInvoice);
	int select;
	do
	{
		system("cls");
		cout << "\n\t ----------------------------------" << endl;
		cout << "\t1. Display all invoice." << endl;
		cout << "\t2. Print invoice have total money max." << endl;
		cout << "\t3. Book have amount purchase max." << endl;
		cout << "\t0. Exit." << endl;
		cout << "\t**************************************" << endl;
		cout << " -- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
			system("cls");
			display_invoice();
			system("pause");
			break;
		case 2:
			cout << "CODE BOOK" << setw(30) << "NAME BOOK" << setw(20) << "PRICE" << setw(20) << "QUANTITY" << endl;
			cout << "\t ==============================================================" << endl;
			print_total_max();
			cout << endl;
			system("pause");
			break;
		case 3:
			cout << "CODE BOOK" << setw(30) << "NAME BOOK" << setw(20) << "PRICE" << endl;
			cout << "===========================================================" << endl;
			find_invoice_max(FileBook);
			cout << endl;
			system("pause");
			break;
		default:
			break;
		}
	} while (select != 0);
}
