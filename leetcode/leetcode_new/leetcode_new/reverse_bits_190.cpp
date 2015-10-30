#include"top.h"

int Solution::reverseBits(int n){
	int bit_arr[32];
	int temp=n;
	int pos=0;
	FOR(i,32) bit_arr[i]=0;
	while(temp){
		bit_arr[pos++]=temp%2;
		temp/=2;
	}
	int result=0;
	int base = 1;
	FOR(i,32) {
		result+=(base*bit_arr[31-i]);
		base *=2;
	}
	return result;
}

void let_190(){
	Solution sol;
	cout<<sol.reverseBits(43261596)<<endl;;
}