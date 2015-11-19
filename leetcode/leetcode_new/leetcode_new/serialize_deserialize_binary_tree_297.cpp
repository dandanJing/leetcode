#include"top.h"

extern char c[1000];
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string result="";
		if(root==NULL)return "[]";

        queue<TreeNode*> node_queue;
		queue<TreeNode*> node_queue1;
		node_queue.push(root);
		TreeNode* temp;
		int count;
		while(1){
			count=0;
			while(node_queue.size()){
				temp=node_queue.front();
				node_queue.pop();
				if(temp==NULL){
					if(result.size()){
						result+=",null";
					}else{
						result+="[null";
					}
				}else{
					if(result.size()){
						result+=",";
					}else{
						result+="[";
					}
					sprintf(c,"%d",temp->val);
					result+=c;
					if(temp->left)count++;
					if(temp->right)count++;
					node_queue1.push(temp->left);
					node_queue1.push(temp->right);
				}
			}
			if(count==0)break;
			count=0;
			while(node_queue1.size()){
				temp=node_queue1.front();
				node_queue1.pop();
				if(temp==NULL){
					if(result.size()){
						result+=",null";
					}else{
						result+="[null";
					}
				}else{
					if(result.size()){
						result+=",";
					}else{
						result+="[";
					}
					sprintf(c,"%d",temp->val);
					result+=c;
					if(temp->left)count++;
					if(temp->right)count++;
					node_queue.push(temp->left);
					node_queue.push(temp->right);
				}
			}
		}
		
		result+="]";
		return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		if(data.size()==2) return NULL;

        TreeNode* result=NULL;
		vector<TreeNode*> node_vec;

		char curc;
		string temps="";
		int tempv=0;
		bool isneg=false;
		FOR(i,data.size()){
			curc=data[i];
			if(curc=='[')continue;
			else if(curc=='-')isneg=true;
			else if(curc==','){
				if(temps.size()){
					temps="";
					node_vec.push_back(NULL);
				}else if(isneg){
					isneg=false;
					TreeNode* node=(TreeNode*) new TreeNode(-tempv);
					node_vec.push_back(node);
					tempv=0;
				}else{
					TreeNode* node=(TreeNode*) new TreeNode(tempv);
					node_vec.push_back(node);
					tempv=0;
				}
			}else if(curc>='0' && curc<='9'){
				tempv=10*tempv+curc-'0';
			}else if(curc==']'){
				if(temps.size()){
					temps="";
					node_vec.push_back(NULL);
				}else if(isneg){
					isneg=false;
					TreeNode* node=(TreeNode*) new TreeNode(-tempv);
					node_vec.push_back(node);
					tempv=0;
				}else{
					TreeNode* node=(TreeNode*) new TreeNode(tempv);
					node_vec.push_back(node);
					tempv=0;
				}
			}else{
				temps+=curc;
			}
		}

		result=node_vec[0];
		queue<TreeNode*> node_queue;
		node_queue.push(node_vec[0]);
		int ii=0;
		while(ii+2<node_vec.size()){
			TreeNode* temp=node_queue.front();
			node_queue.pop();
			temp->left=node_vec[ii+1];
			temp->right=node_vec[ii+2];
			if(node_vec[ii+1]) node_queue.push(node_vec[ii+1]);
			if(node_vec[ii+2]) node_queue.push(node_vec[ii+2]);
			ii+=2;
		}
		return result;
    }
};


void let_297(){
	TreeNode* root=(TreeNode*) new TreeNode(1);
	TreeNode* node1=(TreeNode*) new TreeNode(2);
	TreeNode* node2=(TreeNode*) new TreeNode(3);
	TreeNode* node3=(TreeNode*) new TreeNode(4);
	TreeNode* node4=(TreeNode*) new TreeNode(5);
	/*root->left=node1;
	root->right=node2;
	node2->left=node3;
	node2->right=node4;*/
	Codec temp;
	string s=temp.serialize(root);
	cout<<s<<endl;
	TreeNode* result=temp.deserialize(s);
	cout<<result->val<<endl;
}