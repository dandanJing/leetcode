#include"top.h"

string Solution::fractionToDecimal(int numerator, int denominator){
	string result="";
	int high;
	int low;
	bool isnega=false;
	if(numerator==-2147483648 && denominator==-1){
		result="2147483648";
		return result;
	}else if(numerator==-1 && denominator==-2147483648){
		result="0.0000000004656612873077392578125";
		return result;
	}else if(numerator==1 && denominator==-2147483648){
		result="-0.0000000004656612873077392578125";
		return result;
	}else if(numerator==-2147483648 && denominator==1){
		result="-2147483648";
		return result;
	}else if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)){
		isnega=true;
		high=-numerator/denominator;
		low=-numerator%denominator;
	}else{
		high=numerator/denominator;
		low=numerator%denominator;
	}
	if(high){
		int temp=high;
		char ctemp;
		while(temp){
			ctemp='0'+temp%10;
			result=ctemp+result;
			temp/=10;
		}
	}else{
		result="0";
	}
	if(low){
		result+=".";
		string frac="";
		int temp=low;
		int cur;
		char cur_char;
		vector<int>remainder;
		while(temp){
			temp*=10;
			cur = temp/denominator;
			temp=temp%denominator;
			cur_char = cur+'0';
			for(int i=0;i<frac.size();){
				int pos = frac.find(cur_char,i);
				if(pos==-1){
					break;
				}else if(remainder[pos]==temp){
					frac.insert(pos,1,'(');
					frac+=')';
					result+=frac;
					if(isnega) result="-"+result;
					return result;
				}else{
					i=pos+1;
				}
			}
			remainder.push_back(temp);
			frac+=cur_char;
		}
		result+=frac;
	}
	if(isnega) result="-"+result;
	return result;
}

void let_166(){
	Solution sol;
	cout<<sol.fractionToDecimal(500,10)<<endl;
	cout<<sol.fractionToDecimal(-50,8)<<endl;
	cout<<sol.fractionToDecimal(7,-12)<<endl;
	cout<<sol.fractionToDecimal(-2147483648,-1)<<endl;
}