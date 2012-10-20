/*
 *  Cell.h
 *  new4
 *
 *  Created by Ruly on 10-2-18.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __UICELL_H__
#define __UICELL_H__
#include "Face.h"
#include "orb.h"
#include <set>
#include "IListener.h"

using namespace orb;

#include "MemberController.h"
#include "ViewController.h"

class Cell
	:	public IUnknown
{
public:
	Cell(void);
	virtual ~Cell(void);
public:
	EventController* GetEventController(void);
	ViewController* GetViewController(void) const;
	MemberController* GetMemberController(void)const;
	void Draw(void);
	bool PickList(std::vector<Cell*>&,
		const Vec2& pos)	const;
	bool HitTest(const Cell&)	const;
	void GetLocalPos(Vec2& pos)	const;
	Vec2 GetCursorPos(void)	const;
	Vec2 GetRealPos(void)	const;
	bool GetEnable(void)	const;
	bool SetEnable(bool is_enable);
	bool GetVisible(void)	const;
	bool SetVisible(bool is_visible);
	virtual void OnDraw(void);
	virtual void OnFrameMove(void);
	virtual void OnTouchDown(void);
	virtual void OnTouchUp(void);
	virtual void OnTouchClick(void);
	virtual void OnEventNotify(EVENT);
private:
	MemberController* m_member_controller;
	ViewController*	m_face_controller;
	EventController* m_event_controller;
	bool m_enable;
	bool m_is_visible;
};
#endif	//	__UICELL_H__





