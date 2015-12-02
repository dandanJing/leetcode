#include"top.h"

//void changetree(TreeNode* root1){
//	if(root1==NULL)return ;
//	TreeNode* left_node=root1->left;
//	TreeNode* right_node=root1->right;
//	if(left_node){
//		changetree(left_node);
//		changetree(right_node);
//		root1->right=left_node;
//		TreeNode*temp=left_node;
//		while(temp->right){
//			temp=temp->right;
//		}
//		temp->right=right_node;
//	}else{
//		changetree(right_node);
//	}
//}
//
//void Solution::flatten(TreeNode* root){
//	if(root==NULL)return;
//	if(root->left==NULL && root->right==NULL)return;
//
//	changetree(root);
//}
 
void Solution::flatten(TreeNode* root){
	if(root==NULL)return;
	if(root->left==NULL) flatten(root->right);
	else{
		flatten(root->left);
		TreeNode* temp=root->right;
		root->right=root->left;
		root->left=NULL;
		TreeNode* cur=root->right;
		while(cur->right){
			cur=cur->right;
		}
		cur->right=temp;
		flatten(temp);
	}
}

void let_114(){
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
	node2->right=node5;
	Solution sol;
	sol.flatten(root);
	while(root) {cout<<root->val<<"->";root=root->right;}
	cout<<endl;
}