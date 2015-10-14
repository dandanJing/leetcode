#include"top.h"

class Stack {
	queue<int> data;
public:
    // Push element x onto stack.
    void push(int x) {
		if(this->data.size()==0) {this->data.push(x);return;}

		int size=this->data.size();
		int *temp=(int *)new int[size];

		FOR(i,size){
			temp[i]=this->data.front();
			this->data.pop();
		}
		this->data.push(x);
		FOR(i,size) this->data.push(temp[i]);
		delete temp;
    }

    // Removes the element on top of the stack.
    void pop() {
        this->data.pop();
    }

    // Get the top element.
    int top() {
        return this->data.front();
    }

    // Return whether the stack is empty.
    bool empty() {
		return this->data.empty();
    }
};

void let_225(){
	Stack temp;
	temp.push(1);
	temp.pop();
	cout<<temp.empty()<<endl;
	temp.push(2);
	temp.push(3);
	cout<<temp.top()<<endl;
	temp.pop();
	cout<<temp.top()<<endl;
}