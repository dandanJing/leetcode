#include"top.h"

class TrieNode {
	
public:
    // Initialize your data structure here.
	std::map<string,int>  data[26];
    TrieNode() {
        
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(!word.size()) return;
		int pos=word[0]-'a';

		std::map<string,int>::iterator it;
		it = (this->root->data)[pos].find(word);
		if(it == (this->root->data)[pos].end())
			(this->root->data)[pos].insert(pair<string,int>(word,1));
		else
			it->second++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(!word.size()) return true;
		int pos=word[0]-'a';
		std::map<string,int>::iterator it;
		it = (this->root->data)[pos].find(word);

		if(it == (this->root->data)[pos].end())
			return false;
		else
			return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(!prefix.size()) return true;
		int pos=prefix[0]-'a';

		std::map<string,int>::iterator it;
		for(it=(this->root->data)[pos].begin();it!=(this->root->data)[pos].end();it++){
			string temp=it->first;
			if(temp.find(prefix,0)==0) return true;
		}
		return false;
    }

private:
    TrieNode* root;
};

void let_208(){
	 Trie temp;
	 temp.insert("ab");
	 temp.insert("bc");
	 temp.insert("cd");
	 cout<<temp.search("a")<<endl;
	 cout<<temp.startsWith("a")<<endl;
	 cout<<temp.startsWith("c")<<endl;
	 cout<<temp.startsWith("d")<<endl;
}