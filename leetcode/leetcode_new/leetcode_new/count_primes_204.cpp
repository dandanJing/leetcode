#include"top.h"

int Solution::countPrimes(int n){
	if(n<=2) return 0;
	if(n==3) return 1;
	if(n<=5) return 2;
	if(n<=7) return 3;

	vector<int> prime_vec;
	prime_vec.push_back(2);
	prime_vec.push_back(3);
	prime_vec.push_back(5);
	prime_vec.push_back(7);

	int temp_val=11;
	while(temp_val<n){
		int pos=1;
		while(pos<prime_vec.size()){
			int temp_prime=prime_vec[pos];
			if(temp_val%temp_prime==0) break;
			else if(temp_prime>=sqrt(temp_val)) {prime_vec.push_back(temp_val); break;}//temp_valÊÇËØÊý
			pos++;
		}
		temp_val+=2;
	}

	return prime_vec.size();
}

void let_204(){
	Solution sol;
	cout<<sol.countPrimes(5)<<endl;
	cout<<sol.countPrimes(30)<<endl;
	cout<<sol.countPrimes(500)<<endl;
	cout<<sol.countPrimes(5000)<<endl;
}