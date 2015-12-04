#include"top.h"

int Solution::nthSuperUglyNumber(int n, vector<int>& primes){
	 int* counts = new int[primes.size()];
     int* record = new int[n];
	 record[0] = 0;
	 
	 queue<int> que_int;
	 for(int i=0; i<primes.size(); i++){
		 counts[i] = 0;
		 que_int.push(primes[i]);
	 }

	 int index = 1;
	 while(index<n){
		 int tmp = que_int.front();
		 que_int.pop();
		 for(int i=0; i<primes.size(); i++){
			  if (tmp == primes[i] * record[counts[i]]) {
                    if (tmp != record[index - 1]) {
                        record[index] = tmp;    
                        index ++;
                    }
                    counts[i] ++;
                   // if ((long)primes[i] * record[counts[i]] < Integer.MAX_VALUE)
                    que_int.push(primes[i] * record[counts[i]]);
                    break;
                }
		 }
	 }
	 return record[n-1];
}

void let_313(){

}