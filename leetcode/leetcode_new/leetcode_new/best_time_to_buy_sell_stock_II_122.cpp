#include"top.h"

int findMaxProfit(vector<int> prices, int start,int end){
	if(end-start<2) return 0;
	if(end-start==2) return max(prices[start+1]-prices[start],0);

	int size = end-start;
	
	int* min_sets=(int *) new int[size];
	int mmin=prices[start];
	for(int i=1;i<size;i++){
		min_sets[i]=mmin;
		mmin = min(mmin,prices[start+i]);
	}

	int result=0;
	int temp_price;
	int count_gain;
	for(int i=1;i<size;i++){
		temp_price = prices[start+i];
		if(temp_price>min_sets[i]){
			count_gain=temp_price-min_sets[i]+findMaxProfit(prices,start+i+1,end);
			if(count_gain > result) result=count_gain;
		}
	}
	delete min_sets;
	return result;
}

int Solution::maxProfitII(vector<int>& prices){
	if(prices.size()<2) return 0;
	int size = prices.size();

	return findMaxProfit(prices,0,size);
}

void let_122(){
	ifstream fin;
	fin.open("let_122.txt");
	int value;
	char temp;
	vector<int> prices;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		prices.push_back(value);
	}

	Solution sol;
	cout<<sol.maxProfitII(prices)<<endl;
}