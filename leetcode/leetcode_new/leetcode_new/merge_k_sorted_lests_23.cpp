#include"top.h"

ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
	ListNode*temp1=l1,*temp2=l2;
	ListNode*head=NULL,*cur=NULL;
	while(temp1&&temp2){
		if(temp1->val<=temp2->val){
			if(head){
				cur->next=temp1;
			}else{
				head=temp1;
			}
			cur=temp1;
			temp1=temp1->next;
		}else{
			if(head){
				cur->next=temp2;
			}else{
				head=temp2;
			}
			cur=temp2;
			temp2=temp2->next;
		}
	}
	if(temp1==NULL && cur){
		cur->next=temp2;
	}else if(temp1==NULL){
		head=temp2;
	}else if(temp2==NULL && cur){
		cur->next=temp1;
	}else{
		head=temp1;
	}
	return head;
}

ListNode* mergeResult(vector<ListNode*>& lists, int start, int end){
	if(start>end)return NULL;
	if(start==end)return lists[start];
	if(start+1==end)return mergeTwoList(lists[start],lists[start+1]);
	int middle=(start+end)/2;
	ListNode* list1=mergeResult(lists,start,middle);
	ListNode* list2=mergeResult(lists,middle+1,end);
	return mergeTwoList(list1,list2);
}
ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
	ListNode*head=NULL,*temp1=NULL,*tempj=NULL;
	ListNode*cur=NULL;
	int len=0;

	if(lists.size()>50){
		return mergeResult(lists,0,lists.size()-1);
	}

	vector<ListNode*> vec;
	FOR(i,lists.size()){
		vec.push_back(lists[i]);
	}
	FOR(i,vec.size()){
		temp1=vec[i];
		if(!temp1){len++;continue;}
		int j;
		for(j=i-1;j>=0;j--){
			tempj=vec[j];
			if(!tempj)vec[j+1]=vec[j];
			else if(tempj->val>temp1->val)vec[j+1]=vec[j];
			else break;
		}
		vec[j+1]=temp1;
	}
	while(len<lists.size()){
		temp1=vec[0];
		if(!temp1){len++;continue;}
		if(cur){
			cur->next=temp1;
			cur=temp1;
		}else{
			cur=temp1;
			head=temp1;
		}
		vec[0]=temp1->next;
		temp1=temp1->next;

		int j;
		for(j=0;j<lists.size()-len-1;j++){
			if(!temp1){vec[j]=vec[j+1];continue;}
			tempj=vec[j];
			if(temp1->val<vec[j+1]->val)break;
			else vec[j]=vec[j+1];
		}
		vec[j]=temp1;
		if(!temp1) {len++;}
	}
	if(cur)cur->next=NULL;
	return head;
}

void let_23(){
	ifstream fin;
	fin.open("let_23.txt");
	int N;fin>>N;
	char tempc;
	int value;
	vector<ListNode*> vec;
	FOR(i,N){
		ListNode* head=NULL;
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
		fin>>tempc>>tempc;
		vec.push_back(head);
	}
	Solution sol;
	ListNode*temp=sol.mergeKLists(vec);
	while(temp){
		cout<<temp->val<<",";
		temp=temp->next;
	}
	cout<<endl;
}