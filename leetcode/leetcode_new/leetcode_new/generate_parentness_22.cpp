#include"top.h"

vector<string> Solution::generateParenthesis(int n) {
	vector<vector<string>> vec_gen;
	vector<string> vec1;
	vector<string> vec2;
	vec1.push_back("()");
	vec2.push_back("(())");
	vec2.push_back("()()");
	vec_gen.push_back(vec1);
	vec_gen.push_back(vec2);
	int num1,num2;
	vector<string> temp1,temp2;
	for(int i=3;i<=n;i++){
		std::map<string,int> str_map;
		std::map<string,int>::iterator it;
		string cur_str="";
		temp1=vec_gen.back();
		FOR(kk,temp1.size()){
			cur_str='('+temp1[kk]+')';
			str_map.insert(pair<string,int>(cur_str,1));
		}
		
		for(int j=1;j<i;j++){
			 num1=j;num2=i-j;
			 temp1=vec_gen[num1-1];
			 temp2=vec_gen[num2-1];
			 FOR(ii,temp1.size()){
				 FOR(jj,temp2.size()){
					 cur_str=temp1[ii]+temp2[jj];
					 it=str_map.find(cur_str);
					 if(it==str_map.end()){
						 str_map.insert(pair<string,int>(cur_str,1));
					 }
				 }
			 }
		}
		vector<string> vec_add;
		for(it=str_map.begin();it!=str_map.end();it++){
			vec_add.push_back(it->first);
		}
		vec_gen.push_back(vec_add);
	}
	return vec_gen[n-1];
}

void let_22(){
	Solution sol;
	vector<string> result=sol.generateParenthesis(6);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;
}