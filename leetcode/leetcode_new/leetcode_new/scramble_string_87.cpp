#include"top.h"

bool Solution::isScramble(string s1, string s2) {
	if(s1.size()!=s2.size())return false;
        if(s1.size()==0) return true;
        
		string t1(s1);
        string t2(s2);
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());
        if(t1.compare(t2)!=0) return false;

        if(s1[0]==s2[0])return isScramble(s1.substr(1,s1.size()-1),s2.substr(1,s2.size()-1));
        for(int i=1;i<s1.size();i++){
			string str1=s1.substr(0,i);
			string str2=s2.substr(0,i);

			string str3=s1.substr(i,s2.size()-i);
			string str4=s2.substr(i,s2.size()-i);

			if(isScramble(str1,str2) && isScramble(str3,str4))return true;

			string str5=s2.substr(0,s2.size()-i);
			string str6=s2.substr(s2.size()-i,i);
			if(isScramble(str1,str6) && isScramble(str3,str5))return true;
		}
        return false;
		/*int pos1=s1.find(s2[0]);
		int pos2=s2.find(s1[0]);
		while( pos1!=-1){
			pos2=s2.find(s1[0]);
			while(pos2!=-1 ){
				for(int i=pos2-pos1+1;i<=pos2;i++){
					if(i<=0)continue;
					if(i==1){
						string str1=s1.substr(0,pos1);
						string str2=s2.substr(1,pos1);

						string str3=s1.substr(pos1+1,s2.size()-pos1-1);
						string str4=s2.substr(pos1+1,s2.size()-pos1-1);
						 string rstr1;
						 rstr1.replace(rstr1.begin(),rstr1.end(),str1.rbegin(),str1.rend());
            
						if(isScramble(rstr1,str2) && isScramble(str3,str4))return true;
					}else{
						if(i+pos1>s2.size()) continue;

						string str1=s1.substr(0,pos1);
						string str2=s2.substr(i,pos1);
						string rstr1;
						rstr1.replace(rstr1.begin(),rstr1.end(),str1.rbegin(),str1.rend());

						string str3=s1.substr(pos1+1,i-1);
						string str4=s2.substr(1,i-1);

						string str5="";
						string str6="";
						if(i+pos1<s2.size()){
							str5=s1.substr(pos1+i,s2.size()-pos1-i);
							str6=s2.substr(pos1+i,s2.size()-pos1-i);
						}
            
						if(isScramble(rstr1,str2) && isScramble(str3,str4) && isScramble(str5,str6))return true;
					}
				}
            
				pos2=s2.find(s1[0],pos2+1);
			}
			pos1=s1.find(s2[0],pos1+1);
		}
		
        return false;*/

		/*std::map<char,int>char_map;
		std::map<char,int>::iterator it;
		for(int i=0;i<pos1;i++){
			it=char_map.find(s1[i]);
			if(it!=char_map.end())it->second++;
			else char_map.insert(pair<char,int>(s1[i],1));
		}*/
}

void let_87(){
	Solution sol;
	cout<<sol.isScramble("bbaa","abab")<<endl;
	cout<<sol.isScramble("abc","bca")<<endl;
	cout<<sol.isScramble("great","getra")<<endl;
}