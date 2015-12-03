#include"top.h"

void Solution::connect(TreeLinkNode *root){
	TreeLinkNode *head=root;
	while(head){
		TreeLinkNode *temp = head;
		head = NULL;
		TreeLinkNode *tleft;
		while(temp){
			if(!head && temp->left) {
				head=temp->left;
				tleft=head;
				if(temp->right){
					tleft->next = temp->right;
					tleft = temp->right;
				}
			}else if(!head && temp->right) {
				head=temp->right;
				tleft=head;
			}else{
				if(temp->left){
					tleft->next = temp->left;
					tleft = temp->left;
				}
				if(temp->right){
					tleft->next = temp->right;
					tleft = temp->right;
				}
			}

			temp = temp->next;
		}
	}
}

void let_117(){
	TreeLinkNode *root = (TreeLinkNode *)new TreeLinkNode(1);
	TreeLinkNode *node1 = (TreeLinkNode *)new TreeLinkNode(2);
	TreeLinkNode *node2 = (TreeLinkNode *)new TreeLinkNode(3);
	TreeLinkNode *node3 = (TreeLinkNode *)new TreeLinkNode(4);
	TreeLinkNode *node4 = (TreeLinkNode *)new TreeLinkNode(5);
	TreeLinkNode *node5 = (TreeLinkNode *)new TreeLinkNode(6);
	root->left = node1;
	root->right = node2;
	node1->left = node3;
	node1->right = node4;
	node2->right = node5;
	Solution sol;
	sol.connect(root);
	while(root){
		TreeLinkNode *temp=root;
		root = NULL;

		while(temp){
			if(temp->left && root==NULL) root=temp->left;
			if(temp->right && root==NULL) root=temp->right;
			cout<<temp->val<<",";
			temp = temp->next;
		}
		cout<<endl;
	}
}