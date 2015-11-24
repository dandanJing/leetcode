#include"top.h"

int getDecodeNum(string s){
	if(!s.size())return 0;
	if(s.size()==1 && s[0]!='0')return 1;
	else if(s.size()==1) return 0;

	int result=0;
	result+=getDecodeNum(s.substr(1,s.size()-1));
	if(s[0]=='1' || (s[0]=='2' && s[1]<'7')) result+=getDecodeNum(s.substr(2,s.size()-2));
	return result;
}

//输入"10"：期望1
//输入"101":期望1
int Solution::numDecodings(string s) {
	if(!s.size())return 0;
	if(s.size()==1 && s[0]!='0')return 1;
	else if(s[0]=='0') return 0;

	vector<int> count_vec;
	FOR(i,s.size())count_vec.push_back(1);
	for(int i=s.size()-1;i>=0;i--){
		if(i==s.size()-1){if(s[i]=='0') count_vec[i]=0;continue;}
		if(s[i]=='1' || (s[i]=='2' && s[i+1]<'7')){
			if(i==s.size()-2)count_vec[i]=count_vec[i+1]+1;
			else count_vec[i]=count_vec[i+1]+count_vec[i+2];
		}else if(s[i]=='0')count_vec[i]=0;
		else count_vec[i]=count_vec[i+1];
	}
	return count_vec[0];
}

void let_91(){
	Solution sol;
	cout<<sol.numDecodings("301")<<endl;
	cout<<sol.numDecodings("101")<<endl;
	cout<<sol.numDecodings("1234")<<endl;
	cout<<sol.numDecodings("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253")<<endl;
}