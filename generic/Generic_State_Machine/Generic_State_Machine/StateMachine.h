//--------------------------------------------------------------------------
// StateMachine.h
//--------------------------------------------------------------------------

#ifndef __CSTATE_MACHINE_H__
#define __CSTATE_MACHINE_H__

#include "Test.h"

template<class T> class CState;

template<class T>
class CStateMachine
{
public:
	CStateMachine();
	~CStateMachine();

	// only for initialize the FSM
	inline void SetCurrentState( CState<T> * po_state)
	{ mpo_currentState = po_state; }
	inline void SetPreviousState( CState<T> * po_state)
	{ mpo_previousState = po_state; }
	inline void SetGlobalState( CState<T> * po_states)
	{ mpo_globalState = po_state; }

	void Update() const;
	void ChangeState(CState<T> *);
	void RevertToPreviousState();

	inline CState<T> * GetCurrentState() const
	{ return mpo_currentState; }
	inline CState<T> * GetPreviousState() const
	{ return mpo_previousState; }
	inline CState<T> * GetGlobalState() const
	{ return mpo_globalState; }

private:
	T			* mpo_owner;
	CState<T>	* mpo_currentState;
	CState<T>	* mpo_previousState;
	CState<T>	* mpo_globalState;
};
#endif
