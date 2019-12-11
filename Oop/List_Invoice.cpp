
#include "List_Invoice.h"
#include <iostream>
#include <iomanip>
using namespace std;
List_Invoice::List_Invoice()
{
}


List_Invoice::~List_Invoice()
{
}

void List_Invoice::input_data(List_Book& lbook)
{
	Invoice hd(lbook.search_book());
	if (hd.get_book().get_name() == "")
	{
		cout << " -- No book found need search." << endl;
		return;
	}
	string select;
	cout << "\t ---------- " << endl;
	cout << "Do you want addition invoice?(Yes/No): ";
	getline(cin, select);
	cout << "\t ---------- " << endl;
	if (select == "No" || select == "no")
		return;
	else
	{
		int quantity;
		do
		{
			cout << "Input quanity book need buy: ";
			cin >> quantity;
			if (!cin || quantity <= 0)
			{
				cout << "Input data error. ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!cin || quantity <= 0);
		hd.set_quanity(quantity);
		list_invoice.push_back(hd);
		puts(" ");
	}
}

void List_Invoice::output_data()
{
	cout << left <<setw(20)<< "CODE BOOK" << setw(40) << "NAME BOOK" << setw(20) << "PRICE" << setw(20) << "QUANITY" << setw(20) << "INTO MONEY" << endl;
	cout << "==============================================================================================================" << endl;
	long long Sum = 0;
	for (auto i : list_invoice)
	{
		i.display_invoice();
		
		Sum += i.get_book().get_price() * i.get_quanity();
	}
	cout << "\n\t\tTotal money payment:   " << Sum << endl;
}
void List_Invoice::display_file_invoice()
{
	long long Sum = 0;
	ofstream FileInvoice("List_Invoice.txt", ios::out | ios::app);
	for (auto i : list_invoice)
	{
		FileInvoice << i.get_book().get_code() << "\t" << i.get_book().get_name() << "\t" << i.get_book().get_price() << "\t" << i.get_quanity() << endl;
		Sum += i.get_book().get_price() * i.get_quanity();
	}
	FileInvoice << "-\tTotal money payment:\t" << Sum<<"\t0.0" << endl;
}


void List_Invoice::edit_invoice()
{
	int select;
	do
	{
		system("cls");
		output_data();
		cout << "\n\t -------------------" << endl;
		cout << " \t--- INVOICE MANAGER --- " << endl;
		cout << "\t1.Edit quantity." << endl;
		cout << "\t2.Delete book." << endl;
		cout << "\t0.Exit." << endl;
		cout << "-- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			modify_quanity();
			system("pause");
			break;
		}
		case 2:
		{
			delete_book_invoice();
			system("pause");
		}
		default:
			break;
		}
	} while (select != 0);
}

Invoice List_Invoice::search_book_invoice()
{
	string booLook;
	cout << "Input name book need search: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, booLook);
	vector <Invoice> tempList;
	int cnt = 0;
	for (auto i : list_invoice)
	{
		if (i.get_book().get_name() == booLook)
		{
			tempList.push_back(i);
			cnt++;
		}
	}
	if (cnt == 1)
	{
		for (auto i : tempList)
			return i;
	}
	else if (cnt > 1)
	{
		string codeLook;
		cout << "Input code book need search: ";
		fflush(stdin);
		getline(cin, codeLook);
		for (auto i : tempList)
		{
			if (i.get_book().get_code() == codeLook)
				return i;
		}
	}
	return Invoice(Book("", "", 0.0, " ",""), 0.0);
}

void List_Invoice::modify_quanity()
{
	Invoice invoice = search_book_invoice();
	if (invoice.get_book().get_name() == "")
	{
		cout << "No found book in invoice." << endl;
		return;
	}
	int new_quanity;
	cout << "Input new quanity of book: ";
	cin >> new_quanity;
	vector<Invoice>::iterator it;
	for (it = list_invoice.begin(); it != list_invoice.end(); ++it)
	{
		if ((*it).get_book().get_code() == invoice.get_book().get_code())
		{
			(*it).set_quanity(new_quanity);
		}
	}
}

void List_Invoice::delete_book_invoice()
{
	Invoice invoice = search_book_invoice();
	if (invoice.get_book().get_name() == "")
	{
		cout << "No found book in invoice." << endl;
		return;
	}
	vector<Invoice>::iterator it;
	for (it = list_invoice.begin(); it != list_invoice.end(); ++it)
	{
		if ((*it).get_book().get_code() == invoice.get_book().get_code())
		{
			list_invoice.erase(it);
			return;
		}
	}
}

