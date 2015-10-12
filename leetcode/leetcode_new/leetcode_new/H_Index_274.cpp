#include"top.h"

//-------!!!错误1：输入[],期望输出为0
//-------!!!错误2：输入[100],期望输出为1
//-------!!!错误3：输入[0,1],期望输出为1
//-------!!!错误4：题目理解错误，题意为大于等于h的至少有h个，
//-------!!!错误5：输入[0,0,4,4],期望输出为2
int Solution::hIndex(vector<int>& citations){
	int cite_size=citations.size();
	if(!cite_size) return 0;

	int *cite_sort=(int *)(new int[cite_size]);
	//插入排序
	int temp,j;
	FOR(i,cite_size){
		temp=citations[i];
		for(j=i-1;j>=0;j--){
			if(temp<cite_sort[j])cite_sort[j+1]=cite_sort[j];
			else break;
		}
		cite_sort[j+1]=temp;
	}

	for(int i=cite_size;i>=0;i--){
		if(cite_sort[cite_size-i]>=i) return i;
	}
	
	return 0;
}

void let_274(){
	ifstream fin;
	fin.open("let_274.txt");
	int N;fin>>N;
	int value;
	string temp;
	Solution sol;
	getline(fin,temp);
	FOR(i,N){
		vector<int> cite;
		getline(fin,temp);
		value=0;
		FOR(j,temp.size()){
			if(temp[j]==' '){cite.push_back(value);value=0;}
			else value=value*10+temp[j]-'0';
		}
		cite.push_back(value);
		cout<<"Case "<<i+1<<": ";
		cout<<sol.hIndex(cite)<<endl;
	}
}