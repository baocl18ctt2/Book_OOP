#include "Message.h"

Message::Message()
{
}

Message::Message(vector<Message*> list)
{
	list_message = list;
}

Message::Message(string kind, string people, string message)
{
	mkind = kind;
	mPeople = people;
	mMessage = message;
}

Message::~Message()
{
}

void Message::read_1_information(ifstream& FileMessage)
{
	getline(FileMessage, mkind, ',');
	FileMessage.seekg(1, 1);
	getline(FileMessage, mPeople, ',');
	FileMessage.seekg(1, 1);
	getline(FileMessage, mMessage);
}

void Message::display_1_information()
{
	cout << mkind << ": " << mMessage << endl;
}

void Message::set_kind(string kind)
{
	mkind = kind;
}

string Message::get_kind()
{
	return mkind;
}

void Message::set_people(string people)
{
	mPeople = people;
}

string Message::get_people()
{
	return mPeople;
}

void Message::set_message(string message)
{
	mMessage = message;
}

string Message::get_message()
{
	return mMessage;
}

void Message::read_information_message(ifstream& FileMessage)
{
	while (FileMessage.eof() == false)
	{
		Message* mes = new Message;
		mes->read_1_information(FileMessage);
		if (mes->get_people() == "")
		{
			break;
		}
		list_message.push_back(mes);
	}
}
