
#include "List_Manage.h"
#include <iomanip>

List_Manage::List_Manage(vector<Admin*> List)
{
	this->list_manage = List;
}

List_Manage::List_Manage()
{
}


List_Manage::~List_Manage()
{
}
List_Manage::List_Manage(List_Book& ListSach, List_Book& listBook, vector<Admin*> list, string Name, string Pass)
{
	this->lSach = ListSach;
	this->lbook = listBook;
	this->list_manage = list;
	this->NAME = Name;
	this->PASS = Pass;
}
void List_Manage::read_information(ifstream& FileIn)
{
	while (FileIn.eof() == false)
	{
		Admin* ad = new Admin;
		ad->read_1_information(FileIn);
		if (ad->get_name() == "")
		{
			break;
		}
		list_manage.push_back(ad);
	}
	FileIn.close();
}

void List_Manage::display_information_admin(ifstream& FileAdmin)
{
	read_information(FileAdmin);
	ofstream FileOut("List_Admin.txt", ios::out);
	FileAdmin.clear();
	for (auto i : list_manage)
	{
		FileOut << i->get_kind() << ", " << i->get_account() << ", " << i->get_password() << ", " << i->get_name() << endl;
	}
	FileOut.close();
}
void List_Manage::display_information_author(ifstream& FileAuthor)
{
	//read_information(FileAuthor);
	ofstream FileOut("List_Author.txt", ios::out);
	FileAuthor.clear();
	for (auto i : list_manage)
	{
		if (i->get_kind() == "Author")
		{
			FileOut << i->get_kind() << ", " << i->get_account() << ", " << i->get_password() << ", " << i->get_name() << ", " << i->get_age() << endl;
		}
	}
	FileOut.close();
}
void List_Manage::display_information_publisher(ifstream& FilePublisher)
{
	//read_information(FilePublisher);
	ofstream FileOut("List_Publisher.txt", ios::out);
	FilePublisher.clear();
	for (auto i : list_manage)
	{
		if (i->get_kind() == "Publisher")
		{
			FileOut << i->get_kind() << ", " << i->get_account() << ", " << i->get_password() << ", " << i->get_name() << ", " << i->get_age() << endl;
		}
	}
	FileOut.close();
}
void List_Manage::display_information_user(ifstream& FileUser)
{
	//read_information(FileUser);
	ofstream FileOut("List_User.txt", ios::out);
	FileUser.clear();
	for (auto i : list_manage)
	{
		if (i->get_kind() == "User")
		{
			FileOut << i->get_kind() << ", " << i->get_account() << ", " << i->get_password() << ", " << i->get_name() << ", " << i->get_age() << endl;
		}
	}
	FileOut.close();
}

void List_Manage::add_book()
{
	Book* boo = new Book;
	string name, code, author, publisher;
	double price;
	cout << " Input name of book need addtion: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, name);
	boo->set_name(name);
	cout << " Input code of book need addtion: ";
	fflush(stdin);
	getline(cin, code);
	boo->set_code(code);
	do
	{
		cout << " Input price of book need addtion: ";
		cin >> price;
		if (!cin || price <= 0)
		{
			cout << " Input price error. Please input correcty." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (!cin || price <= 0);
	boo->set_price(price);
	cout << " Input author of book need addtion: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, author);
	boo->set_author(author);
	cout << " Input publisher of book addtion: ";
	fflush(stdin);
	getline(cin, publisher);
	boo->set_publisher(publisher);
	boo->set_hidebook(false);
	lSach.list_book.push_back(boo);
	lbook.list_book.push_back(boo);
}
void List_Manage::delete_book()
{
	Book boo = lSach.search_book();
	lSach.Delete(boo);
	lbook.Delete(boo);
}
void List_Manage::Edit_book()
{
	system("cls");
	Book boo = lSach.search_book();
	if (boo.get_name() == "")
	{
		cout << " --- No found book in library ----" << endl;
		return;
	}
	int select;
	do
	{
		system("cls");
		for (auto i : lSach.list_book)
		{
			if ((*i).get_code() == boo.get_code())
				cout << (*i).get_name() << "\t" << (*i).get_code() << "\t" << (*i).get_price() << "\t" << (*i).get_author() << "\t" << (*i).get_publisher() << endl;
		}
		cout << "\n\t ----------" << endl;
		cout << "\t0. Exit." << endl;
		cout << "\t1. Edit name." << endl;
		cout << "\t2. Edit code." << endl;
		cout << "\t3. Edit price." << endl;
		cout << "\t4. Edit author." << endl;
		cout << "\t5. Edit publisher." << endl;
		cout << "\t**********" << endl;
		cout << "Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			lSach.Update_name(boo);
			break;
		}
		case 2:
		{
			lSach.Update_code(boo);
			break;
		}
		case 3:
		{
			lSach.Update_price(boo);
			break;
		}
		case 4:
		{
			lSach.Update_author(boo);
			break;
		}
		case 5:
		{
			lSach.Update_publisher(boo);
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}
void List_Manage::hide_book()
{
	Book boo = lSach.search_book();
	if (boo.get_name() == "")
	{
		cout << " -- No found book this." << endl;
		return;
	}
	else
	{
		lbook.Hide_book(boo);
	}
}
void List_Manage::unclock_book()
{
	Book boo = lSach.search_book();
	if (boo.get_name() == "")
	{
		cout << " -- No found this book." << endl;
		return;
	}
	for (auto i : lbook.list_book)
	{
		if (boo.get_name() == i->get_name() && boo.get_code() == i->get_code() && i->get_hidebook() == false)
		{
			cout << " -- Unclock book failed." << endl;
			return;
		}
	}
	lbook.list_book.push_back(new Book(boo.get_name(), boo.get_code(), boo.get_price(), boo.get_author(), boo.get_publisher()));
	lbook.list_book.back()->set_hidebook(false);
	cout << " -- Unclock book success." << endl;
}
void List_Manage::print_menu(ifstream& FileIn,ifstream& FileTemp)
{
	int select;
	this->lSach.read_list_book(FileIn);
	this->lbook.read_list_book(FileTemp);
	do
	{
		system("cls");
		this->lSach.display_list_book(FileIn);
		this->lbook.display_hide_book(FileTemp);
		cout << "\n\n\t -----------------------" << endl;
		cout << "\t --- BOOK MANAGER ---" << endl;
		cout << "\t1. Addtion book." << endl;
		cout << "\t2. Delete boook." << endl;
		cout << "\t3. Edit book." << endl;
		cout << "\t4. Hide book." << endl;
		cout << "\t5. Unlock book." << endl;
		cout << "\t0. Exit." << endl;
		cout << "\t *********************" << endl;
		cout << " -- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
			add_book();
			break;
		case 2:
		{
			delete_book();
			system("pause");
			break;
		}
		case 3:
		{
			Edit_book();
			system("pause");
			break;
		}
		case 4:
		{
			hide_book();
			system("pause");
			break;
		}
		case 5:
		{
			unclock_book();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}

Admin List_Manage::check_login(string account, string password)
{
	for (auto i : list_manage)
	{
		if ((*i).get_account() == account && (*i).get_password() == password)
		{
			return *i;
		}
	}
	return Admin(" ", " ", " ", " ", 0.0);
}
void List_Manage::add_author()
{
	Admin* ad = new Admin();
	ad->set_kind("Author");
	string newAccount, newPass, newName;
	cout << "Input account need addtion: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, newAccount);
	ad->set_account(newAccount);
	cout << "Input password need addtion: ";
	fflush(stdin);
	getline(cin, newPass);
	ad->set_password(newPass);
	cout << "Input user name need addtion: ";
	fflush(stdin);
	getline(cin, newName);
	ad->set_name(newName);
	float age;
	cout << "Input ager author: ";
	cin >> age;
	ad->set_age(age);
	list_manage.push_back(ad);
}

void List_Manage::delete_author_Or_publisher()
{
	string del_account;
	cout << "Input account could delete: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, del_account);
	vector<Admin*>::iterator it;
	for (it = list_manage.begin(); it != list_manage.end(); ++it)
	{
		if ((*it)->get_account() == del_account)
		{
			list_manage.erase(it);
			cout << "-- You have successfully deleted." << endl;
			return;
		}
	}
	cout << " -- No found account this." << endl;
}

Admin List_Manage::search_author_Or_publisher()
{
	string search_account;
	cout << "Input account need search: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, search_account);
	for (auto i : list_manage)
	{
		if (i->get_account() == search_account)
		{
			return *i;
		}
	}
	return Admin("", "", "", "", 0.0);
}

void List_Manage::edit_author_Or_publisher()
{
	int select;
	Admin ad = search_author_Or_publisher();
	if (ad.get_account() == "")
	{
		cout << "No found account this." << endl;
		return;
	}
	do
	{
		system("cls");
		ad.display_1_information();
		cout << "\n\t -----------------" << endl;
		cout << "\t0. Exit." << endl;
		cout << "\t1. Edit account." << endl;
		cout << "\t2. Edit password." << endl;
		cout << "\t3. Edit user name." << endl;
		cout << "\t4. Edit age." << endl;
		cout << "\t***************" << endl;
		cout << "-- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			string edit_account;
			cout << "Input account need modify: ";
			cin.ignore();
			fflush(stdin);
			getline(cin, edit_account);
			for (auto i : list_manage)
			{
				if (i->get_name() == ad.get_name())
				{
					ad.set_account(edit_account);
					i->set_account(edit_account);
				}
			}
			break;
		}
		case 2:
		{
			string edit_pass;
			cout << "Input password need modify: ";
			cin.ignore();
			fflush(stdin);
			getline(cin, edit_pass);
			for (auto i : list_manage)
			{
				if (i->get_name() == ad.get_name())
				{
					ad.set_password(edit_pass);
					i->set_password(edit_pass);
				}
			}
			break;
		}
		case 3:
		{
			string edit_name;
			cout << "Input user name need modify: ";
			cin.ignore();
			fflush(stdin);
			getline(cin, edit_name);
			
			for (auto i : list_manage)
			{
				if (i->get_name() == ad.get_name())
				{
					ad.set_name(edit_name);
					i->set_name(edit_name);
				}
			}
			break;
		}
		case 4:
		{
			float edit_age;
			cout << "Input age need modify: ";
			fflush(stdin);
			cin >> edit_age;
			for (auto i : list_manage)
			{
				if (i->get_name() == ad.get_name())
				{
					ad.set_age(edit_age);
					i->set_age(edit_age);
				}
			}
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}

void List_Manage::Cauthor(ifstream& FileAuthor)
{
	int select;
	this->read_information(FileAuthor);
	do
	{
		system("cls");
		this->display_information_author(FileAuthor);
		cout << left << setw(20) << " KIND" << setw(20) << "ACCOUNT" << setw(20) << "PASSWORD" << setw(20) << "USER NAME" << setw(30) << "AGE" << endl;
		cout << "\t ====================================================================" << endl;
		for (auto i : list_manage)
		{
			if (i->get_kind() == "Author")
			{
				i->display_1_information();	
			}
		}
		cout << "\n\t -----------------------" << endl;
		cout << "\t --- AUTHOR MANAGER ---" << endl;
		cout << "\t1. Addtion author." << endl;
		cout << "\t2. Delete author." << endl;
		cout << "\t3. Edit author." << endl;
		cout << "\t ************************" << endl;
		cout << " -- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
			add_author();
			break;
		case 2:
		{
			delete_author_Or_publisher();
			system("pause");
			break;
		}
		case 3:
		{
			edit_author_Or_publisher();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}

void List_Manage::Cpublisher(ifstream& FilePublisher)
{
	int select;
	//this->display_information_publisher(FilePublisher);
	this->read_information(FilePublisher);
	do
	{
		system("cls");
		this->display_information_publisher(FilePublisher);
		cout << left << setw(20) << " KIND" << setw(20) << "ACCOUNT" << setw(20) << "PASSWORD" << setw(20) << "USER NAME" << setw(30) << "AGE" << endl;
		cout << "\t =============================================================" << endl;
		for (auto i : list_manage)
		{
			if (i->get_kind() == "Publisher")
			{
				i->display_1_information();
			}
		}
		cout << "\n\t -----------------------" << endl;
		cout << "\t --- PUBLISHER MANAGER ---" << endl;
		cout << "\t1. Addtion publisher." << endl;
		cout << "\t2. Delete publisher." << endl;
		cout << "\t3. Edit publisher." << endl;
		cout << "\t ************************" << endl;
		cout << " -- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
			add_publisher();
			break;
		case 2:
		{
			delete_author_Or_publisher();
			system("pause");
			break;
		}
		case 3:
		{
			edit_author_Or_publisher();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}

void List_Manage::add_publisher()
{
	Admin* ad = new Admin();
	ad->set_kind("Publisher");
	string newAccount, newPass, newName;
	cout << "Input account need addtion: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, newAccount);
	ad->set_account(newAccount);
	cout << "Input password need addtion: ";
	fflush(stdin);
	getline(cin, newPass);
	ad->set_password(newPass);
	cout << "Input user mame need addtion: ";
	fflush(stdin);
	getline(cin, newName);
	ad->set_name(newName);
	float age;
	cout << "Input age of publisher need addtion: ";
	cin >> age;
	ad->set_age(age);
	list_manage.push_back(ad);
}


void List_Manage::Cuser(ifstream& FileUser)
{
	int select;
	this->read_information(FileUser);
	do
	{
		system("cls");
		this->display_information_user(FileUser);
		cout << left << setw(20) << " KIND" << setw(20) << "ACCOUNT" << setw(20) << "PASSWORD" << setw(20) << "USER NAME" <<setw(30) << "AGE" << endl;
		cout << "\t ============================================================" << endl;
		for (auto i : list_manage)
		{
			if (i->get_kind() == "User")
				i->display_1_information();
		}
		cout << "\n\t -------------------" << endl;
		cout << "\t --- USER MANAGER ---" << endl;
		cout << "\t1. Addtion user." << endl;
		cout << "\t2. Delete user." << endl;
		cout << "\t3. Edit user." << endl;
		cout << "\t4. Send message." << endl;
		cout << "\t *********************" << endl;
		cout << " -- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
			add_user();
			break;
		case 2:
		{
			delete_author_Or_publisher();
			system("pause");
			break;
		}
		case 3:
		{
			edit_author_Or_publisher();
			system("pause");
			break;
		}
		case 4:
		{
			send_message();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}

void List_Manage::add_user()
{
	Admin* ad = new Admin();
	ad->set_kind("User");
	string newAccount, newPass, newName;
	cout << "Input account need addtion: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, newAccount);
	ad->set_account(newAccount);
	cout << "Input password need addtion: ";
	fflush(stdin);
	getline(cin, newPass);
	ad->set_password(newPass);
	cout << "Input user name need addtion: ";
	fflush(stdin);
	getline(cin, newName);
	ad->set_name(newName);
	float age;
	cout << "Input age of user need addtion: ";
	cin >> age;
	ad->set_age(age);
	list_manage.push_back(ad);
}

void List_Manage::send_message()
{
	int select;
	do
	{
		system("cls");
		cout << "\n\t -------------------------" << endl;
		cout << "\t1. Send message to personal." << endl;
		cout << "\t2. Send message by age." << endl;
		cout << "\t3. Send message all user." << endl;
		cout << "\t0. Exit" << endl;
		cout << "\t **************************" << endl;
		cout << " -- Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			message_personal();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			message_by_age();
			system("pause");
			break;
		}
		case 3:
		{
			message_all_user();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}

void List_Manage::message_by_age()
{
	float age;
	cout << "Input age need send message: ";
	cin >> age;
	int select;
	cout << "\n\t --------------------" << endl;
	cout << "\t1. Over " << age << " years old." << endl;
	cout << "\t2. Under " << age << " years old." << endl;
	cout << "\t ************************" << endl;
	cout << " -- Please select: ";
	cin >> select;
	if (select == 1)
	{
		string mMessage;
		cout << "Input the text of the message: ";
		cin.ignore();
		fflush(stdin);
		getline(cin, mMessage);
		ofstream FileMessage("List_Message.txt", ios::out | ios::app);
		FileMessage << "Admin, " << age << "+, " << mMessage << endl;
		cout << " -- Message send success." << endl;
		return;
	}
	if (select == 2)
	{
		string mMessage;
		cout << "Input the text of the message: ";
		cin.ignore();
		fflush(stdin);
		getline(cin, mMessage);
		ofstream FileMessage("List_Message.txt", ios::out | ios::app);
		FileMessage << "Admin, " << age << "-, " << mMessage << endl;
		cout << " -- Message send success." << endl;
		return;
	}
}

void List_Manage::message_personal()
{
	string send_name;
	cout << "Input the recipient of the message: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, send_name);
	for (auto i : list_manage)
	{
		if (i->get_kind() == "User" && i->get_name() == send_name)
		{
			string mMessage;
			cout << "Input the text of the message: ";
			cin.ignore();
			fflush(stdin);
			getline(cin, mMessage);
			ofstream FileMessage("List_Message.txt", ios::out | ios::app);
			FileMessage << "Admin, " << send_name << ", " << mMessage << endl;
			cout << " -- Message send success." << endl;
			return;
		}
	}
	cout << " -- No found the recipient name this." << endl;
	return;
}

void List_Manage::message_all_user()
{
	string mMessage;
	cout << "Input the text of the message: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, mMessage);
	ofstream FileMessage("List_Message.txt", ios::out | ios::app);
	FileMessage << "Admin, all user, " << mMessage << endl;
	cout << " -- Message send success." << endl;
	return;
}
