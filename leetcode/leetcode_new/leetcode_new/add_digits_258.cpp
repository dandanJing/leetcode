#include"top.h"

int Solution::addDigits(int num){
	int temp=num;
	int tempdiv;
	int value;
	while(temp>10){
		value=0;
		tempdiv=temp;
		while(tempdiv){
			value+=tempdiv%10;
			tempdiv/=10;
		}
		temp=value;
	}
	return temp;
}

void let_258(){
	ifstream fin;
	fin.open("let_258.txt");
	int N;fin>>N;
	int value;
	Solution sol;
	FOR(i,N){
		fin>>value;
		cout<<"Case "<<i+1<<": ";
		cout<<sol.addDigits(value)<<endl;
	}
}