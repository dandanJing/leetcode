#include"top.h"

bool Solution::isMatch44(string s, string p){
	if(s.size()==0 && p.size()==0) return true;
	else if(p.size()==0)return false;
	else if(s.size()==0){
    		for(int i=0;i<p.size();i++){
    			if(p[i]!='*')return false;
    		}
    		return true;
	    }
	if(s[0]==p[0] || p[0]=='?')return isMatch44(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
	if(s[s.size()-1]==p[p.size()-1] || p[p.size()-1]=='?')return isMatch44(s.substr(0,s.size()-1),p.substr(0,p.size()-1));

	if(s[s.size()-1] != p[p.size()-1] && (p[p.size()-1]!='?' && p[p.size()-1]!='*')) return false;
	if(s[0] != p[0] && (p[0]!='?' && p[0]!='*')) return false;

	string maxstr="";
	string tempstr="";
	int maxpos=0;
	int curpos=0;
	int qcount=0;
	int pcount=0;
	for(int i=0;i<p.size();i++){
		if(p[i]=='*' || p[i]=='?'){
			if(p[i]=='?')qcount++;
			else pcount++;

			if(tempstr.size()>maxstr.size()){
				maxstr=tempstr;
				maxpos=curpos;
			}
			tempstr="";
			curpos=i+1;
		}else{
			tempstr+=p[i];
		}
	}
	if(tempstr.size()>maxstr.size()){
				maxstr=tempstr;
				maxpos=curpos;
			}

	if(!maxstr.size()) {
		if(qcount> s.size())return false;
		else if(qcount== s.size())return true;
		else if(pcount)return true;
		else return false;
	}

	int pos=s.find(maxstr,0);
	while(pos!=-1){
		string str1=s.substr(0,pos);
		string str2=p.substr(0,maxpos);
		string str3=s.substr(pos+maxstr.size(),s.size()-(pos+maxstr.size()));
		string str4=p.substr(maxpos+maxstr.size(),p.size()-(maxpos+maxstr.size()));
		if(isMatch44(str1,str2) && isMatch44(str3,str4))return true;
		pos=s.find(maxstr,pos+1);
	}
	return false;
	/*if(s.size()==0 && p.size()==0) return true;
	    else if(p.size()==0)return false;
	    else if(s.size()==0){
    		for(int i=0;i<p.size();i++){
    			if(p[i]!='*')return false;
    		}
    		return true;
	    }
		if(s[s.size()-1] != p[p.size()-1] && (p[p.size()-1]!='?' || p[p.size()-1]!='*')) return false;
		if(s[0]==p[0] || p[0]=='?') return isMatch44(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
		else if(p[0]=='*'){
			int temp=1;
			while(temp<p.size()){
				if(p[temp]=='*')temp++;
				else break;
			}
			if(temp==p.size())return true;
			int cur=0;
			while(cur<s.size()){
				if(isMatch44(s.substr(cur,s.size()-cur),p.substr(temp,p.size()-temp)))return true;
				cur++;
			}
		}
		return false;*/
    	/*int pos1=s.size()-1, pos2=p.size()-1;
    	while(pos1>=0 && pos2>=0){
    		if(s[pos1]==p[pos2]){
    			pos1--;pos2--;
    		}else if(p[pos2]=='?'){
    			pos1--;pos2--;
    		}else if(p[pos2]=='*'){
				pos2--;
				while(pos2>=0 && p[pos2]=='*'){
					pos2--;
				}
				if(pos2<0) return true;

    		    int temp=pos1;
				if(p[pos2]=='?')temp=pos1+1;
				while(temp>=0){
					if(p[pos2]=='?'){
						if(isMatch44(s.substr(0,temp),p.substr(0,pos2)))return true;
					}else if(s[temp]==p[pos2]){
						if(isMatch44(s.substr(0,temp),p.substr(0,pos2)))return true;
					}

					temp--;
				}
				return false;
    		}else{
    			return false;
    		}
    	}
    	if(pos1<0 && pos2<0) return true;
    	else if(pos1<0){
    	    for(int i=0;i<=pos2;i++){
    	        if(p[i]!='*')return false;
    	    }
    		return true;
    	}
    	return false;*/
}

void let_44(){
	Solution sol;
	cout<<sol.isMatch44("ab","*a*")<<endl;//1
	cout<<sol.isMatch44("aa","aa")<<endl;//1
	cout<<sol.isMatch44("aa","*")<<endl;//1
	cout<<sol.isMatch44("aa","a*")<<endl;//1
	cout<<sol.isMatch44("ab","?*")<<endl;//1
	cout<<sol.isMatch44("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb","**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")<<endl;//0
	cout<<sol.isMatch44("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb","b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a")<<endl;//0
	cout<<sol.isMatch44("aa","a")<<endl;//0
	cout<<sol.isMatch44("aaa","aa")<<endl;//0
	cout<<sol.isMatch44("aab","c*a*b")<<endl;//0
	cout<<sol.isMatch44("bbbababbabbbbabbbbaabaaabbbbabbbababbbbababaabbbab","a******b*")<<endl;//0
	cout<<sol.isMatch44("abaabaaaabbabbaaabaabababbaabaabbabaaaaabababbababaabbabaabbbbaabbbbbbbabaaabbaaaaabbaabbbaaaaabbbabb","ab*aaba**abbaaaa**b*b****aa***a*b**ba*a**ba*baaa*b*ab*")<<endl;//0
	


}