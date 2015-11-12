#include"top.h"

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode*temp1=l1,*temp2=l2;
	ListNode*head=NULL,*cur=NULL;
	while(temp1&&temp2){
		if(temp1->val<=temp2->val){
			if(head){
				cur->next=temp1;
			}else{
				head=temp1;
			}
			cur=temp1;
			temp1=temp1->next;
		}else{
			if(head){
				cur->next=temp2;
			}else{
				head=temp2;
			}
			cur=temp2;
			temp2=temp2->next;
		}
	}
	if(temp1==NULL && cur){
		cur->next=temp2;
	}else if(temp1==NULL){
		head=temp2;
	}else if(temp2==NULL && cur){
		cur->next=temp1;
	}else{
		head=temp1;
	}
	return head;
}

void let_21(){
	ifstream fin;
	fin.open("let_21.txt");
	char tempc;
	int value;
	ListNode* head1=NULL,*head2=NULL;
	ListNode*temp=NULL;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		ListNode* cur=(ListNode*) new ListNode(value);
		if(temp){
			temp->next=cur;
			temp=cur;
		}else{
			temp=cur;
			head1=cur;
		}
	}
	fin>>tempc;
	temp=NULL;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		ListNode* cur=(ListNode*) new ListNode(value);
		if(temp){
			temp->next=cur;
			temp=cur;
		}else{
			temp=cur;
			head2=cur;
		}
	}
	Solution sol;
	head1=NULL;
	temp=sol.mergeTwoLists(head1,head2);
	while(temp){
		cout<<temp->val<<",";
		temp=temp->next;
	}
	cout<<endl;
}