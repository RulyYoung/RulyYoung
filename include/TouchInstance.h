/*
 *  untitled.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>
#include "TouchInterface.h"
class TouchInstance
	:	public ITouch
{
	TouchInstance(void);

public:

	TouchInstance(NSSet*, UIView*);
	virtual int GetCount(void)	const;
	virtual bool GetPos(float& x, float& y, int index)	const;

private:
	NSSet* m_touchs;
	UIView* m_view;
};