#ifndef AUTOMAT_H
#define AUTOMAT_H

#include "State.h"

class IAutomat
{
public:
	virtual void Action1() = 0;
	virtual void Action2() = 0;
	virtual void Action3() = 0;
	virtual IState * GetStateA() = 0;
	virtual IState * GetStateB() = 0;
	virtual IState * GetStateC() = 0;
	virtual void SetState(IState * s) = 0;
};

class Automat
	: public IAutomat
{
	IState * statA_; 
	IState * statB_; 
	IState * statC_;
	IState * currentState_;

public:
	Automat()
		:statA_(new StateA(this)), 
		statB_(new StateB(this)), 
		statC_(new StateC(this)), 
		currentState_(statA_)
	{}

	void Action1();
	void Action2();
	void Action3();

	// inline
	IState * GetStateA()
	{
		return statA_;
	}

	IState * GetStateB()
	{
		return statB_;
	}

	IState * GetStateC()
	{
		return statC_;
	}

	IState * GetCurrentState()
	{
		return currentState_;
	}

	void SetState(IState * s)
	{
		currentState_ = s;
	}
};

#endif