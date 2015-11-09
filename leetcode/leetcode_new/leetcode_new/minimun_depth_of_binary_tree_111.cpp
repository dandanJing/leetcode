#include"top.h"

int Solution::minDepth(TreeNode* root){
	if(root==NULL) return 0;

	queue<pair<TreeNode*,int>>node_queue;
	node_queue.push(pair<TreeNode*,int>(root,1));
	pair<TreeNode*,int> temp;
	while(node_queue.size()){
		temp=node_queue.front();
		node_queue.pop();
		if(temp.first->left){
			node_queue.push(pair<TreeNode*,int>(temp.first->left,1+temp.second));
		}
		if(temp.first->right){
			node_queue.push(pair<TreeNode*,int>(temp.first->right,1+temp.second));
		}
		if(!temp.first->left && !temp.first->right){
			return temp.second;
		}
	}
	return 0;
}

void let_111(){
	TreeNode* root=(TreeNode*)new TreeNode(1);
	TreeNode* node1=(TreeNode*)new TreeNode(2);
	TreeNode* node2=(TreeNode*)new TreeNode(5);
	TreeNode* node3=(TreeNode*)new TreeNode(3);
	TreeNode* node4=(TreeNode*)new TreeNode(4);
	TreeNode* node5=(TreeNode*)new TreeNode(6);
	root->left=node1;
	root->right=node2;
	/*node1->left=node3;
	node1->right=node4;
	node2->right=node5;*/
	Solution sol;
	cout<<sol.minDepth(root)<<endl;
}