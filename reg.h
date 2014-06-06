#include "common.h"
#define REG_SIZE 4
class reg{
private:
	void init(){
		vt.clear();
		vt.push_back("si");
		vt.push_back("di");
		vt.push_back("bx");
		vt.push_back("cx");
		memset(flag, sizeof(flag), 0);
	}
	reg(){
		init();
	}
public:
	vector <string> vt;
	bool flag[REG_SIZE];
	static shared_ptr <reg> single(){
		static bool flag = false;
		static shared_ptr <reg> res;
		if(flag)
			return res;
		res.reset(new reg());
		flag = true;
		return res;
	}
	string find(int i){
		return vt[i];
	}
	string finde(int i){
		string res = "e";
		res += vt[i];
		return res;
	}
	void setflag(int i){
		flag[i] = true;
	}
	void setfree(int i){
		flag[i] = false;
	}
	int findfree(){
		for(int i = 0; i < REG_SIZE; ++i){
			if(!flag[i]){
				return i;
			}
		}
		return -1;
	}
	void clear(){
		//why can't memset??
		for(int i  = 0; i < REG_SIZE; ++i)
			flag[i] = false;
	}
	void setesi(){
		flag[0] = true;
	}
	void freeesi(){
		flag[0] = false;
	}
	void setcx(){
		flag[3] = true;
	}
	void freecx(){
		flag[3] = false;
	}
};