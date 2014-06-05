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
	virtual int gencode(){
	}//return the value is store in?
	void setcodestr(const string & _codestr){
		codestr = _codestr;
	}
	virtual bool expr_value_type(){

	}
	virtual ~base_expr(){
		
	}
	virtual bool isconst(){

	}
	virtual void emitcode(){

	}
};

class unary_expr: public base_expr{
public:
	int op;
	shared_ptr <base_expr> child;
	int gencode();
	bool expr_value_type();
	unary_expr(){
		type = UNARY_EXPR_TYPE;
	}
	bool isconst(){
		return child -> isconst();
	}
	void emitcode(){
		child -> emitcode();
		cout << codestr << endl;
	}
};


class binary_expr: public base_expr{
public:
	int op;
	shared_ptr <base_expr>  lchild;
	shared_ptr <base_expr> rchild;
	int gencode();
	bool expr_value_type();
	binary_expr(){
		type = BINARY_EXPR_TYPE;
	}
	bool isconst(){
		return lchild -> isconst() && rchild -> isconst();
	}
	void emitcode(){
		lchild -> emitcode();
		rchild -> emitcode();
		cout << codestr << endl;
	}
};
class leaf_node_value: public base_expr{
public:
	value_set value;
	int type_id;
	int gencode();
	bool expr_value_type(){
		if(type_id == INT_TYPE)
			return false;
		else
			return true;
	}
	bool isconst(){
		return true;
	}
	void emitcode(){
		cout << codestr << endl;
	}
}; 
class record_node_value: public base_expr{
public:
	string id;
	string member;
	int gencode();
	bool expr_value_type();
	record_node_value(){
		type = RECORD_EXPR_TYPE;
	}
	bool isconst(){
		return false;
	}
	void emitcode(){
		cout << codestr << endl;
	}
};

class id_node_value: public base_expr{
public:
	string id;
	id_node_value(){
		type = ID_EXPR_TYPE;
	}
	int gencode();
	bool expr_value_type();
	bool isconst(){
		return false;
	}
	void emitcode(){
		cout << codestr << endl;
	}
};

class arr_node_value: public base_expr{
public:
	string id;
	shared_ptr <base_expr> index;
	arr_node_value(){
		type = ARR_EXPR_TYPE;
	}
	int gencode();
	bool expr_value_type();
	bool isconst(){
		return false;
	}
	void emitcode(){
		cout << codestr << endl;
	}
};
