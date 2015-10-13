#include"top.h"

bool isUgly(int num){
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

vector<int> ugly_num_vec;
//---------!!¥ÌŒÛ1£∫ ‰»Î1352 ±≥¨ ±
int Solution::nthUglyNumber(int n){
	if(n==0) return 0;
	if(n<=ugly_num_vec.size()) return ugly_num_vec[n-1];

	int temp_val=1;
	int vec_size=ugly_num_vec.size();
	if(vec_size) temp_val=ugly_num_vec[vec_size-1]+1;
	
	while(n>vec_size){
		if(isUgly(temp_val)) {ugly_num_vec.push_back(temp_val++);vec_size++;}
		else temp_val++;
	}
	return ugly_num_vec[n-1];
}

void let_264(){
	ifstream fin;
	fin.open("let_263.txt");
	int N;fin>>N;
	int value;
	Solution sol;
	FOR(i,N){
		fin>>value;
		cout<<"Case "<<i+1<<": ";
		cout<<sol.nthUglyNumber(value)<<endl;
	}
}