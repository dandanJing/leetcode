#include"top.h"

//错误1：[4,2,3] 期望 1
//[4,2,0,3,2,5] 期望9
int Solution::trap(vector<int>& height){
	int val1=0,val2=0;
	int result=0;
	int h1,h2,i1;
	vector<int>h_vec;
	vector<int>pos_vec;
	vector<int>min_vec;
	FOR(i,height.size()){
		for(int j=h_vec.size()-1;j>=0;j--){
			if(h_vec[j]<=height[i]){
				h1=h_vec.back();
				h2=min_vec.back();
				i1=pos_vec.back()+1;
				result+=((i-i1)*(h1-h2));
				h_vec.pop_back();
				pos_vec.pop_back();
				min_vec.pop_back();
				if(min_vec.size())min_vec[min_vec.size()-1]=h1;
			}else if(pos_vec[j]+1<i){
				h1=height[i];
				h2=min_vec.back();
				i1=pos_vec.back()+1;
				result+=((i-i1)*(h1-h2));
				min_vec[min_vec.size()-1]=h1;
				break;
			}else break;
		}
		if(height[i]){
			h_vec.push_back(height[i]);
			pos_vec.push_back(i);
			min_vec.push_back(0);
			/*if (min_vec.size())min_vec.push_back(min_vec.back());
			else min_vec.push_back(0);*/
		}
	}
	/*while(h_vec.size()>1){
		h1=h_vec.back();
		h2=min_vec.back();
		i1=pos_vec.back()-1;
		h_vec.pop_back();
		pos_vec.pop_back();
		min_vec.pop_back();
		int i=pos_vec.back();
		result+=((i1-i)*(h1-h2));
				
	}*/
	return result;
}

void let_42(){
	ifstream fin;
	fin.open("let_42.txt");
	char tempc;
	int value;
	vector<int> height;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		height.push_back(value);
	}
	Solution sol;
	cout<<sol.trap(height)<<endl;
}