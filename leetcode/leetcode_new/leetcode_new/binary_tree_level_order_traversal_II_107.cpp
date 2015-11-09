#include"top.h"

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
	vector<vector<int>>result;
	if(root==NULL)return result;
	int level=1;
	queue<pair<TreeNode*,int>>queue_node;
	queue_node.push(pair<TreeNode*,int>(root,level));
	pair<TreeNode*,int> cur_pair;
	vector<int> cur_vec;
	while(queue_node.size()){
		cur_pair=queue_node.front();
		queue_node.pop();
		if(cur_pair.second!=level){
			vector<int>temp_vec(cur_vec);
			result.push_back(temp_vec);
			cur_vec.clear();
			level++;
		}
		cur_vec.push_back(cur_pair.first->val);
		if(cur_pair.first->left)queue_node.push(pair<TreeNode*,int>(cur_pair.first->left,cur_pair.second+1));
		if(cur_pair.first->right)queue_node.push(pair<TreeNode*,int>(cur_pair.first->right,cur_pair.second+1));
	}
	result.push_back(cur_vec);

	vector<int>to_change;
	FOR(i,result.size()/2){
		to_change=result[i];
		result[i]=result[result.size()-1-i];
		result[result.size()-1-i]=to_change;
	}
	return result;
}

void let_107(){
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
	vector<vector<int>>result=sol.levelOrderBottom(root);
	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
}