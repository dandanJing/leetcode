#include"top.h"

int Solution::nthSuperUglyNumber(int n, vector<int>& primes){
	 int* counts = new int[primes.size()];
     int* record = new int[n];
	 int* tempVal = new int[primes.size()];
	 int* tempPos = new int[primes.size()];
	 record[0] = 1;
	 
	 for(int i=0; i<primes.size(); i++){
		 counts[i] = 0;
		 tempVal[i] = primes[i];
		 tempPos[i] = i;
	 }

	 int index = 1;
	 while(index<n){
		 int tmp = tempVal[0];
		 if(tmp != record[index-1]) record[index++] = tmp;

         int pos = tempPos[0];
		 counts[pos]++;

		 int nxt = record[counts[pos]]*primes[pos];
		 tempVal[0] = nxt;

		 int i=1;
		 for(; i<primes.size(); i++){
			 if(nxt > tempVal[i]){
				 tempVal[i-1] = tempVal[i];
				 tempPos[i-1] = tempPos[i];
			 }else break;
		 }
		 tempVal[i-1] = nxt;
		 tempPos[i-1] = pos;
	 }
	 return record[n-1];
}

void let_313(){
	vector<int>primes;
	primes.push_back(2);
	primes.push_back(7);
	primes.push_back(13);
	primes.push_back(19);
	Solution sol;
	cout<<sol.nthSuperUglyNumber(12,primes)<<endl;
}