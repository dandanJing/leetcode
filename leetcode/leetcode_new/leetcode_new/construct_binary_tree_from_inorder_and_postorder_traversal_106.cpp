#include"top.h"

TreeNode* Solution::buildTreeII(vector<int>& inorder, vector<int>& postorder){
	TreeNode*result=NULL;
	if(inorder.size()==0)return result;
	if(postorder.size()!=inorder.size())return result;
	int posi=0,posj=0;
	vector<TreeNode*>vec_node;
	vector<int> vec_set;
	int last_in;
	bool isLeft=true;
	while(posi<inorder.size()||posj<inorder.size()){
		if(posi<inorder.size() && posj<inorder.size() && inorder[posi]==postorder[posj]){
			TreeNode*cur=(TreeNode*)new TreeNode(inorder[posi]);
			cur->left=result;
			result=cur;
			posi++;posj++;
			isLeft=true;
		}else if(vec_set.size() && last_in==postorder[posj]){
			isLeft=true;
			TreeNode*cur=(TreeNode*)new TreeNode(last_in);
			vec_set.pop_back();
			if(vec_set.size())last_in=vec_set.back();

			if(vec_node.size()){
				TreeNode*right=vec_node.back();
				vec_node.pop_back();
				cur->right=right;
				cur->left=result;
				result=cur;
			}else{
				cur->right=result;
				result=cur;
			}
			
			posj++;
		}else if(posi+1<inorder.size() && posj+1<inorder.size() &&inorder[posi]==postorder[posj+1]&&inorder[posi+1]==postorder[posj]){
			TreeNode*cur=(TreeNode*)new TreeNode(inorder[posi]);
			TreeNode*right=(TreeNode*)new TreeNode(inorder[posi+1]);
			cur->right=right;
			if(isLeft){
				cur->left=result;
				result=cur;
			}else{
				vec_node.push_back(cur);
			}
	
			posi+=2;
			posj+=2;
		}else{
			isLeft=false;
			vec_set.push_back(inorder[posi]);
			last_in=inorder[posi];
			posi++;
		}
	}
	
	return result;
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