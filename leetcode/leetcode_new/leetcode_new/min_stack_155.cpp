#include"top.h"

class MinStack {
	vector<int>data;
	vector<int> sort_data;
public:
    void push(int x) {
		this->data.push_back(x);
		this->sort_data.push_back(x);
		int i,temp=x;
		for(i=this->sort_data.size()-2;i>=0;i--){
			if(x<=this->sort_data[i])break;
			sort_data[i+1]=sort_data[i];
		}
		sort_data[i+1]=temp;
    }

    void pop() {
		this->data.pop_back();
		this->sort_data.pop_back();
    }

    int top() {
        return this->data[this->data.size()-1];
    }

    int getMin() {
        return this->sort_data[this->sort_data.size()-1];
    }
};

void let_155(){
	MinStack temp;
	temp.push(1);
	temp.push(5);
	temp.push(8);
	temp.push(0);
	cout<<temp.getMin()<<", "<<temp.top()<<endl;
	temp.pop();
	cout<<temp.getMin()<<", "<<temp.top()<<endl;
}