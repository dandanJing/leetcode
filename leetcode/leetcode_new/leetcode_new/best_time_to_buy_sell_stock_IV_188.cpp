#include"top.h"

int findResult(vector<int>& prices, int start, int end){
    if(start+1 > end)return 0;
    int size = end-start+1;
    
    int* min_sets=(int *) new int[size];
	int * max_sets=(int *) new int[size];

	int mmin=prices[0+start];
	for(int i=1;i<size;i++){
		min_sets[i]=mmin;
		mmin = min(mmin,prices[i+start]);
	}

	int mmax=prices[end];
	for(int i=end;i>=start;i--){
		mmax=max(mmax,prices[i]);
		max_sets[i-start]=mmax;	
	}

	int mgain=0;
	for(int i=1;i<size;i++){
		if(max_sets[i]-min_sets[i]>mgain) mgain=max_sets[i]-min_sets[i];
	}
	delete max_sets;
	delete min_sets;
	return mgain;
}

int findMaxProfit(int k,vector<int>&temp_vec, int start, int end){
    if(k<=0) return 0;
    if(temp_vec.size()<2) return 0;
	if(start>=end) return 0;
	
	if(k==1)return findResult(temp_vec,start,end);
	
	int result = findResult(temp_vec,start,end);
    int mval=temp_vec[start];
    int temp;
    for(int i=start;i<=end;i++){
        if(i-1>=start && mval > temp_vec[i-1])mval=temp_vec[i-1];
        
        temp=0;
        if(i>start) temp=temp_vec[i]-mval;
        int temp1 = findMaxProfit(k,temp_vec,i+1,end);
        temp+=findMaxProfit(k-1,temp_vec,i+1,end);
        temp = max(temp,temp1);
        if(temp>result) result=temp;
    }
    return result;
	
}

//int Solution::maxProfitIV(int k, vector<int>& prices){
//	if(k<=0) return 0;
//    if(prices.size()<2) return 0;
//
//	    int pos1=0;
//		int last_val=-1;
//    	vector<int>temp_vec;
//    	while(pos1<prices.size()-1){
//    		if(prices[pos1]<prices[pos1+1]){
//				if(pos1>last_val){
//					temp_vec.push_back(prices[pos1]);
//					temp_vec.push_back(prices[pos1+1]);
//					last_val=pos1+1;
//				}
//				else if(pos1+1>last_val){
//    				temp_vec.push_back(prices[pos1+1]);
//					last_val=pos1+1;
//				}
//    		}
//    
//    		pos1++;
//    	}
//    	temp_vec.push_back(prices.back());
//	    if(temp_vec.size()<2) return 0;
//	    
//	    return findMaxProfit(7,temp_vec,0,temp_vec.size()-1);
//}

int Solution::maxProfitIV(int k, vector<int>& prices){
	if(k<=0) return 0;
    if(prices.size()<2) return 0;

	int pos1=0;
	int last_val=-1;
    vector<int>temp_vec;
    while(pos1<prices.size()-1){
    	if(prices[pos1]<prices[pos1+1]){
			if(pos1>last_val){
				temp_vec.push_back(prices[pos1]);
				temp_vec.push_back(prices[pos1+1]);
				last_val=pos1+1;
			}
			else if(pos1+1>last_val){
    			temp_vec.push_back(prices[pos1+1]);
				last_val=pos1+1;
			}
    	}
    
    	pos1++;
    }
    temp_vec.push_back(prices.back());
	if(temp_vec.size()<2) return 0;
	
	int** result=(int **) new int*[k];
	for(int i=0;i<k;i++) result[i]=(int *) new int[temp_vec.size()+1];

	result[0][0]=0;
	for(int i=0;i<k;i++){
	}
	
}

void let_188(){
	ifstream fin;
	fin.open("let_188.txt");
	int value;
	char temp;
	vector<int> prices;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		prices.push_back(value);
	}

	Solution sol;
	cout<<sol.maxProfitIV(2,prices)<<endl;
}