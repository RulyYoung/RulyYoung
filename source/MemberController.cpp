//
//  MemberController.cpp
//  D10
//
//  Created by Ruly on 2012-9-3.
//
//

#include "MemberController.h"
#include "Cell.h"



MemberController::MemberController(Cell* in_owner)
:	m_parent( NULL )
,	m_owner( in_owner )
{}
MemberController::~MemberController(void)
{}
Cell* MemberController::GetOwner(void)	const
{
	return m_owner;
}
void MemberController::Clear(void)
{
	std::vector<Cell*> free_table;
	ForEach( [&](Cell* p){
		free_table.push_back( p );
	});
	for(auto i = free_table.begin(); i != free_table.end(); ++i)
	{
		SAFE_DELETE( *i );
	}
	member_list.clear();
}
void MemberController::AddChild(Cell* p)
{
	if( 0 == p )
	{
		return;
	}
	if( p->GetMemberController()->GetParent() )
	{
		p->GetMemberController()->GetParent()->GetMemberController()->RemoveChild( p );
	}
	p->GetMemberController()->m_parent = m_owner;
	member_list.insert( p );
}
void MemberController::RemoveChild(Cell* p)
{
	if( 0 == p )
	{
		return;
	}
	p->GetMemberController()->m_parent = NULL;
	member_list.erase( p );
}
Cell* MemberController::GetParent(void)	const
{
	return m_parent;
}
MemberController* MemberController::GetMemberControllerFromCell
(Cell* p)
{
	return p->GetMemberController();
}


