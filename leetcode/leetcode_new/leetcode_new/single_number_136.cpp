#include"top.h"

int Solution::singleNumber(vector<int>& nums){
	std::map<int,int> map_num;
	std::map<int,int>::iterator it;
	FOR(i,nums.size()){
		it=map_num.find(nums[i]);
		if(it!=map_num.end()){
			map_num.erase(nums[i]);
		}else{
			map_num.insert(pair<int,int>(nums[i],1));
		}
	}
	it=map_num.begin();
	return it->first;
}

void let_136(){
	vector<int> nums;
	ifstream fin;
	fin.open("let_136.txt");
	int value;
	char temp;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.singleNumber(nums)<<endl;
}