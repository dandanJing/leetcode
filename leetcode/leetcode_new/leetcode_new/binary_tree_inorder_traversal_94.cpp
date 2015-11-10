#include"top.h"

void inorderTree(TreeNode* root,vector<int>&result){
	if(root==NULL)return;
	if(root->left)inorderTree(root->left,result);
	result.push_back(root->val);
	if(root->right)inorderTree(root->right,result);
}
vector<int> Solution::inorderTraversal(TreeNode* root){
	vector<int>result;
	inorderTree(root,result);
	return result;
}

void let_94(){
	TreeNode* root=(TreeNode*)new TreeNode(3);
	TreeNode* node1=(TreeNode*)new TreeNode(9);
	TreeNode* node2=(TreeNode*)new TreeNode(20);
	TreeNode* node3=(TreeNode*)new TreeNode(15);
	TreeNode* node4=(TreeNode*)new TreeNode(7);
	root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;
	Solution sol;
	vector<int>result=sol.inorderTraversal(root);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;
}