#pragma once
#include <iostream>
#include <string>
#include "List_Manage.h"
#include "List_Book.h"
using namespace std;
class cPublisher
{
private:
	string account;
	string password;
public:
	cPublisher();
	~cPublisher();
	cPublisher(List_Book& lSach, List_Book& lBook, List_Manage lpublisher);
	List_Manage listPublisher;
	List_Book listSACH;
	List_Book lbook;
	Admin login(ifstream& FilePublisher);
	void add_book(Admin ad);
	void delete_book();
	void Edit_book();
	void print_menu(ifstream& FileIn, ifstream& FilePublisher, ifstream& FileTemp);
	void unclock_book();
	void message_by_age();
	void message_personal();
	void message_all_user();
	void send_message();
};

