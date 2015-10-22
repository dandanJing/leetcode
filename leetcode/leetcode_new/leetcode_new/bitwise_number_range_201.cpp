#include"top.h"

//----!!!错误1 ,输入10，11，期望输出10
int Solution::rangeBitwiseAnd(int m, int n){
	if(m==n) return m;
	int max_val=max(m,n)/2;
	int max_base=1;
	while(max_val){
		max_base*=2;
		max_val/=2;
	}
	if(m<max_base || n< max_base){
		return 0;
	}

	int result=m&n;
	int temp=result;
	int cur_val=0;
	int base=1;
	while(temp){
		if(temp%2){
			cur_val=2*cur_val+base;
		}else{
			result-=cur_val;
			cur_val=0;
		}
		temp/=2;
		base*=2;
	}
	return result;
}

void let_201(){
	Solution sol;
	cout<<sol.rangeBitwiseAnd(5,7)<<endl;
	cout<<sol.rangeBitwiseAnd(1,3)<<endl;
	cout<<sol.rangeBitwiseAnd(29,30)<<endl;
}