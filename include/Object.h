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
public:
	Object(void);
	~Object(void);
	unsigned int AddRef(void);
	unsigned int Release(void);
private:
	unsigned int m_ref_counter;
};

#endif
