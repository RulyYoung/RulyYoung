/*
 *  Touch.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TOUCH_H__
#define __TOUCH_H__
#include "Base.h"
#include "TouchInterface.h"

class Touch
{
public:
	
	Touch(void);
	
	void OnTouchBegin(ITouch*);
	void OnTouchEnd(ITouch*);
	void OnTouchMove(ITouch*);
	void OnTouchDragBegin(ITouch*);
	void OnTouchDragEnd(ITouch* begin, ITouch* end);
	
private:
	
	bool m_bUITouch;
	POINT m_posStart;
};

#endif//	__TOUCH_H__