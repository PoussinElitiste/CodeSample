
template<class T> class CStateMachine;

class Test
{
public:
	Test()
        : mpo_stateMachine(0)
	{  }

	~Test() 
	{ }

private:
	CStateMachine<Test> * mpo_stateMachine;
};