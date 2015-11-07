#include"top.h"

vector<int> result;
void findNode(TreeNode* temp){
	if(temp==NULL)return;
	if(temp->left)findNode(temp->left);
	if(temp->right)findNode(temp->right);
	result.push_back(temp->val);
}

vector<int> Solution::postorderTraversal(TreeNode* root){
	if(root==NULL)return result;

	findNode(root);
	return result;
}

void let_145(){
	TreeNode *root=(TreeNode *)new TreeNode(1);
	TreeNode *node1=(TreeNode *)new TreeNode(2);
	TreeNode *node2=(TreeNode *)new TreeNode(3);
	TreeNode *node3=(TreeNode *)new TreeNode(4);
	TreeNode *node4=(TreeNode *)new TreeNode(5);
	root->right=node1;
	node1->left=node2;
	/*node1->left=node3;
	node2->right=node4;*/
	Solution sol;
	vector<int> result=sol.postorderTraversal(root);
	FOR(i,result.size()){
		cout<<result[i]<<",";
	}
	cout<<endl;
}