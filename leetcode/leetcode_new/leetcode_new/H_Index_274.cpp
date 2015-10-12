#include"top.h"

int Solution::hIndex(vector<int>& citations){
	return citations.size();
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
			value=value*10+temp[j]-'0';
		}
		cite.push_back(value);
		cout<<"Case "<<i+1<<": ";
		cout<<sol.hIndex(cite)<<endl;
	}
}