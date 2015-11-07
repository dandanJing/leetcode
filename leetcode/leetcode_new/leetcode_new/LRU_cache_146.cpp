#include"top.h"

class LRUCache{
	int capacity;
	std::map<int,int>map_int;
	vector<int>data;
public:
    LRUCache(int capacity) {
		this->capacity=capacity;
    }
    
    int get(int key) {
		std::map<int,int>::iterator it;
		it=this->map_int.find(key);
		if(it != this->map_int.end())return it->second;
		return -1;
    }
    
    void set(int key, int value) {
        std::map<int,int>::iterator it;
		it=this->map_int.find(key);
		if(it != this->map_int.end()){
			this->map_int.insert(pair<int,int>(key,value));
			int i;
			for(i=0;i<this->data.size();i++){
				if(this->data[i]==key)break;
			}
			for(int j=i;j<this->data.size()-1;j++){
				this->data[j]=this->data[j+1];
			}
			this->data[this->data.size()-1]=key;
		}else{
			this->map_int.insert(pair<int,int>(key,value));
			this->data.push_back(key);
		}
		if(this->data.size()>this->capacity){
			int temp=this->data[0];
			for(int i=0;i<this->data.size()-1;i++){
				this->data[i]=this->data[i+1];
			}
			this->data.pop_back();
			this->map_int.erase(temp);
		}
    }
};

void let_146(){
	LRUCache temp(2);
	temp.set(1,2);
	temp.set(2,3);
	cout<<temp.get(1)<<endl;
	cout<<temp.get(3)<<endl;
	temp.set(3,4);
	cout<<temp.get(1)<<endl;
	cout<<temp.get(3)<<endl;
}