#include"top.h"

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs){
	vector<vector<string>> result;
	std::map<string,vector<string>> map_str;
	std::map<string,vector<string>>::iterator it;

	string cur_str;
	string md_str;
	FOR(i,strs.size()){
		cur_str=strs[i];
		md_str=cur_str;
		FOR(j,cur_str.size()){
			int kk;
			char tc=md_str[j];
			for(kk=j-1;kk>=0;kk--){
				if(md_str[kk]>tc)md_str[kk+1]=md_str[kk];
				else break;
			}
			md_str[kk+1]=tc;
		}
		it=map_str.find(md_str);
		if(it==map_str.end()){
			vector<string> tmp_vec;
			tmp_vec.push_back(cur_str);
			map_str.insert(pair<string,vector<string>>(md_str,tmp_vec));
		}else{
			it->second.push_back(cur_str);
		}
	}
	for(it=map_str.begin();it!=map_str.end();it++){
		vector<string>temp=it->second;
		for(int ii=1;ii<temp.size();ii++){
			string cur=temp[ii];
			int jj;
			for(jj=ii-1;jj>=0;jj--){
				if(temp[jj]>cur)temp[jj+1]=temp[jj];
				else break;
			}
			temp[jj+1]=cur;
		}
		result.push_back(temp);
	}
	
	return result;
}
//bool isAnagram(string str1, string str2){
//	int aph[26];
//	FOR(i,26)aph[i]=0;
//	FOR(i,str1.size())aph[str1[i]-'a']++;
//	FOR(i,str2.size()){
//		aph[str2[i]-'a']--;
//		if(aph[str2[i]-'a']<0)return false;
//	}
//	return true;
//}

//vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
//	vector<vector<string>> result;
//	vector<bool>find_vec;
//	FOR(i,strs.size()){
//		find_vec.push_back(false);
//	}
//	FOR(i,strs.size()){
//		if(find_vec[i])continue;
//		else{
//			vector<string>temp;
//			for(int j=i+1;j<strs.size();j++){
//				if(strs[j].size()!=strs[i].size())continue;
//				if(isAnagram(strs[j],strs[i])){
//					find_vec[j]=true;
//					temp.push_back(strs[j]);
//				}
//			}
//			find_vec[i]=true;
//			temp.push_back(strs[i]);
//			for(int ii=1;ii<temp.size();ii++){
//				string cur=temp[ii];
//				int jj;
//				for(jj=ii-1;jj>=0;jj--){
//					if(temp[jj]>cur)temp[jj+1]=temp[jj];
//					else break;
//				}
//				temp[jj+1]=cur;
//			}
//			result.push_back(temp);
//		}
//	}
//
//	return result;
//}

void let_49(){
	vector<string>strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	Solution sol;
	vector<vector<string>> result=sol.groupAnagrams(strs);
	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
}