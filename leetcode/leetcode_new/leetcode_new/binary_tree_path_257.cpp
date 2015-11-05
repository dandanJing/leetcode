#include"top.h"

void findBinaryTreePath(TreeNode* root,string temp_str,vector<string>& result);
extern char c[1000];

vector<string> Solution::binaryTreePaths(TreeNode* root){
	vector<string> result;
	if(root==NULL) return result;

	string temp_str="";
	sprintf(c,"%i",root->val);
	temp_str+=c;

	if(root->left==NULL && root->right==NULL){
		result.push_back(temp_str);
	}else{
		if(root->left) findBinaryTreePath(root->left,temp_str,result);
		if(root->right) findBinaryTreePath(root->right,temp_str,result);
	}
	
	return result;
}

void findBinaryTreePath(TreeNode* root,string temp_str,vector<string>& result){
	if(root==NULL) result.push_back(temp_str);
	sprintf(c,"%i",root->val);
	temp_str=temp_str+"->"+c;

	if(root->left==NULL && root->right==NULL){
		result.push_back(temp_str);
	}else{
		if(root->left) findBinaryTreePath(root->left,temp_str,result);
		if(root->right) findBinaryTreePath(root->right,temp_str,result);
	}
}

TreeNode* tree;
void initTree(){
	tree=(TreeNode*)(new TreeNode(1));
	tree->left=(TreeNode*)(new TreeNode(2));
	tree->right=(TreeNode*)(new TreeNode(3));
	tree->left->right=(TreeNode*)(new TreeNode(5));
}

void let_257(){
	Solution sol;
	initTree();
	vector<string> result=sol.binaryTreePaths(tree);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}