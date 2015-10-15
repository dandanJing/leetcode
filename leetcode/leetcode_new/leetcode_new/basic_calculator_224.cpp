#include"top.h"

bool checkVector1(vector<int>&nums_vec,vector<char>&op_vec){
	int pos_op=0;
	int pos_num=0;
	while(pos_op>=0 && pos_op<op_vec.size()){
		char op=op_vec[pos_op];

		if(op=='('){pos_op++;continue;}
		if(op==')'){
			for(int i=pos_op-1;i<op_vec.size()-2;i++) op_vec[i]=op_vec[i+2];
			op_vec.pop_back();
			op_vec.pop_back();
			pos_op--;
			continue;
		}

		if(pos_op+1 < op_vec.size()){
			char op_next=op_vec[pos_op+1];
			if(op_next=='('){pos_op+=2;pos_num++;continue;}
		}
		
		if(nums_vec.size()<=pos_num+1) return false;

		if(op=='+') nums_vec[pos_num]=nums_vec[pos_num]+nums_vec[pos_num+1];
		else nums_vec[pos_num]=nums_vec[pos_num]-nums_vec[pos_num+1];

		for(int i=pos_num+1;i<nums_vec.size()-1;i++) nums_vec[i]=nums_vec[i+1];
		for(int i=pos_op;i<op_vec.size()-1;i++) op_vec[i]=op_vec[i+1];

		nums_vec.pop_back();
		op_vec.pop_back();
	}
	return true;
}

int Solution::calculate1(string s){
	if(s.size()==0) return 0;

	vector<int>nums_vec;
	vector<char>op_vec;
	bool isVal=false;
	int temp_value=0;
	int open_count=0;
	FOR(i,s.size()){
		if(s[i]>='0'&&s[i]<='9') {
			isVal=true;
			temp_value=temp_value*10+s[i]-'0';
		}else {
			if(isVal){
				nums_vec.push_back(temp_value);
				temp_value=0;
				isVal=false;
				if(!checkVector1(nums_vec,op_vec)) cout<<"error!"<<endl;
			}
			if(s[i]==')') {
				if(!op_vec.size()){cout<<"error!"<<endl;return 0;}
				else if(op_vec[op_vec.size()-1]=='(')op_vec.pop_back();
				else{checkVector1(nums_vec,op_vec);op_vec.pop_back();}		
			}
			else if(s[i]!=' ') op_vec.push_back(s[i]);
		}
	}
	if(isVal){
		nums_vec.push_back(temp_value);
	}
	if(!checkVector1(nums_vec,op_vec)) cout<<"error!"<<endl;;
	return nums_vec[0];
}

void let_224(){
	ifstream fin;
	fin.open("let_224.txt");
	int N;fin>>N;
	string s;
	getline(fin,s);
	Solution sol;
	FOR(i,N){
		getline(fin,s);
		cout<<"Case "<<i+1<<": ";
		cout<<s<<","<<sol.calculate1(s)<<endl;
	}
}