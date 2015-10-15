#include"top.h"

int countTreeNode(TreeNode* root);
int Solution::countNodes(TreeNode* root){
	return countTreeNode(root);
}

int countTreeNode(TreeNode* root){
	int result=1;
	if(root==NULL) return 0;
	else{
		if(root->left) result+=countTreeNode(root->left);
		if(root->right) result+=countTreeNode(root->right);
	}
	return result;
}

void let_222(){
	TreeNode* tree=(TreeNode*)(new TreeNode(4));
	TreeNode* node1=(TreeNode*)(new TreeNode(2));
	TreeNode* node2=(TreeNode*)(new TreeNode(7));
	tree->left=node1;
	tree->right=node2;
	TreeNode* node3=(TreeNode*)(new TreeNode(1));
	TreeNode* node4=(TreeNode*)(new TreeNode(3));
	node1->left=node3;
	node1->right=node4;
	TreeNode* node5=(TreeNode*)(new TreeNode(6));
	TreeNode* node6=(TreeNode*)(new TreeNode(9));
	node2->left=node5;
	node2->right=node6;
	
	Solution sol;
	cout<<sol.countNodes(tree)<<endl;
}