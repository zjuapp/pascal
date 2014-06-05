#include "routine.h"
#include "enviroment.h"
#include "common.h"
void func::gencode(){
	cout << name << ":" << endl;
	routine::gencode();
}
void procedure::gencode(){
	cout << name << ":" << endl;
	routine::gencode();
}
void routine::gencode(){
	enviroment::single() -> insert(this -> header.get());
	for(int i = 0; i < stmt_vt -> vt.size(); ++i){
		stmt_vt -> vt[i] -> gencode();
		stmt_vt -> vt[i] -> emitcode();
	}
	for(int i = 0; i < header -> r_r -> vt.size(); ++i){
		header -> r_r -> vt[i] -> gencode();
	}
	enviroment::single() -> pop();
}
void routine::add_function_param(){
	for(int i = 0; i < header -> r_r -> vt.size(); ++i){
		header -> r_r -> vt[i] -> add_function_param();
	}
}
void procedure::add_function_param(){
	int l = param.size();
	map <string, string> mp;
	for(int i = l - 1; i >= 0; --i){
		header -> v_r -> insert_front(param[i].second.first, param[i].second.second);
	}
	routine::add_function_param();
}
void func::add_function_param(){
	int l = param.size();
	for(int i = l - 1; i >= 0; --i){
		header -> v_r -> insert_front(param[i].second.first, param[i].second.second);
	}
	header -> v_r -> insert_front(name, ret);
	routine::add_function_param();
}