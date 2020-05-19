#ifndef IAUTOMAT_H
#define IAUTOMAT_H

class IState;

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

#endif