//
//  Object.h
//  D10
//
//  Created by Ruly on 2012-10-13.
//
//

#ifndef D10_Object_h
#define D10_Object_h

class Object
{
private:
	virtual ~Object(void);
protected:
	Object(void);
public
	virtual unsigned int AddRef(void);
	virtual unsigned int Release(void);
private:
	unsigned int m_ref_counter;
};

#endif
