#include"top.h"

//
vector<int> Solution::rightSideView(TreeNode* root){
	vector<int> result;
	if(root==NULL) return result;

	queue<TreeNode*> tree_queue;
	TreeNode* temp;
	tree_queue.push(root);
	int cur_layer_size=1;
	while(cur_layer_size){
		FOR(i,cur_layer_size){
			temp=tree_queue.front();
			tree_queue.pop();
			if(temp->left) tree_queue.push(temp->left);
			if(temp->right) tree_queue.push(temp->right);
		}
		cur_layer_size=tree_queue.size();
		result.push_back(temp->val);
	}
	return result;
}

void let_199(){
	TreeNode* tree=(TreeNode*)(new TreeNode(1));
	TreeNode* node2=(TreeNode*)(new TreeNode(2));
	TreeNode* node3=(TreeNode*)(new TreeNode(3));
	TreeNode* node4=(TreeNode*)(new TreeNode(4));
	TreeNode* node5=(TreeNode*)(new TreeNode(5));
	TreeNode* node6=(TreeNode*)(new TreeNode(6));
	tree->left=node2;
	tree->right=node3;
	node2->left=node4;
	node3->left=node5;
	node4->right=node6;
	Solution sol;
	vector<int>result=sol.rightSideView(tree);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}