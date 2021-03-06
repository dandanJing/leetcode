#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;

typedef istringstream ISS;

#define FOR(i,n) for(int i=0;i<n;i++)

struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution{
public:
	/*bool wordPattern(string pattern,string str);
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
	vector<int> singleNumber(vector<int>& nums);
	int addDigits(int num);
	vector<string> binaryTreePaths(TreeNode* root);
	bool isAnagram(string s, string t);
	vector<int> diffWaysToCompute(string input) ;
	bool searchMatrix(vector<vector<int>>& matrix, int target) ;
	vector<int> maxSlidingWindow(vector<int>& nums, int k);
	void deleteNode(ListNode* node);
	vector<int> productExceptSelf(vector<int>& nums) ;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
	bool isPalindrome(ListNode* head) ;
	int countDigitOne(int n);
	bool isPowerOfTwo(int n);
	int kthSmallest(TreeNode* root, int k);
	vector<int> majorityElement(vector<int>& nums);
	vector<string> summaryRanges(vector<int>& nums);
	TreeNode* invertTree(TreeNode* root);
	int calculate(string s);
	int calculate1(string s);
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
	int countNodes(TreeNode* root);
	int maximalSquare(vector<vector<char>>& matrix) ;
	bool containsNearbyDuplicate(vector<int>& nums, int k) ;
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
	bool containsDuplicate(vector<int>& nums) ;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
	vector<vector<int>> combinationSum3(int k, int n);
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);
	int findKthLargest(vector<int>& nums, int k);
	int minSubArrayLen(int s, vector<int>& nums);
	int rob(vector<int>& nums);
	int robII(vector<int>& nums);
	bool exist(vector<vector<char>>& board, string word);
	
	ListNode* reverseList(ListNode* head);
	bool isIsomorphic(string s, string t);
	int countPrimes(int n);
	ListNode* removeElements(ListNode* head, int val) ;
	bool isHappy(int n);
	int rangeBitwiseAnd(int m, int n);
	int numIslands(vector<vector<char>>& grid);
	void rotate(vector<int>& nums, int k);
	int reverseBits(int n) ;
	vector<int> rightSideView(TreeNode* root);
	vector<string> findRepeatedDnaSequences(string s) ;
	int trailingZeroes(int n);
	int titleToNumber(string s);
	int majorityElement(vector<int>& nums);
	string convertToTitle(int n);
	string fractionToDecimal(int numerator, int denominator);
	int compareVersion(string version1, string version2);
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
	int findPeakElement(vector<int>& nums);
	string largestNumber(vector<int>& nums);
	int maxProduct(vector<int>& nums);
	int findMin(vector<int>& nums);
	int findMinII(vector<int>& nums);
	int evalRPN(vector<string>& tokens);
	ListNode* sortList(ListNode* head);
	ListNode* insertionSortList(ListNode* head);
	void reorderList(ListNode* head);
	bool hasCycle(ListNode *head);
	ListNode *detectCycle(ListNode *head);
	int singleNumber(vector<int>& nums);
	int maxPoints(vector<Point>& points);
	vector<int> preorderTraversal(TreeNode* root);
	vector<int> postorderTraversal(TreeNode* root);
	bool isPalindrome(string s) ;
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
	void solve(vector<vector<char>>& board);
	int sumNumbers(TreeNode* root);
	int minimumTotal(vector<vector<int>>& triangle);
	vector<vector<int>> generate(int numRows);
	vector<int> getRow(int rowIndex);
	bool hasPathSum(TreeNode* root, int sum);
	vector<vector<int>> pathSum(TreeNode* root, int sum);
	int minDepth(TreeNode* root);
	bool isBalanced(TreeNode* root);
	TreeNode* sortedListToBST(ListNode* head);
	TreeNode* sortedArrayToBST(vector<int>& nums);
	bool isSymmetric(TreeNode* root) ;
	vector<vector<int>> levelOrder(TreeNode* root);
	vector<vector<int>> levelOrderBottom(TreeNode* root) ;
	vector<vector<int>> zigzagLevelOrder(TreeNode* root);
	int maxDepth(TreeNode* root);
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
	TreeNode* buildTreeII(vector<int>& inorder, vector<int>& postorder);
	bool isSameTree(TreeNode* p, TreeNode* q);
	bool isValidBST(TreeNode* root);
	int numTrees(int n);
	vector<TreeNode*> generateTrees(int n);
	vector<int> inorderTraversal(TreeNode* root);
	void recoverTree(TreeNode* root);
	int lengthOfLastWord(string s);
	ListNode* rotateRight(ListNode* head, int k);
	ListNode* deleteDuplicates(ListNode* head);
	ListNode* deleteDuplicatesII(ListNode* head);
	ListNode* removeNthFromEnd(ListNode* head, int n);
	bool isValid(string s);
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) ;
	ListNode* partition(ListNode* head, int x);
	ListNode* mergeKLists(vector<ListNode*>& lists) ;
	vector<int> spiralOrder(vector<vector<int>>& matrix) ;
	vector<vector<int>> generateMatrix(int n);
	void setZeroes(vector<vector<int>>& matrix) ;
	bool searchMatrix(vector<vector<int>>& matrix, int target) ;
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
	int maxSubArray(vector<int>& nums);
	int removeDuplicates(vector<int>& nums);
	int search(vector<int>& nums, int target);
	bool searchII(vector<int>& nums, int target) ;
	int maxPathSum(TreeNode* root);
	int lengthOfLongestSubstring(string s);
	int myAtoi(string str);
	vector<int> findSubstring(string s, vector<string>& words) ;
	string multiply(string num1, string num2);
	vector<int> twoSum(vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	string convert(string s, int numRows);
	int reverse(int x);
	bool isPalindrome(int x) ;
	int removeElement(vector<int>& nums, int val);
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	string intToRoman(int num);
	void nextPermutation(vector<int>& nums);
	vector<int> searchRange(vector<int>& nums, int target);
	int searchInsert(vector<int>& nums, int target);
	int firstMissingPositive(vector<int>& nums) ;
	int trap(vector<int>& height);
	bool canJump(vector<int>& nums);
	int jump(vector<int>& nums) ;
	void rotate(vector<vector<int>>& matrix);
	int uniquePaths(int m, int n);
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
	int minPathSum(vector<vector<int>>& grid);
	vector<int> plusOne(vector<int>& digits) ;
	void sortColors(vector<int>& nums) ;
	string countAndSay(int n);
	int numDecodings(string s) ;
	vector<string> generateParenthesis(int n) ;
	bool isNumber(string s) ;
	bool isAdditiveNumber(string num);
	bool isMatch(string s, string p);
	int maxArea(vector<int>& height)
	int threeSumClosest(vector<int>& nums, int target);
	ListNode* reverseKGroup(ListNode* head, int k);
	bool isMatch44(string s, string p);
	int minDistance(string word1, string word2);
	int largestRectangleArea(vector<int>& height);
	bool isScramble(string s1, string s2) ;
	vector<vector<int>> subsetsWithDup(vector<int>& nums);
	vector<string> restoreIpAddresses(string s);
	void flatten(TreeNode* root);
	string addBinary(string a, string b);
	int divide(int dividend, int divisor);
	vector<vector<string>> groupAnagrams(vector<string>& strs) ;
	vector<vector<int>> subsets(vector<int>& nums);
	vector<Interval> merge(vector<Interval>& intervals);
	vector<vector<int>> threeSum(vector<int>& nums);
	string longestPalindrome(string s);
	string minWindow(string s, string t);
	int maxProfit(vector<int>& prices);
	int maxProfitII(vector<int>& prices);
	int maxProfitIV(int k, vector<int>& prices);
	int nthUglyNumber(int n);
	int maxProfit309(vector<int>& prices);
	int nthSuperUglyNumber(int n, vector<int>& primes);
	bool wordBreak(string s, vector<string>& wordDict);
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words);*/

	int longestConsecutive(vector<int>& nums);
	void connect(TreeLinkNode *root);
	vector<vector<string>> partition(string s);
	vector<vector<string>> ladderLength(string beginWord, string endWord, std::map<string,int>& wordList);
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
	int maximumGap(vector<int>& nums);
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
	
	int calculateMinimumHP(vector<vector<int>>& dungeon);
	string shortestPalindrome(string s);
};
