#include"top.h"

int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost){
	if(gas.size()<=0)return -1;
	if(gas.size()!=cost.size())return -1;

	int sum_gas=0;
	int sum_cost=0;
	
	vector<int>temp_vec;
	vector<int>pos_vec;
	int temp_val=-1;
	int temp_pos;
	FOR(i,gas.size()){
		sum_gas+=gas[i];
		sum_cost+=cost[i];

		if(temp_val>=0 && temp_val+gas[i]>=cost[i]){
			temp_val+=(gas[i]-cost[i]);
		}else if(temp_val>=0){
			temp_vec.push_back(temp_val);
			pos_vec.push_back(temp_pos);
			temp_vec.push_back(gas[i]-cost[i]);
			pos_vec.push_back(i);
			temp_val=-1;
		}else if(gas[i]>=cost[i]){
			temp_pos=i;
			temp_val=(gas[i]-cost[i]);
		}else{
			temp_vec.push_back(gas[i]-cost[i]);
			pos_vec.push_back(i);
		}
	}
	if(sum_gas<sum_cost)return -1;

	if(temp_val>=0){
		for(int i=0;i<temp_vec.size();i++){
			temp_val+=temp_vec[i];
			if(temp_val<0)return -1;
		}
	}
	if(temp_val>=0)return temp_pos;

	return -1;
}

void let_134(){
	vector<int> gas;
	vector<int> cost;

	ifstream fin;
	fin.open("let_134.txt");
	int value;
	char temp;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		gas.push_back(value);
	}
	fin>>temp;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		cost.push_back(value);
	}
	Solution sol;
	cout<<sol.canCompleteCircuit(gas,cost)<<endl;
}