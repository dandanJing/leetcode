#include"top.h"

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
	int m=nums1.size();
	int n=nums2.size();
	double result=0;

	if(nums1.size()==0 && nums2.size()==0)return 0.0;
	else if(nums1.size()==0 && nums2.size()>1){
		if(n%2) result=nums2[n/2];
		else {
			result=nums2[n/2];
			result=(result+nums2[n/2-1])/2;
		}
		return result;
	}else if(nums1.size()==0) return nums2[0];
	else if(nums2.size()==0 && nums1.size()>1){
		if(m%2) result=nums1[m/2];
		else {
			result=nums1[m/2];
			result=(result+nums1[m/2-1])/2;
		}
		return result;
	}else if(nums2.size()==0) return nums1[0];
	
	int pos1=0;int pos2=0;
	int count=0;
	int lastval=0;
	
	while(1){
		if(count==(m+n)/2){
			if(pos1<=nums1.size()-1 && pos2<=nums2.size()-1) result=min(nums1[pos1],nums2[pos2]);
			else if(pos1<=nums1.size()-1)result=nums1[pos1];
			else result=nums2[pos2];
			if(!((m+n)%2)){
				result=(result+lastval)/2;
			}
			break;
		}
		if(pos1>=nums1.size())lastval=nums2[pos2++];
		else if(pos2>=nums2.size())lastval=nums1[pos1++];
		else if(nums1[pos1]<nums2[pos2])lastval=nums1[pos1++];
		else lastval=nums2[pos2++];
		
		count++;
	}
	return result;
}

void let_4(){
	ifstream fin;
	fin.open("let_4.txt");
	char tempc;
	int value;
	vector<int> nums1;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums1.push_back(value);
	}
	fin>>tempc;
	vector<int> nums2;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums2.push_back(value);
	}
	Solution sol;
	cout<<sol.findMedianSortedArrays(nums1,nums2)<<endl;
}