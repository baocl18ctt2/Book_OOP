#pragma once
#include "Book.h"
#include <iostream>
#include <vector>
class List_Book
{
public:
	vector<Book*> list_book;
	List_Book(vector<Book*> List);
	List_Book();
	virtual ~List_Book();
	void read_list_book(ifstream& FileIn);
	void display_list_book(ifstream& FileIn);
	void display_hide_book(ifstream& FileTemp);
	Book search_book();
	void Delete(Book boo);
	void Update_price(Book boo);
	void Update_name(Book boo);
	void Update_code(Book boo);
	void Update_author(Book boo);
	void Update_publisher(Book boo);
	void Edit();
	void display_1_list_book(ifstream& FileIn);
	void Hide_book(Book boo);
	void heapify(Book arr[], int n, int i);
	void heapSort(Book arr[], int n);
};

