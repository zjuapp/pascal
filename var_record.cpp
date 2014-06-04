#include "var_record.h"
bool var_record::insert(const string type_id, shared_ptr <base_type> type){
	if(mp.find(type_id) != mp.end())
		return false;
	mp[type_id] = type;
	vt.push_back(make_pair(type_id, type));
	return true;
}
pair <int,int> var_record::searchoffset(const string & id){
	int off = 0;
	for(int i = 0; i < vt.size(); ++i){
		if(vt[i].first != id)
			off += vt[i].second -> getsize();
		else{
			return make_pair(off, vt[i].second -> gettype());
		}
	}
	return make_pair(-1, -1);
}
pair <int, int> var_record::searchoffset(const string & id, int index){
	int off = 0;
	for(int i = 0; i < vt.size(); ++i){
		if(vt[i].first != id)
			off += vt[i].second -> getsize();
		else{
			if(vt[i].second -> gettype() == ARR_TYPE){
				arr_type * tmp = (arr_type *)vt[i].second.get();
				off += tmp -> nxt -> getsize() * index;
				return make_pair(off, tmp -> nxt -> gettype());
			}
			else
				return make_pair(-1,-1);
		}
	}
	return make_pair(-1,-1);
}
pair <int, int> var_record::searchoffset(const string & id, const string & member){
	int off = 0;
	for(int i = 0; i < vt.size(); ++i){
		if(vt[i].first != id)
			off += vt[i].second -> getsize();
		else{
			if(vt[i].second -> gettype() == RECORD_TYPE){
				record_type * tmp = (record_type *)vt[i].second.get();
				auto off2 = tmp -> search(member);
				if(off2.first == -1)
					return make_pair(-1,-1);
				return make_pair(off + off2.first, off2.second);
			}
		}
	}
	return make_pair(-1,-1);
}
void var_record::gencode(){
	int off = 0;
	for(int i = 0; i < vt.size(); ++i){
		off += vt[i].second -> getsize();
	}
	cout << "SUBI $SP, $SP, " + itoa(off) << endl;
}
