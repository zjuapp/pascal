#pragma once
#include "common.h"
#include "type_value.h"
class const_record{
private:
	map <string , pair<type_ptr, value_set> >mp;
public:
	bool insert(const string & id, 
		type_ptr type, 
		value_set value){
		if(mp.find(id) != mp.end())
			return false;
		mp[id] = make_pair(type,value);
		return true;
	}

	void debug(){
		for(auto i = mp.begin(); i != mp.end(); ++i){
			cout << i -> first << " " << i -> second.first -> gettype() 
			<< " " << value_set_to_str(i -> second.first -> gettype(), i -> second.second) << endl;
		}
	}
	bool exist_check(){
		
	}
};

