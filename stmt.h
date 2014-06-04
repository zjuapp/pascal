#pragma once
#include "expr.h"
class base_stmt{
public:
	string codestr;
	base_stmt(){
		codestr = UNDEFINE_EXPR;
	}
	virtual void gencode(){
	}
	void setcode(const string & _codestr){
		codestr = _codestr;
	}
};


class stmt_list{
public:
	vector < shared_ptr <base_stmt> > vt;
};

class if_stmt:public base_stmt{
public:
	shared_ptr <base_expr>  judge;
	shared_ptr <base_stmt> lchild;
	shared_ptr <base_stmt> rchild;
	void gencode(){

	}
};

class assign_stmt:public base_stmt{
public:
	shared_ptr <base_expr> value;

};
class record_assign: public assign_stmt{
public:
	string id;
	string member;
	void gencode();

};
class normal_assign: public assign_stmt{
public:
	string id;
	void gencode();
};
class arr_assign: public assign_stmt{
public:
	shared_ptr <base_expr> index;
	string id;
};

class while_stmt: public base_stmt{
public:
	shared_ptr <base_expr> judge;
	shared_ptr <base_stmt> stmt;
};

class for_stmt: public base_stmt{
public:
	string id;
	shared_ptr <base_expr> start;
	shared_ptr <base_expr> end;
	shared_ptr <base_stmt> stmt;
	int dic;	
};

class repeat_stmt: public base_stmt{
public:
	shared_ptr <stmt_list> stmt_vt;
	shared_ptr <base_expr> judge;
};

class case_expr{
public:
	shared_ptr <base_stmt> stmt;
};

class case_expr_id : public case_expr{
public:
	string id;
};

class case_expr_const: public case_expr{
public:
	shared_ptr <key_value_tuple> value;
};

class case_expr_list{
public:
	vector < shared_ptr<case_expr> >  case_vt;
};
class case_stmt: public base_stmt{
public:
	shared_ptr <base_expr> expr;
	shared_ptr <case_expr_list> case_list;
};

class goto_stmt:public base_stmt{
public:
	int addr;//address to go

};

class proc_stmt: public base_stmt{
public:
	string proc_id;
	vector < shared_ptr <base_expr> > param;
};


