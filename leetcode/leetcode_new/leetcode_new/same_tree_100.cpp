#include"top.h"

bool isSameTree(TreeNode* p, TreeNode* q){
	return true;
}

void let_100(){
	TreeNode* root=(TreeNode*)new TreeNode(3);
	TreeNode* node1=(TreeNode*)new TreeNode(9);
	TreeNode* node2=(TreeNode*)new TreeNode(20);
	TreeNode* node3=(TreeNode*)new TreeNode(15);
	TreeNode* node4=(TreeNode*)new TreeNode(7);
	root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;
	TreeNode* temp=(TreeNode*)new TreeNode(3);
	temp->left=node1;
	temp->right=node2;
	Solution sol;
	cout<<sol.isSameTree(root,temp)<<endl;
}