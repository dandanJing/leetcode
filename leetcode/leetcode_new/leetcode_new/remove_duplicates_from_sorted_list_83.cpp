#include"top.h"

ListNode* Solution::deleteDuplicates(ListNode* head){
	if(head==NULL)return head;
	ListNode* pre=head;
	ListNode* last=head->next;
	while(last){
		if(last->val==pre->val){
			pre->next=last->next;
			delete last;
			last=pre->next;
		}else{
			pre=last;
			last=last->next;
		}
	}
	return head;
}

void let_83(){
	ifstream fin;
	fin.open("let_83.txt");
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
	temp=sol.deleteDuplicates(head);
	while(temp){
		cout<<temp->val<<",";
		temp=temp->next;
	}
	cout<<endl;
}