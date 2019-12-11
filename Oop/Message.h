#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "List_Manage.h"
using namespace std;
class Message
{
protected:
	string mkind;
	string mPeople;
	string mMessage;
public:
	vector<Message*> list_message;
	Message();
	Message(vector<Message*> list);
	Message(string kind,string people,string message);
	virtual ~Message();
	void read_1_information(ifstream& FileMessage);
	void display_1_information();
	void set_kind(string kind);
	string get_kind();
	void set_people(string people);
	string get_people();
	void set_message(string message);
	string get_message();
	void read_information_message(ifstream& FileMessage);
	
};

