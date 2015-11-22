#include"top.h"

int Solution::reverse(int x){
	int result=0;
	int temp=abs(x);
	int lastval=0;
	while(temp){
		lastval=result;
		result=result*10+temp%10;
		if(lastval!=result/10)return 0;
		temp/=10;
	}
	if(x<0)result=-result;
	return result;
}

void let_7(){
	Solution sol;
	cout<<sol.reverse(321)<<endl;
	cout<<sol.reverse(-123)<<endl;
	cout<<sol.reverse(1534236469)<<endl;//ÆÚÍûÊä³ö0
}