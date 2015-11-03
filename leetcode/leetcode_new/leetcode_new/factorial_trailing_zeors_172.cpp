#include"top.h"

int Solution::trailingZeroes(int n){
	int temp=n;
	int result=0;
	while(temp){
		result+= temp/5;
		temp/=5;
	}
	return result;
}

void let_172(){
	Solution sol;
	cout<<sol.trailingZeroes(5)<<endl;
}