#include"top.h"

int countNum(int n);

//------!!!����1��û�п�������-1�����
//------!!!����2����Ŀ��Ҫ�������1��������1���ִ����ܺͣ������ǰ���1�����ֵĸ���
//------!!!����3������10
//------!!!����4������20
//------!!!����5������101
//------!!!����5������110
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