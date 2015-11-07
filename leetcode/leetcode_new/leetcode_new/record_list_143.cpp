#include"top.h"

void Solution::reorderList(ListNode* head){
	if(head==NULL)return;

	ListNode* temp=head;
	vector<ListNode*>vec;
	while(temp){
		vec.push_back(temp);
		temp=temp->next;
	}
	for(int i=0;i<vec.size()/2;i++){
		vec[i]->next=vec[vec.size()-1-i];
		vec[vec.size()-1-i]->next=vec[i+1];
	}
	vec[(vec.size())/2]->next=NULL;
}

void let_143(){
	ifstream fin;
	fin.open("let_143.txt");
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
	sol.reorderList(root);
	ListNode*result=root;
	while(result){
		cout<<result->val<<",";
		result=result->next;
	}
	cout<<endl;
}