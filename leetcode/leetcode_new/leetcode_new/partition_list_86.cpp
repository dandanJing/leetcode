#include"top.h"

ListNode* Solution::partition(ListNode* head, int x){
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
	temp=sol.partition(head,1);
	while(temp){
		cout<<temp->val<<",";
		temp=temp->next;
	}
	cout<<endl;
}