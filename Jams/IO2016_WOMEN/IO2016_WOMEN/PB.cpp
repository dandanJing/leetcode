#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void PB(bool isSmall){
	ifstream fin;
	ofstream fout;
	if(isSmall) {
		fin.open("B-small-practice.in");
		fout.open("B-small-practice.out");
	} else {
		fin.open("B-large-practice.in");
		fout.open("B-large-practice.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}	
	int T, D, K, N;
	fin>>T;
	for (int i = 0; i < T; i++) {
		fin>>D>>K>>N;
		
		N %= D;
		int k_pos, left, right;
		fout<<"Case #"<<i+1<<":";
		K--;
		if (K % 2 == 0) {
			left = (K + 1 + 2 * N) % D;
		} else {
			left = (K + 1 - 2 * N + 2 * D) % D;
		}
		right = (left - 2 + D) % D;
		fout<<" "<<left + 1<<" "<<right + 1<<endl;
	}
	fin.close();
	fout.close();
}