#include"top.h"

int Solution::largestRectangleArea(vector<int>& height){
	int result=0;
    for(int i=0;i<height.size();i++){
         if(i+1<height.size() && height[i]<=height[i+1])continue;
		 int minH=height[i];
		 for(int j=i;j>=0;j--){
			 minH=min(minH,height[j]);
			 int area=(i-j+1)*minH;
			 result=max(result,area);
		 }
    }
	return result;
}

void let_84(){
	ifstream fin;
	fin.open("let_84.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.largestRectangleArea(nums)<<endl;
}