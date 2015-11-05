#include"top.h"

ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB){
	std::map<ListNode*,int> map_list;
	std::map<ListNode*,int>::iterator it;
	ListNode *temp=headA;
	while(temp){
		map_list.insert(pair<ListNode*,int>(temp,1));
		temp=temp->next;
	}
	if(map_list.size()==0)return NULL;

	temp=headB;
	while(temp){
		it=map_list.find(temp);
		if(it!=map_list.end()) return temp;
		temp=temp->next;
	}
	return NULL;
}

void let_160(){
	ListNode* head=(ListNode*)new ListNode(0);
	ListNode* node1=(ListNode*)new ListNode(1);
	ListNode* node2=(ListNode*)new ListNode(2);
	head->next=node1;
	node1->next=node2;
	ListNode* node3=(ListNode*)new ListNode(3);
	//node3->next=node2;
	Solution sol;
	ListNode* result=sol.getIntersectionNode(head,node3);
	if(result)
		cout<<result->val<<endl;
	else
		cout<<"NULL"<<endl;
}