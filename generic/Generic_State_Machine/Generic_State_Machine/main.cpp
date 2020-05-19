//--------------------------------------------------------------------------
// main.cpp
//--------------------------------------------------------------------------

#include "StateMachine.h"
#include "State.h"
#include "Test.h"

class CStateA : public CState<Test>
{
public:
	void Enter(Test *){}
	void Execute(Test *){}
	void Exit(Test *){}

	CStateA() {}
	~CStateA() {}
};

class CStateB : public CState<Test>
{
public:
	void Enter(Test *){}
	void Execute(Test *){}
	void Exit(Test *){}

	CStateB() {}
	~CStateB() {}
};

int main()
{
	Test localTest;
    CStateMachine<Test> smTest();
return 0;
}