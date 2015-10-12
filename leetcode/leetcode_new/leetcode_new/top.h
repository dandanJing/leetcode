#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

typedef istringstream ISS;

#define FOR(i,n) for(int i=0;i<n;i++)

class Solution{
public:
	bool wordPattern(string pattern,string str);
	int findDuplicate(vector<int>& nums);
	void gameOfLife(vector<vector<int>>& board);
	void moveZeroes(vector<int>& nums);
};