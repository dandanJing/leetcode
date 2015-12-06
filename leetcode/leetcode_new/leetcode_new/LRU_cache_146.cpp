#include"top.h"

typedef struct _Node_{

	int key;    //��
	int value;  //����
	
	struct _Node_ *next;  //��һ���ڵ�
	struct _Node_ *pre;   //��һ���ڵ�

}CacheNode;

class LRUCache{

private:
	int cache_size_;                   //cache����
	int cache_real_size_;              //Ŀǰʹ�õĳ���
	CacheNode *p_cache_list_head;      //ͷ�ڵ�ָ��
	CacheNode *p_cache_list_near;      //β�ڵ�ָ��
	std::map<int,CacheNode *> key_map;

	void detachNode(CacheNode *node);  //����ڵ�
	void addToFront(CacheNode *node);  //���ڵ���뵽��һ��

public:
	LRUCache(int cache_size=10);  //���캯����Ĭ��cache��СΪ10
	~LRUCache();      //��������
    int get(int key) {
		std::map<int,CacheNode *>::iterator it = key_map.find(key);
        if(it != key_map.end()){
            CacheNode *p = it->second;
            detachNode(p);
            addToFront(p);
            return p->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        std::map<int,CacheNode *>::iterator it = key_map.find(key);
        CacheNode *p;
        if(it != key_map.end()){
            p = it->second;
            p->value=value;
            detachNode(p);
            addToFront(p);
            return;
        }
        
		//cout<<cache_real_size_<<","<<cache_size_<<endl;
		if(cache_real_size_ >= cache_size_){
			//cout << "free" <<endl;
			p=p_cache_list_near->pre->pre;
			key_map.erase(p->next->key);
			delete p->next;
			p->next=p_cache_list_near;
			p_cache_list_near->pre=p;
		}
	
		p=new CacheNode();//(CacheNode *)malloc(sizeof(CacheNode));
	
		if(p==NULL)
			return ;

		addToFront(p);
		p->key=key;
		p->value=value;
		key_map.insert(pair<int,CacheNode *>(key,p));
		cache_real_size_++;
    }
};
 LRUCache::LRUCache(int capacity) {
		cache_size_=capacity;
		cache_real_size_=0;
		p_cache_list_head=new CacheNode();
		p_cache_list_near=new CacheNode();
		p_cache_list_head->next=p_cache_list_near;
		p_cache_list_head->pre=NULL;
		p_cache_list_near->pre=p_cache_list_head;
		p_cache_list_near->next=NULL;
    }
    
LRUCache::~LRUCache(){
		CacheNode *p;
		p=p_cache_list_head->next;
		while(p!=NULL)
		{	
			delete p->pre;
			p=p->next;
		}

		delete p_cache_list_near;
	
	}

void LRUCache::detachNode(CacheNode *node) {
	node->pre->next=node->next;
	node->next->pre=node->pre;
}

void LRUCache::addToFront(CacheNode *node){
	node->next=p_cache_list_head->next;
	p_cache_list_head->next->pre=node;
	p_cache_list_head->next=node;
	node->pre=p_cache_list_head;
}

void let_146(){
	LRUCache temp(2);
	temp.set(1,2);
	temp.set(2,3);
	cout<<temp.get(1)<<endl;
	cout<<temp.get(3)<<endl;
	temp.set(3,4);
	cout<<temp.get(1)<<endl;
	cout<<temp.get(3)<<endl;
	cout<<temp.get(2)<<endl;
}