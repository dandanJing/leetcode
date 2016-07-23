#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

void PB(bool isSmall){
	ifstream fin;
	ofstream fout;
	if(isSmall) {
		fin.open("B-small-attempt0.in");
		fout.open("B-small-attempt0.out");
	} else {
		fin.open("B-large.in");
		fout.open("B-large.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}	
	int T;
	fin>>T;
	string s;
	for (int i = 0; i < T; i++) {
		fin>>s;
		fout<<"Case #"<<i+1<<": ";
		int count = 0;
		int minus = 0;
		
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '+') {
				if (minus) {
					count += (minus == j ? 1 : 2);
					minus = 0;
				}
			} else {
				minus++;
			}
		}
		if(minus) count += (minus == s.size()? 1 : 2);
		fout<<count<<endl;
	}
	fin>>T;
	fin.close();
	fout.close();
}