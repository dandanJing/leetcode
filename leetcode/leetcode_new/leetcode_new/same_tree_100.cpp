#include"top.h"

bool Solution::isSameTree(TreeNode* p, TreeNode* q){
	queue<TreeNode*>queue1;
	queue<TreeNode*>queue2;
	queue1.push(p);
	queue2.push(q);
	TreeNode* temp1,*temp2;
	while(queue1.size()){
		temp1=queue1.front();
		queue1.pop();
		temp2=queue2.front();
		queue2.pop();
		if(temp1 && temp2){
			if(temp1->val!=temp2->val)return false;
			queue1.push(temp1->left);
			queue1.push(temp1->right);
			queue2.push(temp2->left);
			queue2.push(temp2->right);
		}else if(!temp1 && !temp2)continue;
		else return false;
	}
	return true;
}

void let_100(){
	TreeNode* root=(TreeNode*)new TreeNode(3);
	TreeNode* node1=(TreeNode*)new TreeNode(9);
	TreeNode* node2=(TreeNode*)new TreeNode(20);
	TreeNode* node3=(TreeNode*)new TreeNode(15);
	TreeNode* node4=(TreeNode*)new TreeNode(7);
	root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;
	TreeNode* temp=(TreeNode*)new TreeNode(3);
	temp->left=node1;
	//temp->right=node2;
	Solution sol;
	cout<<sol.isSameTree(root,temp)<<endl;
}