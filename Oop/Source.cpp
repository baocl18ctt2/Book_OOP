
#include "Header.h"
#include "cPublisher.h"
#include "fileInvoice.h"
void cUser(List_Book& lSach, List_Manage& luser, List_Invoice& linvoice, ifstream& FileTemp, ifstream& FileUser,ifstream &FileMessage)
{
	User user = User(lSach, luser,linvoice);
	if (user.check_login_account(FileUser) == false)
	{
		cout << "-- Login failed." << endl;
		return;
	}
	else
	{
		user.printf_menu(FileTemp, FileUser, FileMessage);
	}
}
void Actor(List_Book& lSach, List_Book& lBook, List_Manage& lAuthor, ifstream& FileIn,ifstream &FileAuthor,ifstream &FileTemp)
{
	cAuthor author = cAuthor(lSach,lBook, lAuthor);
	author.print_menu(FileIn, FileAuthor,FileTemp);
}
void Publisher(List_Book& lSach, List_Book& lBook, List_Manage& lpublisher, ifstream& FileIn, ifstream& FilePublisher,ifstream &FileTemp)
{
	cPublisher publisher = cPublisher(lSach, lBook, lpublisher);
	publisher.print_menu(FileIn, FilePublisher, FileTemp);
}
void admin(List_Book& lSach, List_Book& lBook,vector<Admin*> list,ifstream& FileIn,ifstream &FileTemp, ifstream& FileAuthor,ifstream& FilePublisher,ifstream& FileUser)
{
	int key = 0;
	cout << "Moi nhap ten: ";
	cin.ignore();
	string Ten, Pass;
	getline(cin, Ten);
	cout << "Moi nha Pass: ";
	cin >> Pass;
	List_Manage admin = List_Manage(lSach, lBook, list, Ten, Pass);
	do
	{
		system("cls");
		//admin.list_manage.clear();
		cout << "\n\t -----------------" << endl;
		cout << "\t1. Edit book." << endl;
		cout << "\t2. Edit author." << endl;
		cout << "\t3. Edit publisher." << endl;
		cout << "\t4. Edit user." << endl;
		cout << "\t0. Exit." << endl;
		cout << "\t ****************" << endl;
		cout << "-- Please select: ";
		cin >> key;
		system("cls");
		switch (key)
		{
		case 1:
			admin.print_menu(FileIn,FileTemp);
			break;
		case 2:
		{
			admin.Cauthor(FileAuthor);
			break;
		}
		case 3:
		{
			admin.Cpublisher(FilePublisher);
			break;
		}
		case 4:
		{
			admin.Cuser(FileUser);
			break;
		}
		default: break;
		}
	} while (key != 0);
}
void cInvoice(ifstream& FileInvoice, ifstream& FileBook)
{
	fileInvoice* invoice = new fileInvoice();
	invoice->print_menu(FileInvoice, FileBook);
}