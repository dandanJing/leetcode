#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

typedef istringstream ISS;

#define FOR(i,n) for(int i=0;i<n;i++)

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution{
public:
	bool wordPattern(string pattern,string str);
	int findDuplicate(vector<int>& nums);
	void gameOfLife(vector<vector<int>>& board);
	void moveZeroes(vector<int>& nums);
	vector<string> addOperators(string num, int target);
	int numSquares(int n) ;
	int firstBadVersion(int n) ;
	int hIndex(vector<int>& citations) ;
	string numberToWords(int num) ;
	int missingNumber(vector<int>& nums);
	bool isUgly(int num);
	int nthUglyNumber(int n);
	vector<int> singleNumber(vector<int>& nums);
	int addDigits(int num);
	vector<string> binaryTreePaths(TreeNode* root);
	bool isAnagram(string s, string t);
	vector<int> diffWaysToCompute(string input) ;
	bool searchMatrix(vector<vector<int>>& matrix, int target) ;
	vector<int> maxSlidingWindow(vector<int>& nums, int k);
};
