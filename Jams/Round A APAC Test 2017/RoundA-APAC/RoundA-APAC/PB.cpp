#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


void findMin(int r, int c, vector<vector<int>>& vec, 
	vector<vector<int>>& mod_vec, const int &R, const int &C) {
		int val = mod_vec[r][c];
	if (r - 1 > 0 && mod_vec[r - 1][c] > vec[r - 1][c] && mod_vec[r - 1][c] > val) {
		mod_vec[r - 1][c] = max(val, vec[r - 1][c]);
		findMin(r - 1, c, vec, mod_vec, R, C);
	} 
	if (r + 1 < R - 1 && mod_vec[r + 1][c] > vec[r + 1][c] && mod_vec[r + 1][c] > val) {
		mod_vec[r + 1][c] = max(val, vec[r + 1][c]);
		findMin(r + 1, c, vec, mod_vec, R, C);
	}
	if (c - 1 > 0 && mod_vec[r][c - 1] > vec[r][c - 1] && mod_vec[r][c - 1] > val) {
		mod_vec[r][c - 1] = max(val, vec[r][c - 1]);
		findMin(r, c - 1, vec, mod_vec, R, C);
	}
	if (c + 1 < C - 1 && mod_vec[r][c + 1] > vec[r][c + 1] && mod_vec[r][c + 1] > val) {
		mod_vec[r][c + 1] = max(val, vec[r][c + 1]);
		findMin(r, c + 1, vec, mod_vec, R, C);
	}
}

void PB(bool isSmall){
	ifstream fin;
	ofstream fout;
	ofstream Debugout;
	if(isSmall) {
		fin.open("B-small-practice.in");
		fout.open("B-small-practice.out");
		Debugout.open("Debug-B-small-practice.out");
	} else {
		fin.open("B-large-practice.in");
		fout.open("B-large-practice.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}	
	int T, R, C, val;
	fin>>T;
	vector<vector<int>> vec;
	for (int i = 0; i < T; i++) {
		fout<<"Case #"<<i+1<<":"<<" ";
		vec.clear();

		fin>>R>>C;
		for (int j = 0; j <R; j++) {
			vector<int> temp;
			for (int k = 0; k < C; k++) {
				fin>>val;
				temp.push_back(val);
			}
			vec.push_back(temp);
		}
		
		vector<vector<int>> mod_vec(vec);
		vector<vector<int>> mod_vec1(vec);
		vector<vector<int>> mod_vec2(vec);
		for (int j = 1; j <R - 1; j++) {
			stack<int> st;
			st.push(0);
			for (int k = 1; k < C; k++) {
				while (st.size() > 1 && vec[j][k] > vec[j][st.top()]) {
					st.pop();
				}
				int pos = st.top();
				for (int l = pos + 1; l < k; l++) {
					if (st.top() == 0 && vec[j][k] > vec[j][0]) {
						int val = max(vec[j][l], vec[j][0]);
						mod_vec1[j][l] = max(mod_vec1[j][l], val);
					} else {
						mod_vec1[j][l] = vec[j][k];
					}
				}
				
				st.push(k);
			}
		}
		for (int k = 1; k < C - 1; k++) {
			stack<int> st;
			st.push(0);
			for (int j = 1; j < R; j++) {
				while (st.size() > 1 && vec[j][k] > vec[st.top()][k]) {
					st.pop();
				}
				int pos = st.top();
				for (int l = pos + 1; l < j; l++) {
					
					if (st.top() == 0 && vec[j][k] > vec[0][k]) {
						int val = max(vec[0][k], vec[l][k]);
						mod_vec2[l][k] = max(val, mod_vec[l][k]);
					} else {
						mod_vec2[l][k] = vec[j][k];
					}
				}
				
				st.push(j);
			}
		}
		for (int j = 1; j <R - 1; j++) {
			for (int k = 1; k < C - 1; k++) {
				mod_vec[j][k] = min(mod_vec1[j][k], mod_vec2[j][k]);
			}
		}
		for (int j = 1; j <R - 1; j++) {
			for (int k = 1; k < C - 1; k++) {
				if (mod_vec2[j][k] != mod_vec1[j][k]) {
					findMin(j, k, vec, mod_vec, R, C);
				}
			}
		}
		Debugout<<"Case "<<i<<endl;
		for (int j = 0; j <R ; j++) {
			for (int k = 0; k < C; k++) {
				if (mod_vec[j][k] == vec[j][k])
					Debugout<<mod_vec[j][k]<<" ";
				else
					Debugout<<vec[j][k]<<"["<<mod_vec[j][k]<<"] ";
			}
			Debugout<<endl;
		}
		int result = 0;
		for (int j = 1; j <R - 1; j++) {
			for (int k = 1; k < C - 1; k++) {
				result += mod_vec[j][k] - vec[j][k];
			}
		}
		fout<<result<<endl;
	}
	fin.close();
	fout.close();
	Debugout.close();
}