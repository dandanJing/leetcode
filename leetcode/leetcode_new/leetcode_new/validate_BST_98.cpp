#include"top.h"

bool judgeValid(TreeNode* root,int min_val,int max_val,bool ismin,bool ismax){
	if(root==NULL)return true;
	if(ismax && root->val>=max_val)return false;
	if(ismin && root->val<=min_val)return false;
	if(!judgeValid(root->left,min_val,root->val,ismin,1))return false;
	if(!judgeValid(root->right,root->val,max_val,1,ismax))return false;
	return true;
}

bool Solution::isValidBST(TreeNode* root){
	if(root==NULL)return true;
	
	return judgeValid(root,0x80000000,0x7fffffff,0,0);
}

void let_98(){
	TreeNode* root=(TreeNode*)new TreeNode(2147483647);
	TreeNode* node1=(TreeNode*)new TreeNode(1);
	TreeNode* node2=(TreeNode*)new TreeNode(5);
	TreeNode* node3=(TreeNode*)new TreeNode(0);
	TreeNode* node4=(TreeNode*)new TreeNode(2);
	TreeNode* node5=(TreeNode*)new TreeNode(4);
	TreeNode* node6=(TreeNode*)new TreeNode(6);
	TreeNode* node7=(TreeNode*)new TreeNode(3);
	/*root->left=node1;
	root->right=node2;
	node1->left=node3;
	node1->right=node4;
	node2->left=node5;
	node2->right=node6;
	node3->right=node7;*/
	Solution sol;
	cout<<sol.isValidBST(root)<<endl;
}