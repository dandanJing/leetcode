#include"top.h"

//输入"010010" 期望 ["0.10.0.10","0.100.1.0"]
//输入"101023" 期望["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
vector<string> Solution::restoreIpAddresses(string s){
	vector<string> result;
        int pos1,pos2,pos3;
        int val1,val2,val3,val4;
        int size=s.size();
        if(size>12)return result;
        if(size<4)return result;
        
        pos1=-1;val1=0;

        while(1){
            pos1++;
			if(s[0]=='0' && pos1>0) return result;
            if(pos1>=3)break;
			
            val1=10*val1+s[pos1]-'0';
            if(val1>255)break;
            
            val2=0;
            pos2=pos1;
            while(1){
                pos2++;

				if(size-pos2-1<2)break;
				if(s[pos1+1]=='0' && pos2>pos1+1) break;

				 val2=10*val2+s[pos2]-'0';
                if(size-pos2-1>6)continue;
                
                if(val2>255)break;
                
                val3=0;
                pos3=pos2;
                while(1){
                    pos3++;
                    if(size-pos3-1<1)break;
					if(s[pos2+1]=='0' && pos3>pos2+1) break;

					val3=10*val3+s[pos3]-'0';
                    if(size-pos3-1>3)continue;;
                
					if(s[pos3+1]=='0' && pos3+1<size-1) continue;

                    if(val3>255)break;
                    val4=0;
                    for(int i=pos3+1;i<size;i++)val4=10*val4+s[i]-'0';
                    if(val4<=255){
                        string temp="";
                        for(int j=0;j<s.size();j++){
                            temp+=s[j];
                            if(j==pos1 || j==pos2 || j==pos3) temp+='.';
                        }
                        result.push_back(temp);
                    }
                }
            }
        }
        
        return result;
}

void let_93(){
	Solution sol;
	vector<string>result=sol.restoreIpAddresses("172162541");
	FOR(i,result.size())cout<<result[i]<<endl;
	
	/*result=sol.restoreIpAddresses("25525511135");
	FOR(i,result.size())cout<<result[i]<<endl;
	
	result=sol.restoreIpAddresses("010010");
	FOR(i,result.size())cout<<result[i]<<endl;*/
	
	
}