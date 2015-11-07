#include"top.h"

ListNode* Solution::detectCycle(ListNode *head){
	ListNode *result=NULL;

	ListNode *temp=head;
	std::map<ListNode *,int> list_map;
	std::map<ListNode *,int>::iterator it;
	while(temp){
		it=list_map.find(temp);
		if(it!=list_map.end()){result=temp;break;}

		list_map.insert(pair<ListNode *,int>(temp,1));
		temp=temp->next;
	}
	return result;
}

void let_142(){
	ifstream fin;
	fin.open("let_141.txt");
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
	//cur->next=root;
	Solution sol;
	ListNode* result=sol.detectCycle(root);
	if(result )cout<<result->val<<endl;
	else cout<<"NULL"<<endl;
}