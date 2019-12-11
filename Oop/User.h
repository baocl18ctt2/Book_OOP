#pragma once
#include <string>
#include <iostream>
#include "List_Manage.h"
#include "List_Invoice.h"
#include "Message.h"
using namespace std;
class User
{
private:
	string mAccount;
	string mPassword;
public:
	User();
	User(string, string);
	User(const User&);
	List_Book listSACH;
	List_Invoice listINVOICE;
	List_Manage listUSER;
	User(List_Book& lSach, List_Manage& luser,List_Invoice& linvoice);
	void set_account(string);
	string get_account();
	void set_password(string);
	string get_password();
	virtual ~User();
	Admin Login(ifstream& FileUser);
	void Registration(ifstream& FileIn);
	bool check_login_account(ifstream& FileIn);
	void printf_menu(ifstream& FileIn, ifstream& FileUser, ifstream& FileMessage);
	void read_message(ifstream& FileUser, ifstream& FileMessage);
	void send_message(ifstream& FileUser);
};

