#include"top.h"

void Solution::recoverTree(TreeNode* root){
}

void let_99(){
	TreeNode* root=(TreeNode*)new TreeNode(3);
	TreeNode* node1=(TreeNode*)new TreeNode(9);
	TreeNode* node2=(TreeNode*)new TreeNode(20);
	TreeNode* node3=(TreeNode*)new TreeNode(15);
	TreeNode* node4=(TreeNode*)new TreeNode(27);
	root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;
	Solution sol;
	sol.recoverTree(root);
	cout<<root->val<<endl;
}