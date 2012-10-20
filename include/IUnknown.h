//
//  IUnknown.h
//  test
//
//  Created by Ruly on 2012-7-18.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef test_IUnknown_h
#define test_IUnknown_h

class IUnknown
{
protected:
	IUnknown(void);
	virtual ~IUnknown(void);
public:
	virtual unsigned long Release(void);
	virtual unsigned long AddRef(void);
private:
	unsigned long m_my_ref_count;
};


template<typename T_PTRTYPE>
class SmartPtr
{
public:
	SmartPtr(void)
		:	ptr( 0 )
	{}
	SmartPtr(const SmartPtr& in_other)
		:	ptr( 0 )
	{
		Set( in_other.ptr );
	}
	~SmartPtr(void)
	{
		Set( 0 );
	}
	explicit SmartPtr(T_PTRTYPE in_ptr)
		:	ptr( 0 )
	{
		Set( in_ptr );
	}
	T_PTRTYPE operator=(T_PTRTYPE in_ptr)
	{
		Set( in_ptr );
		return ptr;
	}
	T_PTRTYPE GetPtr(void)	const
	{
		return ptr;
	}
	bool operator<(const SmartPtr& other)	const
	{
		return ptr < other.ptr;
	}
	bool operator==(const SmartPtr& other)	const
	{
		return ptr == other.ptr;
	}
	T_PTRTYPE operator->(void)const
	{
		return ptr;
	}
	void Set(T_PTRTYPE in_ptr)
	{
		if( ptr != in_ptr )
		{
			if( ptr )
			{
				ptr->Release();
			}
			ptr = in_ptr;
			if( in_ptr )
			{
				in_ptr->AddRef();
			}
		}
	}
private:
	T_PTRTYPE ptr;
};



#endif
