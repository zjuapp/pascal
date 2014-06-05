#include "enviroment.h"
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
pair<int, int> enviroment::search(const string &id){
	int l = q.size();
	int off = 0;
	for(int i = l - 1; i >= 0; --i){
		auto res  = q[i] -> v_r -> search(id);
		if(res.second == -1){
			off += res.first;
			continue;
		}
		else{
			off += res.first;
			return make_pair(off, res.second);
		}
	}
	return make_pair(off, -1);
}
pair<int, int> enviroment::search(const string & id, int index){
	int l = q.size();
	int off = 0;
	for(int i = l - 1; i >= 0; --i){
		auto res  = q[i] -> v_r -> search(id, index);
		if(res.second == -1){
			off += res.first;
			continue;
		}
		else{
			off += res.first;
			return make_pair(off, res.second);
		}
	}
	return make_pair(off, -1);
}
pair<int, int> enviroment::search(const string & id, const string & member){
	int l = q.size();
	int off = 0;
	for(int i = l - 1; i >= 0; --i){
		auto res  = q[i] -> v_r -> search(id, member);
		if(res.second == -1){
			off += res.first;
			continue;
		}
		else{
			off += res.first;
			return make_pair(off, res.second);
		}
	}
	return make_pair(off, -1);
}
shared_ptr <routine> enviroment::searchfunc(const string & id){
	int l = q.size();
	int off = 0;
	for(int i = l - 1; i >= 0; --i){
		for(int j = 0; j < q[i] -> r_r -> vt.size(); ++j){
			if(q[i] -> r_r -> vt[j] -> name == id){
				return q[i] -> r_r -> vt[i];
			}
		}
	}
	return nullptr;	
}
