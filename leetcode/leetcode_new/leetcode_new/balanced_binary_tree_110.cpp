#include"top.h"

bool findHeight(TreeNode* root, int &height){
	if(root==NULL) {height=0;return true;}
	if(root->left==NULL && root->right==NULL){height=1;return true;}
	int leftHeight,rightHeight;
	if(findHeight(root->left,leftHeight) && findHeight(root->right,rightHeight)){
		if(abs(leftHeight-rightHeight)<=1){
			height=max(leftHeight,rightHeight)+1;
			return true;
		}
	}
	return false;
}

bool Solution::isBalanced(TreeNode* root){
	int height;
	return findHeight(root,height);
}

void let_110(){
	TreeNode* root=(TreeNode*)new TreeNode(1);
	TreeNode* node1=(TreeNode*)new TreeNode(2);
	TreeNode* node2=(TreeNode*)new TreeNode(5);
	TreeNode* node3=(TreeNode*)new TreeNode(3);
	TreeNode* node4=(TreeNode*)new TreeNode(4);
	TreeNode* node5=(TreeNode*)new TreeNode(6);
	root->left=node1;
	root->right=node2;
	node1->left=node3;
	node1->right=node4;
	node3->right=node5;
	Solution sol;
	cout<<sol.isBalanced(root)<<endl;
}