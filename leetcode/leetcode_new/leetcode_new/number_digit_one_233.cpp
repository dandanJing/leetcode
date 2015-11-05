#include"top.h"

int countNum(int n);

//------!!!错误1：没有考虑输入-1的情况
//------!!!错误2：题目需要计算包含1的数字中1出现次数总和，而不是包含1的数字的个数
//------!!!错误3：输入10
//------!!!错误4：输入20
//------!!!错误5：输入101
//------!!!错误5：输入110
int Solution::countDigitOne(int n){

	return countNum(n);
}

int countNum(int n){
	if(n<=0) return 0;

	int grade=1000000000;
	while(n<grade){
		grade/=10;
	}

	if(grade==1) return 1;

	int result=0;
	int highVal=n/grade;
	if(highVal>1){
		result=grade+countNum(grade-1)*highVal+countNum(n%grade);
	}else{
		result=n%grade+1+countNum(grade-1)+countNum(n%grade);
	}
	return result;
}


void let_233(){
	ifstream fin;
	fin.open("let_233.txt");
	int N;fin>>N;
	int value;
	Solution sol;
	FOR(i,N){
		fin>>value;
		cout<<"Case "<<i+1<<": ";
		cout<<sol.countDigitOne(value)<<endl;
	}
}