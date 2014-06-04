#pragma once
#include "routine.h"
#include "type_value.h"
class enviroment{
public:
	deque < shared_ptr <routine_head> > q;
	static shared_ptr <enviroment> single();
	void insert(routine_head * tmp);
	shared_ptr <routine_head> top();
	void pop();
	pair<int, int> search(const string & id);
	pair<int, int> search(const string & id, int index);
	pair<int, int> search(const string & id, const string & member);
};