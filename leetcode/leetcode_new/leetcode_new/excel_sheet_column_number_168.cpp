#include"top.h"

string Solution::convertToTitle(int n){
	string result="";
	string str_blank="";
	char ctemp;
	int temp=n;
	int cur;
	while(temp){
		temp-=1;
		cur=temp%26;
		temp/=26;
		ctemp=cur+'A';
		str_blank+=ctemp;
		result=str_blank+result;
		str_blank="";
	}
	return result;
}

void let_168(){
	Solution sol;
	cout<<sol.convertToTitle(52)<<endl;
}