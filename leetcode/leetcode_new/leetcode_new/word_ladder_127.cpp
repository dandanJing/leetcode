#include"top.h"

vector<vector<string>> Solution::ladderLength(string beginWord, string endWord, std::map<string,int>& wordList){
	vector<vector<string>> result;
        if(beginWord.size() == 0 || endWord.size() == 0) return result;
        
        queue<vector<string>> wordQ;
        
        vector<string> vec;
        vec.push_back(beginWord);
        wordQ.push(vec);
        
        vector<string>blank;
        wordQ.push(blank);
        vector<string> clear_vec;
        while(wordQ.size()){
            
            vector<string> tp_vec = wordQ.front();
            wordQ.pop();
            
            if(tp_vec.size()){
                string temp = tp_vec.back();
                for(int i=0; i<temp.size(); i++){
                    char tmp = temp[i];
                    for(char rep='a'; rep<='z'; rep++){
                        temp[i] = rep;
                        if(rep == tmp) continue;
                        else if(temp == endWord){
                            vector<string> add_vec(tp_vec);
                            add_vec.push_back(endWord);
                            result.push_back(add_vec);
                            break;
                        } else{
                            if(wordList.find(temp) != wordList.end()){
                                vector<string> nxt_vec(tp_vec);
                                nxt_vec.push_back(temp);
                                wordQ.push(nxt_vec);
                                clear_vec.push_back(temp);
                            }
                        }
                    }
                    temp[i]=tmp;
                }
            }else if(!result.size() && wordQ.size()){
				for(int i=0;i<clear_vec.size();i++){
					wordList.erase(clear_vec[i]);
				}
				clear_vec.clear();
                wordQ.push(tp_vec);
            }else break;
            
        }
        return result;
}

void let_127(){
	
	std::map<string,int> wordList;
	wordList.insert(pair<string,int>("ted",1));
	wordList.insert(pair<string,int>("tex",1));
	wordList.insert(pair<string,int>("red",1));
	wordList.insert(pair<string,int>("tax",1));
	wordList.insert(pair<string,int>("tad",1));
	wordList.insert(pair<string,int>("den",1));
	wordList.insert(pair<string,int>("rex",1));
	wordList.insert(pair<string,int>("pee",1));
	Solution sol;
	vector<vector<string>> result=sol.ladderLength("red","tax",wordList);
	cout<<result.size()<<endl;
}