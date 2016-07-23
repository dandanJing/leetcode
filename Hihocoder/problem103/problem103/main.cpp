#include<iostream>
#include<fstream>
using namespace std;

class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node() {
		this->left = NULL;
		this->right = NULL;
	}
	Node(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* query(Node *root, int k);
Node* insert(Node *root, int value);
//Node* leftRotate(Node* t);
//Node* rightRotate(Node* t);
//Node* maintain(Node* root, bool isLeft);

int main() {
	/*ifstream fin("input.txt");
	ofstream fout("output.txt");
	Node *root = NULL;
	int N;
	fin>>N;
	char op;
	int val;
	for (int i = 0; i < N; i++) {
		fin>>op>>val;
		if (op == 'I') {
			root = insert(root, val);
		} else {
			fout<<query(root, val)->val<<endl;
		}
	}
	fin.close();
	fout.close();
	getchar();*/
	//return 0;

	Node *root = NULL;
	int N;
	cin>>N;
	char op;
	int val;
	for (int i = 0; i < N; i++) {
		cin>>op>>val;
		if (op == 'I') {
			root = insert(root, val);
		} else {
			cout<<query(root, val)->val<<endl;
		}
	}

	return 0;
}

Node* insert(Node *root, int value) {
	if (root == NULL) {
		root = new Node(value);
	} else if (root->val < value) {
		root->right = insert(root->right, value);
	} else {
		root->left = insert(root->left, value);
	}
	//maintain(root, root->val >= value);
	return root;
}


//Node* maintain(Node* root, bool isLeft) {
//	if (root == NULL) return NULL;
//
//	bool is_change = false;
//	if (isLeft) {
//		int left = root->left ? root->left->s : 0;
//		int right_right = (root->right && root->right->right) ? root->right->right->s : 0;
//		int right_left = (root->right && root->right->left) ? root->right->left->s : 0;
//		if (right_right > left) {
//			root = leftRotate(root);
//			is_change = true;
//		} else if (right_left > left) {
//			root->right = rightRotate(root->right);
//			root = leftRotate(root);
//			is_change = true;
//		}
//	} else {
//		int right = root->right ? root->right->s : 0;
//		int left_left = (root->left && root->left->left) ? root->left->left->s  : 0;
//		int left_right = (root->left && root->left->right) ? root->left->right->s : 0;
//		if (left_left > right) {
//			root = rightRotate(root);
//			is_change = true;
//		} else if (left_right > right) {
//			root->left = leftRotate(root->left);
//			root = rightRotate(root);
//			is_change = true;
//		}
//	}
//	if (is_change) {
//		root->left = maintain(root->left, false);
//		root->right = maintain(root->right, true);
//		root = maintain(root, false);
//		root = maintain(root, true);
//	}
//	
//	return root;
//}
//
//Node* leftRotate(Node* t) {
//	if (t == NULL || t->left == NULL) return t;
//
//	Node *root = t->right;
//	t->right = root->left;
//	root->left = t;
//	root->s = t->s;
//	t->s = (t->left ? t->left->s : 0) + (t->right ? t->right->s : 0) + 1;
//	return root;
//}
//
//Node* rightRotate(Node* t) {
//	if (t == NULL || t->left == NULL) return t;
//
//	Node *root = t->left;
//	t->left = root->right;
//	root->right = t;
//	root->s = t->s;
//	t->s = (t->left ? t->left->s : 0) + (t->right ? t->right->s : 0) + 1;
//	return root;
//}

Node* query(Node *root, int k) {
	if (root == NULL) return NULL;
	else if (k == root->val) return root;
	else if (k < root->val) return query(root->left, k);
	else {
		Node* result = query(root->right, k);
		if (result == NULL) return root;
		else return result;
	}
}