#include"top.h"

//----!!!����1��Ҫ��������������������ʣ����ʱ��Ч��
//----!!!����2������[1,2,3,4,5,6,7,8]������8�����7
int findTreeHeight(TreeNode* root){
	TreeNode* temp=root;
	int height=0;
	while(temp){
		height++;
		temp=temp->left;
	}
	return height;
}

int Solution::countNodes(TreeNode* root){
	if(root==NULL) return 0;

	int result=1;
	TreeNode* temp=root;
	while(temp){
		int rightHeight=findTreeHeight(temp->right);
		int leftHeight=findTreeHeight(temp->left);
		if(rightHeight>=leftHeight && rightHeight){
			result=2*result+1;
			temp=temp->right;
		}else if(leftHeight){
			result=2*result;
			temp=temp->left;
		}else{
			temp=temp->left;
		}
	}
	return result;
}

void let_222(){
	TreeNode* tree=(TreeNode*)(new TreeNode(1));
	TreeNode* node1=(TreeNode*)(new TreeNode(2));
	TreeNode* node2=(TreeNode*)(new TreeNode(3));
	tree->left=node1;
	tree->right=node2;
	TreeNode* node3=(TreeNode*)(new TreeNode(4));
	TreeNode* node4=(TreeNode*)(new TreeNode(5));
	node1->left=node3;
	node1->right=node4;
	TreeNode* node5=(TreeNode*)(new TreeNode(6));
	TreeNode* node6=(TreeNode*)(new TreeNode(7));
	node2->left=node5;
	node2->right=node6;
	TreeNode* node7=(TreeNode*)(new TreeNode(8));
	/*node3->left=node7;*/

	Solution sol;
	cout<<sol.countNodes(tree)<<endl;
}