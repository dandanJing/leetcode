#include"top.h"

vector<int> Solution::preorderTraversal(TreeNode* root){
	vector<int> result;
	if(root==NULL)return result;

	stack<TreeNode*>node_stack;
	node_stack.push(root);
	while(node_stack.size()){
		TreeNode*temp=node_stack.top();
		node_stack.pop();
		result.push_back(temp->val);

		if(temp->right)node_stack.push(temp->right);
		if(temp->left)node_stack.push(temp->left);
		
	}
	return result;
}

void let_144(){
	TreeNode *root=(TreeNode *)new TreeNode(1);
	TreeNode *node1=(TreeNode *)new TreeNode(2);
	TreeNode *node2=(TreeNode *)new TreeNode(3);
	TreeNode *node3=(TreeNode *)new TreeNode(4);
	TreeNode *node4=(TreeNode *)new TreeNode(5);
	root->left=node1;
	root->right=node2;
	node1->left=node3;
	node2->right=node4;
	Solution sol;
	vector<int> result=sol.preorderTraversal(root);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;
}