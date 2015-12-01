#include"top.h"

string Solution::minWindow(string s, string t){
	    string result="";
        std::map<char,int> char_map;
        std::map<char,int>::iterator it;
        
        int len=t.size();
        //½¨Á¢×Öµä
        for(int i=0;i<t.size();i++){
            it=char_map.find(t[i]);
            if(it == char_map.end()){
                char_map.insert(pair<char,int>(t[i],1));
            }else{
                it->second++;
            }
        }
        
        int curlen=0;
        int spos=0;
        for(int i=0;i<s.size();i++){
            it=char_map.find(s[i]);
            if(it != char_map.end()){
                if(it->second > 0){
                    it->second--;
                    curlen++;
                    if(curlen==1)spos=i;
                    if(curlen==len){
                        
                        while(spos<=i){
                            if(curlen==len){
                                string temps=s.substr(spos,i-spos+1);
								if(!result.size())result=temps;
                                else if(temps.size()<result.size())result=temps;

                                it=char_map.find(s[spos]);
                                if(it != char_map.end()){
                                    it->second++;
                                    if(it->second > 0)curlen--;
                                }
                                spos++;
                            }else{
                                break;
                            }
                        }
                    }
                }
                else it->second--;
            }
        }
        return result;
}

void let_76(){
	Solution sol;
	cout<<sol.minWindow("a","a")<<endl;
	//cout<<sol.minWindow("ADOBECODEBANC","ABCC")<<endl;
}