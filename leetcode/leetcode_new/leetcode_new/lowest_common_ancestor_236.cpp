#include"top.h"

TreeNode* findLowestAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool findp, bool findq);

//----!!!错误1：输入[1,2],1,2,期望输出为1，实际输出为1
TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
	return findLowestAncestor(root,p,q,false,false);
}

TreeNode* findLowestAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool findp, bool findq){
	if(root==NULL) return root;
	else if(root==p && root==q) return root;
	else if(root==p){
		if(findq)return root;

		TreeNode* result=findLowestAncestor(root->left,p,q,true,findq);
		if(result) return root;

		result=findLowestAncestor(root->right,p,q,true,findq);
		if(result) return root;
	}else if(root==q){
		if(findp)return root;

		TreeNode* result=findLowestAncestor(root->left,p,q,findp,true);
		if(result) return root;

		result=findLowestAncestor(root->right,p,q,findp,true);
		if(result) return root;
	}else if(root->left==p && root->right==q) return root;
	else if(root->left==q && root->right==p) return root;
	else if(findp){
		if(root==q) return root;
		else{
			TreeNode* result=findLowestAncestor(root->left,p,q,findp,findq);
			if(result) return result;

			result=findLowestAncestor(root->right,p,q,findp,findq);
			if(result) return result;
		}
	}else if(findq){
		if(root==p) return root;
		else{
			TreeNode* result=findLowestAncestor(root->left,p,q,findp,findq);
			if(result) return result;
			result=findLowestAncestor(root->right,p,q,findp,findq);
			if(result) return result;
		}
	}else{
		TreeNode* result;
		if(root->left==p){
			result=findLowestAncestor(root->left,p,q,true,findq);
			if(result) return root->left;

			result=findLowestAncestor(root->right,p,q,true,findq);
			if(result) return root;
		}else if(root->right==p){
			result=findLowestAncestor(root->left,p,q,true,findq);
			if(result) return root;

			result=findLowestAncestor(root->right,p,q,true,findq);
			if(result) return root->right;
		}else if(root->left==q){
			result=findLowestAncestor(root->left,p,q,findp,true);
			if(result) return root->left;

			result=findLowestAncestor(root->right,p,q,findp,true);
			if(result) return root;
		}else if(root->right==q){
			result=findLowestAncestor(root->left,p,q,findp,true);
			if(result) return root;

			result=findLowestAncestor(root->right,p,q,findp,true);
			if(result) return root->right;
		}else{
			result=findLowestAncestor(root->left,p,q,findp,findq);
			if(result) return result;

			result=findLowestAncestor(root->right,p,q,findp,findq);
			if(result) return result;

			TreeNode*  result1;
			result=findLowestAncestor(root->left,p,q,true,findq);
			result1=findLowestAncestor(root->right,p,q,findp,true);
			if(result&&result1) return root;

			result=findLowestAncestor(root->right,p,q,true,findq);
			result1=findLowestAncestor(root->left,p,q,findp,true);
			if(result&&result1)  return root;
		}
	}
	return NULL;
}

void let_236(){
	TreeNode* tree=(TreeNode*)(new TreeNode(3));
	TreeNode* node1=(TreeNode*)(new TreeNode(5));
	TreeNode* node2=(TreeNode*)(new TreeNode(1));
	tree->left=node1;
	tree->right=node2;
	TreeNode* node3=(TreeNode*)(new TreeNode(6));
	TreeNode* node4=(TreeNode*)(new TreeNode(2));
	node1->left=node3;
	node1->right=node4;
	TreeNode* node5=(TreeNode*)(new TreeNode(0));
	TreeNode* node6=(TreeNode*)(new TreeNode(8));
	node2->left=node5;
	node2->right=node6;
	TreeNode* node7=(TreeNode*)(new TreeNode(7));
	TreeNode* node8=(TreeNode*)(new TreeNode(4));
	node4->left=node7;
	node4->right=node8;

	
	Solution sol;
	TreeNode* result=sol.lowestCommonAncestor(tree,node7,node6);
	cout<<result->val<<endl;
}