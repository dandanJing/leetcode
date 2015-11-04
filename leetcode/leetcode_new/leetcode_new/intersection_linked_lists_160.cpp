#include"top.h"

ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB){
	ListNode* result=NULL;
	return result;
}

void let_160(){
	ListNode* head=(ListNode*)new ListNode(1);
	ListNode* node1=(ListNode*)new ListNode(2);
	ListNode* node2=(ListNode*)new ListNode(1);
	head->next=node1;
	node1->next=node2;
	Solution sol;
	ListNode* result=sol.getIntersectionNode(head,node1);
}