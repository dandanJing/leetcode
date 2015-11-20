#include"top.h"

string sumStr(string num1, string num2){
	int pos1=num1.size()-1;
	int pos2=num2.size()-1;
	string result="";
	int val1,val2,val3=0;
	int temp;
	char tempc;
	while(pos1>=0 || pos2>=0){
		if(pos1>=0 )val1=num1[pos1]-'0';
		else val1=0;
		
		if( pos2>=0)val2=num2[pos2]-'0';
		else val2=0;

		temp=val1+val2+val3;
		tempc=temp%10+'0';
		result=tempc+result;
		val3=temp/10;
		pos1--;
		pos2--;
	}
	if(val3){
		tempc=val3+'0';
		result=tempc+result;
	}
	return result;
}

string multiStr(string num1, int val2, int base){
	if(val2==0)return "0";
	string result="";
	int pos1=num1.size()-1;
	int val1,val3=0;
	int temp;
	char tempc;
	while(pos1>=0){
		val1=num1[pos1]-'0';
		temp=val1*val2+val3;
		tempc=temp%10+'0';
		result=tempc+result;
		val3=temp/10;
		pos1--;
	}
	if(val3){
		tempc=val3+'0';
		result=tempc+result;
	}
	while(base){
		result+='0';
		base--;
	}
	return result;
}

string Solution::multiply(string num1, string num2){
	string result="0";
	string temp;
	int val;
	if(num1.size()>num2.size()){
		FOR(i,num2.size()){
			val=num2[num2.size()-1-i]-'0';
			temp=multiStr(num1,val,i);
			result=sumStr(result,temp);
		}
	}else{
		FOR(i,num1.size()){
			val=num1[num1.size()-1-i]-'0';
			temp=multiStr(num2,val,i);
			result=sumStr(result,temp);
		}
	}

	return result;
}

void let_43(){
	Solution sol;
	cout<<sol.multiply("2522","0")<<endl;
	cout<<sol.multiply("25","25")<<endl;
	cout<<sol.multiply("656756725","76725")<<endl;
}