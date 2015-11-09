#include"top.h"

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum){
	vector<vector<int>> result;
	if(root==NULL) return result;

	queue<pair<TreeNode*,vector<int>>>node_queue;
	vector<int>cur;
	cur.push_back(root->val);
	cur.push_back(root->val);
	node_queue.push(pair<TreeNode*,vector<int>>(root,cur));
	pair<TreeNode*,vector<int>> temp;
	while(node_queue.size()){
		temp=node_queue.front();
		node_queue.pop();
		if(temp.first->left){
			cur=(vector<int>)(temp.second);
			int sum_val=cur.back();
			cur.pop_back();
			cur.push_back(temp.first->left->val);
			cur.push_back(temp.first->left->val+sum_val);
			node_queue.push(pair<TreeNode*,vector<int>>(temp.first->left,cur));
		}
		if(temp.first->right){
			cur=temp.second;
			int sum_val=cur.back();
			cur.pop_back();
			cur.push_back(temp.first->right->val);
			cur.push_back(temp.first->right->val+sum_val);
			node_queue.push(pair<TreeNode*,vector<int>>(temp.first->right,cur));
		}
		if(!temp.first->left && !temp.first->right){
			cur=temp.second;
			int sum_val=cur.back();
			cur.pop_back();
			if(sum_val==sum){result.push_back(cur);}
		}
	}
	
	return result;
}

void let_113(){
	TreeNode* root=(TreeNode*) new TreeNode(5);
	TreeNode* node1=(TreeNode*) new TreeNode(4);
	TreeNode* node2=(TreeNode*) new TreeNode(8);
	TreeNode* node3=(TreeNode*) new TreeNode(11);
	TreeNode* node4=(TreeNode*) new TreeNode(13);
	TreeNode* node5=(TreeNode*) new TreeNode(4);
	TreeNode* node6=(TreeNode*) new TreeNode(7);
	TreeNode* node7=(TreeNode*) new TreeNode(2);
	TreeNode* node9=(TreeNode*) new TreeNode(5);
	TreeNode* node8=(TreeNode*) new TreeNode(1);
	root->left=node1;
	root->right=node2;
	node1->left=node3;
	node2->left=node4;
	node2->right=node5;
	node3->left=node6;
	node3->right=node7;
	node5->right=node8;
	node5->left=node9;
	Solution sol;
	vector<vector<int>> result=sol.pathSum(root,22);

	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}