#include"top.h"

bool Solution::isSymmetric(TreeNode* root) {
	if(root==NULL)return true;
	queue<TreeNode*>left_queue;
	queue<TreeNode*>right_queue;
	left_queue.push(root->left);
	right_queue.push(root->right);
	TreeNode*temp_left,*temp_right;
	while(left_queue.size()){
		temp_left=left_queue.front();
		left_queue.pop();
		temp_right=right_queue.front();
		right_queue.pop();
		if(temp_left==NULL && temp_right==NULL)continue;
		else if(temp_left==NULL)return false;
		else if(temp_right==NULL)return false;
		else if(temp_left->val == temp_right->val){
			left_queue.push(temp_left->left);
			left_queue.push(temp_left->right);
			right_queue.push(temp_right->right);
			right_queue.push(temp_right->left);
		}else{
			return false;
		}
	}
	return true;
}

void let_101(){
	TreeNode* root=(TreeNode*)new TreeNode(1);
	TreeNode* node1=(TreeNode*)new TreeNode(2);
	TreeNode* node2=(TreeNode*)new TreeNode(2);
	TreeNode* node3=(TreeNode*)new TreeNode(3);
	TreeNode* node4=(TreeNode*)new TreeNode(4);
	TreeNode* node5=(TreeNode*)new TreeNode(4);
	TreeNode* node6=(TreeNode*)new TreeNode(3);
	root->left=node1;
	root->right=node2;
	node1->left=node3;
	node1->right=node4;
	node2->left=node5;
	//node2->right=node6;
	Solution sol;
	cout<<sol.isSymmetric(root)<<endl;
	node2->right=node6;
}