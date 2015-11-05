#include"top.h"

bool compaStr(string data,string word){
	if(data.size()!=word.size()) return false;

	bool result=true;
	FOR(j,word.size()){
		if(word[j]=='.')continue;
		else if(word[j]==data[j])continue;
		else {result=false; break;}
	}
	if(result) return result;
	
	return false;
}

class WordDictionary {
	vector<string>ones;
	vector<string>data[26*26];
public:

    // Adds a word into the data structure.
    void addWord(string word) {
		if(word.size()==0) return;
		else if(word.size()==1) this->ones.push_back(word);
		else {
			int pos=(word[0]-'a')*26+word[1]-'a';
			this->data[pos].push_back(word);
		}	
    }


    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		if(word.size()==0) return false;
		else if(word.size()==1){
			if(word[0] =='.' && ones.size()) return true;
			else if(word[0]=='.') return false;

			FOR(i,ones.size()){
				if(compaStr(ones[i],word)) return true;
			}
		}else{
			int i_s=0, i_e=26;
			int j_s=0, j_e=26;
			if(word[0]!='.'){
				i_s=word[0]-'a';
				i_e=word[0]-'a'+1;
			}
			if(word[1]!='.'){
				j_s=word[1]-'a';
				j_e=word[1]-'a'+1;
			}
			for(int i=i_s;i<i_e;i++){
				for(int j=j_s;j<j_e;j++){
					vector<string> temp=this->data[i*26+j];
					FOR(k,temp.size()){
						if(compaStr(temp[k],word)) return true;
					}
				}
			}
		}
		return false;

    }
};

void let_211(){
	WordDictionary wordDictionary;
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	cout<<wordDictionary.search("pad")<<endl;
	cout<<wordDictionary.search("bad")<<endl;
	cout<<wordDictionary.search(".ad")<<endl;
	cout<<wordDictionary.search("b..")<<endl;
}