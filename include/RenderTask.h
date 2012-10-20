//
//  RenderTask.h
//  D10
//
//  Created by Ruly on 2012-10-13.
//
//

#ifndef D10_RenderTask_h
#define D10_RenderTask_h
#include "Color.h"

class RenderTask
:	public Object
{
protected:
	RenderTask(void);
	virtual ~RenderTask(void);
};

class Face;
class RenderTaskFace
{
public:
	RenderTaskFace(void);
	virtual ~RenderTaskFace(void);
	const Color& SetColor(const Color&);
	float SetWidth(float);
	float SetHeight(float);
	float SetX(float);
	float SetY(float);
private:
	Face* m_face;
};

class RenderTaskMngr
{
public:
	RenderTaskMngr(void);
	~RenderTaskMngr(void);
	RenderTask* GetFirst(void);
	void Send(RenderTask*);
	void Pop(void);
private:
	void Clear(void);
	std::list<RenderTask*> m_render_queue;
};





#endif
