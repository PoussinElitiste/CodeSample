//--------------------------------------------------------------------------
// State.h
//--------------------------------------------------------------------------

#ifndef __CSTATE_H__
#define __CSTATE_H__

template<class T>
class CState
{
public:
	CState();
	virtual ~CState();

	virtual void Enter(T *)		= 0;
	virtual void Execute(T *)	= 0;
	virtual void Exit(T *)		= 0;
};

#endif
