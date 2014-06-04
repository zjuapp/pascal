#include "stmt.h"
#include "enviroment.h"
void record_assign::gencode(){
	int i = 2;
	value -> gencode(i);
	auto in = enviroment::single() -> top() -> v_r -> search(id, member);
	codestr = "SW R2, " +  itoa(in.first) + "($SP)";
	cout << codestr << endl;
}
void normal_assign::gencode(){
	int i =  2;	
	value -> gencode(i);
	auto in = enviroment::single() -> top() -> v_r -> search(id);
	codestr = "SW R2, " +  itoa(in.first) + "($SP)";
	cout << codestr << endl;
}
