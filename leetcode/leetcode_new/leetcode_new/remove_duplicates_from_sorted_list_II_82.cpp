#include"top.h"

ListNode* Solution::deleteDuplicatesII(ListNode* head){
	if(head==NULL)return head;
	vector<ListNode*> node_vec;
	ListNode*temp=head;
	while(temp){
		node_vec.push_back(temp);
		temp=temp->next;
	}
	int i=0;
	head=NULL;
	ListNode*pre=NULL;
	while(i<node_vec.size()){
		if(i==node_vec.size()-1 || node_vec[i]->val!=node_vec[i+1]->val){
			temp=node_vec[i];
			if(pre){
				pre->next=temp;
				temp->next=NULL;
				pre=temp;
			}else{
				pre=temp;
				pre->next=NULL;
				head=temp;
			}
			i++;
		}else{
			int j;
			for(j=i+2;j<node_vec.size();j++){
				if(node_vec[i]->val!=node_vec[j]->val)break;
			}
			i=j;
		}
	}
	
	return head;
}

void let_82(){
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
	temp=sol.deleteDuplicatesII(head);
	while(temp){
		cout<<temp->val<<",";
		temp=temp->next;
	}
	cout<<endl;
}