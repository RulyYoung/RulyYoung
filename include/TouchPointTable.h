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
#import <UIKit/UIKit.h>
#include "TouchPoint.h"
#include <vector>


class TouchPointTable
:	public std::vector<TouchPoint>
{
public:
	TouchPointTable(NSSet* touchs, UIView* view);
};

#endif	//	__TOUCHINTERFACE_H__