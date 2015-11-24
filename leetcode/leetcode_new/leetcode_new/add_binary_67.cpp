#include"top.h"

string Solution::addBinary(string a, string b){
	string result="";
	int val=0;
	int val1,val2;
	int temp;
	char tempc;
	int pos1=a.size()-1,pos2=b.size()-1;
	while(pos1>=0 || pos2>=0){
		if(pos1>=0)val1=a[pos1--]-'0';
		else val1=0;
		if(pos2>=0)val2=b[pos2--]-'0';
		else val2=0;
		temp=val1+val2+val;
		tempc='0'+temp%2;
		result=tempc+result;
		val=temp/2;
	}
	if(val)result="1"+result;
	return result;
}

void let_67(){
	Solution sol;
	cout<<sol.addBinary("0","1")<<endl;
	cout<<sol.addBinary("11","1")<<endl;
}