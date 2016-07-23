#include<iostream>
#include<fstream>
using namespace std;
class Trie {
public:
    int count;
    Trie* childs[26];
    Trie() {
        this->count = 1;
        for (int i = 0; i < 26; i++) {
            this->childs[i] = NULL;
        }
    }
};

void insert(Trie* root, string s);
int query(Trie* root, string s);
//int main() {
//    int N;
//	char s[12];
//    Trie* root = new Trie();
//    cin>>N;
//    for (int i = 0; i < N; i++) {
//        cin>>s;
//        insert(root, s);
//    }
//    cin>>N;
//    for (int i = 0; i < N; i++) {
//        cin>>s;
//        cout<<query(root, s)<<endl;
//    }
//}

int main() {
    int N;
	char s[12];
    Trie* root = new Trie();
	ifstream fin("input.txt");
	ofstream fout("output.txt");
    fin>>N;
    for (int i = 0; i < N; i++) {
        fin>>s;
        insert(root, s);
    }
    fin>>N;
    for (int i = 0; i < N; i++) {
        fin>>s;
        fout<<query(root, s)<<endl;
    }
	fin.close();
	fout.close();
}

void insert(Trie* root, string s) {
    Trie* temp = root;
    for (int i = 0; i < s.size(); i++) {
        int val = s[i] - 'a';
        if (temp->childs[val]) {
            temp->childs[val]->count++;
        } else {
            temp->childs[val] = new Trie();
        }
        temp = temp->childs[val];
    }
}

int query(Trie* root, string s) {
    Trie* temp = root;
    int i = 0;
    while (i < s.size() && temp) {
        int val = s[i] - 'a';
        if (temp->childs[val]) {
            temp = temp->childs[val];
        } else break;
        i++;
    }
    if (i < s.size()) return 0;
    else return temp->count;
}