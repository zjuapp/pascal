#include "stmt.h"
#include "enviroment.h"
void record_assign::gencode(){
	int i = 2;
	value -> gencode(i);
	auto in = enviroment::single() -> top() -> v_r -> search(id, member);
	codestr = "SW R2, " +  itoa(in.first) + "($SP)";
	cout << codestr << endl;
}
void normal_assign::gencode(){
	int i =  2;	
	value -> gencode(i);
	auto in = enviroment::single() -> top() -> v_r -> search(id);
	codestr = "SW R2, " +  itoa(in.first) + "($SP)";
	cout << codestr << endl;
}
void proc_stmt::debug(){
	auto rout = enviroment::single() -> searchfunc(proc_id);
	if(rout == nullptr){
		cout << "no function:" << proc_id << "is founded" << endl;
		return;
	}
	if(rout -> gettype() == FUNC_ROUTINE){
		auto proc = (procedure *)rout.get();
		if(proc -> param.size() != param.size()){
			cout << "proc param size error" << endl;
			return;
		}
		for(int i = 0; i < param.size(); ++i){

		}
	}
	else{
		auto fun = (func * )rout.get();
		if(fun -> param.size() != param.size()){
			cout << "func param size error" << endl;
			return;
		}
		for(int i = 0; i < param.size(); ++i){
			if(fun -> param[i].first == 1){
				if(param[i] -> gettype() == ARR_EXPR_TYPE){
					auto res = (arr_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id, res -> index);
					cout << "param " << i << endl;
					cout << offset.first << endl;
				}
				else
				if(param[i] -> gettype() == ID_EXPR_TYPE){
					auto res = (id_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id);
					cout << "param " << i << endl;
					cout << offset.first << endl;
				}
				else
				if(param[i] -> gettype() == RECORD_EXPR_TYPE){
					auto res = (record_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id, res -> member);
					cout << "param " << i << endl;
					cout << offset.first << endl;
				}
			}
			else{
				cout << "param " << i << endl;
				param[i] -> gencode(i);
			}	
		}
	}
}