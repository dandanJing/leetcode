#include"top.h"

ListNode* Solution::rotateRight(ListNode* head, int k){
	vector<ListNode*>node_vec;
	ListNode* temp=head;
	while(temp){
		node_vec.push_back(temp);
		temp=temp->next;
	}
	if(!node_vec.size())return head;
	int shift=k%node_vec.size();
	if(!shift)return head;
	node_vec[node_vec.size()-shift-1]->next=NULL;
	node_vec[node_vec.size()-1]->next=head;
	return node_vec[node_vec.size()-shift];
}

void let_61(){
	ifstream fin;
	fin.open("let_61.txt");
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
	temp=sol.rotateRight(head,5);
	while(temp){
		cout<<temp->val<<",";
		temp=temp->next;
	}
	cout<<endl;
}