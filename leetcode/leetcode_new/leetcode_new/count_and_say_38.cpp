#include"top.h"

vector<string> count_vec;
string Solution::countAndSay(int n){
	if(n==0)return "";
	if(count_vec.size()==0){
		count_vec.push_back("1");
		count_vec.push_back("11");
		count_vec.push_back("21");
		//count_vec.push_back("1211");
		//count_vec.push_back("111221");
	}
	if(n<=count_vec.size())return count_vec[n-1];
	string cur_str;
	string nxt_str;
	int temp;
	char cur_char;
	char count_char;
	while(n>count_vec.size()){
		cur_str=count_vec.back();
		cur_char=cur_str[0];
		nxt_str="";
		int pos=1;
		int cur_count=1;
		while(pos<cur_str.size()){
			if(cur_str[pos]==cur_char){cur_count++;pos++;}
			else {
				count_char=cur_count+'0';
				nxt_str+=count_char;
				nxt_str+=cur_char;
				cur_char=cur_str[pos++];
				cur_count=1;
			}
		}
		count_char=cur_count+'0';
		nxt_str+=count_char;
		nxt_str+=cur_char;
		count_vec.push_back(nxt_str);
	}
	return count_vec[n-1];
}

void let_38(){
	Solution sol;
	cout<<sol.countAndSay(1)<<endl;
	cout<<sol.countAndSay(4)<<endl;
	cout<<sol.countAndSay(5)<<endl;
}