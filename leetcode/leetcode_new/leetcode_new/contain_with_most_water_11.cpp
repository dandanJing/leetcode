#include"top.h"

int maxHeight=0;
void findVal(vector<int>& height, int start1, int end1,int start2,int end2){
	if(start1>end1)return;
	if(start2>end2)return;

	int temph;
	if(start1+5>=end1 || start2+5>=end2){
		for(int i=start1;i<=end1;i++){
			for(int j=start2;j<=end2;j++){
				temph=min(height[i],height[j]);
				if(temph*(i-j)<=maxHeight)continue;
				else maxHeight=temph*(i-j);
			}
		}
	}else{
		int mid1=(start1+end1)/2;
		int mid2=(start2+end2)/2;
		findVal(height,start1,mid1,start2,mid2);
		findVal(height,mid1+1,end1,start2,mid2);
		findVal(height,start1,mid1,mid2+1,end2);
		findVal(height,mid1+1,end1,mid2+1,end2);
	}
}

void findMaxVal(vector<int>& height, int start, int end){
	if(start>=end) return;
	
	int temph;
	if(start+5>=end){
		for(int i=start;i<=end;i++){
			for(int j=start;j<i;j++){
				temph=min(height[i],height[j]);
				if(temph*(i-j)<=maxHeight)continue;
				else maxHeight=temph*(i-j);
			}
		}
	}else{
		int mid=(start+end)/2;
		findMaxVal(height,start,mid);
		findMaxVal(height,mid+1,end);
		findVal(height,start,mid,mid+1,end);
	}
}
int Solution::maxArea(vector<int>& height){
	maxHeight=0;
	findMaxVal(height,0,height.size()-1);
	return maxHeight;
	/*int result=0;
	int temph;
	FOR(i,height.size()){
		if(height[i]*(i-1)<result)continue;
		FOR(j,i){
			temph=min(height[i],height[j]);
			if(temph*(i-j)<=result)continue;
			else result=temph*(i-j);
		}
	}
	return result;*/
}

void let_11(){
	ifstream fin;
	fin.open("let_11.txt");
	char tempc;
	int value;
	vector<int> height;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		height.push_back(value);
	}
	Solution sol;
	cout<<sol.maxArea(height)<<endl;
}