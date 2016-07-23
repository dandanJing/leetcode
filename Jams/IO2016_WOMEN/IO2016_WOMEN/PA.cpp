#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void PA(bool isSmall){
	ifstream fin;
	ofstream fout;
	if(isSmall) {
		fin.open("A-small-practice.in");
		fout.open("A-small-practice.out");
	} else {
		fin.open("A-large-practice.in");
		fout.open("A-large-practice.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}	
	int T, N, val;
	vector<int> vals;
	fin>>T;
	for (int i = 0; i < T; i++) {
		fin>>N;
		vals.clear();
		for (int j = 0; j < 2 * N; j++) {
			fin>>val;
			vals.push_back(val);
		}
		sort(vals.begin(), vals.end());
		int right = -1, temp;
		int count = 0;
		fout<<"Case #"<<i+1<<":";
		for (int j = 0; j < 2 * N; j++) {
			if (vals[j] <= 0) continue;
			else {
				fout<<" "<<vals[j];
				count++;
				if (count == N) break;
				temp = vals[j] / 3 * 4;
				
				while (right <= j || vals[right] != temp) {
					right++;
				}
				vals[right] = vals[j] = 0;
			}
		}
		fout<<endl;
	}
	fin.close();
	fout.close();
}