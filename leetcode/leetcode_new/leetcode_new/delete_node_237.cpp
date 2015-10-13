#include"top.h"

void Solution::deleteNode(ListNode* node){
	ListNode* next=node->next;
	if(next==NULL) return;

	node->val=next->val;
	node->next=next->next;
	delete next;
}

void let_237(){
	ListNode* node1=(ListNode*) new ListNode(1);
	ListNode* node2=(ListNode*) new ListNode(2);
	ListNode* node3=(ListNode*) new ListNode(3);
	ListNode* node4=(ListNode*) new ListNode(4);
	node1->next=node2;
	node2->next=node3;
	node3->next=node4;

	Solution sol;
	sol.deleteNode(node3);
	ListNode* temp=node1;
	while(temp!=NULL){
		cout<<temp->val<<"->";
		temp=temp->next;
	}
	cout<<endl;
}