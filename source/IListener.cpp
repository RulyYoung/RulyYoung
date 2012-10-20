//
//  IListener.cpp
//  test
//
//  Created by Ruly on 2012-8-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "IListener.h"
#include "Base.h"

EventController::EventController(void)
	: func_table( NULL )
{}
EventController::~EventController(void)
{
	ClearListener();
}
IListener* EventController::AddListener(IListener* listener)
{
	if( NULL == listener )
	{
		return NULL;
	}
	listener->AddRef();
	RemoveListener( listener );
	if( NULL == func_table )
	{
		func_table = NEW std::multimap<EVENT,SmartPtr<IListener*> >();
	}
	func_table->insert( std::make_pair( listener->GetEventType(), listener ) );
	return listener;
}
void EventController::RemoveListener(IListener* listener)
{
	if( NULL == func_table )
	{
		return;
	}
	for( std::multimap<EVENT,SmartPtr<IListener*> >::iterator
		i = func_table->begin();
		i != func_table->end(); ++i )
	{
		if( listener->GetEventType() != i->first )
		{
			break;
		}
		if( listener->GetEventType() == i->first
		 && i->second.GetPtr() == listener )
		{
			func_table->erase( i );
			break;
		}
	}
}
void EventController::RemoveListener(EVENT event)
{
	if( NULL == func_table )
	{
		return;
	}
	std::multimap<EVENT,SmartPtr<IListener*> >::iterator
		i_find = func_table->find( event );
	while( i_find != func_table->end() );
	{
		func_table->erase( i_find );
		i_find = func_table->find( event );
	}
}
void EventController::EventNotify(EVENT event,Cell* owner)
{
	if( NULL == func_table )
	{
		return;
	}
	for( std::multimap<EVENT,SmartPtr<IListener*> >::const_iterator
		i = func_table->begin();
		i != func_table->end(); ++i )
	{
		if( event != i->first )
		{
			break;
		}
		i->second->OnEvent( owner );
	}
}
void EventController::ClearListener(void)
{
	SAFE_DELETE( func_table );
}

