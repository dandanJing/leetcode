#include"top.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
	ListNode* result=l1;
	int temp,addnum=0;
	ListNode* list1=l1,*list2=l2;
	ListNode* l1_pre=NULL, *l2_pre=NULL;
	while(list1 && list2){
		temp=list1->val+list2->val+addnum;
		list1->val=temp%10;
		addnum=temp/10;

		if(!result) result=list1;
		l1_pre=list1;
		l2_pre=list2;
		list1=list1->next;
		list2=list2->next;
	}
	
	if(list2 && result==NULL){
		result=list2;
	}else if(list2){
		while(list2){
			temp=list2->val+addnum;
			list2->val=temp%10;
			addnum=temp/10;
			l1_pre->next=list2;
			l1_pre=list2;
			list2=list2->next;
		}
	}else if(list1){
		while(list1){
			temp=list1->val+addnum;
			list1->val=temp%10;
			addnum=temp/10;
			l1_pre=list1;
			list1=list1->next;
		}
	}
	if(addnum){
		ListNode*node1=(ListNode*)new ListNode(addnum);
		l1_pre->next=node1;
	}
	return result;
}

void let_2(){
	ListNode*root=(ListNode*)new ListNode(2);
	ListNode*root1=(ListNode*)new ListNode(5);
	ListNode*node1=(ListNode*)new ListNode(4);
	ListNode*node2=(ListNode*)new ListNode(3);
	ListNode*node3=(ListNode*)new ListNode(6);
	ListNode*node4=(ListNode*)new ListNode(4);
	root->next=node1;
	//node1->next=node2;
	root1->next=node3;
	node3->next=node4;
	Solution sol;
	ListNode* result=sol.addTwoNumbers(root,root1);
	while(result){
		cout<<result->val<<",";
		result=result->next;
	}
	cout<<endl;
}