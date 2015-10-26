#include"top.h"

bool Solution::isHappy(int n){
	if(n==0) return false;
	int cur_num=n;
	int result=0;
	int temp;

	std::map<int,int> data;
	std::map<int,int>::iterator it;
	data.insert(pair<int,int>(n,1));
	while(cur_num!=1){
		result=0;
		temp=cur_num;
		while(temp){
			result=result+(temp%10)*(temp%10);
			temp/=10;
		}
		it=data.find(result);
		if(it == data.end()){cur_num=result;data.insert(pair<int,int>(result,1));}
		else return false;
	}
	return true;
}

void let_202(){
	Solution sol;
	cout<<sol.isHappy(2)<<endl;
	cout<<sol.isHappy(19)<<endl;
	/*cout<<sol.isHappy(82)<<endl;
	cout<<sol.isHappy(100)<<endl;
	cout<<sol.isHappy(68)<<endl;
	cout<<sol.isHappy(1)<<endl;*/
}