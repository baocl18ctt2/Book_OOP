
#include "List_Book.h"
#include <iostream>
#include <iomanip>

List_Book::List_Book()
{
}


List_Book::~List_Book()
{
}
List_Book::List_Book(vector<Book*> List)
{
	this->list_book = List;
}

void List_Book::read_list_book(ifstream& FileIn)
{
	while (FileIn.eof() == false)
	{
		Book* book = new Book;
		book->read_book_file(FileIn);
		book->set_hidebook(false);
		if (book->get_code() == "")
		{
			break;
		}
		list_book.push_back(book);
	}
}

void List_Book::display_list_book(ifstream& FileIn)
{
	cout << setw(10) << "CODE BOOK" << setw(35) << "NAME BOOK" << setw(20) << "PRICE BOOK" << setw(25) << "AUTHOR BOOK" << setw(25) << "PUBLISHER BOOK" << endl;
	cout << "===================================================================================================================" << endl;
	//heapSort(list_book[0], list_book.size());
	for (auto i : list_book)
	{
		cout << right << setw(10) << i->get_code() << setw(35) << i->get_name() << setw(20) << i->get_price() << setw(25) << i->get_author() << setw(25) << i->get_publisher() << endl;
	}
	ofstream FileOut("List_Sach.txt", ios::out);
	FileIn.clear();
	for (auto i : list_book)
	{
		FileOut << i->get_name() << ", " << i->get_code() << ", " << i->get_price() << ", " << i->get_author() << ", " << i->get_publisher() << endl;
	}
	FileOut.close();

}
void List_Book::display_hide_book(ifstream& FileTemp)
{
	ofstream FileOut("List_Temp.txt", ios::out);
	FileTemp.clear();
	for (auto i : list_book)
	{
		if (i->get_hidebook() == false)
		{
			FileOut << i->get_name() << ", " << i->get_code() << ", " << i->get_price() << ", " << i->get_author() << ", " << i->get_publisher() << endl;
		}
	}
	FileOut.close();
}
void List_Book::display_1_list_book(ifstream& FileIn)
{
	ofstream FileOut("List_Sach.txt", ios::out);
	FileIn.clear();
	for (auto i : list_book)
	{
		FileOut << i->get_name() << ", " << i->get_code() << ", " << i->get_price() << ", " << i->get_author() << ", " << i->get_publisher() << endl;
	}
	FileOut.close();
}
Book List_Book::search_book()
{
	string booLook;
	cout << "Input name book need search: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, booLook);
	vector <Book*> tempList;
	int cnt = 0;
	for (auto i : list_book)
	{
		if (i->get_name() == booLook)
		{
			tempList.push_back(i);
			cnt++;
		}
	}
	if (cnt == 1)
	{
		for (auto i : tempList)
			return *i;
	}
	else if (cnt > 1)
	{
		string codeLook;
		cout << "Input code book need search: ";
		fflush(stdin);
		getline(cin, codeLook);
		for (auto i : tempList)
		{
			if (i->get_code() == codeLook)
				return *i;
		}
	}
	return Book("", "", 0.0, " ", " ");
}

void List_Book::Delete(Book boo)
{
	vector<Book*>::iterator it;
	for (it = list_book.begin(); it != list_book.end(); ++it)
	{
		if (boo.get_code() == (*it)->get_code())
		{
			list_book.erase(it);
			break;
		}
	}
}

void List_Book::Update_price(Book boo)
{
	double newprice;
	if (boo.get_name() == "")
	{
		cout << "No book found in list book!" << endl;
		return;
	}
	cout << "Input new price of book: ";
	cin >> newprice;
	vector <Book*>::iterator it;
	for (it = list_book.begin(); it != list_book.end(); ++it)
	{
		if ((*it)->get_code() == boo.get_code())
		{
			(*it)->set_price(newprice);
		}
	}
}
void List_Book::Update_name(Book boo)
{
	string Newname;
	cout << "Input new name of book: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, Newname);
	vector <Book*>::iterator it;
	for (it = list_book.begin(); it != list_book.end(); ++it)
	{
		if ((*it)->get_code() == boo.get_code())
		{
			(*it)->set_name(Newname);
		}
	}
}
void List_Book::Update_code(Book boo)
{
	string NewCode;
	cout << "Input new code of book: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, NewCode);
	vector <Book*>::iterator it;
	for (it = list_book.begin(); it != list_book.end(); ++it)
	{
		if ((*it)->get_code() == boo.get_code())
		{
			(*it)->set_code(NewCode);
		}
	}
}
void List_Book::Update_author(Book boo)
{
	string NewAuthor;
	cout << "Input new author of book: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, NewAuthor);
	vector <Book*>::iterator it;
	for (it = list_book.begin(); it != list_book.end(); ++it)
	{
		if ((*it)->get_code() == boo.get_code())
		{
			(*it)->set_author(NewAuthor);
		}
	}
}
void List_Book::Update_publisher(Book boo)
{
	string NewPublisher;
	cout << "Input new publisher of book: ";
	cin.ignore();
	fflush(stdin);
	getline(cin, NewPublisher);
	vector <Book*>::iterator it;
	for (it = list_book.begin(); it != list_book.end(); ++it)
	{
		if ((*it)->get_code() == boo.get_code())
		{
			(*it)->set_publisher(NewPublisher);
		}
	}
}
void List_Book::Edit()
{
	Book boo = search_book();
	if (boo.get_name() == "")
	{
		cout << "No book found in list book!" << endl;
	}
	else
	{
		cout << " \n \t ------------------ " << endl;
		cout << " \t--- EDIT BOOK ---" << endl;
		cout << "\t ------------------------" << endl;
		cout << "\t1. Delete book" << endl;
		cout << "\t2. Update price" << endl;
		cout << "\t *******" << endl;
		cout << " Please select: ";
		int selection;
		cin >> selection;
		switch (selection) {
		case 1:
			Delete(boo);
			break;
		case 2:
			Update_price(boo);
			break;
		}
	}
}
void List_Book::Hide_book(Book boo)
{
	vector<Book*>::iterator it;
	for (it = list_book.begin(); it != list_book.end(); ++it)
	{
		if ((*it)->get_code() == boo.get_code())
			(*it)->set_hidebook(true);
	}
}

void List_Book::heapify(Book* arr, int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l].get_code() > arr[largest].get_code())
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r].get_code() > arr[largest].get_code())
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void List_Book::heapSort(Book* arr, int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}
