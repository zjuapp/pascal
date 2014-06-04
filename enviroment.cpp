#include "enviroment.h"
int enviroment::search(const string & id){
	
}
void enviroment::insert(routine_head * tmp){
	shared_ptr <routine_head> tp(tmp);
	q.push_back(tp);
}
shared_ptr <routine_head> enviroment::top(){
	return q.back();
}
void enviroment::pop(){
	q.pop_back();
	
}
shared_ptr <enviroment> enviroment::single(){
	static bool flag = false;
	static shared_ptr <enviroment> res;
	if(flag)
		return res;
	res.reset(new enviroment());
	flag = true;
	return res;
}