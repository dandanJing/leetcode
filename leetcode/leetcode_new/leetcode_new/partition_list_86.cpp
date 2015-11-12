#include"top.h"

ListNode* Solution::partition(ListNode* head, int x){
	ListNode*cur=NULL, *largehead=NULL;
	ListNode* small=NULL, *large=NULL;
	
	cur=head;
	while(cur){
		if(cur->val<x){
			if(small)small->next=cur;
			else head=cur;
			small=cur;
		}else{
			if(large)large->next=cur;
			else largehead=cur;
			large=cur;
		}
		cur=cur->next;
	}
	if(large)large->next=NULL;

	if(small)small->next=largehead;
	else head=largehead;
	return head;
}

void let_86(){
	ifstream fin;
	fin.open("let_86.txt");
	char tempc;
	int value;
	ListNode* head;
	ListNode*temp=NULL;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		ListNode* cur=(ListNode*) new ListNode(value);
		if(temp){
			temp->next=cur;
			temp=cur;
		}else{
			temp=cur;
			head=cur;
		}
	}
	Solution sol;
	temp=sol.partition(head,2);
	while(temp){
		cout<<temp->val<<",";
		temp=temp->next;
	}
	cout<<endl;
}