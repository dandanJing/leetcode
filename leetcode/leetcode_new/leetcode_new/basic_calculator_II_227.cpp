#include"top.h"

int getResult(char temp, int val1, int val2){
	if(temp=='+') return val1+val2;
	else if(temp=='-')return val1-val2;
	else if(temp=='*')return val1*val2;
	else return val1/val2;
}

bool checkVector(vector<int>&nums_vec,vector<char>&op_vec){
	while(op_vec.size()){
		char op=op_vec[op_vec.size()-1];
		if(nums_vec.size()<2) return false;

		if(op=='*'||op=='/'){
			int val2=nums_vec[nums_vec.size()-1];
			int val1=nums_vec[nums_vec.size()-2];
			if(op=='*')nums_vec[nums_vec.size()-2]=val1*val2;
			else if(val2==0) return false;
			else nums_vec[nums_vec.size()-2]=val1/val2;
		}else if(op_vec.size()>1){
			if(nums_vec.size()<3) return false;
			int val2=nums_vec[nums_vec.size()-2];
			int val1=nums_vec[nums_vec.size()-3];
			op=op_vec[op_vec.size()-2];

			if(op=='/'&&val2==0) return false;
			else nums_vec[nums_vec.size()-3]=getResult(op,val1,val2);

			nums_vec[nums_vec.size()-2]=nums_vec[nums_vec.size()-1];
			op_vec[op_vec.size()-2]=op_vec[op_vec.size()-1];
		}else{
			break;
		}
		nums_vec.pop_back();
		op_vec.pop_back();
	}
	return true;
}

int Solution::calculate(string s){
	if(s.size()==0) return 0;

	vector<int>nums_vec;
	vector<char>op_vec;
	bool isVal=false;
	int temp_value=0;
	FOR(i,s.size()){
		if(s[i]>='0'&&s[i]<='9') {
			isVal=true;
			temp_value=temp_value*10+s[i]-'0';
		}else {
			if(isVal){
				nums_vec.push_back(temp_value);
				temp_value=0;
				isVal=false;
				if(!checkVector(nums_vec,op_vec)) cout<<"error"<<endl;
			}
			if(s[i]!=' ') op_vec.push_back(s[i]);
		}
	}
	if(isVal){
		nums_vec.push_back(temp_value);
		checkVector(nums_vec,op_vec);
	}
	int result=nums_vec[0];
	FOR(i,op_vec.size()){
		result=getResult(op_vec[i],result,nums_vec[i+1]);
	}
	return result;
}
//int Solution::calculate(string s){
//	if(s.size()==0) return 0;
//
//	vector<int>nums_vec;
//	vector<char>op_vec;
//	int result;
//	int temp_value=0;
//	bool isVal=false;
//	FOR(i,s.size()){
//		if(s[i]>='0'&&s[i]<='9') {
//			isVal=true;
//			temp_value=temp_value*10+s[i]-'0';
//		}else if(s[i]!=' '){
//			if(isVal){
//				nums_vec.push_back(temp_value);
//				temp_value=0;
//				isVal=false;
//			}
//			if(s[i]=='*'||s[i]=='/'){
//				op_vec.push_back(s[i]);
//			}else{
//			}
//			if(op_vec.size()){
//				char temp_op=op_vec[op_vec.size()-1];
//				if(!nums_vec.size()) return -1;
//
//				if(temp_op=='*'||temp_op=='/'){
//					int val=nums_vec[nums_vec.size()-1];
//					if(temp_op=='*')nums_vec[nums_vec.size()-1]=val*temp_value;
//					else if(temp_value==0)return -1;
//					else nums_vec[nums_vec.size()-1]=val/temp_value;
//				}else if(op_vec.size()>0){
//					char op=op_vec[op_vec.size()-1];
//					if(nums_vec.size()<1)return -1;
//
//					int val1=nums_vec[nums_vec.size()-1];
//					nums_vec[nums_vec.size()-1]=getResult(op,val1,temp_value);
//					op_vec.pop_back();
//				}else{
//					nums_vec.push_back(temp_value);
//				}
//			}else{
//				nums_vec.push_back(temp_value);
//			}
//				temp_value=0;
//				isVal=false;
//			}
//			op_vec.push_back(s[i]);
//		}else if(isVal){
//			if(op_vec.size()){
//				char temp_op=op_vec[op_vec.size()-1];
//				if(!nums_vec.size()) return -1;
//
//				if(temp_op=='*'||temp_op=='/'){
//					int val=nums_vec[nums_vec.size()-1];
//
//					if(temp_op=='*')nums_vec[nums_vec.size()-1]=val*temp_value;
//					else if(temp_value==0)return -1;
//					else nums_vec[nums_vec.size()-1]=val/temp_value;
//					op_vec.pop_back();
//				}else if(op_vec.size()>1){
//					if(nums_vec.size()<2) return -1;
//
//					char pre_op=op_vec[op_vec.size()-2];
//					int val1=nums_vec[nums_vec.size()-1];
//					int val2=nums_vec[nums_vec.size()-2];
//					if(pre_op=='/' && val2==0)return -1;
//
//					int result=getResult(pre_op,val1,val2);
//					nums_vec[nums_vec.size()-2]=result;
//					nums_vec[nums_vec.size()-1]=temp_value;
//
//					op_vec[op_vec.size()-2]=op_vec[op_vec.size()-1];
//					op_vec.pop_back();
//				}else{
//					nums_vec.push_back(temp_value);
//				}
//			}else{
//				nums_vec.push_back(temp_value);
//			}
//			temp_value=0;
//			isVal=false;
//		}
//	}
//	if(isVal){
//		nums_vec.push_back(temp_value);
//	}
//	while(op_vec.size()!=0){
//		char temp_op=op_vec[op_vec.size()-1];
//		if(nums_vec.size()<2)return -1;
//
//		if(temp_op=='*'||temp_op=='/'){
//			int val1=nums_vec[nums_vec.size()-1];
//			int val2=nums_vec[nums_vec.size()-2];
//
//			if(temp_op=='*')nums_vec[nums_vec.size()-2]=val1*val2;
//			else if(val2==0)return -1;
//			else nums_vec[nums_vec.size()-2]=val1/val2;
//		}else{
//			int val1=nums_vec[0];
//			int val2=nums_vec[1];
//			char op=op_vec[0];
//
//			if(op=='/' && val2==0)return -1;
//			else nums_vec[0]=getResult(op,val1,val2);
//
//			for(int i=1;i<nums_vec.size()-1;i++) nums_vec[i]=nums_vec[i+1];
//			for(int i=0;i<op_vec.size()-1;i++)op_vec[i]=op_vec[i+1];
//		}
//
//		op_vec.pop_back();
//		nums_vec.pop_back();
//	}
//	return nums_vec[0];
//}

void let_227(){
	ifstream fin;
	fin.open("let_227.txt");
	int N;fin>>N;
	string s;
	getline(fin,s);
	Solution sol;
	FOR(i,N){
		getline(fin,s);
		cout<<"Case "<<i+1<<": ";
		cout<<s<<","<<sol.calculate(s)<<endl;
	}
}