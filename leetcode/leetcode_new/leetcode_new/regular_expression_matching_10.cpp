#include"top.h"

bool Solution::isMatch(string s, string p){
	if(s.size()==0 && p.size()==0) return true;
	else if(p.size()==0)return false;
	else if(s.size()==0){
		if(p.size()%2)return false;
		for(int i=1;i<p.size();i+=2){
			if(p[i]!='*')return false;
		}
		return true;
	}

	int pos1=s.size()-1, pos2=p.size()-1;
	while(pos1>=0 && pos2>=0){
		if(s[pos1]==p[pos2]){
			pos1--;pos2--;
		}else if(p[pos2]=='.'){
			pos1--;pos2--;
		}else if(p[pos2]=='*'){
			if(pos2==0)return false;
			else if(p[pos2-1]=='.'){
				if(pos2-1==0)return true;

				int temp=pos1+1;
				while(temp>=0){
					if(isMatch(s.substr(0,temp),p.substr(0,pos2-1)))return true;
					temp--;
				}
				return false;
			}else if(p[pos2-1]!=s[pos1]){
				pos2-=2;
			}else{
				int temp=pos1+1;
				while(1){
					if(temp<0 || (temp<pos1+1 && p[pos2-1]!=s[temp]))break;
					if(isMatch(s.substr(0,temp),p.substr(0,pos2-1)))return true;
					temp--;
				}
				return false;
			}
		}else{
			return false;
		}
	}
	if(pos1<0 && pos2<0) return true;
	else if(pos1<0){
		if(pos2 % 2){
			while(pos2>=0){
				if(p[pos2]!='*')return false;
				pos2-=2;
			}
			return true;
		}
	}
	return false;
}

void let_10(){
	Solution sol;
	
	cout<<sol.isMatch("cbbbaccbcacbcca","b*.*b*a*.a*b*.a*")<<endl;
	/*cout<<sol.isMatch("","c*c*")<<endl;
	cout<<sol.isMatch("aasdfasdfasdfasdfas","aasdf.*asdf.*asdf.*asdf.*s")<<endl;
	cout<<sol.isMatch("aab","b.*")<<endl;
	cout<<sol.isMatch("ab","a*..")<<endl;
	cout<<sol.isMatch("aabvd","a*,v*.")<<endl;

	cout<<sol.isMatch("aa","a")<<endl;
	cout<<sol.isMatch("aa","aa")<<endl;
	cout<<sol.isMatch("aaa","aa")<<endl;
	cout<<sol.isMatch("aa","a*")<<endl;
	cout<<sol.isMatch("aa",".*")<<endl;
	cout<<sol.isMatch("ab",".*")<<endl;
	cout<<sol.isMatch("aab","c*a*b")<<endl;*/
}