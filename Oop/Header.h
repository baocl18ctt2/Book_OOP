#pragma once
#include <iostream>
#include "List_Book.h"
#include "stdlib.h"
#include <fstream>
#include "List_Manage.h"
#include "cAuthor.h"
#include "cPublisher.h"
#include "User.h"
using namespace std;
void cUser(List_Book& lSach, List_Manage& luser, List_Invoice& linvoice, ifstream& FileIn, ifstream& FileUser,ifstream &FileMessage);
void Actor(List_Book& lSach, List_Book& lBook, List_Manage& lAuthor, ifstream& FileIn, ifstream& FileAuthor, ifstream& FileTemp);
void admin(List_Book& lSach, List_Book& lBook, vector <Admin*> list, ifstream& FileIn, ifstream& FileTemp, ifstream& FileAuthor, ifstream& FilePublisher, ifstream& FileUser);
void Publisher(List_Book& lSach, List_Book& lBook, List_Manage& lpublisher, ifstream& FileIn, ifstream& FilePublisher,ifstream &FileTemp);
void cInvoice(ifstream& FileInvoice, ifstream& FileBook);