#include"top.h"

//
vector<int> Solution::rightSideView(TreeNode* root){
	vector<int> result;
	if(root==NULL) return result;

	TreeNode* tleft=root->left;
	TreeNode* tright=root->right;
	result.push_back(root->val);
	while(tleft || tright){
		if(tright) {
			result.push_back(tright->val);
			if(tright->left || tright->right){
				tleft = tright->left;
				tright =tright->right;
			}else if(tleft){
				tright = tleft->right;
				tleft = tleft->left;
			}else break;
		}else{
			result.push_back(tleft->val);
			tright = tleft->right;
			tleft = tleft->left;
		}
	}
	return result;
}

void let_199(){
	TreeNode* tree=(TreeNode*)(new TreeNode(1));
	TreeNode* node2=(TreeNode*)(new TreeNode(2));
	TreeNode* node3=(TreeNode*)(new TreeNode(3));
	TreeNode* node4=(TreeNode*)(new TreeNode(4));
	TreeNode* node5=(TreeNode*)(new TreeNode(5));
	TreeNode* node6=(TreeNode*)(new TreeNode(6));
	tree->left=node2;
	tree->right=node3;
	node2->left=node4;
	node3->left=node5;
	node4->right=node6;
	Solution sol;
	vector<int>result=sol.rightSideView(tree);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}