#include"top.h"

int Solution::sumNumbers(TreeNode* root){
	if(root==NULL)return 0;

	queue<pair<TreeNode*,int>>node_queue;
	node_queue.push(pair<TreeNode*,int>(root,root->val));

	int result=0;
	pair<TreeNode*,int> cur_pair;
	while(node_queue.size()){
		cur_pair=node_queue.front();
		node_queue.pop();
		TreeNode*temp=cur_pair.first;
		if(temp->left){
			node_queue.push(pair<TreeNode*,int>(temp->left,10*cur_pair.second+temp->left->val));
		}
		if(temp->right){
			node_queue.push(pair<TreeNode*,int>(temp->right,10*cur_pair.second+temp->right->val));
		}
		if(temp->left==NULL && temp->right==NULL)result+=cur_pair.second;
	}
	return result;
}

void let_129(){
	TreeNode* root=(TreeNode*) new TreeNode(4);
	TreeNode* node1=(TreeNode*) new TreeNode(9);
	TreeNode* node2=(TreeNode*) new TreeNode(0);
	TreeNode* node3=(TreeNode*) new TreeNode(1);
	root->left=node1;
	root->right=node2;
	node1->right=node3;

	Solution sol;
	cout<<sol.sumNumbers(root)<<endl;
}