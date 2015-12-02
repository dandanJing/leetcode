#include"top.h"

void getResult(vector<int>& nums, vector<vector<int>>&result,queue<vector<int>>&cur,int len){
	if(len > nums.size() || cur.size()==0 )return;

	while(cur.size() && cur.front().size()==len){
		vector<int>temp=cur.front();
		cur.pop();

		int pos=-1;
		if(temp.size()){
			pos=temp.back();
			vector<int> toadd;
			FOR(i,temp.size()){
				toadd.push_back(nums[temp[i]]);
			}
			result.push_back(toadd);
		}else{
			result.push_back(temp);
		}
		for(int j=pos+1;j<nums.size();j++){
			if(j>pos+1 && nums[j]==nums[j-1])continue;
			vector<int>temp1(temp);
			temp1.push_back(j);
			cur.push(temp1);
		}
	}
	getResult(nums,result,cur,len+1);
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums){
	sort(nums.begin(),nums.end());
	vector<vector<int>>result;
	vector<int>temp;
	queue<vector<int>>cur;
	cur.push(temp);
	getResult(nums,result,cur,0);
	return result;
}

//vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums){
//	FOR(i,nums.size()){
//		int j;
//		int val=nums[i];
//		for(j=i-1;j>=0;j--){
//			if(nums[j]>val)nums[j+1]=nums[j];
//			else break;
//		}
//		nums[j+1]=val;
//	}
//	int pos=0;
//	std::map<int,int>count_map;
//	while(pos<nums.size()-1){
//		if(nums[pos+1]==nums[pos]){
//			int j=pos+2;
//			for(;j<nums.size();j++){
//				if(nums[j]!=nums[pos])break;
//			}
//			count_map.insert(pair<int,int>(pos,j-pos));
//			pos=j;
//		}else{
//			pos++;
//		}
//	}
//	vector<vector<int>>result;
//	return result;
//}

void let_90(){
	ifstream fin;
	fin.open("let_90.txt");
	char tempc;
	int val;
	
	vector<int>nums;
	while(fin.peek()!=']'){
		fin>>tempc>>val;
		nums.push_back(val);
	}
	Solution sol;
	vector<vector<int>>result=sol.subsetsWithDup(nums);
	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<result.size()<<endl;
}