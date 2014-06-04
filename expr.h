#pragma once
#include "common.h"
#include "type_value.h"
#include "var_record.h"
#define UNDEFINE_EXPR "undefine_expr"
#define BASE_EXPR_TYPE "base_type"
#define UNARY_EXPR_TYPE "unary_type"
#define BINARY_EXPR_TYPE "binary_type"
#define CONST_EXPR_TYPE "leaf_node_value"
#define ID_EXPR_TYPE "id_node_value"
#define RECORD_EXPR_TYPE "record_node_value"
#define ARR_EXPR_TYPE "arr_node_value"
class base_expr{
public:
	string codestr;
	bool flag;
	string type;
	string gettype(){
		return type;
	}
	bool type_id;//表达式结果 整数或则浮点 true表示浮点数
	base_expr(){
		codestr = UNDEFINE_EXPR;
		flag = false;
		type = BASE_EXPR_TYPE;
	}
	virtual void gencode(int &i){
	}//i 表示是放在哪个寄存器中
	void setcodestr(const string & _codestr){
		codestr = _codestr;
	}
	virtual bool expr_value_type(){

	}
	virtual ~base_expr(){
		
	}
};

class unary_expr: public base_expr{
public:
	int op;
	shared_ptr <base_expr> child;
	void gencode(int &i);
	bool expr_value_type();
	unary_expr(){
		type = UNARY_EXPR_TYPE;
	}
};


class binary_expr: public base_expr{
public:
	int op;
	shared_ptr <base_expr>  lchild;
	shared_ptr <base_expr> rchild;
	void gencode(int & i);
	bool expr_value_type();
	binary_expr(){
		type = BINARY_EXPR_TYPE;
	}
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
	record_node_value(){
		type = RECORD_EXPR_TYPE;
	}
};

class id_node_value: public base_expr{
public:
	string id;
	id_node_value(){
		type = ID_EXPR_TYPE;
	}
	void gencode(int & i);
	bool expr_value_type();
};

class arr_node_value: public base_expr{
public:
	string id;
	int index;
	arr_node_value(){
		type = ARR_EXPR_TYPE;
	}
	void gencode(int &i);
	bool expr_value_type();
};
