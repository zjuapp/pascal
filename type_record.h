#pragma once
#include "common.h"
#include "type_value.h"
class type_record{
private:
	map <string, shared_ptr <base_type> > mp;
public:
	bool insert(const string type_id, shared_ptr <base_type> type){
		if(mp.find(type_id) != mp.end())
			return false;
		mp[type_id] = type;
		return true;
	}
	void debug(){
		for(auto i = mp.begin(); i != mp.end(); ++i){
			cout << i -> first << " " << i -> second -> gettype() << endl;
		}
	}
};
