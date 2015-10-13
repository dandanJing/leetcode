#include"top.h"

bool Solution::isUgly(int num){
	int temp=num;
	while(1){
		if(!temp) return false;
		if(temp==1) return true;

		if(!(temp%5)) temp/=5;
		else if(!(temp%3))temp/=3;
		else if(!(temp%2))temp/=2;
		else return false;
	}
	return true;
}

void let_263(){
	ifstream fin;
	fin.open("let_263.txt");
	int N;fin>>N;
	int value;
	Solution sol;
	FOR(i,N){
		fin>>value;
		cout<<"Case "<<i+1<<": ";
		cout<<sol.isUgly(value)<<endl;
	}
}