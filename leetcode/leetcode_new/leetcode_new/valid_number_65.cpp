#include"top.h"

 bool Solution::isNumber(string s) {
	    int posblank=0;
		for(posblank=0;posblank<s.size();posblank++){
            if(s[posblank]!=' ')break;
        }
        int temp=s.find(' ',posblank+1);
		if(temp!=-1){
           for(int i=temp+1;i<s.size();i++){
                if(s[i]!=' ')return false;
           }
        }
        
        int posneg=s.find('-');
        int possci=s.find('e');
        int posdec=s.find('.');
		int pospos=s.find('+');
		if(pospos!=-1 && posneg!=-1)return false;
		else if(pospos!=-1)posneg=pospos;

        for(int i=0;i<posneg;i++){
            if(s[i]==' ')continue;
            else return false;
        }
        int num=0;
        if(possci!=-1 && posdec!=-1){

		}else if(posdec!=-1){
            int divide = posdec;
            bool isnum1=false;
            for(int i=posneg+1;i<divide;i++){
                if(s[i]==' ')continue;
                else if(s[i]>='0' && s[i]<='9') {isnum1=true;}
                else return false;
            }
            
            
            bool isnum2=false;
            for(int i=divide+1;i<s.size();i++){
                if(s[i]==' '){continue;}
                else if(s[i]>='0' && s[i]<='9') {isnum2=true;}
                else return false;
            }
            if(!isnum1 && !isnum2)return false;
        }else if(possci!=-1){
            int divide = possci;
            bool isnum=false;
            for(int i=posneg+1;i<divide;i++){
                if(s[i]==' ')continue;
                else if(s[i]>='0' && s[i]<='9') {isnum=true;}
                else return false;
            }
            if(!isnum)return false;
            
            isnum=false;
            for(int i=divide+1;i<s.size();i++){
                if(s[i]==' ')continue;
                else if(s[i]>='0' && s[i]<='9') {isnum=true;}
                else return false;
            }
            if(!isnum)return false;
        }else{
            bool isnum=false;
            for(int i=posneg+1;i<s.size();i++){
                if(s[i]==' ')continue;
                else if(s[i]>='0' && s[i]<='9') {isnum=true;continue;}
                else return false;
            }
            if(!isnum)return false;
        }
        
        return true;
 }

 void let_65(){
	 Solution sol;
	 /*cout<<sol.isNumber("3 2")<<endl;
	 cout<<sol.isNumber("3 ")<<endl;
	 cout<<sol.isNumber("3. ")<<endl;
	 cout<<sol.isNumber(".1")<<endl;*/
	 cout<<sol.isNumber("-01")<<endl;
	 cout<<sol.isNumber("+.8")<<endl;
	 cout<<sol.isNumber("46.e3")<<endl;
 }