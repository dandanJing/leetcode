#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

void PA(bool isSmall){
	ifstream fin;
	ofstream fout;
	if(isSmall) {
		fin.open("A-small-attempt0.in");
		fout.open("A-small-attempt0.out");
	} else {
		fin.open("A-large.in");
		fout.open("A-large.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}
	int T, N;
	fin>>T;
	for (int i = 0; i < T; i++) {
		fin>>N;
		fout<<"Case #"<<i+1<<": ";
		if(N == 0) {
			fout<<"INSOMNIA"<<endl;
			continue;
		}
		int temp = 0;
		set<char> c_set;
		for (int j = 0; j < 10; j++) c_set.insert('0' + j);
		set<char>::iterator it;
		char s[8];
		while(!c_set.empty()) {
			temp += N;
			sprintf(s, "%d", temp);
			string str(s);
			vector<char> vc;
			for(it = c_set.begin();it != c_set.end(); it++){
				if(str.find(*it) != -1) {
					vc.push_back(*it);
				}
			}
			for(int j = 0; j < vc.size(); j++) c_set.erase(vc[j]);
		}
		fout<<temp<<endl;
	}
	fin.close();
	fout.close();
}