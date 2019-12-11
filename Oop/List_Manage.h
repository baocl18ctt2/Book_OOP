#pragma once
#include <iostream>
#include <string>
#include "Admin.h"
#include "List_Book.h"
using namespace std;
class List_Manage
{
private:
	string NAME;
	string PASS;
public:
	vector<Admin*> list_manage;
	List_Manage(vector<Admin*> List);
	List_Book lSach;
	List_Book lbook;
	List_Manage();
	virtual ~List_Manage();
	void read_information(ifstream& FileIn);
	void display_information_admin(ifstream& FileAdmin);
	void display_information_author(ifstream& FileAuthor);
	void display_information_publisher(ifstream& FilePublisher);
	void display_information_user(ifstream& FileUser);
	void add_book();
	void delete_book();
	void Edit_book();
	List_Manage(List_Book&, List_Book&, vector<Admin*> list, string, string);
	void print_menu(ifstream& FileIn, ifstream& FileTemp);
	Admin check_login(string account, string password);
	void Cauthor(ifstream& FileAuthor);
	void add_author();
	void delete_author_Or_publisher();
	Admin search_author_Or_publisher();
	void edit_author_Or_publisher();
	void Cpublisher(ifstream& FilePublisher);
	void add_publisher();
	void Cuser(ifstream& FileUser);
	void add_user();
	void hide_book();
	void unclock_book();
	void send_message();
	void message_by_age();
	void message_personal();
	void message_all_user();
};

