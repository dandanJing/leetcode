#include"top.h"

int Solution::maxDepth(TreeNode* root){
	if(root==NULL)return 0;

	int depth=1;
	queue<pair<TreeNode*,int>>queue_node;
	queue_node.push(pair<TreeNode*,int>(root,depth));
	pair<TreeNode*,int> cur_pair;
	while(queue_node.size()){
		cur_pair=queue_node.front();
		queue_node.pop();
		if(cur_pair.second>depth)depth=cur_pair.second;
		if(cur_pair.first->left)queue_node.push(pair<TreeNode*,int>(cur_pair.first->left,cur_pair.second+1));
		if(cur_pair.first->right)queue_node.push(pair<TreeNode*,int>(cur_pair.first->right,cur_pair.second+1));
	}
	return depth;
}

void let_104(){
	TreeNode* root=(TreeNode*)new TreeNode(3);
	TreeNode* node1=(TreeNode*)new TreeNode(9);
	TreeNode* node2=(TreeNode*)new TreeNode(20);
	TreeNode* node3=(TreeNode*)new TreeNode(15);
	TreeNode* node4=(TreeNode*)new TreeNode(7);
	root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;
	Solution sol;
	cout<<sol.maxDepth(root)<<endl;
}