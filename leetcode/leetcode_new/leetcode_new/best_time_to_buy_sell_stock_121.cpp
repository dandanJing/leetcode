#include"top.h"

//int Solution::maxProfit(vector<int>& prices){
//	if(prices.size()<2) return 0;
//	int size = prices.size();
//
//	int* min_sets=(int *) new int[size];
//	int * max_sets=(int *) new int[size];
//	int mmin;
//	if(prices[0]>prices[1]){
//		min_sets[1]=prices[1];
//		max_sets[1]=0;
//		mmin =prices[1];
//	}else{
//		min_sets[1]=prices[0];
//		max_sets[1]=prices[1];
//		mmin =prices[0];
//	}
//	
//	for(int i=2;i<prices.size();i++){
//		min_sets[i]=min_sets[1];
//		max_sets[i]=max_sets[1];
//		int max_gain=max_sets[i]-min_sets[i];
//		int temp_gain;
//		for(int j=1;j<i;j++){
//			if(prices[i]>max_sets[j])temp_gain=prices[j]-min_sets[j];
//			else temp_gain=max_sets[j]-min_sets[j];
//			if(temp_gain>max_gain){
//				max_gain = temp_gain;
//				min_sets[i]=min_sets[j];
//				max_sets[i]=max(max_sets[j],prices[i]);
//			}
//		}
//		if(prices[i]<mmin){
//			mmin = prices[i];
//		}else if(prices[i]-mmin>max_sets[i]-min_sets[i]){
//			max_sets[i]=prices[i];
//			min_sets[i]=mmin;
//		}
//	}
//	int result=max_sets[size-1]-min_sets[size-1];
//	delete max_sets;
//	delete min_sets;
//	return max(result,0);
//}

int Solution::maxProfit(vector<int>& prices){
	if(prices.size()<2) return 0;
	int size = prices.size();
	int* min_sets=(int *) new int[size];
	int * max_sets=(int *) new int[size];

	int mmin=prices[0];
	for(int i=1;i<size;i++){
		min_sets[i]=mmin;
		mmin = min(mmin,prices[i]);
	}

	int mmax=prices[size-1];
	for(int i=size-1;i>0;i--){
		mmax=max(mmax,prices[i]);
		max_sets[i]=mmax;	
	}

	int mgain=0;
	for(int i=1;i<size;i++){
		if(max_sets[i]-min_sets[i]>mgain) mgain=max_sets[i]-min_sets[i];
	}
	delete max_sets;
	delete min_sets;
	
	return mgain;
}

void let_121(){
	ifstream fin;
	fin.open("let_121.txt");
	int value;

	vector<int> prices;
	while(!fin.eof()){
		fin>>value;
		prices.push_back(value);
	}

	Solution sol;
	cout<<sol.maxProfit(prices)<<endl;
}