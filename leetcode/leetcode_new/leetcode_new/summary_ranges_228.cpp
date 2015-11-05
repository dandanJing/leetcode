#include"top.h"

extern char c[1000];
vector<string> Solution::summaryRanges(vector<int>& nums){
	vector<string> result;
	if(nums.size()==0) return result;

	int small=nums[0],large=nums[0];
	string temp="";
	if(nums.size()==1) {
		sprintf(c,"%d",small);
		temp+=c;
		result.push_back(temp);
		return result;
	}
	for(int i=1;i<nums.size();i++){
		if(nums[i]==large+1){
			large++;
			if(i==nums.size()-1){
				sprintf(c,"%d",small);
				temp+=c;
				temp+="->";
				sprintf(c,"%d",large);
				temp+=c;
				result.push_back(temp);
				temp="";
			}
		}else{
			if(small==large){
				sprintf(c,"%d",small);
				temp+=c;
				result.push_back(temp);
				temp="";
			}else{
				sprintf(c,"%d",small);
				temp+=c;
				temp+="->";
				sprintf(c,"%d",large);
				temp+=c;
				result.push_back(temp);
				temp="";
			}
			
			small=large=nums[i];
			if(i==nums.size()-1){
				sprintf(c,"%d",small);
				temp+=c;
				result.push_back(temp);
				temp="";
			}
		}
	}
	return result;
}

void let_228(){
	ifstream fin;
	fin.open("let_228.txt");
	vector<int> nums;
	int value;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}

	Solution sol;
	vector<string> result=sol.summaryRanges(nums);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}