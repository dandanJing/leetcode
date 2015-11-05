#include"top.h"

struct DualListNode {
     int val;
     DualListNode *next;
	 DualListNode* before;
     DualListNode(int x) : val(x), next(NULL), before(NULL) {}
};

class MinStack {
	vector<DualListNode *>data;
	DualListNode *head;
	DualListNode *tail;
	vector<int> sort_data;
public:
	MinStack(){this->head=NULL;this->tail=NULL;}
    void push(int x) {
		DualListNode * temp=(DualListNode *)new DualListNode(x);
		this->data.push_back(temp);
		if(this->head==NULL){this->head=temp;this->tail=temp;}
		else{
			DualListNode *it1=head,*it2=tail;
			while(1){
				if(x<=it1->val){
					temp->before=it1->before;
					temp->next=it1;
					if(it1->before) it1->before->next=temp;
					it1->before=temp;
					if(it1==this->head)this->head=temp;
					break;
				}else if(x>=it2->val){
					temp->before=it2;
					temp->next=it2->next;
					if(it2->next) it2->next->before=temp;
					it2->next=temp;
					if(it2==this->tail)this->tail=temp;
					break;
				}else if(it1==it2 || it1->next==it2){
					temp->before=it1;
					temp->next=it1->next;
					if(it1->next) it1->next->before=temp;
					it1->next=temp;
					break;
				}else{
					it1=it1->next;
					it2=it2->before;
				}
			}
		}
    }

    void pop() {
		DualListNode* temp=this->data.back();
		this->data.pop_back();
		if(temp==this->head)this->head=temp->next;
		if(temp==this->tail)this->tail=temp->before;
		if(temp->before)temp->before->next=temp->next;
		if(temp->next)temp->next->before=temp->before;
		delete temp;
    }

    int top() {
        return this->data[this->data.size()-1]->val;
    }

    int getMin() {
		if(!this->head)return 0;
		return this->head->val;
    }
};

void let_155(){
	MinStack temp;
	temp.push(2);
	temp.push(0);
	temp.push(3);
	temp.push(0);
	cout<<temp.getMin()<<endl;temp.pop();
	cout<<temp.getMin()<<endl;temp.pop();
	cout<<temp.getMin()<<endl;temp.pop();
	cout<<temp.getMin()<<endl;temp.pop();
	/*for(int i=-10000;i<=0;i++)temp.push(i);
	for(int i=-10000;i<=0;i++) {cout<<temp.getMin()<<endl;temp.pop();}*/
}