#include"top.h"

bool Solution::hasPathSum(TreeNode* root, int sum){
	if(root==NULL) return false;

	queue<pair<TreeNode*,int>>node_queue;
	node_queue.push(pair<TreeNode*,int>(root,root->val));
	pair<TreeNode*,int> temp;
	while(node_queue.size()){
		temp=node_queue.front();
		node_queue.pop();
		if(temp.first->left){
			node_queue.push(pair<TreeNode*,int>(temp.first->left,temp.first->left->val+temp.second));
		}
		if(temp.first->right){
			node_queue.push(pair<TreeNode*,int>(temp.first->right,temp.first->right->val+temp.second));
		}
		if(!temp.first->left && !temp.first->right && temp.second==sum){
			return true;
		}
	}
	return false;
}

void let_112(){
	TreeNode* root=(TreeNode*) new TreeNode(5);
	TreeNode* node1=(TreeNode*) new TreeNode(4);
	TreeNode* node2=(TreeNode*) new TreeNode(8);
	TreeNode* node3=(TreeNode*) new TreeNode(11);
	TreeNode* node4=(TreeNode*) new TreeNode(13);
	TreeNode* node5=(TreeNode*) new TreeNode(4);
	TreeNode* node6=(TreeNode*) new TreeNode(7);
	TreeNode* node7=(TreeNode*) new TreeNode(2);
	TreeNode* node8=(TreeNode*) new TreeNode(1);
	root->left=node1;
	root->right=node2;
	node1->left=node3;
	node2->left=node4;
	node2->right=node5;
	node3->left=node6;
	node3->right=node7;
	node5->right=node8;
	Solution sol;
	cout<<sol.hasPathSum(root,27)<<endl;
}