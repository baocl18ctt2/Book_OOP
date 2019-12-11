
#include "User.h"
#include <fstream>
#include "Admin.h"
#include <iomanip>
#include <sstream>
User::User()
{
}

User::User(string account, string passowrd)
{
	mAccount = account;
	mPassword = passowrd;
}

User::User(const User& User)
{
	mAccount = User.mAccount;
	mPassword = User.mPassword;
}

User::User(List_Book& lSach, List_Manage& luser, List_Invoice& linvoice)
{
	listSACH = lSach;
	listUSER = luser;
	listINVOICE = linvoice;
}

void User::set_account(string account)
{
	mAccount = account;
}

string User::get_account()
{
	return mAccount;
}

void User::set_password(string password)
{
	mPassword = password;
}

string User::get_password()
{
	return mPassword;
}


User::~User()
{
}

Admin User::Login(ifstream& FileUser)
{
	cout << "Input account of user: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, mAccount);
	cout << "Input password of user: ";
	fflush(stdin);
	getline(cin, mPassword);
	this->listUSER.read_information(FileUser);
	for (auto i : listUSER.list_manage)
	{
		if (i->get_account() == mAccount && i->get_password() == mPassword)
			return *i;
	}
	return Admin("", "", "", "", 0.0);
}


void User::Registration(ifstream& FileUser)
{
	string account, pass, pass1, name;
	cout << "Input name account registered: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, account);
	cout << "Input password account registered: ";
	fflush(stdin);
	getline(cin, pass);
	do
	{
		cout << "confirm registration password: ";
		fflush(stdin);
		getline(cin, pass1);
		if (pass != pass1)
		{
			cout << "Password registration error. ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (pass != pass1);
	cout << "Input name of you:  ";
	fflush(stdin);
	getline(cin, name);
	listUSER.list_manage.push_back(new Admin("User", account, pass, name, 0.0));
	listUSER.display_information_user(FileUser);
}
bool User::check_login_account(ifstream& FileUser)
{
	int select;
	do
	{
		system("cls");
		cout << "\n\t -------------" << endl;
		cout << "\t1. Login" << endl;
		cout << "\t2. Registration" << endl;
		cout << "\t0. Exit." << endl;
		cout << "\t*************" << endl;
		cout << "-- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			Admin ad = Login(FileUser);
			if (ad.get_name() == "")
				return false;
			else
			{
				return true;
			}
		}
		case 2:
		{
			Registration(FileUser);
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}

void User::printf_menu(ifstream& FileTemp, ifstream& FileUser,ifstream &FileMessage)
{
	int key;
	List_Book lSach;
	do
	{
		system("cls");
		lSach.read_list_book(FileTemp);
		cout << setw(10) << "CODE BOOK" << setw(35) << "NAME BOOK" << setw(20) << "PRICE BOOK" << setw(25) << "AUTHOR BOOK" << setw(25) << "PUBLISHER BOOK" << endl;
		cout << "===================================================================================================================" << endl;
		for (auto i : lSach.list_book)
		{
			cout << right << setw(10) << i->get_code() << setw(35) << i->get_name() << setw(20) << i->get_price() << setw(25) << i->get_author() << setw(25) << i->get_publisher() << endl;
		}
		cout <<"\n\t --------------------" << endl;
		cout << "\t1. Search book." << endl;
		cout << "\t2. Edit invoice." << endl;
		cout << "\t3. Printf invoice." << endl;
		cout << "\t4. See the message." << endl;
		cout << "\t5. Send the message." << endl;
		cout << "\t0. Exit." << endl;
		cout << "\t********************" << endl;
		cout << "Xin moi lua chon: ";
		cin >> key;
		switch (key)
		{
		case 1:
		{
			system("cls");
			listINVOICE.input_data(lSach);
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			listINVOICE.edit_invoice();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			listINVOICE.output_data();
			listINVOICE.display_file_invoice();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			read_message(FileUser, FileMessage);
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			send_message(FileUser);
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (key != 0);
}

void User::read_message(ifstream& FileUser, ifstream& FileMessage)
{
	Admin ad = Login(FileUser);
	if (ad.get_name() == "")
	{
		cout << "-- No found user." << endl;
		return;
	}
	Message message;
	message.read_information_message(FileMessage);
	std::string out_string;
	std::stringstream ss;
	ss << ad.get_age();
	out_string = ss.str();
	for (auto i : message.list_message)
	{
		if (i->get_people() == ad.get_name() || i->get_people() == "all user")
		{
			i->display_1_information();
		}
		if (i->get_people().substr(2, 3) == "+" && i->get_people().substr(0, 2) < out_string)
		{
			i->display_1_information();
		}
		if (i->get_people().substr(2, 3) == "-" && i->get_people().substr(0, 2) > out_string)
		{
			i->display_1_information();
		}
	}
}

void User::send_message(ifstream& FileUser)
{
	Admin ad = Login(FileUser);
	if (ad.get_name() == "")
	{
		cout << "-- No found user." << endl;
		return;
	}
	string receiver;
	cout << "Input name receiver: ";
	cin.ignore();
	getline(cin, receiver);
	string mMessage;
	cout << "Input the text of the message: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, mMessage);
	ofstream FileMessage("List_Message.txt", ios::out | ios::app);
	FileMessage << ad.get_name() << ", " << receiver << ", " << mMessage << endl;
	cout << " -- Message send success." << endl;
	return;
}
