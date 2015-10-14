#include"top.h"

bool Solution::isPowerOfTwo(int n){
	if(n<=0) return false;

	while(n>1){
		if(n%2) return false;
		n=n/2;
	}
	return true;
}

void let_231(){
	Solution sol;
	int n=32;
	cout<<sol.isPowerOfTwo(n)<<endl;
}