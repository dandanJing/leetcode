#include"top.h"

void findSmallestNum(int value,int cur_num);

int smallestNum=0x7fffffff;
int Solution::numSquares(int n) {
	smallestNum=0x7fffffff;
	findSmallestNum(n,0);
	return smallestNum;
}

void findSmallestNum(int value,int cur_num){
	if(value<0) return;
	else if(value==0 && cur_num<smallestNum){smallestNum=cur_num;return;}
	else if(cur_num>=smallestNum) return;

	int max_sqrt=(int)sqrt(value);
	cur_num++;
	for(int i=max_sqrt;i>=1;i--)
		findSmallestNum(value-i*i,cur_num);
}

void let_279(){
	ifstream fin;
	fin.open("let_279.txt");
	int N;fin>>N;
	int value;
	Solution sol;
	FOR(i,N){
		fin>>value;
		cout<<"Case "<<i+1<<": ";
		cout<<sol.numSquares(value)<<endl;
	}
}