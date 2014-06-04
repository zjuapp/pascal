#include "expr.h"
#include "enviroment.h"
void unary_expr::gencode(int &i){
	int k = i;
	child -> gencode(i);
	switch(op){
	case MINUS_TYPE:
		codestr = "SUB R" + itoa(k) + ", R1, R" + itoa(k);
		break;
	case NOT_TYPE:
		codestr = "SUB R" + itoa(k) + ", R1, R" + itoa(k);
		codestr += "\nADDI R" + itoa(k) + ", R" + itoa(k) + ", -1";
	}
	cout << codestr << endl;
}
void binary_expr::gencode(int & i){
	int k = i;
	int l = ++i;
	lchild -> gencode(i);
	int r = i;
	rchild -> gencode(i);
	switch(op){
	case MUL_TYPE:
		codestr = "MUL R" + itoa(k) + ", R" + itoa(l) + " , R" + itoa(r);
		break;
	case PLUS_TYPE:
		codestr = "ADD R" + itoa(k) + ", R" + itoa(l) + " , R" + itoa(r); 
	case MINUS_TYPE:
		codestr = "SUB R" + itoa(k) + ", R" + itoa(l) + " , R" + itoa(r); 	
	}
	cout << codestr << endl;
}
void leaf_node_value::gencode(int &i){
	string str = value_set_to_str(type_id, value);
	switch(type_id){
	case INT_TYPE:
		codestr = "ADDI R" + itoa(i) + " , R1," + str;
		break;
	case REAL_TYPE:
		codestr = "ADDI F" + itoa(i) + " , R1," + str;	
	}
	++i;
	cout << codestr << endl;
}
void record_node_value::gencode(int & i){
	auto off = enviroment::single() -> top() -> v_r -> searchoffset(id, member);
	switch(off.second){
	case INT_TYPE:
		codestr = "LW R" + itoa(i) + " " + itoa(off.first) + "($SP)";
		break;
	case REAL_TYPE:
		codestr = "L.D R" + itoa(i) + " " + itoa(off.first) + "($SP)" + 
		"\n" + "MTC1 R" + itoa(i) + ", F" + itoa(1);
	}
	++i;
	cout << codestr << endl;
}

bool record_node_value::expr_value_type(){
	if(flag)
		return type_id;
	auto off = enviroment::single() -> top() -> v_r -> searchoffset(id, member);
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
