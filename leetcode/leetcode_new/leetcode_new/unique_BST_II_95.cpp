#include"top.h"

vector<TreeNode*> setTree(int start,int end){
	vector<TreeNode*>result;
	if(start>end)return result;
	if(start==end){
		TreeNode*temp=(TreeNode*)new TreeNode(start);
		result.push_back(temp);
		return result;
	}
	for(int i=start;i<=end;i++){
		
		TreeNode*left=NULL;
		TreeNode*right=NULL;
		if(i==start){
			vector<TreeNode*> right_vec=setTree(i+1,end);
			FOR(j,right_vec.size()){
				right=right_vec[j];
				TreeNode*temp=(TreeNode*)new TreeNode(i);
				temp->right=right;
				result.push_back(temp);
			}
		}else if(i==end){
			vector<TreeNode*> left_vec=setTree(start,i-1);
			FOR(j,left_vec.size()){
				left=left_vec[j];
				TreeNode*temp=(TreeNode*)new TreeNode(i);
				temp->left=left;
				result.push_back(temp);
			}
		}else{
			vector<TreeNode*> right_vec=setTree(i+1,end);
			vector<TreeNode*> left_vec=setTree(start,i-1);
			FOR(j,right_vec.size()){
				FOR(k,left_vec.size()){
					left=left_vec[k];
					right=right_vec[j];
					TreeNode*temp=(TreeNode*)new TreeNode(i);
					temp->right=right;
					temp->left=left;
					result.push_back(temp);
				}
			}
		}
	}
	return result;
}

vector<TreeNode*> Solution::generateTrees(int n){
	vector<TreeNode*>result;
	if(n==0){result.push_back(NULL);return result;}
	return setTree(1,n);
}

void let_95(){
	Solution sol;
	vector<TreeNode*>result=sol.generateTrees(0);
	FOR(i,result.size()){
		TreeNode*temp=result[i];
		if(temp) cout<<temp->val<<endl;
	}
}