
#include "Invoice.h"
#include <iomanip>

Invoice::Invoice()
{
}


Invoice::~Invoice()
{
}

Invoice::Invoice(Book mboo, int number)
{
	boo = mboo;
	mQuantity = number;
}

Invoice::Invoice(Book mboo)
{
	boo = mboo;
}

Book Invoice::get_book()
{
	return boo;
}

void Invoice::set_quanity(int quantity)
{
	mQuantity = quantity;
}

int Invoice::get_quanity()
{
	return mQuantity;
}

void Invoice::set_book(Book mboo)
{
	boo = mboo;
}
void Invoice::display_invoice()
{
	long long money = boo.get_price() * mQuantity;
	cout << left << setw(20) << boo.get_code() << setw(40) << boo.get_name() << setw(20) << boo.get_price() << setw(20) << mQuantity << setw(20) << money << endl;
}