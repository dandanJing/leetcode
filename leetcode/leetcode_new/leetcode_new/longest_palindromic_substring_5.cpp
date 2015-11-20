#include"top.h"

bool isPalindrome(string s){
	bool result=true;
	int size=s.size();
	FOR(i,(size+1)/2){
		if(s[i]==s[size-1-i])continue;
		return false;
	}
	return result;
}

string findLagest(string s,int start, int end){
	string result="";
	if(start>end) return result;
	else if(start==end){
		result+=s[start];
		return result;
	}

	vector<int>pos_vec;
	pos_vec.push_back(start);
	int pos=s.find(s[start],start+1);
	while(pos!=-1){
		pos_vec.push_back(pos);
		pos=s.find(s[start],pos+1);
	}

	int pos1,pos2;
	FOR(i,pos_vec.size()){
		pos1=pos_vec[i];
		if(s.size()-pos1<=result.size())break;

		for(int j=pos_vec.size()-1;j>i;j--){
			pos2=pos_vec[j];
			if(pos2-pos1+1<=result.size())break;

			if(isPalindrome(s.substr(pos1,pos2-pos1+1)))result=s.substr(pos1,pos2-pos1+1);
			else if(pos2-pos1-1>result.size()){
				string temp=findLagest(s,pos1+1,pos2-1);
				if(temp.size()>result.size())result=temp;
			}
		}
	}
	if(pos_vec.size()){
		string temp=findLagest(s,pos_vec.back()+1,s.size()-1);
		if(temp.size()>result.size())result=temp;
	}
	return result;
}

string Solution::longestPalindrome(string s){
	return findLagest(s,0,s.size()-1);
}

 void let_5(){
	 Solution sol;
	 //cout<<sol.longestPalindrome("abcbacddsddcabc")<<endl;
	 cout<<sol.longestPalindrome("abcbdsdbdcabc")<<endl;
 }