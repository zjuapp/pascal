#pragma once
#include "type_value.h"
class var_record{
private:
	map <string, shared_ptr <base_type> > mp;
	vector < pair <string, shared_ptr <base_type> > > vt;
	string concat(const vector <string> & vt){
		string res = "";
		for(const string & s: vt){
			res += s + ":";
		}
		return res;
	}
public:
	bool insert(const string type_id, shared_ptr <base_type> type);
	pair <int,int> searchoffset(const string & id);
	pair <int, int> searchoffset(const string & id, int index);
	pair <int, int> searchoffset(const string & id, const string & member);
	void gencode();
};