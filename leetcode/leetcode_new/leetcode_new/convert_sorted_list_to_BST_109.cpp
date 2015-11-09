#include"top.h"

void buildBST(vector<TreeNode*>node_vec){
	if(node_vec.size()<=1)return;
	queue<pair<int,int>>node_queue;
	node_queue.push(pair<int,int>(0,node_vec.size()-1));
	pair<int,int> cur_pair;
	while(node_queue.size()){
		cur_pair=node_queue.front();
		node_queue.pop();
		if(cur_pair.first>=cur_pair.second)continue;
		if(cur_pair.first==cur_pair.second-1){
			node_vec[cur_pair.first]->right=node_vec[cur_pair.second];
			continue;
		}
		
		int middle=(cur_pair.first+cur_pair.second)/2;
		node_vec[middle]->left=node_vec[(middle-1+cur_pair.first)/2];
		node_vec[middle]->right=node_vec[(middle+1+cur_pair.second)/2];
		node_queue.push(pair<int,int>(cur_pair.first,middle-1));
		node_queue.push(pair<int,int>(middle+1,cur_pair.second));
	}
}

TreeNode* Solution::sortedListToBST(ListNode* head){
	TreeNode*result=NULL;
	if(!head)return result;

	vector<TreeNode*>node_vec;
	ListNode*temp=head;
	while(temp){
		TreeNode*cur=(TreeNode*)new TreeNode(temp->val);
		node_vec.push_back(cur);
		temp=temp->next;
	}
	buildBST(node_vec);
	
	return node_vec[(node_vec.size()-1)/2];
}

void let_109(){
	ifstream fin;
	fin.open("let_109.txt");
	char temp;
	int value;
	ListNode*head=NULL;
	ListNode*next;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		ListNode*cur=(ListNode*)new ListNode(value);
		if(head==NULL){head=cur;next=cur;}
		else{next->next=cur;next=cur;}
	}
	Solution sol;
	TreeNode*result=sol.sortedListToBST(head);
	next=head;
	while(next){cout<<next->val<<",";next=next->next;}
	cout<<endl;
}