#include "stmt.h"
#include "enviroment.h"
#include "reg.h"
void record_assign::gencode(){
	base_stmt::gencode();
	auto _reg = reg::single();
	_reg -> clear();
	int k  = value -> gencode();
	auto in = enviroment::single() -> search(id, member);
	codestr = "mov ebp, esp";
	codestr += "\nmov [ebp + " + itoa(in.first) + "], " + _reg -> finde(k);
	cout  << codestr << endl;
	_reg -> setfree(k);
}
void normal_assign::gencode(){
	base_stmt::gencode();
	auto _reg = reg::single();
	int k  = value -> gencode();
	auto in = enviroment::single() -> search(id);
	codestr = "mov ebp, esp";
	codestr += "\nmov [ebp + " + itoa(in.first) + "], " + _reg -> finde(k); 
	cout  << codestr << endl;
	_reg -> setfree(k);
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
	base_stmt::gencode();
	auto rout = enviroment::single() -> searchfunc(proc_id);
	if(rout == nullptr){
		cout << "no function:" << proc_id << "is founded" << endl;
		return;
	}
	if(rout -> gettype() == PROC_ROUTINE){
		int call_length = param.size() * 4;
		auto fun = (procedure *)rout.get();
		codestr = "mov ebp, esp";
		if(fun -> param.size() != param.size()){
			cout << "proc param size error" << endl;
			return;
		}
		for(int i = 0; i < param.size(); ++i){
			if(fun -> param[i].first == 1){
				pair <int, int> offset;
				if(param[i] -> gettype() == ARR_EXPR_TYPE){
					auto res = (arr_node_value *)param[i].get();
				 	offset = enviroment::single() -> search(res -> id, 0);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent"<< endl;
						return;
					}
				}
				else
				if(param[i] -> gettype() == ID_EXPR_TYPE){
					auto res = (id_node_value *)param[i].get();
					offset = enviroment::single() -> search(res -> id);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent" << endl;
						return;
					}
				}
				else
				if(param[i] -> gettype() == RECORD_EXPR_TYPE){
					auto res = (record_node_value *)param[i].get();
					offset = enviroment::single() -> search(res -> id, res -> member);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent";
						return;
					}
				}
				codestr += "\nmov eax ," + itoa(offset.first);
				codestr += "\nmov [ebp - " + itoa((i + 2) * 4) + "], eax";
			
			}
			else{
				cout << codestr << endl;
				int ret = param[i] -> gencode();
				codestr = "";
				codestr += "\nmov [ebp - " + itoa((i + 2) * 4)  + "], " + reg::single() -> finde(ret);
				reg::single() -> setfree(ret);
			}	
		}
		codestr += "\nsub esp, " + itoa(call_length);
		codestr += "\ncall " + fun -> name;
		codestr += "\nadd esp, " + itoa(call_length);
		cout << codestr << endl;	
	}
	else{
		int call_length = (param.size() + 1) * 4;
		codestr = "mov ebp, esp";
		auto fun = (func * )rout.get();
		if(fun -> param.size() != param.size()){
			cout << "func param size error" << endl;
			//cout << fun -> name << endl;
			cout << fun -> param.size() << " " << param.size() << endl;
			return;
		}
		for(int i = 0; i < param.size(); ++i){
			pair<int, int> offset;
			if(fun -> param[i].first == 1){
				if(param[i] -> gettype() == ARR_EXPR_TYPE){
					auto res = (arr_node_value *)param[i].get();
					offset = enviroment::single() -> search(res -> id, 0);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent"<< endl;
						return;
					}
				}
				else
				if(param[i] -> gettype() == ID_EXPR_TYPE){
					auto res = (id_node_value *)param[i].get();
					offset = enviroment::single() -> search(res -> id);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent" << endl;
						return;
					}
				}
				else
				if(param[i] -> gettype() == RECORD_EXPR_TYPE){
					auto res = (record_node_value *)param[i].get();
					offset = enviroment::single() -> search(res -> id, res -> member);
					if(offset.second != fun -> param[i].second.second -> gettype()){
						cout << "param " << i << " type unconsistent";
						return;
					}
				}
				codestr += "\nmov eax ," + itoa(offset.first);
				codestr += "\nmov [ebp - " + itoa((i + 2) * 4) + "], eax";
			}
			else{
				cout << codestr << endl;
				int ret = param[i] -> gencode();
				codestr = "";
				codestr += "\nmov [ebp - " + itoa((i + 2) * 4) + "], " + reg::single() -> finde(ret);
				reg::single() -> setfree(ret);
			}	
		}
		codestr += "\nsub esp, " + itoa(call_length);
		codestr += "\ncall " + fun -> name;
		codestr += "\nadd esp, " + itoa(call_length - 4);
		codestr += "\nmove ebp, esp\nmov eax, [ebp]";
		codestr += "\nadd esp, 4";
		cout << codestr << endl;
	}
}
void arr_assign::gencode(){
	base_stmt::gencode();
	codestr = "";
	auto offset = enviroment::single() -> search(id, 3);
	int k = index -> gencode();
	if(k != 0){
		reg::single() -> setfree(k);
		codestr += "\nmov esi, " + reg::single() -> finde(k);
	}
	reg::single() -> setesi();
	codestr += "\nimul esi, " + itoa(base_type::size(offset.second));
	int v = value -> gencode();
	codestr += "\nmov ebp, esp\n";
	codestr += "\nmov [ebp + esi + " + itoa(offset.first) + "], " + reg::single() -> finde(v);
	cout << codestr << endl;
	reg::single() -> setfree(k);
}
void if_stmt::gencode(){
	base_stmt::gencode();
	int k = judge -> gencode();
	string a1 = labelmanager::genlabel();
	string a2 = labelmanager::genlabel();
	cout << "cmp " + reg::single() -> finde(k) + ", 0" << endl;
	reg::single() -> setfree(k);	
	cout << "jz " + a1 << endl;
	lchild -> gencode();
	cout << "jmp " + a2 << endl;
	cout << a1 + ":" << endl;
	if(rchild == nullptr){
	}
	else{
		rchild -> gencode();
	}
	cout << a2 << ":" << endl;
}
void for_stmt::gencode(){
	base_stmt::gencode();
	auto off = enviroment::single() -> search(id);
	auto _reg = reg::single();
	_reg -> clear();
	int k = start -> gencode();
	cout << "mov ebp, esp" << endl;
	cout << "mov [ebp + " << off.first << "], " + _reg -> finde(k) << endl;
	string loop = labelmanager::genlabel();
	string break_place = labelmanager::genlabel();
	_reg -> setfree(k);
	cout << loop + ":" << endl;
	int w = end -> gencode();
	cout << "mov eax, [ebp + " << off.first  << "]" << endl;
	cout << "cmp eax, " + _reg -> finde(w) << endl;
	cout << "jz " + break_place << endl;
	stmt -> gencode();
	if(dic){
		cout << "mov eax, [ebp + " << off.first << "]" << endl; 
		cout << "sub eax, 1" << endl;
		cout << "mov [ebp + " << off.first << "], eax" << endl; 
	}
	else{
		cout << "mov eax, [ebp + " << off.first << "]" << endl; 
		cout << "add eax, 1" << endl;
		cout << "mov [ebp + " << off.first << "], eax" << endl;
	}
	cout << "jmp " + loop << endl;
	cout << break_place + ":";
}
void while_stmt::gencode(){
	base_stmt::gencode();
	auto _reg = reg::single();
	_reg -> clear();
	string loop =  labelmanager::genlabel();
	string break_place = labelmanager::genlabel();
	cout << loop + ":" << endl; 
	int ju = judge -> gencode();
	cout << "cmp " + _reg -> finde(ju) + ", 0" << endl;  
	_reg -> setfree(ju);
	cout << "jz " + break_place << endl;
	stmt -> gencode();
	cout << "jmp " + loop << endl;
	cout << break_place + ":;";
}

void case_stmt::gencode(){
	base_stmt::gencode();
	auto _reg = reg::single();
	_reg -> clear();
	vector <string> label_vt;
	int lcmp = expr -> gencode();
	for(int i = 0; i < case_list -> case_vt.size(); ++i){
		label_vt.push_back(labelmanager::genlabel());
	}
	string over_label = labelmanager::genlabel();
	for(int i = 0; i < case_list -> case_vt.size(); ++i){
		cout << "cmp " + _reg -> finde(lcmp) + ", " + value_set_to_str(case_list -> case_vt[i] -> value -> first -> gettype(),
			case_list -> case_vt[i] -> value -> second) << endl;
		cout << "jz " + label_vt[i] << endl;
	}
	cout << codestr << endl;
	for(int i = 0; i < case_list -> case_vt.size(); ++i){
		cout << label_vt[i] << ":\n";
		case_list -> case_vt[i] -> stmt -> gencode();
		cout << "jmp " << over_label << endl; 
	}
	cout << over_label << ":;" << endl;
}

void repeat_stmt::gencode(){
	base_stmt::gencode();
	auto _reg = reg::single();
	_reg -> clear();
	string loop =  labelmanager::genlabel();
	cout << loop + ":";
	for(int i = 0; i < stmt_vt -> vt.size(); ++i){
		stmt_vt -> vt[i] -> gencode();
	}
	int ju = judge -> gencode();
	cout << "cmp " + _reg -> finde(ju) + ", 0" << endl; 
	_reg -> setfree(ju);
	cout << "jz " + loop << endl;
}

void goto_stmt::gencode(){
	base_stmt::gencode();
	cout << "jmp " << labelmanager::searchlabel(addr) << endl;
}

int func_node_value::gencode(){
	func_stmt -> gencode();
	int k = reg::single() -> findfree();
	reg::single() -> setflag(k);
	cout << "mov " +reg::single() -> finde(k) + ", eax";
	return k;
}