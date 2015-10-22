#include"top.h"

ListNode* Solution::removeElements(ListNode* head, int val) {
	if(head==NULL) return head;

	ListNode* node1, *node2;
	node1=head;
	while(node1){
		if(node1->val==val){
			head=node1;
			node1=node1->next;
			delete head;
			head=NULL;
		}else break;
	}
	if(node1==NULL) return node1;
	head=node1;

	node2=node1->next;
	while(node2){
		if(node2->val==val){
			node1->next=node2->next;
			ListNode* temp=node2;
			node2=node2->next;
			delete temp;
		}else{
			node1=node2;
			node2=node2->next;
		}

	}
	return head;
}

void let_203(){
	ListNode* node1=(ListNode*) new ListNode(1);
	ListNode* node2=(ListNode*) new ListNode(2);
	ListNode* node3=(ListNode*) new ListNode(6);
	ListNode* node4=(ListNode*) new ListNode(3);
	ListNode* node5=(ListNode*) new ListNode(4);
	ListNode* node6=(ListNode*) new ListNode(5);
	ListNode* node7=(ListNode*) new ListNode(6);
	node1->next=node2;
	node2->next=node3;
	node3->next=node4;
	node4->next=node5;
	node5->next=node6;
	node6->next=node7;

	Solution sol;
	ListNode* result=sol.removeElements(node1,6);
	while(result){
		cout<<result->val<<"->";
		result=result->next;
	}
	cout<<endl;
}