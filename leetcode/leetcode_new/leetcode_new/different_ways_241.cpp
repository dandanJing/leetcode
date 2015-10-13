#include"top.h"

//-----!!!错误1：输入"2-1-1-1-1"，期望输出[-2,0,0,0,0,0,0,2,2,2,2,2,2,4]，实际输出[-2,0,0,2,0,0,2,2,4,2,2,0,2]
void findDiffResult(string input,int cur_pos,int temp_value,vector<int> &result,bool hasPre,int preVal,char preOp);
vector<int> Solution::diffWaysToCompute(string input) {
	vector<int> result;
	if(input.size()==0)return result;

	int pos=0;
	int temp_value=0;
	while(pos<input.size()){
		if(input[pos]<='9' && input[pos]>='0')temp_value=temp_value*10+input[pos++]-'0';
		else break;
	}

	findDiffResult(input,pos,temp_value,result,0,0,' ');
	return result;
}

void findDiffResult(string input,int cur_pos,int temp_value,vector<int> &result,bool hasPre,int preVal,char preOp){
	if(cur_pos>=input.size()) {result.push_back(temp_value);return;}

	char op_char=input[cur_pos++];
	int val=0;
	while(cur_pos<input.size()){
		if(input[cur_pos]<='9' && input[cur_pos]>='0')val=val*10+input[cur_pos++]-'0';
		else break;
	}
	int op_result=0;
	if(op_char=='+')op_result=temp_value+val;
	else if(op_char=='-')op_result=temp_value-val;
	else op_result=temp_value*val;

	//有前缀
	if(hasPre){
		//计算(XX~(aa~bb))....
		int temp1;
		if(preOp=='+')temp1=preVal+op_result;
		else if(preOp=='-')temp1=preVal-op_result;
		else temp1=preVal*op_result;
		if(cur_pos>=input.size()){result.push_back(temp1);return;}

		findDiffResult(input,cur_pos,temp1,result,0,0,' ');

		//计算XX~((aa~bb)....
		findDiffResult(input,cur_pos,op_result,result,hasPre,preVal,preOp);

		//计算XX~(aa~(bb....
		vector<int> temp_vec;
		findDiffResult(input,cur_pos,val,temp_vec,1,temp_value,op_char);
		FOR(i,temp_vec.size()){
			/*op_result=0;
			if(op_char=='+')op_result=temp_value+temp_vec[i];
			else if(op_char=='-')op_result=temp_value-temp_vec[i];
			else op_result=temp_value*temp_vec[i];*/

			op_result=temp_vec[i];
			int temp1;
			if(preOp=='+')temp1=preVal+op_result;
			else if(preOp=='-')temp1=preVal-op_result;
			else temp1=preVal*op_result;
			result.push_back(temp1);
		}
	}else{
		if(cur_pos>=input.size()){result.push_back(op_result);return;}

		//计算(aa~bb)....
		findDiffResult(input,cur_pos,op_result,result,hasPre,preVal,preOp);

		//计算aa~(bb...
		vector<int> temp_vec;
		findDiffResult(input,cur_pos,val,result,1,temp_value,op_char);//----!!!错误1：需要把当前的数val作为temp_value传入进去
		/*FOR(i,temp_vec.size()){
			op_result=0;
			if(op_char=='+')op_result=temp_value+temp_vec[i];
			else if(op_char=='-')op_result=temp_value-temp_vec[i];
			else op_result=temp_value*temp_vec[i];

			result.push_back(op_result);
		}*/
	}
}

void let_241(){
	ifstream fin;
	fin.open("let_241.txt");
	int N;fin>>N;
	string s;
	Solution sol;
	FOR(i,N){
		fin>>s;
		cout<<"Case "<<i+1<<":";
		vector<int> result=sol.diffWaysToCompute(s);
		FOR(k,result.size()) cout<<result[k]<<",";
		cout<<endl;
	}
}