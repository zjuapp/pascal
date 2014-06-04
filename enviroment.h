#pragma once
#include "routine.h"
class enviroment{
public:
	deque < shared_ptr <routine_head> > q;
	static shared_ptr <enviroment> single();
	void insert(routine_head * tmp);
	shared_ptr <routine_head> top();
	void pop();
	int search(const string & id);
};