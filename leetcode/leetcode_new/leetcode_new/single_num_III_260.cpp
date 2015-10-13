#include"top.h"

vector<int> Solution::singleNumber(vector<int>& nums){
	vector<int>result;
	int nums_size=nums.size();
	std::map<int,int> numAndTimes;
	std::map<int,int>::iterator it;

	FOR(i,nums_size){
		it=numAndTimes.find(nums[i]);
		if(it==numAndTimes.end()){
			numAndTimes.insert(pair<int,int>(nums[i],1));
		}else{
			it->second++;
		}
	}
	for(it=numAndTimes.begin();it!=numAndTimes.end();it++){
		if(it->second!=2) result.push_back(it->first);
	}
	
	return result;
}
void let_260(){
	ifstream fin;
	fin.open("let_260.txt");

	vector<int>temp;
	int value;
	while(!fin.eof()){
		fin>>value;
		temp.push_back(value);
	}
	Solution sol;
	vector<int>result=sol.singleNumber(temp);

	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}