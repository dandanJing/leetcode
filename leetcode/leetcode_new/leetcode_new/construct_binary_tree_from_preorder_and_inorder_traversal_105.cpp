#include"top.h"

TreeNode* setTree(vector<int>& preorder, vector<int>& inorder,pair<int,int>pre_pos,pair<int,int>in_pos){
	int pre_pos1=pre_pos.first;
	int pre_pos2=pre_pos.second;
	int in_pos1=in_pos.first;
	int in_pos2=in_pos.second;
	if(pre_pos1>pre_pos2)return NULL;
	if(in_pos1>in_pos2)return NULL;
	TreeNode* result=(TreeNode*)new TreeNode(preorder[pre_pos1]);

	if(pre_pos1==pre_pos2){
		return result;
	}
	int mid1=preorder[pre_pos1];
	int mid_pos2;
	for(mid_pos2=in_pos1;mid_pos2<=in_pos2;mid_pos2++){
		if(inorder[mid_pos2]==mid1)break;
	}
	if(mid_pos2>in_pos2)return NULL;
	if(mid_pos2>in_pos1){
		int size=mid_pos2-in_pos1;
		int left_pos1=pre_pos1+size;
		if(left_pos1>pre_pos2)return NULL;
		TreeNode* left_tree=setTree(preorder,inorder,pair<int,int>(pre_pos1+1,left_pos1),pair<int,int>(in_pos1,mid_pos2-1));
		TreeNode* right_tree=setTree(preorder,inorder,pair<int,int>(left_pos1+1,pre_pos2),pair<int,int>(mid_pos2+1,in_pos2));
		result->right=right_tree;
		result->left=left_tree;
	}else{
		TreeNode* right_tree=setTree(preorder,inorder,pair<int,int>(pre_pos1+1,pre_pos2),pair<int,int>(mid_pos2+1,in_pos2));
		result->right=right_tree;
	}
	return result;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder){
	TreeNode*result=NULL;
	if(preorder.size()==0)return result;
	if(preorder.size()!=inorder.size())return result;

	return setTree(preorder,inorder,pair<int,int>(0,preorder.size()-1),pair<int,int>(0,preorder.size()-1));
}

void let_105(){
	ifstream fin;
	fin.open("let_105.txt");
	char temp;
	int value;
	vector<int>preorder;
	vector<int>inorder;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		preorder.push_back(value);
	}
	fin>>temp;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		inorder.push_back(value);
	}
	Solution sol;
	TreeNode*result=sol.buildTree(preorder,inorder);
	cout<<result->val<<endl;
}