#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
void findNext(long long result[10], int divisors[10]);
void PC(bool isSmall){
	ifstream fin;
	ofstream fout;
	if(isSmall) {
		fin.open("C-small-practice.in");
		fout.open("C-small-practice.out");
	} else {
		fin.open("C-large-practice.in");
		fout.open("C-large-practice.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}
	int T, J;
	fin>>T>>N>>J;
	long long result[9];
	int divisors[9];
	for (int i = 0; i < 9; i++) {
		result[i] = 1;
		for(int k = 0; k < N -1; k++) {
			result[i] *= (i + 2);
		}
		result[i] += 1;
	}
	
	string temp = "";
	fout<<"Case #1"<<": "<<endl;
	for (int i = 0; i < J; i++) {
		
		findNext(result, divisors);
		temp = "";
		long long cur = result[0];
		while(cur) {
			char c = cur % 2 + '0';
			temp += c;
			cur >>= 1;
		}
		reverse(temp.begin(), temp.end());
		fout<<temp;
		for(int j = 0; j < 9; j++) fout<<" "<<divisors[j];
		fout<<endl;
	}
	fin.close();
	fout.close();
}

int findDivisor(long long val, int base) {
	long long max_div = sqrt(val);
	int divisor = 3;
	while (divisor <= max_div) {
		if(divisor % base != 0 && val % divisor == 0){
			return divisor;
		}
		divisor++;
	}
	return -1;
}

bool helper(long long result[9], int divisors[9]) {
	for(int i = 0; i < 9; i++) {
		int res = findDivisor(result[i], i + 2);
		if (res != -1) {
			divisors[i] = res;
		} else return false;
	}
	return true;
}

void findNext(long long result[9], int divisors[9]){
	bool find = false;
	while (!find) {
		find = helper(result, divisors);
		for (int i = 0; i < 9; i++) {
			result[i] += (i + 2);
		}
	}
}