#include"top.h"

class Queue {
	stack<int> data;
public:
    // Push element x to the back of queue.
    void push(int x) {
		if(!data.size())this->data.push(x);
		else{
			int size = this->data.size();
			int * temp=(int *) new int[size];
			FOR(i,size){temp[i]=this->data.top();this->data.pop();}
			this->data.push(x);
			FOR(i,size) this->data.push(temp[size-1-i]);
			delete temp;
		}
    }

    // Removes the element from in front of queue.
    void pop(void) {
        this->data.pop();
    }

    // Get the front element.
    int peek(void) {
        return this->data.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
		return this->data.empty();
    }
};

void let_232(){
	Queue temp;
	temp.push(1);
	temp.push(2);
	temp.push(3);
	cout<<temp.peek()<<endl;
	temp.pop();
	cout<<temp.empty()<<endl;
}