//
//  ViewController.cpp
//  D10
//
//  Created by Ruly on 2012-9-4.
//
//

#include "ViewController.h"
#include "Face.h"
#include "RenderInterface.h"

ViewController::ViewController(void)
{}
ViewController::~ViewController(void)
{}
float ViewController::SetW(float in_value)
{
	m_info.w = in_value;
	return m_info.w;
}
float ViewController::GetW(void)const
{
	return m_info.w;
}
float ViewController::SetH(float in_value)
{
	m_info.h = in_value;
	return m_info.h;
}
float ViewController::GetH(void)const
{
	return m_info.h;
}
unsigned int ViewController::SetColor(unsigned int in_color)
{
	m_info.c = in_color;
	return m_info.c;
}
unsigned int ViewController::GetColor(void)	const
{
	return m_info.c;
}
float ViewController::SetX(float in_value)
{
	m_info.x = in_value;
	return m_info.x;
}
float ViewController::GetX(void)	const
{
	return m_info.x;}
float ViewController::SetY(float in_value)
{
	m_info.y = in_value;
	return m_info.y;
}
float ViewController::GetY(void)	const
{
	return m_info.y;
}
float ViewController::GetAngle(void)	const
{
	return m_info.angle;
}
float ViewController::SetAngle(float in_angle)
{
	m_info.angle = in_angle;
	return m_info.angle;
}
void ViewController::SetImage(const std::string& image_name)
{
	m_info.img = Image2D( image_name.c_str() );
}
bool ViewController::HitTest(const Vec2& pos)	const
{
	return m_info.HitTestI( pos );
}
void ViewController::BeginDraw(void)
{
	BeginFace( m_info );
}
void ViewController::EndDraw(void)
{
	EndFace();
}
void ViewController::Draw(void)
{
	DrawFace( m_info );
}




