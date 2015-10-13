#include"top.h"

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.size()==0) return false;
	int i=0;
	int find_pos=0;
	vector<int> temp;
	while(i<matrix.size()){
		temp=matrix[i];
		if(temp.size()){
			if(temp[0]==target) return true;
			else if(temp[0]>target) break;
		}
		find_pos=i++;
	}

	for(int j=0;j<=find_pos;j++){
		temp=matrix[j];
		int temp_size=temp.size();
		if(temp_size==0) continue;

		if(temp[temp_size-1]<target) continue;
		else if(temp[temp_size-1]==target) return true;
		for(i=1;i<temp_size-1;i++){//可以改成二分法
			if(temp[i]==target) return true;
			else if(temp[i]>target) break;
		}
	}

	return true;
}

void let_240(){
	vector<vector<int>> matrix;
	vector<int> temp1;
	temp1.push_back(1);
	temp1.push_back(4);
	temp1.push_back(7);
	temp1.push_back(11);
	temp1.push_back(15);
	vector<int> temp2;
	temp2.push_back(2);
	temp2.push_back(5);
	temp2.push_back(8);
	temp2.push_back(12);
	temp2.push_back(19);
	vector<int> temp3;
	temp3.push_back(3);
	temp3.push_back(6);
	temp3.push_back(9);
	temp3.push_back(16);
	temp3.push_back(22);
	vector<int> temp4;
	temp4.push_back(10);
	temp4.push_back(13);
	temp4.push_back(14);
	temp4.push_back(17);
	temp4.push_back(24);
	vector<int> temp5;
	temp5.push_back(18);
	temp5.push_back(21);
	temp5.push_back(23);
	temp5.push_back(26);
	temp5.push_back(30);

	matrix.push_back(temp1);
	matrix.push_back(temp2);
	matrix.push_back(temp3);
	matrix.push_back(temp4);
	matrix.push_back(temp5);
	Solution sol;
	cout<<sol.searchMatrix(matrix,26)<<endl;
}