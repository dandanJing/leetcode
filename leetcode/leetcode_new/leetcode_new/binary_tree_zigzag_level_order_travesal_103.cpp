#include"top.h"

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root){
	vector<vector<int>>result;
	if(root==NULL)return result;
	int level=1;
	vector<TreeNode*>odd_vec;
	vector<TreeNode*>even_vec;
	odd_vec.push_back(root);

	TreeNode*temp;
	vector<int> cur_vec;
	while(1){
		if(level%2){
			if(!odd_vec.size())break;
			while(odd_vec.size()){
				temp=odd_vec.back();
				odd_vec.pop_back();
				cur_vec.push_back(temp->val);
				if(temp->right) even_vec.push_back(temp->right);
				if(temp->left) even_vec.push_back(temp->left);
			}
			vector<int>temp_vec;
			FOR(i,cur_vec.size())temp_vec.push_back(cur_vec[cur_vec.size()-1-i]);
			result.push_back(temp_vec);
			cur_vec.clear();
			level++;
		}else{
			if(!even_vec.size())break;
			while(even_vec.size()){
				temp=even_vec.back();
				even_vec.pop_back();
				cur_vec.push_back(temp->val);
				if(temp->left) odd_vec.push_back(temp->left);
				if(temp->right) odd_vec.push_back(temp->right);
			}
			vector<int>temp_vec;
			FOR(i,cur_vec.size())temp_vec.push_back(cur_vec[cur_vec.size()-1-i]);
			result.push_back(temp_vec);
			cur_vec.clear();
			level++;
		}
	}
	return result;
}

void let_103(){
	TreeNode* root=(TreeNode*)new TreeNode(3);
	TreeNode* node1=(TreeNode*)new TreeNode(9);
	TreeNode* node2=(TreeNode*)new TreeNode(20);
	TreeNode* node3=(TreeNode*)new TreeNode(15);
	TreeNode* node4=(TreeNode*)new TreeNode(7);
	root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;
	Solution sol;
	vector<vector<int>>result=sol.zigzagLevelOrder(root);
	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
}