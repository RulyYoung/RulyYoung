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
	return m_info.SetW( in_value );
}
float ViewController::GetW(void)const
{
	return m_info.GetW();
}
float ViewController::SetH(float in_value)
{
	return m_info.SetH( in_value );
}
float ViewController::GetH(void)const
{
	return m_info.GetH();
}
unsigned int ViewController::SetColor(unsigned int in_color)
{
	return m_info.SetColor( in_color ).ToValue();
}
unsigned int ViewController::GetColor(void)	const
{
	return m_info.GetColor().ToValue();
}
float ViewController::SetX(float in_value)
{
	return m_info.SetX( in_value );
}
float ViewController::GetX(void)	const
{
	return m_info.GetX();
}
float ViewController::SetY(float in_value)
{
	return m_info.SetY( in_value );
}
float ViewController::GetY(void)	const
{
	return m_info.GetY();
}
float ViewController::GetAngle(void)	const
{
	return m_info.GetAngle();
}
float ViewController::SetAngle(float in_angle)
{
	return m_info.SetAngle( in_angle );
}
void ViewController::SetImage(const std::string& image_name)
{
	m_info.SetImage( Image2D( image_name.c_str() ) );
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




