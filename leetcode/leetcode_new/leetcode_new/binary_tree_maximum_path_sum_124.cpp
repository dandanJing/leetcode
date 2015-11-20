#include"top.h"

vector<int> findMaxPath(TreeNode* root){
	vector<int> result;
	result.push_back(0);
	result.push_back(0);

	if(root==NULL)return result;
	result[0]=root->val;

	vector<int> left=findMaxPath(root->left);
	vector<int> right=findMaxPath(root->right);
	if(left[0]>=right[0] && left[0]>0){
		result[0]+=left[0];
	}else if(left[0]<right[0] && right[0]>0){
		result[0]+=right[0];
	}
	
	if(root->left && root->right){
		int val1=root->val,val2=left[0],val3=right[0];
		int val4=root->val+left[0],val5=root->val+right[0];
		int val6=root->val+left[0]+right[0];
		int val12=max(val1,val2),val34=max(val3,val4),val56=max(val5,val6);
		int val1234=max(val12,val34);
		int maxval=max(val1234,val56);
		int maxval1=max(maxval,left[1]);
		result[1]=max(maxval1,right[1]);
	}else if(root->left){
		int val1=root->val,val2=left[0],val3=root->val+left[0];
		int val12=max(val1,val2);
		int maxval=max(val12,val3);
		result[1]=max(maxval,left[1]);
	}else if(root->right){
		int val1=root->val,val2=right[0],val3=root->val+right[0];
		int val12=max(val1,val2);
		int maxval=max(val12,val3);
		result[1]=max(maxval,right[1]);
	}else{
		result[1]=root->val;
	}
	return result;
}
int Solution::maxPathSum(TreeNode* root){
	if(root==NULL)return 0;
	int result=root->val;
	vector<int> left=findMaxPath(root->left);
	vector<int> right=findMaxPath(root->right);

	int output;
	if(root->left && root->right){
		int val1=root->val,val2=left[0],val3=right[0];
		int val4=root->val+left[0],val5=root->val+right[0];
		int val6=root->val+left[0]+right[0];
		int val12=max(val1,val2),val34=max(val3,val4),val56=max(val5,val6);
		int val1234=max(val12,val34);
		int maxval=max(val1234,val56);
		int maxval1=max(maxval,left[1]);
		output=max(maxval1,right[1]);
	}else if(root->left){
		int val1=root->val,val2=left[0],val3=root->val+left[0];
		int val12=max(val1,val2);
		int maxval=max(val12,val3);
		output=max(maxval,left[1]);
	}else if(root->right){
		int val1=root->val,val2=right[0],val3=root->val+right[0];
		int val12=max(val1,val2);
		int maxval=max(val12,val3);
		output=max(maxval,right[1]);
	}else{
		output=root->val;
	}
	
	return output;
}

void let_124(){
	TreeNode* root=(TreeNode*) new TreeNode(-1);
	TreeNode* node1=(TreeNode*) new TreeNode(-2);
	TreeNode* node2=(TreeNode*) new TreeNode(3);
	TreeNode* node3=(TreeNode*) new TreeNode(4);
	TreeNode* node4=(TreeNode*) new TreeNode(5);
	root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;
	Solution sol;
	cout<<sol.maxPathSum(root)<<endl;
}