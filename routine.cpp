#include "routine.h"
#include "enviroment.h"
#include "common.h"
#include "reg.h"
#include "string_data.h"
void func::gencode(){
	cout << name << ":" << endl;
	for(int i = 0; i < param.size(); ++i){//reload the pass by address
		if(param[i].first){
			cout << "mov eax, [esp + " + itoa(param.size() * 4 + 8 - (i + 1) * 4) + "]\n";
			cout << "add eax, " << itoa((param.size() + 3) * 4) << endl;
			cout << "mov [esp + " + itoa(param.size() * 4 + 8 - (i + 1) * 4) + "], eax" << endl;
		}	
	}
	routine::gencode();
}
void procedure::gencode(){
	cout << name << ":" << endl;
	for(int i = 0; i < param.size(); ++i){//reload the pass by address
		if(param[i].first){
			cout << "mov eax, [esp + " + itoa(param.size() * 4 + 8 - (i + 1) * 4) + "]\n";
			cout << "add eax, " << itoa((param.size() + 3) * 4) << endl;
			cout << "mov [esp + " + itoa(param.size() * 4 + 8  - (i + 1) * 4) + "], eax" << endl;
		}	
	}
	routine::gencode();
}
void routine::gencode(){
	if(type != FUNC_ROUTINE && type != PROC_ROUTINE){
		cout << "section .data\n";
		string_data::single() -> gencode();
		cout << "section .text\n";
		cout << "global main\n";
		cout << "main:\n";
		cout << "sub esp, " << header -> v_r -> getsize() << endl;
		cout << "xor esi, esi" << endl;
	}
	enviroment::single() -> insert(this -> header.get());
	for(int i = 0; i < stmt_vt -> vt.size(); ++i){
		stmt_vt -> vt[i] -> gencode();
	}
	if(type == FUNC_ROUTINE || type == PROC_ROUTINE){
		cout << "ret" << endl;
	}
	else{
		cout << "mov eax, 1\n";
		cout << "mov ebx, 0\n";
		cout << "int 80h\n";
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
	shared_ptr <base_type> tmp(new base_type(INT_TYPE));
	for(int i = l - 1; i >= 0; --i){
		header -> v_r -> insert_front(param[i].second.first, param[i].second.second);
	}
	header -> v_r -> insert_front("~nop2", tmp);
	header -> v_r -> insert_front("~nop1", tmp);
	routine::add_function_param();
}
void func::add_function_param(){
	int l = param.size();
	shared_ptr <base_type> tmp(new base_type(INT_TYPE));
	for(int i = l - 1; i >= 0; --i){
		header -> v_r -> insert_front(param[i].second.first, param[i].second.second);
	}
	header -> v_r -> insert_front(name, ret);
	header -> v_r -> insert_front("~nop2", tmp);
	header -> v_r -> insert_front("~nop1", tmp);//for esi
	routine::add_function_param();
}