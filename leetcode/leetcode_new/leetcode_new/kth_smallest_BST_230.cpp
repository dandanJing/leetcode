#include"top.h"

bool middleSeq(TreeNode* root,int target,int& cur_count, int& result);
int Solution::kthSmallest(TreeNode* root, int k){
	int result=0;
	int cur_count=0;
	middleSeq(root,k,cur_count,result);
	return result;
}

bool middleSeq(TreeNode* root,int target,int& cur_count, int& result){
	if(cur_count>=target) return false;
	if(root==NULL) return false;

	if(root->left){
		if(middleSeq(root->left,target,cur_count,result)) return true;
	}
	if(cur_count==target-1){result=root->val;return true;}
	cur_count++;
	middleSeq(root->right,target,cur_count,result);
}

void let_230(){
	TreeNode* tree=(TreeNode*)(new TreeNode(3));
	TreeNode* node1=(TreeNode*)(new TreeNode(1));
	TreeNode* node2=(TreeNode*)(new TreeNode(5));
	tree->left=node1;
	tree->right=node2;
	TreeNode* node3=(TreeNode*)(new TreeNode(0));
	TreeNode* node4=(TreeNode*)(new TreeNode(2));
	node1->left=node3;
	node1->right=node4;
	TreeNode* node5=(TreeNode*)(new TreeNode(4));
	TreeNode* node6=(TreeNode*)(new TreeNode(8));
	node2->left=node5;
	node2->right=node6;
	TreeNode* node7=(TreeNode*)(new TreeNode(7));
	TreeNode* node8=(TreeNode*)(new TreeNode(9));
	node6->left=node7;
	node6->right=node8;

	Solution sol;
	cout<<sol.kthSmallest(tree,8)<<endl;
}