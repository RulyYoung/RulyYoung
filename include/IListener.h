//
//  IListener.h
//  test
//
//  Created by Ruly on 2012-8-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef test_IListener_h
#define test_IListener_h
#include <map>

#include "IUnknown.h"

enum EVENT
{
	EVENT_FRAMEMOVE,
};
class Cell;

class IListener
	:	public IUnknown
{
protected:
	IListener(void){}
public:
	virtual EVENT GetEventType(void)	const = 0;
	virtual void OnEvent(Cell* self) = 0;	
};

class EventController
	:	public IUnknown
{
protected:
	~EventController(void);
public:
	EventController(void);
	IListener* AddListener(IListener*);
	void RemoveListener(IListener*);
	void RemoveListener(EVENT event);
	void EventNotify(EVENT,Cell* owner);
	void ClearListener(void);
private:
	std::multimap<EVENT, SmartPtr<IListener*> >* func_table;
};

#define LISTENER_BEGIN(OBJ,EVENTTYPE)\
{\
	Cell* const _OBJ = OBJ;\
	class MyListener\
		: public IListener\
	{\
	public:\
		virtual EVENT GetEventType(void)	const\
		{\
			return EVENTTYPE;\
		}\
		void OnEvent(Cell* OBJ)\
		{
#define LISTENER_END()\
		}\
	};\
	_OBJ->GetEventController()->AddListener( NEW MyListener() )->Release();\
	}

#endif
