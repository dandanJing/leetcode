#include"top.h"

vector<int> num_vec;
void build_vec(int n){
	if(num_vec.size()==0){
		num_vec.push_back(1);
		num_vec.push_back(1);
		num_vec.push_back(2);
		num_vec.push_back(5);
	}
	int temp=num_vec.size()+1;
	while(temp<=n+1){
		int cur=0,left,right;
		FOR(i,temp-1){
			left=i;
			right=temp-2-i;
			cur+=(num_vec[left]*num_vec[right]);
		}
		num_vec.push_back(cur);
		temp++;
	}
}
int Solution::numTrees(int n){
	if(num_vec.size()>n)return num_vec[n];
	build_vec(n);
	return num_vec[n];
}

void let_96(){
	Solution sol;
	cout<<sol.numTrees(4)<<endl;
}