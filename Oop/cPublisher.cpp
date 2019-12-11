
#include "cPublisher.h"
#include "List_Manage.h"

cPublisher::cPublisher()
{
}


cPublisher::~cPublisher()
{
}

cPublisher::cPublisher(List_Book& lSach, List_Book& lBook, List_Manage lpublisher)
{
	listSACH = lSach;
	this->lbook = lBook;
	listPublisher = lpublisher;
}

Admin cPublisher::login(ifstream& FilePublisher)
{
	cout << "Input account publisher: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, account);
	cout << "Input password publisher: ";
	fflush(stdin);
	getline(cin, password);
	this->listPublisher.read_information(FilePublisher);
	//this->listPublisher.display_information_publisher(FilePublisher);
	for (auto i : listPublisher.list_manage)
	{
		if (i->get_account() == account && i->get_password() == password)
		{
			return *i;
		}
	}
	return Admin("", "", "", "", 0.0);
}
void cPublisher::add_book(Admin ad)
{
	Book* boo = new Book;
	string name, code, author;
	double price;
	cout << "Input name of book need addtion: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, name);
	boo->set_name(name);
	cout << "Input code of book need addtion: ";
	fflush(stdin);
	getline(cin, code);
	boo->set_code(code);
	do
	{
		cout << "Input price of book need addtion: ";
		cin >> price;
		if (!cin || price <= 0)
		{
			cout << " Input price error. Please input correcty." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (!cin || price <= 0);
	boo->set_price(price);
	cout << "Input author of book need addtion: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, author);
	boo->set_author(author);
	boo->set_hidebook(false);
	boo->set_publisher(ad.get_name());
	listSACH.list_book.push_back(boo);
	lbook.list_book.push_back(boo);
}
void cPublisher::delete_book()
{
	Book boo = listSACH.search_book();
	if (boo.get_name() == "")
	{
		cout << " -- No found book this!" << endl;
		return;
	}
	else
	{
		listSACH.Delete(boo);
		lbook.Delete(boo);
	}
}
void cPublisher::Edit_book()
{
	system("cls");
	Book boo = listSACH.search_book();
	if (boo.get_name() == "")
	{
		cout << " --- No found book in library ----" << endl;
		return;
	}
	int select;
	do
	{
		system("cls");
		for (auto i : listSACH.list_book)
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
		cout << "\t**********" << endl;
		cout << "Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			listSACH.Update_name(boo);
			break;
		}
		case 2:
		{
			listSACH.Update_code(boo);
			break;
		}
		case 3:
		{
			listSACH.Update_price(boo);
			break;
		}
		case 4:
		{
			listSACH.Update_author(boo);
			break;
		}
		default:
			break;
		}
	} while (select != 0);
}
void cPublisher::unclock_book()
{
	Book boo = listSACH.search_book();
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
void cPublisher::print_menu(ifstream& FileIn, ifstream& FilePublisher,ifstream &FileTemp)
{
	Admin ad = login(FilePublisher);
	if (ad.get_account() == "")
	{
		cout << "Login failed." << endl;
		return;
	}
	int select;
	this->listSACH.read_list_book(FileIn);
	this->lbook.read_list_book(FileTemp);
	do
	{
		system("cls");
		this->listSACH.display_1_list_book(FileIn);
		this->lbook.display_hide_book(FileTemp);
		for (auto i : listSACH.list_book)
		{
			if (ad.get_name() == i->get_publisher())
			{
				cout << "\n\t ================" << endl;
				cout << "]Name book: " << i->get_name() << endl;
				cout << "]Code book: " << i->get_code() << endl;
				cout << "]Price book: " << i->get_price() << endl;
				cout << "]Author book: " << i->get_author() << endl;
				cout << "]Publisher book: " << i->get_publisher() << endl;
			}
		}
		cout << "\n\t -----------------------" << endl;
		cout << "\t --- ADMIN MANAGER ---" << endl;
		cout << "\t1. Addtion book." << endl;
		cout << "\t2. Delete boook." << endl;
		cout << "\t3. Edit book." << endl;
		cout << "\t4. Hide book." << endl;
		cout << "\t5. Unclock book." << endl;
		cout << "\t6. Send message." << endl;
		cout << "\t ********" << endl;
		cout << "Please select: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			system("cls");
			add_book(ad);
			break;
		}
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
			Book boo = listSACH.search_book();
			if (boo.get_name() == "")
			{
				cout << "Hide book failed." << endl;
			}
			else
			{
				vector <Book*>::iterator it;
				for (it = lbook.list_book.begin(); it != lbook.list_book.end(); ++it)
				{
					if ((*it)->get_name() == boo.get_name() && (*it)->get_code() == boo.get_code())
					{
						(*it)->set_hidebook(true);
						break;
					}
				}
				cout << "Hide book success." << endl;
			}
			system("pause");
			break;
		}
		case 5:
		{
			unclock_book();
			system("pause");
			break;
		}
		case 6:
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

void cPublisher::send_message()
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
void cPublisher::message_by_age()
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
		FileMessage << "Publisher, " << age << "+, " << mMessage << endl;
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
		FileMessage << "Publisher, " << age << "-, " << mMessage << endl;
		cout << " -- Message send success." << endl;
		return;
	}
}

void cPublisher::message_personal()
{
	string send_name;
	cout << "Input the recipient of the message: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, send_name);
	List_Manage list;
	ifstream FileUser("List_User.txt", ios::in);
	list.read_information(FileUser);
	for (auto i : list.list_manage)
	{
		if (i->get_kind() == "User" && i->get_name() == send_name)
		{
			string mMessage;
			cout << "Input the text of the message: ";
			cin.ignore();
			fflush(stdin);
			getline(cin, mMessage);
			ofstream FileMessage("List_Message.txt", ios::out | ios::app);
			FileMessage << "Publisher, " << send_name << ", " << mMessage << endl;
			cout << " -- Message send success." << endl;
			return;
		}
	}
	cout << " -- No found the recipient name this." << endl;
	return;
}

void cPublisher::message_all_user()
{
	string mMessage;
	cout << "Input the text of the message: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, mMessage);
	ofstream FileMessage("List_Message.txt", ios::out | ios::app);
	FileMessage << "Publisher, all user, " << mMessage << endl;
	cout << " -- Message send success." << endl;
	return;
}

