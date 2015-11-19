#include"top.h"

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n){

	int cur1=m-1, cur2=n-1;
	int sort_index=m+n-1;
	int temp;
	while(cur1>=0 && cur2>=0){
		if(nums1[cur1]>=nums2[cur2]){
			nums1[sort_index--]=nums1[cur1--];
		}else{
			nums1[sort_index--]=nums2[cur2--];
		}
	}
	if(cur1<0){
		while(cur2>=0){
			nums1[sort_index--]=nums2[cur2--];
		}
	}
	if(cur2<0){
		while(cur1>=0){
			nums1[sort_index--]=nums1[cur1--];
		}
	}
}

void let_88(){
	ifstream fin;
	fin.open("let_88.txt");
	char tempc=' ';
	int value;
	vector<int> nums1;
	vector<int> nums2;
	int count1=0, count2=0;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums1.push_back(value);
		count1++;
	}
	fin>>tempc;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums2.push_back(value);
		count2++;
	}
	FOR(i,count2)nums1.push_back(i);

	Solution sol;
	sol.merge(nums1,count1,nums2,count2);
	FOR(i,nums1.size())cout<<nums1[i]<<",";
	cout<<endl;
}