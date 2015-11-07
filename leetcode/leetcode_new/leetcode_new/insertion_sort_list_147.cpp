#include"top.h"

ListNode* Solution::insertionSortList(ListNode* head){
	if(head==NULL) return head;

	ListNode* cur,*next,*temp,*pre;
	ListNode* cur_pre=head;
	cur=head->next;
	int val;
	while(cur){
		next=cur->next;
		if(cur->val>=cur_pre->val){
			cur_pre=cur_pre->next;
		}else if(head->val>=cur->val){
			cur_pre->next=cur->next;
			cur->next=head;
			head=cur;
		}else{
			cur_pre->next=cur->next;
			pre=head;
			temp=head->next;
			while(temp){
				if(temp->val<cur->val){
					pre=pre->next;
					temp=temp->next;
				}else{
					pre->next=cur;
					cur->next=temp;
					break;
				}
			}

		}
		cur=next;
	}
	return head;
}

void let_147(){
	ifstream fin;
	fin.open("let_147.txt");
	int value;
	char temp;
	fin>>temp>>value;
	ListNode* root=(ListNode*)new ListNode(value);
	ListNode* cur=root;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		ListNode* node1=(ListNode*)new ListNode(value);
		cur->next=node1;
		cur=node1;
	}

	Solution sol;
	ListNode*result=sol.insertionSortList(root);
	while(result){
		cout<<result->val<<",";
		result=result->next;
	}
	cout<<endl;
}