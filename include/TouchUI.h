/*
 *  TouchUI.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-15.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TOUCHUI_H__
#define __TOUCHUI_H__
#include "Touch.h"


class TouchUI
:	public Touch
{
public:

	TouchUI(void);
	
	void OnDraw(void);
	void OnTend(void);

	void OnTouchBegin(ITouch*);
	void OnTouchEnd(ITouch*);
	void OnTouchMove(ITouch*);
	void OnTouchDragBegin(ITouch*);
	void OnTouchDragEnd(ITouch* begin, ITouch* end);
	
};


#endif	//	__TOUCHUI_H__