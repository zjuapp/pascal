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
	virtual void emitcode(){
		cout << codestr << endl;
	}
	void setcode(const string & _codestr){
		codestr = _codestr;
	}
	virtual void debug(){

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
	void gencode();
	void debug(){
		puts("if_stmt");
		int i = 2;
		judge -> gencode();
		lchild -> debug();
		if(rchild.get() != nullptr)
		rchild -> debug();
	}
};

class assign_stmt:public base_stmt{
public:
	shared_ptr <base_expr> value;
	void debug(){

	}
	virtual void emitcode(){
		value -> emitcode();
		cout << codestr << endl;
	}
};
class record_assign: public assign_stmt{
public:
	string id;
	string member;
	void gencode();
	void debug(){
		puts("record_assign");
		int i = 2;
		cout << id << " " << member << endl;
		value -> gencode();
	}
};
class normal_assign: public assign_stmt{
public:
	string id;
	void gencode();
	void debug(){
		puts("normal_assign:");
		int i = 2;
		cout << id << endl;
		value -> gencode();
	}
};
class arr_assign: public assign_stmt{
public:
	shared_ptr <base_expr> index;
	string id;
	void debug(){
		puts("arr_assign");
		cout << id << "\nindex:\n";
		int i = 2;
		index -> gencode();
		value -> gencode();
	}
	void gencode();
};

class while_stmt: public base_stmt{
public:
	shared_ptr <base_expr> judge;
	shared_ptr <base_stmt> stmt;
	void debug(){
		puts("while:");
		int i = 2;
		judge -> gencode();
		stmt -> debug();
	}
	void gencode();
};

class for_stmt: public base_stmt{
public:
	string id;
	shared_ptr <base_expr> start;
	shared_ptr <base_expr> end;
	shared_ptr <base_stmt> stmt;
	int dic;
	void debug(){
		puts("forr");
		int i = 2;
		puts("start");
		start -> gencode();
		puts("end");
		end -> gencode();
		puts("stmt");
		stmt -> debug();
	}	
	void gencode();
};

class repeat_stmt: public base_stmt{
public:
	shared_ptr <stmt_list> stmt_vt;
	shared_ptr <base_expr> judge;
	void debug(){
		cout << "repeat" << endl;
		int j = 2;
		for(int i = 0; i < stmt_vt -> vt.size(); ++i){
			stmt_vt -> vt[i] -> debug();
		}
		cout << "judge" << endl;
		judge -> gencode();
	}
};

class case_expr{
public:
	shared_ptr <base_stmt> stmt;
	virtual void debug(){

	}
};

class case_expr_id : public case_expr{
public:
	string id;
	void debug(){
		cout << id << endl;
	}
};

class case_expr_const: public case_expr{
public:
	shared_ptr <key_value_tuple> value;
	void debug(){
		cout << value_set_to_str(value -> first -> gettype(),
			value -> second) << endl;
	}
};

class case_expr_list{
public:
	vector < shared_ptr<case_expr> >  case_vt;
	void debug(){ 
		for(int i = 0; i < case_vt.size();++i)
			case_vt[i] -> debug();
	}
};
class case_stmt: public base_stmt{
public:
	shared_ptr <base_expr> expr;
	shared_ptr <case_expr_list> case_list;
	void debug(){
		cout << "fuck case" << endl;
		cout <<" case_expr" << endl;
		case_list -> debug();
	}
	void gencode();
};

class goto_stmt:public base_stmt{
public:
	int addr;//address to go
};

class proc_stmt: public base_stmt{
public:
	string proc_id;
	vector < shared_ptr <base_expr> > param;
	void debug();
	void gencode();
};


