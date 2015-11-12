#include"top.h"

void findNode(TreeNode* root,vector<TreeNode*>&min_vec,vector<TreeNode*>&max_vec,vector<pair<TreeNode*,TreeNode*>>&dismatch){
	if(root==NULL)return;

	bool isroot=false;
	FOR(i,min_vec.size()){
		if(root->val<=min_vec[i]->val){dismatch.push_back(pair<TreeNode*,TreeNode*>(root,min_vec[i]));isroot=true;break;}
	}
	if(!isroot){
		FOR(i,max_vec.size()){
			if(root->val>=max_vec[i]->val){dismatch.push_back(pair<TreeNode*,TreeNode*>(root,max_vec[i]));isroot=true;break;}
		}
	}
	//if(isroot)return;
	max_vec.push_back(root);
	findNode(root->left,min_vec,max_vec,dismatch);
	max_vec.pop_back();
	min_vec.push_back(root);
	findNode(root->right,min_vec,max_vec,dismatch);
	min_vec.pop_back();
}

void Solution::recoverTree(TreeNode* root){
	vector<TreeNode*>min_vec;
	vector<TreeNode*>max_vec;
	vector<pair<TreeNode*,TreeNode*>>dismatch;
	findNode(root,min_vec,max_vec,dismatch);
	if(dismatch.size()==0)return;
	else if(dismatch.size()>2){
	}if(dismatch.size()==1){
		int temp=dismatch[0].second->val;
		dismatch[0].second->val=dismatch[0].first->val;
		dismatch[0].first->val=temp;
	}else{
		int temp=dismatch[0].first->val;
		dismatch[0].first->val=dismatch[1].first->val;
		dismatch[1].first->val=temp;
	}

}

void let_99(){
	TreeNode* root=(TreeNode*)new TreeNode(13);
	TreeNode* node1=(TreeNode*)new TreeNode(20);
	TreeNode* node2=(TreeNode*)new TreeNode(9);
	TreeNode* node3=(TreeNode*)new TreeNode(15);
	TreeNode* node4=(TreeNode*)new TreeNode(27);
	TreeNode* node5=(TreeNode*)new TreeNode(7);
	TreeNode* node6=(TreeNode*)new TreeNode(10);
	root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;
	node1->left=node5;
	node1->right=node6;
	Solution sol;
	sol.recoverTree(root);
	cout<<root->val<<endl;
}