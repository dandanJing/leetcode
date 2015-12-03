#include"top.h"

bool isPalindrome(string s){
    if(s.size()==0) return false;
    if(s.size()==1) return true;
    
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}

vector<vector<string>> Solution::partition(string s){
	vector<vector<string>>result;
        if(!s.size()) return result;
        
        queue<vector<string>> que_vec;
        vector<string> first;
        first.push_back(s);
        que_vec.push(first);
        
		
        while(que_vec.size()){
            vector<string>  temp = que_vec.front();
            que_vec.pop();
            string cur_str = temp.back();
            if(cur_str.size()==1){
                result.push_back(temp);
            }else{
                int pos=cur_str.find(cur_str[0]);
                while(pos!=-1){
                    string div_str = cur_str.substr(0,pos+1);
                    if(isPalindrome(div_str)){
                        if(pos==cur_str.size()-1){
                            result.push_back(temp);
                        }else{
                            vector<string>  que_add(temp);
                            que_add.pop_back();
                            que_add.push_back(div_str);
                            que_add.push_back(cur_str.substr(pos+1,cur_str.size()-pos-1));
                            que_vec.push(que_add);
                        }
                    }
                    pos = cur_str.find(cur_str[0],pos+1);
                }
            }
        }
        
        return result;
}

void let_131(){
	Solution sol;
	vector<vector<string>> result=sol.partition("abb");
	cout<<result.size()<<endl;
}