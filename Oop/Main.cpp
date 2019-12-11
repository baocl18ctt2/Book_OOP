
#include <iostream>
#include "List_Book.h"
#include "Book.h"
#include "List_Invoice.h"
#include "User.h"
#include "Admin.h"
#include "List_Manage.h"
#include "Header.h"
#include "cAuthor.h"
#include "cPublisher.h"
#include <iomanip>
#include"fileInvoice.h"
using namespace std;
void print_menu2()
{
	system("cls");
	cout << "\n\t --------------------" << endl;
	cout << "\t --- READER MANAGER ---" << endl;
	cout << "\t1. Inforamtion boook." << endl;
	cout << "\t2. Admin." << endl;
	cout << "\t3. Author." << endl;
	cout << "\t4. Publisher." << endl;
	cout << "\t5. User." << endl;
	cout << "\t6. See information invoice." << endl;
	cout << "\t0. Exit the program." << endl;
	cout << "\t **********************" << endl;
	cout << " -- Please select: ";
}
void main()
{
	int select, select2;
	User user;
	cPublisher publisher;
	cAuthor author;
	List_Manage ad;
	List_Book lboo = List_Book();
	List_Invoice l_invoice;
	vector <Admin*> list;
	while (true)
	{
		ifstream FileIn("Admin.txt", ios::app | ios::in);
		if (FileIn.fail())
		{
			std::cout << "Failed to open this file!" << endl;
			return;
		}
		ifstream FileIn1("List_Sach.txt", ios::app | ios::in);
		if (FileIn1.fail())
		{
			std::cout << "Failed to open this file!" << endl;
			return;
		}
		ifstream FileTemp("List_Temp.txt", ios::app | ios::in);
		if (FileTemp.fail())
		{
			std::cout << "Failed to open this file!" << endl;
			return;
		}
		ifstream FileAuthor("List_Author.txt", ios::app | ios::in);
		if (FileAuthor.fail())
		{
			std::cout << "Failed to open this file!" << endl;
			return;
		}
		ifstream FilePublisher("List_Publisher.txt", ios::app | ios::in);
		if (FilePublisher.fail())
		{
			std::cout << "Failed to open this file!" << endl;
			return;
		}
		ifstream FileUser("List_User.txt", ios::app | ios::in);
		if (FileUser.fail())
		{
			std::cout << "Failed to open this file!" << endl;
			return;
		}
		ifstream FileMessage("List_Message.txt", ios::app | ios::in);
		if (FileMessage.fail())
		{
			std::cout << "Failed to open this file!" << endl;
			return;
		}
		ifstream FileInvoice("List_Invoice.txt", ios::app | ios::in);
		if (FileInvoice.fail())
		{
			std::cout << "Failed to open this file!" << endl;
			return;
		}
		print_menu2();
		cin >> select;
		if (select == 1)
		{
			system("cls");
			List_Book* lboo = new List_Book();
			lboo->read_list_book(FileIn1);
			lboo->display_list_book(FileIn1);
			system("pause");
		}
		if (select == 2)
		{
			system("cls");
			List_Book* lboo = new List_Book();
			List_Book* lBook = new List_Book();
			admin(*lboo, *lBook, list, FileIn1, FileTemp, FileAuthor, FilePublisher, FileUser);
		}
		if (select == 3)
		{
			system("cls");
			List_Book* lboo = new List_Book();
			List_Manage* lAuthor = new List_Manage();
			List_Book* lbook = new List_Book();
			Actor(*lboo, *lbook, *lAuthor, FileIn1, FileAuthor, FileTemp);
			system("pause");
		}
		if (select == 4)
		{
			system("cls");
			List_Book* lboo = new List_Book();
			List_Manage* lPublisher = new List_Manage();
			List_Book* lbook = new List_Book();
			Publisher(*lboo, *lbook, *lPublisher, FileIn1, FilePublisher, FileTemp);
			system("pause");
		}
		if (select == 5)
		{
			system("cls");
			List_Book* lboo = new List_Book();
			List_Manage* luser = new List_Manage();
			List_Invoice* linvoice = new List_Invoice();
			cUser(*lboo, *luser, *linvoice, FileTemp, FileUser,FileMessage);
			system("pause");
		}
		if (select == 6)
		{
			system("cls");
			cInvoice(FileInvoice, FileTemp);
			system("pause");
		}
		if (select == 0)
			break;
	}
}