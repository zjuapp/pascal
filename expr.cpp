#include "expr.h"
#include "enviroment.h"
#include "reg.h"
#include "common.h"
int unary_expr::gencode(){
	int k = child -> gencode();
	switch(op){
	case MINUS_TYPE:
		codestr = "xor " + reg::single() -> finde(k) + ", -1";
		codestr += "\nadd " + reg::single() -> finde(k) + ", 1";
		break;
	case NOT_TYPE:
		codestr = "xor " + reg::single() -> finde(k) + ", -1";
		break;
	}
	cout << codestr << endl;
	return k;
}

int binary_expr::gencode(){
	auto _reg = reg::single();
	int l = lchild -> gencode();
	int r = rchild -> gencode();
	switch(op){
	case MUL_TYPE:
		codestr = "imul " + _reg -> finde(l) +", " + _reg -> finde(r);
		break;
	case PLUS_TYPE:
		codestr = "add " + _reg -> finde(l) +", " + _reg -> finde(r);
		break;
	case MINUS_TYPE:
		codestr = "sub " + _reg -> finde(l) +", " + _reg -> finde(r);
		break;
	case DIV_TYPE:
		codestr  = "mov eax, " + _reg -> finde(l);
		codestr += "\nidiv " + _reg -> finde(r);
		codestr += "\nmov " + _reg -> finde(l) + ", eax";
		break;
	case GE_TYPE:
		codestr = "cmp " + _reg -> finde(l) + ", " + _reg -> finde(r);
		codestr += "\npushf";
		codestr += "\npop eax";
		codestr += "\nshr eax, 7";
		codestr += "\nand eax, 1";
		codestr += "\nxor eax, 1";
		codestr += "\nmov " + _reg -> finde(l) + ", eax";
		break;
	case GT_TYPE:
		codestr = "cmp " + _reg -> finde(r) + ", " + _reg -> finde(l);
		codestr += "\npushf";
		codestr += "\npop eax";
		codestr += "\nshr eax, 7";
		codestr += "\nand eax, 1";
		codestr += "\nmov " + _reg -> finde(l) + ", eax";
		break;
	case LE_TYPE:
		codestr = "cmp " + _reg -> finde(r) + ", " + _reg -> finde(l);
		codestr += "\npushf";
		codestr += "\npop eax";
		codestr += "\nshr eax, 7";
		codestr += "\nand eax, 1";
		codestr += "\nxor eax, 1";
		codestr += "\nmov " + _reg -> finde(l) + ", eax";
		break;
	case LT_TYPE:
		codestr = "cmp " + _reg -> finde(l) + ", " + _reg -> finde(r);
		codestr += "\npushf";
		codestr += "\npop eax";
		codestr += "\nshr eax, 7";
		codestr += "\nand eax, 1";
		codestr += "\nmov " + _reg -> finde(l) + ", eax";
		break;
	case EQUAL_TYPE:
		codestr = "cmp " + _reg -> finde(l) + ", " + _reg -> finde(r);
		codestr += "\npushf";
		codestr += "\npop eax";
		codestr += "\nshr eax, 6";
		codestr += "\nand eax, 1";
		codestr += "\nmov " + _reg -> finde(l) + ", eax";
		break;
	case MOD_TYPE:
		codestr  = "mov eax, " + _reg -> finde(l);
		codestr += "\nidiv " + _reg -> finde(r);
		codestr += "\nmov " + _reg -> finde(l) + ", edx";
		break;
	case UNEQUAL_TYPE:
		codestr = "cmp " + _reg -> finde(l) + ", " + _reg -> finde(r);
		codestr += "\npushf";
		codestr += "\npop eax";
		codestr += "\nshr eax, 6";
		codestr += "\nand eax, 1";
		codestr += "\nxor eax, 1";
		codestr += "\nmov " + _reg -> finde(l) + ", eax";
		break;
	case AND_TYPE:
		codestr = "and " + _reg -> finde(l) +", " + _reg -> finde(r);
		break;
	}
	_reg -> setfree(r);
	cout << codestr << endl;
	return l;
}

int leaf_node_value::gencode(){
	auto _reg = reg::single();
	string str = value_set_to_str(type_id, value);
	int k = _reg -> findfree();
	switch(type_id){
	case INT_TYPE:
		codestr = "xor " + _reg -> finde(k) + "," + _reg -> finde(k);
		codestr += "\nmov " + _reg -> finde(k) + ", " + str;
		break;
	case REAL_TYPE:
		;
	}
	_reg -> setflag(k);
	cout << codestr << endl;
	return k;
}

int record_node_value::gencode(){
	auto _reg = reg::single();
	auto off = enviroment::single() -> top() -> v_r -> search(id, member);
	int k = _reg -> findfree();
	switch(off.second){
	case INT_TYPE:
		codestr = "mov ebp, esp";
		codestr += "\nmov " + _reg -> finde(k) + ", [ebp + " + itoa(off.first) + "]";
		break;
	case REAL_TYPE:
		;
	}
	_reg -> setflag(k);
	cout << codestr << endl;
	return k;
}

bool record_node_value::expr_value_type(){
	if(flag)
		return type_id;
	auto off = enviroment::single() -> top() -> v_r -> search(id, member);
	if(off.second == INT_TYPE)
		type_id = false;
	else
		type_id = true;
	flag = true;
	return type_id;
}

bool unary_expr::expr_value_type(){
	if(flag){
		return type_id;
	}
	type_id = child -> expr_value_type();
	flag = true;
	return type_id;
}

bool binary_expr::expr_value_type(){
	if(flag){
		return type_id;
	}
	type_id = lchild -> expr_value_type() && rchild -> expr_value_type();
	flag = true;
	return type_id;
}

bool id_node_value::expr_value_type(){
	
}
int id_node_value::gencode(){
	auto _reg = reg::single();
	auto off = enviroment::single() -> top() -> v_r -> search(id);
	int k = _reg -> findfree();
	switch(off.second){
	case INT_TYPE:
		codestr = "mov ebp, esp";
		codestr += "\nmov " + _reg -> finde(k) + ", [ebp + " + itoa(off.first) + "]";
		break;
	}
	_reg -> setflag(k);
	cout << codestr << endl;
	return k;
}

bool arr_node_value::expr_value_type(){

}

int arr_node_value::gencode(){
	return 3;
}
