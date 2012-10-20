//
//  App.h
//  D10
//
//  Created by Ruly on 2012-10-20.
//
//

#ifndef __D10__App__
#define __D10__App__

class Engine;
class SceneMngr;
class App
{
public:
	App(void);
	~App(void);
	Engine* GetEngine(void);
	SceneMngr* GetSceneMngr(void)	const;
private:
	SceneMngr* m_scene_mngr_ptr;
	Engine* m_engine_ptr;
};
App* GetApp(void);
#endif /* defined(__D10__App__) */
