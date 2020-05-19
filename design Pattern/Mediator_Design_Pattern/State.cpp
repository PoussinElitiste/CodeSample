#include "Mediator.h"
#include "State.h"

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
#include <string>
using std::string;

Welcome::Welcome(Mediator * m)
	:mediator_(m), response_("n")
{}

void Welcome::Go()
{
	cout << "Welcome! do you want to shop?[Y/N]:";
	try
	{
		cin >> response_;
	}
	catch(...)
	{
		cout << "error";
	}

	if (response_ == string("y"))
		mediator_->Handle("welcome.shop");
	else
		mediator_->Handle("welcome.exit");

}

Shop::Shop(Mediator * m)
	:mediator_(m), response_("n")
{}

void Shop::Go()
{
	cout << "do you want to purchase?[Y/N]:";
	try
	{
		cin >> response_;
	}
	catch(...)
	{
		cout << "error";
	}

	if (response_ == string("y"))
		mediator_->Handle("shop.purchase");
	else
		mediator_->Handle("shop.exit");
}

Purchase::Purchase(Mediator * m)
	:mediator_(m)
{}

void Purchase::Go()
{
	cout << "buy item now?[Y/N]:";
	try
	{
		cin >> response_;
	}
	catch(...)
	{
		cout << "error";
	}

	if (response_ == string("y"))
		cout << "thanks for your purchase" << endl;

	mediator_->Handle("purchase.exit");
}

Exit::Exit(Mediator * m)
	:mediator_(m)
{
}

void Exit::Go()
{
	cout << "Please come again sometime" << endl;
}