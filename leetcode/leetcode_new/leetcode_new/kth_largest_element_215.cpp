#include"top.h"

int Solution::findKthLargest(vector<int>& nums, int k){
	int size=nums.size();
	if(k>size) return 0;
	if(k<=0) return 0;

	int result=0;
	if(k>size/2){
		k=size-k+1;
		int *k_arr=(int *)new int[k];
		int temp;
		FOR(i,k){
			temp=nums[i];
			int j=-1;
			for(j=i-1;j>=0;j--){
				if(k_arr[j]<temp) k_arr[j+1]=k_arr[j];
				else break;
			}
			k_arr[j+1]=temp;
		}

		for(int i=k;i<size;i++){
			temp=nums[i];
			if(temp>=k_arr[0]) continue;
			else {
				int j=0;
				while(j<k-1){
					if(temp<k_arr[j+1])k_arr[j]=k_arr[j+1];
					else {k_arr[j]=temp;break;}
					j++;
				}
				if(j==k-1)k_arr[j]=temp;
			}
		}
		result=k_arr[0];
		delete k_arr;
	}else{
		int *k_arr=(int *)new int[k];
		int temp;
		FOR(i,k){
			temp=nums[i];
			int j=-1;
			for(j=i-1;j>=0;j--){
				if(k_arr[j]>temp) k_arr[j+1]=k_arr[j];
				else break;
			}
			k_arr[j+1]=temp;
		}

		for(int i=k;i<size;i++){
			temp=nums[i];
			if(temp<=k_arr[0]) continue;
			else {
				int j=0;
				while(j<k-1){
					if(temp>k_arr[j+1])k_arr[j]=k_arr[j+1];
					else {k_arr[j]=temp;break;}
					j++;
				}
				if(j==k-1)k_arr[j]=temp;
			}
		}
		result=k_arr[0];
		delete k_arr;
	}
	return result;
}

void let_215(){
	ifstream fin;
	fin.open("let_215.txt");
	int value;
	vector<int> nums;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}

	Solution sol;
	cout<<sol.findKthLargest(nums,3)<<endl;
}