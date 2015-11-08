#include"top.h"

bool Solution::isPalindrome(string s) {
	if(s.size()<=1)return true;
	int posi=0,posj=s.size()-1;
	while(posi<posj){
		if(!((s[posi]>='a' &&s[posi]<='z') || (s[posi]>='A' &&s[posi]<='Z') || (s[posi]>='0' &&s[posi]<='9'))){
			posi++;continue;
		}
		if(!((s[posj]>='a' &&s[posj]<='z') || (s[posj]>='A' &&s[posj]<='Z') || (s[posj]>='0' &&s[posj]<='9'))){
			posj--;continue;
		}
		if((s[posi]>='A' &&s[posi]<='Z')){
			s[posi]=s[posi]-'A'+'a';
		}
		if((s[posj]>='A' &&s[posj]<='Z')){
			s[posj]=s[posj]-'A'+'a';
		}
		if(s[posi]==s[posj]){
			posi++;posj--;continue;
		}else{
			return false;
		}
	}
	return true;
}

void let_125(){
	Solution sol;
	cout<<sol.isPalindrome("A man, a plan, a canal: Panama")<<endl;
}