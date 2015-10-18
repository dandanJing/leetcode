#include"top.h"

bool canFindCicle(vector<bool>& exist_vec,vector<vector<int>> list,int start_pos, vector<int> contain){
	if(start_pos>=list.size()) return false;
	if(exist_vec[start_pos]) {vector<int> no_vec;return canFindCicle(exist_vec,list,start_pos++,no_vec);}

	FOR(i,contain.size()){
		if(start_pos==contain[i]) return true;
	}
	vector<int> temp=list[start_pos];
	FOR(i,temp.size()){
		int cur_pos=temp[i];
		if(exist_vec[cur_pos])continue;
		else{
			vector<int> no_vec(contain);
			no_vec.push_back(start_pos);
			if(canFindCicle(exist_vec,list,cur_pos,no_vec)) return true;
		}
	}

	exist_vec[start_pos]=true;
	return false;
}

bool Solution::canFinish(int numCourses, vector<pair<int, int>>& prerequisites){
	vector<vector<int>> list;
	vector<bool> exist_vec;
	FOR(i,numCourses){
		exist_vec.push_back(false);
		vector<int> temp;
		list.push_back(temp);
	}
	FOR(i,prerequisites.size()){
		pair<int, int> cur=prerequisites[i];
		list[cur.first].push_back(cur.second);
	}
	FOR(i,numCourses){
		if(exist_vec[i]) continue;
		vector<int> no_vec;
		if(canFindCicle(exist_vec,list,i,no_vec)) return true;
	}
	
	return false;
}

void let_207(){
	ifstream fin;
	fin.open("let_207.txt");
	int numCourses;
	fin>>numCourses;
	int val1,val2;
	char c;
	fin>>c>>c;
	vector<pair<int, int>> req;	
	while(fin.peek()!=-1){
		fin>>c;
		fin>>val1>>c>>val2;
		fin>>c;
		fin>>c;
		req.push_back(pair<int,int>(val1,val2));
	}

	Solution sol;
	cout<<sol.canFinish(numCourses,req)<<endl;
}