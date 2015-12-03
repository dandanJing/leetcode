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
	

	int pos1=0;
	vector<int>temp_vec;
	while(pos1<prices.size()-1){
		if(prices[pos1]<prices[pos1+1]){
			temp_vec.push_back(prices[pos1]);
			temp_vec.push_back(prices[pos1+1]);
		}

		pos1++;
	}
	temp_vec.push_back(prices.back());

	int size = temp_vec.size();
	vector<int>result;
	result.push_back(0);
	result.push_back(0);
	int maxval=0;
	for(int i=1;i<size;i++){
		int mval=temp_vec[i-1];
		int cur=temp_vec[i]-temp_vec[i-1]+result[i-1];
		int temp;
		
		for(int j=i-2; j>=0;j--){
			if(maxval==0) break;
			if(temp_vec[j]<mval) mval=temp_vec[j];
			temp = temp_vec[i]-mval;
			if(j>=0) temp+=result[j];
			if(temp>cur)cur=temp;
		}
		if(cur>maxval)maxval=cur;
		result.push_back(cur);
	}
	return maxval;
	//return findMaxProfit(prices,0,size);
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