#include"top.h"
//输入[1,2]，期望[[],[1],[2],[1,2]]
//[4,1,0],期望[[],[4],[1],[1,4],[0],[0,4],[0,1],[0,1,4]]
vector<vector<int>> Solution::subsets(vector<int>& nums){
	FOR(i,nums.size()){
		int j;
		int val=nums[i];
		for(j=i-1;j>=0;j--){
			if(nums[j]>val)nums[j+1]=nums[j];
			else break;
		}
		nums[j+1]=val;
	}
	vector<vector<int>>result;
	int setnum=(1<<nums.size());
	FOR(i,setnum){
		vector<int>temp;
		int val=i;
		int count=0;
		while(val){
			if(val%2)temp.push_back(nums[count]);
			val=val>>1;
			count++;
		}
		result.push_back(temp);
	}
	return result;
}

void let_78(){
	ifstream fin;
	fin.open("let_78.txt");
	char tempc;
	int val;
	
	vector<int>nums;
	while(fin.peek()!=']'){
		fin>>tempc>>val;
		nums.push_back(val);
	}
	Solution sol;
	vector<vector<int>>result=sol.subsets(nums);
	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<result.size()<<endl;
}