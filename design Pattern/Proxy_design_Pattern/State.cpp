#include "State.h"
#include "IAutomat.h"

// stateA
string StateA::Action1()
{
	automat_->SetState(automat_->GetStateB());
	return "StateA->Action1: switch to State B";
}

string StateA::Action2()
{
	return "StateA->Action2: no response";
}

string StateA::Action3()
{
	return "StateA->Action3: no response";
}

// stateB
string StateB::Action1()
{
	return "StateB->Action1: no response";
}

string StateB::Action2()
{
	automat_->SetState(automat_->GetStateC());
	return "StateB->Action2: switch to State C";
}

string StateB::Action3()
{
	return "StateB->Action3: no response";
}

// classC
string StateC::Action1()
{
	return "StateC->Action1: no response";
}

string StateC::Action2()
{
	return "StateC->Action2: no response";
}

string StateC::Action3()
{
	automat_->SetState(automat_->GetStateA());
	return "StateB->Action2: switch to State C";
}
