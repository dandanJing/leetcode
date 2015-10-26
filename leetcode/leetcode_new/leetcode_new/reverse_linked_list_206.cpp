#include"top.h"

ListNode* Solution::reverseList(ListNode* head){
	ListNode* node1, *node2, *node3;
	node1=head;
	if(head==NULL) return head;

	node2=head->next;
	if(node2==NULL) return node1;

	node3=node2->next;
	node1->next=NULL;

	while(node3){
		node2->next=node1;
		node1=node2;
		node2=node3;
		node3=node3->next;
	}
	node2->next=node1;
	return node2;
}

void let_206(){
	ListNode* node1=(ListNode*) new ListNode(1);
	ListNode* node2=(ListNode*) new ListNode(2);
	ListNode* node3=(ListNode*) new ListNode(3);
	node1->next=node2;
	node2->next=node3;

	Solution sol;
	ListNode* result=sol.reverseList(node1);
	while(result){
		cout<<result->val<<"->";
		result=result->next;
	}
	cout<<endl;
}