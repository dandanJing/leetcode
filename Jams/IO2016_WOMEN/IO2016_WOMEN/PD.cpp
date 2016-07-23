#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<iomanip>
using namespace std;

const string FAIL = "IMPOSSIBLE";
int sec_count[26];
char sec_char[26];
char append_char[26];
class Trie {
public:
	bool isKey;
	Trie* children[26];
	Trie(bool isKey) {
		this->isKey = isKey;
		memset(this->children, 0, sizeof(this->children));
	}
};
void buildTrie(Trie* root, string str);
string findResult(Trie* root, int first, int last);
void PD(bool isSmall){
	ifstream fin;
	ofstream fout;
	if(isSmall) {
		fin.open("D-small-practice-1.in");
		fout.open("D-small-practice-1.out");
	} else {
		fin.open("D-small-practice-2.in");
		fout.open("D-small-practice-2.out");
	}
	if(!fin) {
		cout<<"open file error"<<endl;
		return;
	}	
	int T, N;
	fin>>T;
	for (int i = 0; i < T; i++) {
		fin>>N;

		string strs[50];
		string result = "";
		set<string> str_set;
		for (int j = 0; j < N; j++) {
			fin>>strs[j];
			str_set.insert(strs[j]);
			// find if the password is only one letter
			if(1 == strs[j].size()) result = FAIL;
		}
		if(result == FAIL) {
			fout<<"Case #"<<i+1<<": "<<result<<endl;
			continue;
		}
		// find if the password has a repeated letter
		for (int j = 0; j < N; j++) {
			int count[26] = {0}, temp;
			for(int k = 0; k < strs[j].size(); k++) {
				temp = strs[j][k] - 'A';
				if (++count[temp] > 1){
					str_set.erase(strs[j]);
					break;
				}
			}
		}

		// find if there is a letter to be first or last position
		int first = -1, last = -1;
		char c;
		for(int j = 0; j < 26; j++) {
			sec_count[j] = 0;
			c = j + 'A';
			string cur = "";
			cur += c;
			bool isFirst = true;
			bool isLast = true;
			for(int k = 0; k < 26; k++) {
				if(j == k) continue;
				c = k + 'A';
				string prefix = "";
				prefix += c;
				if(str_set.find(c + cur) == str_set.end()) {
					isFirst = false;
					sec_char[j] = c;
				} else {
					sec_count[j]++;
				}
				if(str_set.find(cur + c) == str_set.end()) {
					isLast = false;
				}
			}
			if(isFirst && isLast) {
				result = FAIL;
			} else if(isFirst) {
				if(-1 == first) first = j;
				else result = FAIL;
			} else if(isLast) {
				if(-1 == last) last = j;
				else result = FAIL;
			}
			if(result == FAIL) {
				break;
			}
		}
		if(result == FAIL) {
			fout<<"Case #"<<i+1<<": "<<result<<endl;
			continue;
		}

		Trie* root = new Trie(false);
		set<string>::iterator it;
		for(it = str_set.begin(); it != str_set.end(); it++) {
			buildTrie(root, *it);
		}
		
		result = findResult(root, first, last);
		fout<<"Case #"<<i+1<<": "<<result<<endl;
	}
	fin.close();
	fout.close();
}

void buildTrie(Trie* root, string str) {
	Trie* pre = root;
	Trie* cur = root;
	
	int temp;
	for (int i = 0; i < str.size(); i++) {
		temp = str[i] - 'A';
		if (!cur->children[temp]) {
			cur->children[temp] = new Trie(false);
		} 
		pre = cur;
		cur = cur->children[temp];
	}
	cur->isKey = true;
}

string helper(Trie* root, vector<Trie*> vc, string result, bool visited[26], int len) {
	if(result.size() == len) return result;

	int size = result.size();
	int append = -1;
	if(size) {
		int last = result[size-1] - 'A';
		if (append_char[last] != '0') {
			append = append_char[last] - 'A';
		}
	}
	for (int i = 0; i < 26; i++) {
		if (visited[i]) continue;
		else if(append != -1 && i != append) continue;

		vector<Trie*> nxt;
		bool succ = true;
		for (int j = 0; j < vc.size(); j++) {
			if(vc[j]->children[i] && vc[j]->children[i]->isKey) {
				succ = false;
				break;
			}
			if(vc[j]->children[i]) nxt.push_back(vc[j]->children[i]);
		}
		if(!succ) continue;
		
		nxt.push_back(root);
		char c = 'A' + i;
		visited[i] = true;
		string temp = helper(root, nxt, result + c, visited, len);
		if (temp != FAIL) return temp;
		visited[i] = false;
	}
	return FAIL;
}

string findResult(Trie* root, int first, int last) {
	bool visited[26];
	for(int i = 0; i < 26; i++) {
		visited[i] = false;
	}
	int len = 26;
	vector<Trie*> vc;
	vc.push_back(root);
	
	string temp = "";
	if(first >= 0) {
		visited[first] = true;
		Trie* cur = root->children[first];
		if(cur) vc.push_back(cur);
		char c = 'A' + first;
		temp += c;
	}
	if(last >= 0) {
		visited[last] = true;
		len--;
	}
	
	for(int i = 0; i < 26; i++) {
		append_char[i] = '0';
	}
	for(int i = 0; i < 26; i++) {
		if(sec_count[i] == 24) {
			append_char[sec_char[i]-'A'] = 'A' + i;
		}
	}
	
	temp =  helper(root, vc, temp, visited, len);
	if (last >= 0) {
		char c = 'A' + last;
		temp += c;
	}
	return temp;
} 