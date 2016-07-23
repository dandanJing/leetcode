#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
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
	int T, N;
	string s;
	bool charvec[26];
	fin>>T;
	
	for (int i = 0; i < T; i++) {
		fout<<"Case #"<<i+1<<":";
		fin>>N;
		getline(fin, s);
		int count = 0;
		string result;
		for (int j = 0; j < N; j++) {
			getline(fin, s);
			vector<char>temp;
			for(int k = 0; k < s.size(); k++) {
				if (s[k] <= 'Z' && s[k] >= 'A')
					temp.push_back(s[k]);
			}
			sort(temp.begin(), temp.end());
			vector<char>::iterator new_end = unique(temp.begin(), temp.end());
			temp.erase(new_end, temp.end());
			if (count < temp.size()) {
				count = temp.size();
				result = s;
			} else if (count == temp.size() && s.compare(result) < 0) {
				result = s;
			}
		}
		fout<<" "<<result<<endl;
	}
	fin.close();
	fout.close();
}