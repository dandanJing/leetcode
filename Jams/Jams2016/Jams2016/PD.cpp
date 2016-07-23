#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void PD(bool isSmall){
	ifstream fin;
	ofstream fout;
	if(isSmall) {
		fin.open("D-small-practice.in");
		fout.open("D-small-practice.out");
	} else {
		fin.open("D-large-practice.in");
		fout.open("D-large-practice.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}	
}