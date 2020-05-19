#include "State.h"
#include "Mediator.h"
#include <string>
using std::string;


Mediator::Mediator()
	:welcome_(new Welcome(this)), shop_(new Shop(this)),
	purchase_(new Purchase(this)), exit_(new Exit(this))
{}

void Mediator::Handle(const string & state)
{
	// centralize State transition
	if (state == "welcome.shop")
		shop_->Go();
	else if (state == "shop.purchase")
		purchase_->Go();
	else if (state == "purchase.exit")
		exit_->Go();
	else if (state == "welcome.exit")
		exit_->Go();
	else if (state == "shop.exit")
		exit_->Go();
	else if (state == "purchase.exit")
		exit_->Go();
}

//start point
Welcome & Mediator::GetWelcome() const
{
	return *welcome_;
}