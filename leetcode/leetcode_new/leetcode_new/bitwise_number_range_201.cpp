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

	int result=0;
	int temp_base=max_base;
	while(temp_base){
		if((m/temp_base) == (n/temp_base)){
			result =result+(m/temp_base)*temp_base;
		}else{
			break;
		}
		m=m%temp_base;
		n=n%temp_base;
		temp_base/=2;
	}
	
	return result;
}

void let_201(){
	Solution sol;
	cout<<sol.rangeBitwiseAnd(10,11)<<endl;
	cout<<sol.rangeBitwiseAnd(5,7)<<endl;
	cout<<sol.rangeBitwiseAnd(1,3)<<endl;
	cout<<sol.rangeBitwiseAnd(29,30)<<endl;
}