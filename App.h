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
class App
{
public:
	App(void);
	~App(void);
	Engine* GetEngine(void);
private:
	Engine* m_engine_ptr;
};
App* GetApp(void);
#endif /* defined(__D10__App__) */
