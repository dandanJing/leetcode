#include"top.h"

bool Solution::isPalindrome(ListNode* head) {
	if(head==NULL) return true;

	vector<int> listVec;
	ListNode* temp=head;
	while(temp!=NULL){
		listVec.push_back(temp->val);
		temp=temp->next;
	}

	int size=listVec.size();
	FOR(i,size/2){
		if(listVec[i]!=listVec[size-1-i]) return false;
	}
	return true;
}

void let_234(){
	ListNode* head=(ListNode*)new ListNode(1);
	ListNode* node1=(ListNode*)new ListNode(2);
	ListNode* node2=(ListNode*)new ListNode(1);
	head->next=node1;
	node1->next=node2;
	Solution sol;
	cout<<sol.isPalindrome(head)<<endl;
}