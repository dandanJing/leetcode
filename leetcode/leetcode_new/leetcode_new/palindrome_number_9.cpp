#include"top.h"

//����1---����1���������true
//����2---����-2147483648���������false
//����3---����-3,�������false
bool Solution::isPalindrome(int x) {
	if(x==0x80000000)return false;
	if(x<0)return false;
	if(x<10)return true;
	
	int basemin=1,basemax=10;
	int temp=x/basemax;
	while(temp>=10){
		basemax*=10;
		temp=x/basemax;
	}
	int val1,val2;
	while(basemax>basemin){
		val1=(x/basemax)%10;
		val2=(x/basemin)%10;
		if(val1!=val2)return false;

		basemin*=10;
		basemax/=10;
	}
	return true;
}

void let_9(){
	Solution sol;
	cout<<sol.isPalindrome(-2147483648)<<endl;
	cout<<sol.isPalindrome(-321)<<endl;
	cout<<sol.isPalindrome(100)<<endl;
	cout<<sol.isPalindrome(12321)<<endl;
}