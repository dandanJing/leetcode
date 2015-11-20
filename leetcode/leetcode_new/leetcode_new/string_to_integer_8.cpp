#include"top.h"

//情形1："+"
//情形2："+-2"
//情形3："  010"
//情形4："  -0012a42"
//情形5："+1"
//情形6："   +0 123"
//情形7："2147483648" 期望输出2147483647
//情形8："   - 321"
//情形9："    10522545459"
int Solution::myAtoi(string str){
	int result=0;
	bool isneg=false;
	bool isopt=false;
	bool isop=false;
	bool hasval=false;
	int temp;
	FOR(i,str.size()){
		if(str[i]=='-' && !isop){
			isneg=true;
			isop=true;
		}else if(str[i]>='0' && str[i]<='9'){
			if(isop && (!isneg&&!isopt)) return result;
			temp=result;
			result=result*10+str[i]-'0';
			if(0x7fffffff-temp*10<str[i]-'0' || temp!=result/10){
				if(isneg) return 0x80000000;
				else return 0x7fffffff;
			}
		}else if(str[i]==' '&&!hasval)continue;
		else if(str[i]==' ')break;
		else if(isop)break;
		else if(str[i]=='+'){
			isop=true;
			isopt=true;
		}else{
			isop=true;
		}
		if(str[i]!=' ')hasval=true;
	}
	if(isneg)result=-result;
	return result;
}

void let_8(){
	Solution sol;
	/*cout<<sol.myAtoi("  -0012a42")<<endl;
	cout<<sol.myAtoi("  010")<<endl;
	cout<<sol.myAtoi("+-2")<<endl;
	cout<<sol.myAtoi("+")<<endl;
	cout<<sol.myAtoi("+1")<<endl;
	cout<<sol.myAtoi("   +0 123")<<endl;*/
	cout<<sol.myAtoi("2147483648")<<endl;
	cout<<sol.myAtoi("-2147483648")<<endl;
	cout<<sol.myAtoi("1")<<endl;
	cout<<sol.myAtoi("   - 321")<<endl;
	cout<<sol.myAtoi("    10522545459")<<endl;
}