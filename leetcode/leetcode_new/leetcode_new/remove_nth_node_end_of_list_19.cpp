#include"top.h"

ListNode* Solution::removeNthFromEnd(ListNode* head, int n){
	if(head==NULL)return head;
	vector<ListNode*> node_vec;
	ListNode*temp=head;
	while(temp){
		node_vec.push_back(temp);
		temp=temp->next;
	}
	if(n>node_vec.size())return head;
	else if(n==node_vec.size()){
		temp=head->next;
		delete head;
		head=temp;
	}else{
		node_vec[node_vec.size()-n-1]->next=node_vec[node_vec.size()-n]->next;
		delete node_vec[node_vec.size()-n];
	}
	return head;
}

void let_19(){
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
	temp=sol.removeNthFromEnd(head,1);
	while(temp){
		cout<<temp->val<<",";
		temp=temp->next;
	}
	cout<<endl;
}