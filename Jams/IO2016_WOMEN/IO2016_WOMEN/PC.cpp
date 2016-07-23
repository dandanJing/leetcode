#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int T, C, V, L;
int dividend = 1000000007;
int multiple(int val1, int val2);
void PC(int caseNum){
	ifstream fin;
	ofstream fout;
	if(caseNum == 0) {
		fin.open("C-small-practice-1.in");
		fout.open("C-small-practice-1.out");
	} else if(caseNum == 1) {
		fin.open("C-small-practice-2.in");
		fout.open("C-small-practice-2.out");
	} else {
		fin.open("C-large-practice.in");
		fout.open("C-large-practice.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}	
	
	fin>>T;
	for (int i = 0; i < T; i++) {
		fin>>C>>V>>L;
		int result = 0;
		if (L > 0) {
			int cur_v = V, cur_c = 0;
			result = V;
			for (int j = 1; j < L; j++) {
				cur_c = multiple(cur_v, C);
				cur_v = multiple(result, V);
				int diff = cur_v - dividend;
				result = cur_c + diff < 0 ? cur_c + cur_v : cur_c + diff;
			}
		}

		fout<<"Case #"<<i+1<<": ";
		fout<<result<<endl;
	}
	fin.close();
	fout.close();
}

int multiple(int val1, int val2){
	int temp = 0;
	int diff = val1 - dividend;
	for (int i = 0; i < val2; i++) {
		if(temp + diff < 0) temp += val1;
		else temp += diff;
	}
	
	return temp % dividend;
}