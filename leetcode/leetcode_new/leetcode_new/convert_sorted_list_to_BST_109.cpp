#include"top.h"

TreeNode* buildBST(vector<ListNode*>node_vec,int start_pos,int end_pos){
	TreeNode*result=NULL;
	if(start_pos>end_pos)return result;
	int middle=(start_pos+end_pos)/2;
	ListNode*temp;
	temp=node_vec[middle];
	result=(TreeNode*)new TreeNode(temp->val);
	TreeNode* left=buildBST(node_vec,start_pos,middle-1);
	TreeNode* right=buildBST(node_vec,middle+1,end_pos);
	result->left=left;
	result->right=right;
	return result;
}

TreeNode* Solution::sortedListToBST(ListNode* head){
	TreeNode*result=NULL;
	if(!head)return result;

	vector<ListNode*>node_vec;
	ListNode*temp=head;
	while(temp){
		node_vec.push_back(temp);
		temp=temp->next;
	}
	temp=node_vec[node_vec.size()/2];
	result=(TreeNode*)new TreeNode(temp->val);
	TreeNode* left=buildBST(node_vec,0,node_vec.size()/2-1);
	TreeNode* right=buildBST(node_vec,node_vec.size()/2+1,node_vec.size()-1);
	result->left=left;
	result->right=right;
	return result;
}

void let_109(){
	ifstream fin;
	fin.open("let_109.txt");
	char temp;
	int value;
	ListNode*head=NULL;
	ListNode*next;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		ListNode*cur=(ListNode*)new ListNode(value);
		if(head==NULL){head=cur;next=cur;}
		else{next->next=cur;next=cur;}
	}
	Solution sol;
	TreeNode*result=sol.sortedListToBST(head);
	next=head;
	while(next){cout<<next->val<<",";next=next->next;}
	cout<<endl;
}