#include"top.h"

int Solution::findMinII(vector<int>& nums){
	if(nums.size()==0) return 0;
	if(nums.size()==1) return nums[0];
	if(nums.size()==2) return min(nums[0],nums[1]);

	int imin=0,imax=nums.size()-1,imiddle;
	while(1){
		if(imin>=imax-1) return min(nums[imin],nums[imax]);
		if(nums[imin]<nums[imax]) return nums[imin];

		imiddle=(imin+imax)/2;
		if(nums[imin]<nums[imiddle]){
			imin=imiddle;
		}else if(nums[imin]>nums[imiddle]){
			imax=imiddle;
		}else{
			bool isall=true;
			for(int i=imin;i<imiddle;i++){
				if(nums[i]!=nums[imin]){isall=false;break;}
			}
			if(isall) imin=imiddle;
			else imax=imiddle;
		}
	}
	return 0;
}
void let_154(){
	ifstream fin;
	fin.open("let_153.txt");
	int value;
	char temp;
	fin>>temp;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.findMinII(nums)<<endl;
}