#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "List_Book.h"
using namespace std;
class Admin
{
protected:
	string mkind;
	string mAccount;
	string mPassword;
	string mName;
	float mAge;
public:
	Admin();
	Admin(string kind, string account, string password, string name,float age);
	virtual ~Admin();
	void read_1_information(ifstream& FileIn);
	void display_1_information();
	void set_kind(string kind);
	string get_kind();
	void set_account(string account);
	string get_account();
	void set_password(string password);
	string get_password();
	void set_name(string name);
	string get_name();
	void set_age(float age);
	float get_age();
};

