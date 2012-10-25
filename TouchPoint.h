/*
 *  untitled.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TOUCHPOINT_H__
#define __TOUCHPOINT_H__

class TouchPoint
{
public:
	TouchPoint(void);
	TouchPoint(float inX, float inY, int inIndex);
	int GetIndex(void)	const;
	float GetX(void)	const;
	float GetY(void)	const;
private:
	int m_Index;
	float m_X, m_Y;
};

#endif