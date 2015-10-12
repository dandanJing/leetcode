#include"top.h"


typedef std::map<string,string> patternStrPair;

bool Solution::wordPattern(string pattern,string str){
	patternStrPair patternStrDic;
	patternStrPair strPatternDic;
	map <string, string>::iterator patternStrIter;

	int str_pos=0;
	string temp_pattern,temp_str;
	FOR(i, pattern.size()){
		temp_pattern=pattern[i];
		patternStrIter=patternStrDic.find(temp_pattern);
		temp_str="";
		while(str_pos < str.size() && str[str_pos++] != ' '){
			temp_str+=str[str_pos-1];
		}
		if(temp_str.size()==0) return false;

		if(patternStrIter==patternStrDic.end()){//�����ڸ�patternԪ��
			patternStrIter=strPatternDic.find(temp_str);
			if(patternStrIter==strPatternDic.end()){//�����ڸ�strԪ��
				patternStrDic.insert(pair<string,string>(temp_pattern,temp_str));
				strPatternDic.insert(pair<string,string>(temp_str,temp_pattern));
			}else{
				return false;
			}
		}else{
			if(patternStrIter->second!=temp_str)return false;
		}
	}
	//����Ƿ�str����
	temp_str="";
	while(str_pos < str.size() && str[str_pos++] != ' '){
		temp_str+=str[str_pos-1];
	}
	if(temp_str.size() > 0) return false;

	return true;
}

void let_290(){
	ifstream fin;
	fin.open("let_290.txt");
	string temp;
	getline(fin,temp); //??-----------------����string�Ĵ���
	ISS is(temp);
	int N;is>>N;
	//int N;fin>>N;
	Solution sol;//??----------------��ô���Բ��������ʹ����Ĺ�������
	string pattern,str;
	FOR(i,N){
		getline(fin,pattern);
		getline(fin,str);
		bool result=sol.wordPattern(pattern,str);
		cout<<result<<endl;
	}
}
