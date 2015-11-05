#include"top.h"

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.size()==0) return false;

	int i=0;
	int find_pos=0;
	int start_pos=0;
	int val1,val2;
	vector<int> temp;
	while(i<matrix.size()){
		temp=matrix[i];
		if(temp.size()){
			val1=temp[0];val2=temp[temp.size()-1];
			if(val1==target) return true;
			else if(val1>target) break;

			if(val2==target)return true;
			else if(val2<target) start_pos=i;
		}
		find_pos=i++;
	}

	for(int j=start_pos;j<=find_pos;j++){
		temp=matrix[j];
		int temp_size=temp.size();
		if(temp_size==0) continue;

		int pos1=0,pos2=temp_size-1,middle;
		while(1){
			if(pos1>=pos2-1) break;

			middle=(pos1+pos2)/2;
			if(temp[middle]==target) return true;
			else if(temp[middle]>target){pos2=middle;}
			else {pos1=middle;}
		}
	}

	return false;
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
	cout<<sol.searchMatrix(matrix,9)<<endl;
}