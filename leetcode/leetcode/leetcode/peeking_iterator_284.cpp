#include"top.h"


class Iterator {
    struct Data{
		vector<int> data_nums;
	};
	Data* data;
	int cur_pos;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next(){
		if(hasNext()){
			return this->data->data_nums[this->cur_pos++];
		}else{
			return -1;
		}
	}
	// Returns true if the iteration has more elements.
	bool hasNext() const {
		if(this->cur_pos < this->data->data_nums.size()) return true;
		else return false;
	}
};

Iterator::Iterator(const vector<int>& nums){
	this->cur_pos=0;
	this->data=(Data*)new(Data);
	FOR(i,nums.size())
		this->data->data_nums.push_back(nums[i]);
}

Iterator::Iterator(const Iterator& iter){
	this->cur_pos=0;
	this->data=(Data*)new(Data);
	FOR(i,iter.data->data_nums.size())
		this->data->data_nums.push_back(iter.data->data_nums[i]);	
}

Iterator::~Iterator(){
	delete this->data;
}

class PeekingIterator : public Iterator {
	int isUsePeak;
	int peakValue;
	bool hasNextValue;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
		isUsePeak=0;
		peakValue=-1;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if(isUsePeak) return peakValue;
		else if(this->hasNext()){hasNextValue=1;}
		else {hasNextValue=0;}
		peakValue=next();isUsePeak=1;return peakValue;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if(isUsePeak) {isUsePeak=0; return peakValue;}
		isUsePeak=0;
		Iterator* pIt=this;
		return pIt->next();
	}

	bool hasNext() const {
		const Iterator* pIt=this;
	    if(isUsePeak) return hasNextValue;
		else return pIt->hasNext();
	}
	
};

void let_284(){
	ifstream fin;
	fin.open("let_284.txt");
	vector<int> input_nums;
	int temp;
	while(!fin.eof()){
		fin>>temp;
		input_nums.push_back(temp);
	}
	PeekingIterator peek(input_nums);
	while(peek.hasNext()){
		cout<<"peek:"<<peek.peek()<<",";
		cout<<"next:"<<peek.next()<<endl;
	}
}