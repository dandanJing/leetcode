#include"top.h"

void findNode(TreeNode* root,vector<TreeNode*>&min_vec,vector<TreeNode*>&max_vec,vector<pair<TreeNode*,TreeNode*>>&dismatch){
	if(root==NULL)return;

	bool isroot=false;
	FOR(i,min_vec.size()){
		if(root->val<=min_vec[i]->val){dismatch.push_back(pair<TreeNode*,TreeNode*>(root,min_vec[i]));isroot=true;break;}
	}
	if(!isroot){
		FOR(i,max_vec.size()){
			if(root->val>=max_vec[i]->val){dismatch.push_back(pair<TreeNode*,TreeNode*>(root,max_vec[i]));isroot=true;break;}
		}
	}
	//if(isroot)return;
	max_vec.push_back(root);
	findNode(root->left,min_vec,max_vec,dismatch);
	max_vec.pop_back();
	min_vec.push_back(root);
	findNode(root->right,min_vec,max_vec,dismatch);
	min_vec.pop_back();
}

void Solution::recoverTree(TreeNode* root){
	vector<TreeNode*>min_vec;
	vector<TreeNode*>max_vec;
	vector<pair<TreeNode*,TreeNode*>>dismatch;
	findNode(root,min_vec,max_vec,dismatch);
	if(dismatch.size()==0)return;
	else if(dismatch.size()>2){
		std::map<TreeNode*,TreeNode*>node_map;
		std::map<TreeNode*,TreeNode*>::iterator it;
		
		pair<TreeNode*,TreeNode*> temp_pair;
		FOR(i,dismatch.size()){
			temp_pair=dismatch[i];
			node_map.insert(pair<TreeNode*,TreeNode*>(temp_pair.first,temp_pair.second));
		}
		std::map<TreeNode*,int>find_map;
		std::map<TreeNode*,int>::iterator find_it;
		std::map<TreeNode*,TreeNode*>::iterator next;
		for(it=node_map.begin();it!=node_map.end();it++){
			next=node_map.find(it->second);
			if(next==node_map.end()){
				find_it=find_map.find(it->first);
				if(find_it==find_map.end()){
					find_map.insert(pair<TreeNode*,int>(it->first,1));
				}else{
					find_it->second++;
				}
				
				find_it=find_map.find(it->second);
				if(find_it==find_map.end()){
					find_map.insert(pair<TreeNode*,int>(it->second,1));
				}else{
					find_it->second++;
				}
			}
		}
		vector<TreeNode*> one_vec;
		vector<TreeNode*> multi_vec;
		for(find_it=find_map.begin();find_it!=find_map.end();find_it++){
			if(find_it->second==1){
				one_vec.push_back(find_it->first);
			}else{
				multi_vec.push_back(find_it->first);
			}
		}
		if(one_vec.size()>2 && multi_vec.size()==2){
			int temp=multi_vec[0]->val;
			multi_vec[0]->val=multi_vec[1]->val;
			multi_vec[1]->val=temp;
		}else if(one_vec.size()>2 && multi_vec.size()==1){
			bool ismin=false,ismax=false;
			int maxmax=one_vec[0]->val-1,minmin=one_vec[0]->val+1;
			int maxindex=0,minindex=0;
			FOR(j,one_vec.size()){
				if(one_vec[j]->val<multi_vec[0]->val){
					ismin=true;
					if(one_vec[j]->val<minmin){
						minmin=one_vec[j]->val;
						minindex=j;
					}
				}else{
					ismax=true;
					if(one_vec[j]->val>maxmax){
						maxmax=one_vec[j]->val;
						maxindex=j;
					}
				}
			}
			if(ismin&&ismax){
				one_vec[maxindex]->val=minmin;
				one_vec[minindex]->val=maxmax;
			}else if(ismin){
				one_vec[minindex]->val=multi_vec[0]->val;
				multi_vec[0]->val=minmin;
			}else {
				one_vec[maxindex]->val=multi_vec[0]->val;
				multi_vec[0]->val=maxmax;
			}
		}else if(one_vec.size()==2 && multi_vec.size()==0){
			int temp=one_vec[0]->val;
			one_vec[0]->val=one_vec[1]->val;
			one_vec[1]->val=temp;
		}else if(one_vec.size()==2){
			int multi_val=multi_vec[0]->val;
			int val1=one_vec[0]->val, val2=one_vec[1]->val;
			if(multi_val<max(val1,val2) && multi_val>min(val1,val2)){
				int temp=one_vec[0]->val;
				one_vec[0]->val=one_vec[1]->val;
				one_vec[1]->val=temp;
			}else if(multi_val>(val1,val2)){
				if(val1<val2){
					multi_vec[0]->val=val1;
					one_vec[0]->val=multi_val;
				}else{
					multi_vec[0]->val=val2;
					one_vec[1]->val=multi_val;
				}
			}else{
				if(val1>val2){
					multi_vec[0]->val=val1;
					one_vec[0]->val=multi_val;
				}else{
					multi_vec[0]->val=val2;
					one_vec[1]->val=multi_val;
				}
			}
		}
	}else if(dismatch.size()==1){
		int temp=dismatch[0].second->val;
		dismatch[0].second->val=dismatch[0].first->val;
		dismatch[0].first->val=temp;
	}else{
		int multi_val=dismatch[0].second->val;
		int val1=dismatch[0].first->val, val2=dismatch[1].first->val;
		if(multi_val<max(val1,val2) && multi_val>min(val1,val2)){
			dismatch[0].first->val=val2;
			dismatch[1].first->val=val1;		
		}else if(multi_val>max(val1,val2)){
			if(val1<val2){
				dismatch[0].first->val=multi_val;
				dismatch[0].second->val=val1;
			}else{
				dismatch[1].first->val=multi_val;
				dismatch[0].second->val=val2;
			}
		}else{
			if(val1>val2){
				dismatch[0].first->val=multi_val;
				dismatch[0].second->val=val1;
			}else{
				dismatch[1].first->val=multi_val;
				dismatch[0].second->val=val2;
			}
		}
	}

}

void let_99(){
	/*TreeNode* root=(TreeNode*)new TreeNode(1);
	TreeNode* node1=(TreeNode*)new TreeNode(2);
	TreeNode* node2=(TreeNode*)new TreeNode(3);
	root->left=node1;
	node1->left=node2;*/

	/*TreeNode* root=(TreeNode*)new TreeNode(1);
	TreeNode* node1=(TreeNode*)new TreeNode(3);
	TreeNode* node2=(TreeNode*)new TreeNode(4);
	TreeNode* node3=(TreeNode*)new TreeNode(2);
	root->left=node1;
	node1->left=node2;
	node2->right=node3;*/

	TreeNode* root=(TreeNode*)new TreeNode(1);
	TreeNode* node1=(TreeNode*)new TreeNode(4);
	TreeNode* node2=(TreeNode*)new TreeNode(3);
	TreeNode* node3=(TreeNode*)new TreeNode(2);
	root->left=node1;
	node1->right=node2;
	node2->left=node3;

	/*TreeNode* root=(TreeNode*)new TreeNode(1);
	TreeNode* node1=(TreeNode*)new TreeNode(2);
	TreeNode* node2=(TreeNode*)new TreeNode(5);
	TreeNode* node3=(TreeNode*)new TreeNode(4);
	TreeNode* node4=(TreeNode*)new TreeNode(3);
	root->left=node1;
	root->right=node2;
	node1->left=node3;
	node1->right=node4;*/

	/*TreeNode* root=(TreeNode*)new TreeNode(146);
	TreeNode* node1=(TreeNode*)new TreeNode(71);
	TreeNode* node2=(TreeNode*)new TreeNode(-13);
	TreeNode* node3=(TreeNode*)new TreeNode(55);
	TreeNode* node5=(TreeNode*)new TreeNode(231);
	TreeNode* node6=(TreeNode*)new TreeNode(399);
	TreeNode* node7=(TreeNode*)new TreeNode(321);
	TreeNode* node13=(TreeNode*)new TreeNode(-33);
	root->left=node1;
	root->right=node2;
	node1->left=node3;
	node2->left=node5;
	node2->right=node6;

	node3->left=node7;
	node7->left=node13;*/

	/*TreeNode* root=(TreeNode*)new TreeNode(15);
	TreeNode* node1=(TreeNode*)new TreeNode(25);
	TreeNode* node2=(TreeNode*)new TreeNode(9);
	TreeNode* node3=(TreeNode*)new TreeNode(5);
	TreeNode* node4=(TreeNode*)new TreeNode(12);
	TreeNode* node5=(TreeNode*)new TreeNode(20);
	TreeNode* node6=(TreeNode*)new TreeNode(30);
	TreeNode* node7=(TreeNode*)new TreeNode(1);
	TreeNode* node8=(TreeNode*)new TreeNode(7);
	TreeNode* node9=(TreeNode*)new TreeNode(11);
	TreeNode* node10=(TreeNode*)new TreeNode(14);
	TreeNode* node11=(TreeNode*)new TreeNode(17);
	TreeNode* node12=(TreeNode*)new TreeNode(22);
	TreeNode* node13=(TreeNode*)new TreeNode(27);
	TreeNode* node14=(TreeNode*)new TreeNode(35);
	root->left=node1;
	root->right=node2;
	node1->left=node3;
	node1->right=node4;
	node2->left=node5;
	node2->right=node6;
	node3->left=node7;
	node3->right=node8;
	node4->left=node9;
	node4->right=node10;
	node5->left=node11;
	node5->right=node12;
	node6->left=node13;
	node6->right=node14;*/

	Solution sol;
	sol.recoverTree(root);
	cout<<root->val<<endl;
}