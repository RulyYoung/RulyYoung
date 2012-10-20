/*
 *  UI.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-15.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __UI_H__
#define __UI_H__
#include "Face.h"
#include "Cell.h"

class UI
{
	friend class Cell;

public:

	UI(void);
	
	void OnInit(void);
	void OnFini(void);
	void OnDraw(void);
	void OnTend(void);
	bool ProcTouchDown(float x, float y);
	bool ProcTouchUP(float x, float y);

	Cell* GetRoot(void)	const;
	const Vec2& GetMousePos(void)	const;
	const Vec2& SetMousePos(const Vec2& in);

public:

	Vec2				mouse_pos;
	int					m_nCurrentPushNumber;
	Cell*				m_root;
	std::vector<Cell*>	m_vtrDrag;
};

#endif	//	__UI_H__



