#include"top.h"

enum OPERATION{op_add=1,op_minus=2,op_multi=3};
void findResult(string num,int target,int num1,int num2, int cur_pos,OPERATION cur_op,string cur_result,vector<string>& result);
char c[1000];

vector<string> Solution::addOperators(string num, int target){
	vector<string> result;
	string cur_result="";
	long int num1=0,num2;
	FOR(i,num.size()){
		if(num[0]=='0'&& i>0) break;

		num1*=10;
		num1+=num[i]-'0';//得到第一个操作数
		sprintf(c,"%li",num1);
		cur_result="";
		
		if(i==num.size()-1 && num1==-target) {cur_result=cur_result+"-"+num;result.push_back(cur_result);break;}

		cur_result+=c;
		if(i==num.size()-1 && num1==target) {result.push_back(cur_result);break;}

		num2=0;
		for(int j=i+1;j<num.size();j++){
			if(num[i+1]=='0'&& j>i+1) break;
			num2*=10;
			num2+=num[j]-'0';
			sprintf(c,"%i",num2);
			string temp_str;
			if(j==num.size()-1){
				if(num1+num2==target){
					temp_str=cur_result+"+"+c;
					result.push_back(temp_str);	
				}
				if(num1-num2==target){
					temp_str=cur_result+"-"+c;
					result.push_back(temp_str);
				}
				if(num1*num2==target){
					temp_str=cur_result+"*"+c;
					result.push_back(temp_str);
				}
				break;
			}else{
				string temp_str;
				sprintf(c,"%i",num2);
				temp_str=cur_result+"+"+c;
				findResult(num,target,num1,num2,j+1,op_add,temp_str,result);
				sprintf(c,"%i",num2);
				temp_str=cur_result+"-"+c;
				findResult(num,target,num1,num2,j+1,op_minus,temp_str,result);
				sprintf(c,"%i",num2);
				temp_str=cur_result+"*"+c;
				findResult(num,target,num1,num2,j+1,op_multi,temp_str,result);
			}
		}
	}
	return result;
}


void findResult(string num,int target,int num1,int num2, int cur_pos,OPERATION cur_op,string cur_result,vector<string>& result){
	if(cur_pos>=num.size())return;
	int temp_value,temp_result;
	string temp_string;

	for(int i=cur_pos;i<num.size();i++){
		temp_value=0;
		if(num[cur_pos]=='0' && i>cur_pos) break;
		for(int j=cur_pos;j<=i;j++){
			temp_value*=10;
			temp_value+=num[j]-'0';
		}
		//multi
		temp_result=temp_value*num2;
		sprintf(c,"%i",temp_value);
		temp_string=cur_result+"*"+c;
		if(i==num.size()-1){//已经遍历到最后一个元素
			if(cur_op==op_add)temp_result+=num1;
			else if(cur_op==op_minus) temp_result=num1-temp_result;
			else temp_result*=num1;

			if(temp_result==target) result.push_back(temp_string);
		}else{
			findResult(num,target,num1,temp_result,i+1,cur_op,temp_string,result);
		}

		//add
		temp_result=num1;
		sprintf(c,"%i",temp_value);
		temp_string=cur_result+"+"+c;

		if(cur_op==op_add)temp_result+=num2;
		else if(cur_op==op_minus) temp_result-=num2;
		else temp_result*=num2;
		if(i==num.size()-1){
			temp_result+=temp_value;
			if(temp_result==target) result.push_back(temp_string);
		}else{
			findResult(num,target,temp_result,temp_value,i+1,op_add,temp_string,result);
		}

		//minus
		temp_result=num1;
		sprintf(c,"%i",temp_value);
		temp_string=cur_result+"-"+c;

		if(cur_op==op_add)temp_result+=num2;
		else if(cur_op==op_minus) temp_result-=num2;
		else temp_result*=num2;
		if(i==num.size()-1){
			temp_result-=temp_value;
			if(temp_result==target) result.push_back(temp_string);
		}else{
			findResult(num,target,temp_result,temp_value,i+1,op_minus,temp_string,result);
		}
	}
}

void let_282(){
	ifstream fin;
	fin.open("let_282.txt");
	int N;fin>>N;
	string num;
	int target;
	Solution sol;
	FOR(i,N){
		fin>>num>>target;
		vector<string> temp=sol.addOperators(num,target);
		cout<<"Case "<<i+1<<": ";
		FOR(i,temp.size()) cout<<temp[i]<<" ";
		cout<<endl;
	}
}