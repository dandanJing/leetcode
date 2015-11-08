#include"top.h"

UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode *node){
	if(node==NULL)return node;
	queue<UndirectedGraphNode *>node_queue;
	std::map<UndirectedGraphNode *,UndirectedGraphNode *> labels;
	std::map<UndirectedGraphNode *,UndirectedGraphNode *>::iterator it;

	UndirectedGraphNode *node0=(UndirectedGraphNode*)new UndirectedGraphNode(node->label);
	labels.insert(pair<UndirectedGraphNode *,UndirectedGraphNode *>(node,node0));
	FOR(i,node->neighbors.size()){
		node_queue.push(node->neighbors[i]);
	}
	
	while(node_queue.size()){
		UndirectedGraphNode *temp=node_queue.front();
		node_queue.pop();
		it=labels.find(temp);
		if(it!=labels.end())continue;

		UndirectedGraphNode *node1=(UndirectedGraphNode*)new UndirectedGraphNode(temp->label);
		labels.insert(pair<UndirectedGraphNode *,UndirectedGraphNode *>(temp,node1));
		FOR(i,temp->neighbors.size()){
			node_queue.push(temp->neighbors[i]);
		}
	}
	for(it=labels.begin();it!=labels.end();it++){
		UndirectedGraphNode *temp=it->first;
		std::map<UndirectedGraphNode *,UndirectedGraphNode *>::iterator cur;
		FOR(i,temp->neighbors.size()){
			cur=labels.find(temp->neighbors[i]);
			it->second->neighbors.push_back(cur->second);
		}
	}
	return node0;
}

void let_133(){
	UndirectedGraphNode *node0=(UndirectedGraphNode*)new UndirectedGraphNode(0);
	UndirectedGraphNode *node1=(UndirectedGraphNode*)new UndirectedGraphNode(1);
	UndirectedGraphNode *node2=(UndirectedGraphNode*)new UndirectedGraphNode(2);
	node0->neighbors.push_back(node1);
	node0->neighbors.push_back(node2);
	node1->neighbors.push_back(node2);
	node2->neighbors.push_back(node2);
	Solution sol;
	UndirectedGraphNode *result=sol.cloneGraph(node0);
	cout<<result->label<<endl;
}
