#include"top.h"

void buildBST(vector<TreeNode*>node_vec);

TreeNode* Solution::sortedArrayToBST(vector<int>& nums){
	TreeNode*result=NULL;
	if(!nums.size())return result;

	vector<TreeNode*>node_vec;
	FOR(i,nums.size()){
		TreeNode*cur=(TreeNode*)new TreeNode(nums[i]);
		node_vec.push_back(cur);
	}
	buildBST(node_vec);
	
	return node_vec[(node_vec.size()-1)/2];
}