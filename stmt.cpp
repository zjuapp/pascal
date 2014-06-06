#include "stmt.h"
#include "enviroment.h"
#include "reg.h"
void record_assign::gencode(){
	auto _reg = reg::single();
	_reg -> clear();
	int k  = value -> gencode();
	auto in = enviroment::single() -> search(id, member);
	codestr = "mov ebp, esp";
	codestr += "\nmov [ebp + " + itoa(in.first) + "], " + _reg -> finde(k);
	cout  << codestr << endl;
}
void normal_assign::gencode(){
	auto _reg = reg::single();
	_reg -> clear();
	int k  = value -> gencode();
	auto in = enviroment::single() -> search(id);
	codestr = "mov ebp, esp";
	codestr += "\nmov [ebp + " + itoa(in.first) + "], " + _reg -> finde(k); 
	cout  << codestr << endl;
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
					auto offset = enviroment::single() -> search(res -> id, 0);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent"<< endl;
						return;
					}
					cout << "param " << i << endl;
					cout << offset.first << endl;
				}
				else
				if(param[i] -> gettype() == ID_EXPR_TYPE){
					auto res = (id_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent" << endl;
						return;
					}
					cout << "param " << i << endl;
					cout << offset.first << endl;
				}
				else
				if(param[i] -> gettype() == RECORD_EXPR_TYPE){
					auto res = (record_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id, res -> member);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent";
						return;
					}
					cout << "param " << i << endl;
					cout << offset.first << endl;
				}
			}
			else{
				cout << "param " << i << endl;
				//param[i] -> gencode(i);
			}	
		}
	}
}
void proc_stmt::gencode(){
	auto rout = enviroment::single() -> searchfunc(proc_id);
	if(rout == nullptr){
		cout << "no function:" << proc_id << "is founded" << endl;
		return;
	}
	if(rout -> gettype() == PROC_ROUTINE){
		codestr = "sub esp, " + itoa(param.size() * 4);
		auto fun = (procedure *)rout.get();
		if(fun -> param.size() != param.size()){
			cout << "proc param size error" << endl;
			return;
		}
		for(int i = 0; i < param.size(); ++i){
			if(fun -> param[i].first == 1){
				if(param[i] -> gettype() == ARR_EXPR_TYPE){
					auto res = (arr_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id, 0);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent"<< endl;
						return;
					}
					codestr += "\nmov eax ," + offset.first;
					codestr += "\nmov [esp + " + itoa(param.size() * 4 - (i + 1) * 4) + "], eax";
				}
				else
				if(param[i] -> gettype() == ID_EXPR_TYPE){
					auto res = (id_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent" << endl;
						return;
					}
					codestr += "\nmov eax ," + offset.first;
					codestr += "\nmov [esp + " + itoa(param.size() * 4 - (i + 1) * 4) + "], eax";
				}
				else
				if(param[i] -> gettype() == RECORD_EXPR_TYPE){
					auto res = (record_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id, res -> member);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent";
						return;
					}
					codestr += "\nmov eax ," + offset.first;
					codestr += "\nmov [esp + " + itoa(param.size() * 4 - (i + 1) * 4) + "], eax";
				}
			}
			else{
				cout << codestr << endl;
				int ret = param[i] -> gencode();
				codestr = "";
				codestr += "\nmov [esp + " + itoa(param.size() * 4 - (i + 1) * 4) + "], " + reg::single() -> finde(ret);
				reg::single() -> setfree(ret);
			}	
		}
		codestr += "\ncall " + fun -> name;
		codestr += "\nadd esp, " + itoa(param.size() * 4);
		cout << codestr << endl;	
	}
	else{
		codestr = "sub esp, " + itoa((param.size() + 1) * 4);
		auto fun = (func * )rout.get();
		if(fun -> param.size() != param.size()){
			cout << "func param size error" << endl;
			return;
		}
		for(int i = 0; i < param.size(); ++i){
			if(fun -> param[i].first == 1){
				if(param[i] -> gettype() == ARR_EXPR_TYPE){
					auto res = (arr_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id, 0);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent"<< endl;
						return;
					}
					codestr += "\nmov eax ," + itoa(offset.first);
					codestr += "\nmov [esp + " + itoa(param.size() * 4 - (i + 1) * 4) + "], eax";
				}
				else
				if(param[i] -> gettype() == ID_EXPR_TYPE){
					auto res = (id_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent" << endl;
						return;
					}
					codestr += "\nmov eax ," + itoa(offset.first);
					codestr += "\nmov [esp + " + itoa(param.size() * 4 - (i + 1) * 4) + "], eax";
				}
				else
				if(param[i] -> gettype() == RECORD_EXPR_TYPE){
					auto res = (record_node_value *)param[i].get();
					auto offset = enviroment::single() -> search(res -> id, res -> member);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent";
						return;
					}
					codestr += "\nmov eax ," + itoa(offset.first);
					codestr += "\nmov [esp + " + itoa(param.size() * 4 - (i + 1) * 4) + "], eax";
				}
			}
			else{
				cout << codestr << endl;
				int ret = param[i] -> gencode();
				codestr = "";
				codestr += "\nmov [esp + " + itoa(param.size() * 4 - (i + 1) * 4) + "], " + reg::single() -> finde(ret);
				reg::single() -> setfree(ret);
			}	
		}
		codestr += "\ncall " + fun -> name;
		codestr += "\nadd esp, " + itoa(param.size() * 4);
		codestr += "\nmov eax, [esp]";
		codestr += "\nadd esp, 4";
		cout << codestr << endl;
	}
}
void arr_assign::gencode(){
	reg::single() -> clear();
	codestr = "";
	auto offset = enviroment::single() -> search(id, 3);
	int k = index -> gencode();
	if(k != 0){
		reg::single() -> setfree(k);
		codestr += "\nmov " + reg::single() -> finde(k) + ", " + "esi";
	}
	reg::single() -> setesi();
	codestr += "\nimul esi, " + itoa(base_type::size(offset.second));
	int v = value -> gencode();
	codestr += "\nmov ebp, esp\n";
	codestr += "\nmov [ebp + esi + " + itoa(offset.first) + "], " + reg::single() -> finde(v);
	cout << codestr << endl;
}
void if_stmt::gencode(){
	codestr = "";
	int k = judge -> gencode();
	string a1 = genlabel();
	string a2 = genlabel();
	codestr += "\ncmp " + reg::single() -> finde(k) + ", 0";
	reg::single() -> setfree(k);	
	codestr += "\njz " + a1;
	cout << codestr << endl;
	codestr = "";
	lchild -> gencode();
	codestr += "\njmp " + a2;
	codestr += "\n" + a1 + ":";
	if(rchild == nullptr){
		codestr += "\n;";
	}
	else{
		cout << codestr << endl;
		codestr = "";
		rchild -> gencode();
	}
	codestr += "\n" + a2 + ":\n;";
	cout << codestr << endl;
}
void for_stmt::gencode(){
	auto _reg = reg::single();
	_reg -> clear();
	int k = start -> gencode();
	string loop = genlabel();
	string break_place = genlabel();
	codestr += "\nmov ecx, " +  _reg -> finde(k);
	_reg -> setcx();
	_reg -> setfree(k);
	codestr += "\n" + loop + ":";
	cout << codestr << endl;
	codestr = "";
	int w = end -> gencode();
	codestr += "\ncmp ecx, " + _reg -> finde(w);
	codestr += "\njz " + break_place;
	cout << codestr << endl;
	codestr = "";
	stmt -> gencode();
	cout << "fuck for" << endl;
	if(dic){
		codestr += "\nsub ecx, 1";
	}
	else
		codestr += "\nadd ecx, 1";
	codestr += "\njmp " + loop;
	codestr += "\n" + break_place + ":;";
	cout << codestr << endl;
}
void while_stmt::gencode(){

}

void case_stmt::gencode(){

}