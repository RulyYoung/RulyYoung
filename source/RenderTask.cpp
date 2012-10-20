#include "RenderTask.h"




RenderTaskFace::RenderTaskFace(void)
{}
RenderTaskFace::~RenderTaskFace(void)
{
}
const Color& RenderTaskFace::SetColor(const Color& in_color)
{
	m_face->c = in_color;
	return m_face->c;
}
float RenderTaskFace::SetWidth(float in_w)
{
	m_face->w = in_w;
	return m_face->w;
}
float RenderTaskFace::SetHeight(float in_h)
{}
float RenderTaskFace::SetX(float in_x)
{}
float RenderTaskFace::SetY(float in_y)
{
	return m_face->y;
}

//////////////////////////////////////////

RenderTaskMngr::RenderTaskMngr(void)
{
}
RenderTaskMngr::~RenderTaskMngr(void)
{
	Clear();
}
void RenderTaskMngr:: Send(RenderTask* task_ptr)
{
	m_render_queue.push_back( task_ptr );
}
RenderTask* RenderTaskMngr::GetFirst(void)
{
	if( m_render_queue.empty() )
	{
		return NULL;
	}
	return m_render_queue.front();
}
void RenderTaskMngr::Pop(void)
{
	SAFE_RELEASE( m_render_queue.front() );
	m_render_queue.pop_front();
}
void RenderTaskMngr::Clear(void)
{
	while( !m_render_queue.empty() )
	{
		SAFE_RELEASE( m_render_queue.front() );
		m_render_queue.pop_front();
	}
}