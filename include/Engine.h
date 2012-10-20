/*
 *  Engine.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ENGINE_H__
#define __ENGINE_H__
#include "output.h"

class UI;
class Cell;
class TouchUI;
class Render;
class Engine
{
public:
	Engine(void);
	~Engine(void);
	void OnFrameMove(void);
	void OnDraw(void);
	double GetCurrentTime(void)	const;
	Render* GetRender(void)	const;
	TouchUI* GetTouch(void)	const;
	UI* GetUI(void)	const;
private:
	void OnInit(void);
	Render* m_render_ptr;
	TouchUI* m_touch_ptr;
	UI*		m_ui_ptr;
	double m_clock;
};

Engine& eg(void);
Cell* GetRoot(void);

void game(void);

class App;
App* CreateApp(void);
App* GetApp(void);
void FreeApp(void);
Engine* GetEngine(void);

#endif	//	__ENGINE_H__




