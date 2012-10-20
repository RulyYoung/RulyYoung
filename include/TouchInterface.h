/*
 *  TouchInterface.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TOUCHINTERFACE_H__
#define __TOUCHINTERFACE_H__
#include "DataUtil.h"

class ITouch
{
protected:

	ITouch(void)	{}

public:
	virtual int GetCount(void) const = 0;
	virtual bool GetPos(float& x, float& y, int index)	const = 0;
};

int GetTouchCount(void);
bool GetTouchPos(int* x, int* y,int index);

#endif	//	__TOUCHINTERFACE_H__