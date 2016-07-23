#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

void PAA(bool isSmall){
	ifstream fin;
	ofstream fout;
	if(isSmall) {
		fin.open("A-small-practice.in");
		fout.open("AA-small-practice.out");
	} else {
		fin.open("A-large-practice.in");
		fout.open("AA-large-practice.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}	
	int T, N, val;
	map<int,int> vals;
	map<int,int>::iterator it;
	fin>>T;
	for (int i = 0; i < T; i++) {
		fin>>N;
		for (int j = 0; j < 2 * N; j++) {
			fin>>val;
			it = vals.find(val);
			if(it != vals.end()) {
				it->second++;
			} else {
				vals.insert(pair<int,int>(val,1));
			}
		}
		fout<<"Case #"<<i+1<<":";
		for (int j = 0; j < N; j++) {
			it = vals.begin();
			while(it->first % 4 == 0 && vals.find(it->first / 4 * 3) != vals.end()){
				it = vals.find(it->first / 4 * 3);
			}
			
			int cur = it->first;
			fout<<" "<<cur;
			it->second--;
			if (it->second == 0) vals.erase(cur);

			it = vals.find(cur / 3 * 4);
			it->second--;
			if (it->second == 0) vals.erase(it->first);
		}
		fout<<endl;
	}
	fin.close();
	fout.close();
}