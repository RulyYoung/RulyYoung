//
//  MemberController.h
//  D10
//
//  Created by Ruly on 2012-9-3.
//
//

#ifndef D10_MemberController_h
#define D10_MemberController_h
#include <set>
class Cell;
class MemberController
{
public:
	MemberController(Cell* in_owner);
	~MemberController(void);
	void Clear(void);	
	void AddChild(Cell*p);
	void RemoveChild(Cell*p);
	Cell* GetOwner(void)	const;
	Cell* GetParent(void)	const;
	template<typename T_FUNC>
	unsigned int ForEachTree(T_FUNC func, bool is_include_self);
	template<typename T_FUNC>
	void ForEach(T_FUNC func);
private:
	MemberController* GetMemberControllerFromCell(Cell*);
	Cell* m_parent;
	Cell* m_owner;
	std::set<Cell*>		member_list;
};


template<typename T_FUNC>
unsigned int MemberController::ForEachTree(T_FUNC func, bool is_include_self)
{
	unsigned int count = 1;
	if( is_include_self )
	{
		func( GetOwner() );
	}
	for( auto i = member_list.begin();
		i != member_list.end(); ++i )
	{
		GetMemberControllerFromCell( *i )->ForEachTree
		( func, true );
	}
	return count;
}
template<typename T_FUNC>
void MemberController::ForEach(T_FUNC func)
{
	for( auto i = member_list.begin();
		i != member_list.end(); ++i )
	{
		func( *i );
	}
}
#endif
