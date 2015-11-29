#include"top.h"

 bool Solution::isNumber(string s) {
	    //检查空格位置
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
        //检查科学计数e是否有多个
		int possci=s.find('e');
		temp=s.find('e',possci+1);
		if(temp!=-1) return false;
		if(possci!=-1){
			bool isnum=false;
			for(int i=possci+1;i<s.size();i++){
				if(s[i]==' ')continue;
				else if(s[i]>='0' && s[i]<='9') {isnum=true;continue;}
				else if(s[i]=='-'|| s[i]=='+'){
					if(i!=possci+1)return false;
				}else return false;
				
			}
			if(!isnum)return false;
		}

		//检查小数点是否有多个
		int posdec=s.find('.');
		temp=s.find('.',posdec+1);
		if(temp!=-1) return false;

		//检查小数点存在的情况
		if(possci!=-1 && posdec>possci)return false;
		if(posdec!=-1){
			int maxpos=s.size();
			if(possci!=-1)maxpos=possci;
			temp=s.find('-');
			if(temp>=maxpos) temp=-1;

			int pospos=s.find('+');
			if(pospos>=maxpos) pospos=-1;
			temp=max(temp,pospos);

			if(temp!=-1 && temp>posdec)return false;
			else if(temp!=-1 && temp<maxpos){
				for(int i=0;i<temp;i++){
					if(s[i]==' ')continue;
					else return false;
				}
			}

			bool isnum1=false;
            for(int i=temp+1;i<posdec;i++){
                if(s[i]==' ')continue;
                else if(s[i]>='0' && s[i]<='9') {isnum1=true;}
                else return false;
            }
            
            
            bool isnum2=false;
            for(int i=posdec+1;i<maxpos;i++){
                if(s[i]==' '){continue;}
                else if(s[i]>='0' && s[i]<='9') {isnum2=true;}
                else return false;
            }
            if(!isnum1 && !isnum2)return false;
		}
		//检查包含e不包含.的情况
		if(possci!=-1 && posdec==-1){
			int posneg=s.find('-');
			if(posneg>possci)posneg=-1;

			int pospos=s.find('+');
			if(pospos>possci)pospos=-1;
			posneg=max(posneg,pospos);
			for(int i=0;i<posneg;i++){
				if(s[i]==' ')continue;
				else return false;
			}
			bool isnum=false;
            for(int i=posneg+1;i<possci;i++){
                if(s[i]==' ')continue;
                else if(s[i]>='0' && s[i]<='9') {isnum=true;continue;}
                else return false;
            }
            if(!isnum)return false;
		}

		//检查不包含e和.的情况
		if(posdec==-1 && possci==-1){
			int posneg=s.find('-');
			int pospos=s.find('+');
			if(pospos!=-1 && posneg!=-1)return false;
			else if(pospos!=-1)posneg=pospos;
			for(int i=0;i<posneg;i++){
				if(s[i]==' ')continue;
				else return false;
			}
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
	 cout<<sol.isNumber("3 2")<<endl;//0
	 cout<<sol.isNumber("3 ")<<endl;//1
	 cout<<sol.isNumber("3. ")<<endl;//1
	 cout<<sol.isNumber(".1")<<endl;//1
	 cout<<sol.isNumber("-01")<<endl;//1
	 cout<<sol.isNumber("+.8")<<endl;//1
	 cout<<sol.isNumber("46.e3")<<endl;//1
	 cout<<sol.isNumber(".e")<<endl;//0
	 cout<<sol.isNumber(" 005047e+6")<<endl;//1
	 cout<<sol.isNumber("e9")<<endl;//0 
	 cout<<sol.isNumber(" 5.1e0j3Z3")<<endl;//0 
	 
 }