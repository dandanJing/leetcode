#include"top.h"

void swapList(vector<ListNode*>& vec,int start,int end){
	if(start>=end)return;
	ListNode* temp;
	
	temp=vec[start]->next;
	vec[start]->next=vec[end]->next;
	vec[end]->next=temp;
	temp=vec[start];
	vec[start]=vec[end];
	vec[end]=temp;

	if(start){
		vec[start-1]->next=vec[start];
	}
	vec[end-1]->next=vec[end];
}

void sortResult(vector<ListNode*>& vec,int start,int end){
	if(start>=end) return;
	if(start+1==end){
		if(vec[start]->val>vec[end]->val){
			swapList(vec,start,end);
		}
		return;
	}
	int middle=(start+end)/2;
	if(vec[start]->val>min(vec[middle]->val,vec[end]->val) && vec[start]->val<max(vec[middle]->val,vec[end]->val)){
		swapList(vec,start,end);
	}else if(vec[middle]->val>min(vec[start]->val,vec[end]->val) && vec[middle]->val<max(vec[start]->val,vec[end]->val)){
		swapList(vec,middle,end);
	}
	int posi=start,posj=end-1;
	while(posi!=posj){
		while(vec[posi]->val<=vec[end]->val && posi<posj)posi++;
		while(vec[posj]->val>vec[end]->val &&  posi<posj)posj--;
		swapList(vec,posi,posj);
	}
	if(vec[posi]->val<=vec[end]->val){
		sortResult(vec,start,posi);
		sortResult(vec,posi+1,end);
	}else{
		swapList(vec,posi,end);
		sortResult(vec,start,posi);
		sortResult(vec,posi+1,end);
	}
}
ListNode* Solution::sortList(ListNode* head){
	if(head==NULL)return head;
	
	ListNode* temp=head;
	vector<ListNode*>vec;
	std::map<int,int>map_list;
	std::map<int,int>::iterator it;
	while(temp){
		vec.push_back(temp);
		it=map_list.find(temp->val);
		if(it==map_list.end()){
			map_list.insert(pair<int,int>(temp->val,1));
		}else{
			it->second++;
		}
		temp=temp->next;
	}
	if(vec.size()/map_list.size()>=100){
		ListNode* temp=NULL;
		ListNode* root=NULL;
		int i=0;
		for(it=map_list.begin();it!=map_list.end();it++){
			vec[i++]->val=it->first;
		}
		sortResult(vec,0,map_list.size()-1);

		int pos=map_list.size()-1;
		i=vec.size()-1;
		while(i>=0){
			it=map_list.find(vec[pos--]->val);
			for(int j=i-it->second+1;j<=i;j++){
				vec[j]->val=it->first;
			}
			i=i-it->second;
		}
	}else{
		sortResult(vec,0,vec.size()-1);
	}
	return vec[0];
}

void let_148(){
	ifstream fin;
	fin.open("let_148.txt");
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
	ListNode*result=sol.sortList(root);
	while(result){
		cout<<result->val<<",";
		result=result->next;
	}
	cout<<endl;
}