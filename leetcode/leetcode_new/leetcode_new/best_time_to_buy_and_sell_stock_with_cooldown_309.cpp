#include"top.h"

int findResult(vector<int>& prices, int ** dp, int i, int j){
    if(i >= j) return 0;
   
    if(i+1 == j) {dp[i][j]= max(0, prices[j]-prices[i]);return dp[i][j];}
    if(dp[i][j] > 0) return dp[i][j];
    
    int result = max(0, prices[j]-prices[i]);
    int temp = 0;
    for(int k=i; k<j; k++){
        if(prices[k] < prices[k+1])continue;
        else{
            if(k==i) result = findResult(prices,dp, i+1, j);
            else result = max(findResult(prices,dp,k+2,j)+prices[k]-prices[i], findResult(prices,dp,k,j)+prices[k-1]-prices[i]);
            break;
        }
    }
    dp[i][j] = result;
    return dp[i][j];
}

int Solution::maxProfit309(vector<int>& prices){
	if(prices.size() < 2) return 0;
        
        int len = prices.size();
        int **dp = new int*[len];
        
        for(int i=0; i<len; i++){
            dp[i] = new int[len];
            for(int j=0; j<len; j++){
                dp[i][j] = 0;
            }
        }
        return findResult(prices,dp,0,len-1);
}

void let_309(){
	ifstream fin;
	fin.open("let_309.txt");
	int value;

	vector<int> prices;
	while(!fin.eof()){
		fin>>value;
		prices.push_back(value);
	}

	Solution sol;
	cout<<sol.maxProfit309(prices)<<endl;
}