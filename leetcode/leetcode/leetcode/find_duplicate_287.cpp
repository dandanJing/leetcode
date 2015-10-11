#include"top.h"
using namespace std;


class Solution{
public:
	int findDuplicate(vector<int>& nums){
		int nums_size=nums.size();
		FOR(i,nums_size)cout<<nums[i]<<",";
		cout<<endl;
		return 0;
	}
};

void let_287(){
	fstream fin;
	fin.open("let_287.txt");
	Solution sol;
	vector<int> num_vec;
	int temp;
	while(!fin.eof()){
		fin>>temp;
		num_vec.push_back(temp);
	}
	sol.findDuplicate(num_vec);
}