#include"top.h"

//void Solution::rotate(vector<int>& nums, int k){
//	int size = nums.size();
//	int shift = k%size;
//	if(shift > size/2){
//		shift -= size;
//	}
//	int temp;
//	while(shift){
//		if(shift > 0){//ÓÒÒÆ
//			temp = nums[size-1];
//			for(int i=size-1;i>0;i--){
//				nums[i]=nums[i-1];
//			}
//			nums[0]=temp;
//			shift--;
//		}else{ //×óÒÆ
//			temp = nums[0];
//			FOR(i,size-1){
//				nums[i]=nums[i+1];
//			}
//			nums[size-1]=temp;
//			shift++;
//		}
//	}
//}

void Solution::rotate(vector<int>& nums, int k){
	int size = nums.size();
	int shift = k%size;
	bool shiftRight = true;
	if(shift > size/2){
		shift = size-shift;
		shiftRight = false;
	}
	int * arr = (int *) new int[shift];
	if(shiftRight){
		FOR(i,shift) arr[i]=nums[size-(shift-i)];
		for(int i=size-1;i>=shift;i--){
			nums[i]=nums[i-shift];
		}
		FOR(i,shift) nums[i]=arr[i];
	}else{
		FOR(i,shift) arr[i]=nums[i];
		for(int i=0;i<size-shift;i++){
			nums[i]=nums[i+shift];
		}
		FOR(i,shift) nums[size-(shift-i)]=arr[i];
	}
	delete arr;
}
void let_189(){
	ifstream fin;
	fin.open("let_189.txt");
	char temp;
	int value;
	fin>>temp;

	vector<int> nums;
	while(!fin.eof() && fin.peek()!=-1){
		fin>>value>>temp;
		nums.push_back(value);
	}
	Solution sol;
	sol.rotate(nums,3);
	FOR(i,nums.size()) cout<<nums[i]<<",";
	cout<<endl;
}