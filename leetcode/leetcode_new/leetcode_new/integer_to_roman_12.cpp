#include"top.h"
//´íÎó1£ºÊäÈë4£¬ ÆÚÍûIV
string Solution::intToRoman(int num){
	string result="";
	
	int temp=num;
	int base=10;
	int val=0;
	string cur;
	while(temp){
		val=temp%10;
		if(base==10){
			if(val==9){
				result+="IX";
				val=0;
			}else if(val>=5){
				result+="V";
				val-=5;
			}else if(val==4){
				result+="IV";
				val=0;
			}
			FOR(i,val)result+="I";
		}else if(base==100){
			cur="";
			if(val==9){
				cur+="XC";
				val=0;
			}else if(val>=5){
				cur+="L";
				val-=5;
			}else if(val==4){
				cur+="XL";
				val=0;
			}
			FOR(i,val)cur+="X";

			result=cur+result;
		}else if(base==1000){
			cur="";
			if(val==9){
				cur+="CM";
				val=0;
			}else if(val>=5){
				cur+="D";
				val-=5;
			}else if(val==4){
				cur+="CD";
				val=0;
			}
			FOR(i,val)cur+="C";
			result=cur+result;
		}else if(base==10000){
			FOR(i,val)result="M"+result;
		}
		base*=10;
		temp/=10;
	}
	return result;
}

void let_12(){
	Solution sol;
	cout<<sol.intToRoman(40)<<endl;
	cout<<sol.intToRoman(4)<<endl;
	cout<<sol.intToRoman(50)<<endl;
	cout<<sol.intToRoman(99)<<endl;
	cout<<sol.intToRoman(399)<<endl;
	cout<<sol.intToRoman(999)<<endl;
}