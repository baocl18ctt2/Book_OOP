#pragma once
#include <iostream>
#include <string>
#include "List_Manage.h"
#include "List_Book.h"
using namespace std;
class cAuthor
{
private:
	string account;
	string password;
public:
	cAuthor();
	~cAuthor();
	cAuthor(List_Book& lSach, List_Book& lBook, List_Manage lAuthor);
	List_Manage listAuthor;
	List_Book listSACH;
	List_Book lbook;
	Admin login(ifstream& FileAuthor);
	void add_book(Admin ad);
	void delete_book();
	void Edit_book();
	void print_menu(ifstream& FileIn, ifstream& FileAuthor,ifstream& FileTemp);
	void unclock_book();
	void message_by_age();
	void message_personal();
	void message_all_user();
	void send_message();
};

