#include"top.h"

TreeNode* setTreeII(vector<int>& inorder, vector<int>& postorder,pair<int,int>in_pos,pair<int,int>post_pos){
	int post_pos1= post_pos.first;
	int  post_pos2= post_pos.second;
	int in_pos1=in_pos.first;
	int in_pos2=in_pos.second;
	if(post_pos1>post_pos2)return NULL;
	if(in_pos1>in_pos2)return NULL;

	TreeNode* result=NULL;
	if(in_pos1==in_pos2){
		return (TreeNode*)new TreeNode(inorder[in_pos1]);
	}
	int posi=in_pos1,posj=post_pos1;
	while(posi<=in_pos2 || posj<=post_pos2){
		if(inorder[posi]==postorder[posj]){
			TreeNode* cur=(TreeNode*)new TreeNode(inorder[posi]);
			cur->left=result;
			result=cur;
			posi++;posj++;
		}else{
			int find_pos;
			for(find_pos=posj+1;find_pos<=post_pos2;find_pos++){
				if(inorder[posi]==postorder[find_pos])break;
			}
			TreeNode* right=setTreeII(inorder,postorder,pair<int,int>(posi+1,posi+find_pos-posj),pair<int,int>(posj,find_pos-1));
			TreeNode* cur=(TreeNode*)new TreeNode(inorder[posi]);
			cur->left=result;
			cur->right=right;
			result=cur;
			posi=posi+find_pos-posj+1;
			posj=find_pos+1;
		}
	}
	return result;
}

TreeNode* Solution::buildTreeII(vector<int>& inorder, vector<int>& postorder){
	TreeNode*result=NULL;
	if(inorder.size()==0)return result;
	if(postorder.size()!=inorder.size())return result;

	return setTreeII(inorder,postorder,pair<int,int>(0,inorder.size()-1),pair<int,int>(0,inorder.size()-1));
}

void let_106(){
	ifstream fin;
	fin.open("let_106.txt");
	char temp;
	int value;
	vector<int>inorder;
	vector<int>postorder;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		inorder.push_back(value);
	}
	fin>>temp;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		postorder.push_back(value);
	}
	Solution sol;
	TreeNode*result=sol.buildTreeII(inorder,postorder);
	if(result) cout<<result->val<<endl;
}