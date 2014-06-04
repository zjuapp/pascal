#pragma once
#include "common.h"
#include "type_value.h"
#include "var_record.h"
#define UNDEFINE_EXPR "undefine_expr"


class base_expr{
public:
	string codestr;
	bool flag;
	bool type_id;//表达式结果 整数或则浮点 true表示浮点数
	bool expr_value_type(){

	}
	base_expr(){
		codestr = UNDEFINE_EXPR;
		flag = false;
	}
	virtual void gencode(int &i){//i 表示是放在哪个寄存器中
	}
	void setcodestr(const string & _codestr){
		codestr = _codestr;
	}
};

class unary_expr: public base_expr{
public:
	int op;
	shared_ptr <base_expr> child;
	void gencode(int &i);
	bool expr_value_type();

};


class binary_expr: public base_expr{
public:
	int op;
	shared_ptr <base_expr>  lchild;
	shared_ptr <base_expr> rchild;
	void gencode(int & i);
	bool expr_value_type();
};
class leaf_node_value: public base_expr{
public:
	value_set value;
	int type_id;
	void gencode(int &i);
	bool expr_value_type(){
		if(type_id == INT_TYPE)
			return false;
		else
			return true;
	}
}; 
class record_node_value: public base_expr{
public:
	string id;
	string member;
	void gencode(int & i);
	bool expr_value_type();
};

class id_node_value: public base_expr{
public:
	string id;
	void gencode(){

	}
	bool expr_value_type(){

	}
};



