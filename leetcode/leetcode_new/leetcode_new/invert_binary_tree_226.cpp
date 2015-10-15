#include"top.h"

void invertTreeNode(TreeNode* root){
	if(root==NULL) return;
	if(root->left) invertTreeNode(root->left);
	if(root->right) invertTreeNode(root->right);

	TreeNode* temp=root->left;
	root->left=root->right;
	root->right=temp;
}

TreeNode* Solution::invertTree(TreeNode* root){
	invertTreeNode(root);
	return root;
}

void let_226(){
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
	TreeNode* result=sol.invertTree(tree);
	cout<<1<<endl;
}