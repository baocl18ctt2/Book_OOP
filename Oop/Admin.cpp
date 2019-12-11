
#include "Admin.h"
#include <iomanip>
Admin::Admin()
{
}
Admin::Admin(string kind, string account, string password, string name,float age)
{
	mkind = kind;
	mAccount = account;
	mPassword = password;
	mName = name;
	mAge = age;
}

Admin::~Admin()
{
}

void Admin::read_1_information(ifstream& FileIn)
{
	getline(FileIn, mkind, ',');
	if (mkind == "\nAuthor" || mkind == "\nPublisher" || mkind == "\nUser")
	{
		mkind.erase(mkind.begin(), mkind.begin() + 1);
	}
	FileIn.seekg(1, 1);
	getline(FileIn, mAccount, ',');
	FileIn.seekg(1, 1);
	getline(FileIn, mPassword, ',');
	FileIn.seekg(1, 1);
	getline(FileIn, mName, ',');
	FileIn.seekg(1, 1);
	FileIn >> mAge;
	/*string temp;
	getline(cin, temp);*/
}
void Admin::display_1_information()
{
	cout << left << setw(20) << mkind << setw(20) << mAccount << setw(20) << mPassword << setw(20) << mName << setw(30) << mAge << endl;
}

void Admin::set_kind(string kind)
{
	mkind = kind;
}

string Admin::get_kind()
{
	return mkind;
}

void Admin::set_account(string account)
{
	mAccount = account;
}

string Admin::get_account()
{
	return mAccount;
}

void Admin::set_password(string password)
{
	mPassword = password;
}

string Admin::get_password()
{
	return mPassword;
}

void Admin::set_name(string name)
{
	mName = name;
}

string Admin::get_name()
{
	return mName;
}

void Admin::set_age(float age)
{
	mAge = age;
}

float Admin::get_age()
{
	return mAge;
}

