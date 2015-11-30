#include"top.h"

ListNode* Solution::reverseKGroup(ListNode* head, int k){
	if(k<=1) return head;

	ListNode*temp=head;
        ListNode*pre=head;
        ListNode*post=head;
        ListNode* temphead=head;
        ListNode*cur;
        int count;
        while(1){
            pre=temphead;
            count=0;
            while(pre){
                pre=pre->next;
                count++;
                if(count==k)break;
            }
            if(count<k)break;
            
            count=1;
            cur=temphead;
            pre=temphead->next;
            while(count<k){
                post=pre->next;
                pre->next=cur;
                cur=pre;
                pre=post;
                count++;
            }
            if(temp==head)head=cur;
            else temp->next=cur;
            
            temp=temphead;
            temp->next=pre;
            temphead=pre;
        }
        return head;
}

void let_25(){
	ifstream fin;
	fin.open("let_25.txt");
	char tempc;
	int value;
	ListNode*head=NULL;
	ListNode*cur=NULL;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		ListNode* temp=(ListNode*)new ListNode(value);
		if(head==NULL){head=temp;cur=temp;}
		else {cur->next=temp;cur=temp;}
	}
	Solution sol;
	ListNode* result=sol.reverseKGroup(head,1);
	while(result){
		cout<<result->val<<",";
		result=result->next;
	}
	cout<<endl;
}