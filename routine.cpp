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
	enviroment::single() -> insert(this -> header);
	for(int i = 0; i < stmt_vt -> vt.size(); ++i){
		stmt_vt -> vt[i] -> gencode();
		stmt_vt -> vt[i] -> emitcode();
	}
	header -> c_r -> debug();
	/*
	for(int i = 0; i < header -> r_r -> vt.size(); ++i){
		cout << header -> r_r;
	}*/	
	enviroment::single() -> pop();
}