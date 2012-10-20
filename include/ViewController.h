//
//  ViewController.h
//  D10
//
//  Created by Ruly on 2012-9-4.
//
//

#ifndef __D10__ViewController__
#define __D10__ViewController__
#include <string>
#include "Face.h"
class Cell;
class ViewController
{
	friend class Cell;
private:
	ViewController(void);
	~ViewController(void);
public:
 	float SetX(float);
	float GetX(void)	const;
	float SetY(float);
	float GetY(void)	const;
	float SetW(float in_value);
	float GetW(void)const;
	float SetH(float in_value);
	float GetH(void)const;
	float GetAngle(void)	const;
	float SetAngle(float);
	unsigned int SetColor(unsigned int in_color);
	unsigned int GetColor(void)	const;
	void SetImage(const std::string&);
	bool HitTest(const Vec2& pos)	const;
	void BeginDraw(void);
	void Draw(void);
	void EndDraw(void);
private:
	Face m_info;
};

#endif /* defined(__D10__ViewController__) */
