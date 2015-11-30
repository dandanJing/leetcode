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

    	int pos1=s.size()-1, pos2=p.size()-1;
    	while(pos1>=0 && pos2>=0){
    		if(s[pos1]==p[pos2]){
    			pos1--;pos2--;
    		}else if(p[pos2]=='?'){
    			pos1--;pos2--;
    		}else if(p[pos2]=='*'){
    		    int temp=pos1+1;
				while(temp>=0){
					if(isMatch44(s.substr(0,temp),p.substr(0,pos2)))return true;
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
    	return false;
}

void let_44(){
	Solution sol;
	/*cout<<sol.isMatch44("aa","a")<<endl;
	cout<<sol.isMatch44("aa","aa")<<endl;
	cout<<sol.isMatch44("aaa","aa")<<endl;
	cout<<sol.isMatch44("aa","*")<<endl;
	cout<<sol.isMatch44("aa","a*")<<endl;
	cout<<sol.isMatch44("ab","?*")<<endl;*/
	cout<<sol.isMatch44("aab","c*a*b")<<endl;
}