//--------------------------------------------------------------------------
// StateMachine.cpp
//--------------------------------------------------------------------------
#include "StateMachine.h"
#include "State.h"

CStateMachine<class T>::CStateMachine()
	: mpo_owner(0)
	, mpo_currentState(0)
	, mpo_previousState(0)
	, mpo_globalState(0)
{}

CStateMachine<class T>::~CStateMachine()
{}

void CStateMachine<class T>::Update() const
{
	if( mpo_globalState ) mpo_globalState->Execute(mpo_owner);

	if( mpo_currentState ) mpo_currentState->Execute(mpo_owner);
}

void CStateMachine<class T>::ChangeState(CState<T> * po_newState )
{
	if( !po_newState )
		return;
	//assert( po_newState && "<CStateMachine::ChangeState> - try to change to a null state");
	
	mpo_previousState = mpo_currentState;

	mpo_currentState->Exit( mpo_owner );

	mpo_currentState = po_newState;

	mpo_currentState->Enter( mpo_owner );
}

void CStateMachine<class T>::RevertToPreviousState()
{
	ChangeState(mpo_previousState);
}
