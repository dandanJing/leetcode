#include"top.h"
extern char c[1000];
//----!!!错误1，还是没有考虑同级的影响
bool canFindCicle(vector<bool>& exist_vec,vector<vector<int>> list,int start_pos, map<int,int> contain){
	if(start_pos>=list.size()) return false;

	vector<int> temp=list[start_pos];
	if(temp.size()==0) return false;

	contain.insert(pair<int,int>(start_pos,1));
	exist_vec[start_pos]=true;
	map<int,int>::iterator it;
	FOR(i,temp.size()){
		int cur_pos=temp[i];
		it=contain.find(cur_pos);
		if(it!=contain.end()) return true;
		else{
			if(canFindCicle(exist_vec,list,cur_pos,contain)) return true;
		}
	}

	return false;
}

bool Solution::canFinish(int numCourses, vector<pair<int, int>>& prerequisites){
	if(prerequisites.size()<=1) return true;

	vector<vector<int>> list;
	vector<bool> exist_vec;
	int min_val=numCourses;
	FOR(i,numCourses){
		exist_vec.push_back(false);
		vector<int> temp;
		list.push_back(temp);
	}
	FOR(i,prerequisites.size()){
		pair<int, int> cur=prerequisites[i];
		list[cur.first].push_back(cur.second);
		if(cur.first<min_val) min_val=cur.first;
	}

	map<int,int> contain;
	for(int i=min_val;i<numCourses;i++){
		if(exist_vec[i]) continue;

		if(canFindCicle(exist_vec,list,min_val,contain)) return false;
	}
	return true;
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