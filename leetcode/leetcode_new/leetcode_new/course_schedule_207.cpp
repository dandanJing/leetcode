#include"top.h"
extern char c[1000];

bool canFindCicle(vector<bool>& exist_vec,vector<vector<int>> list,int start_pos, map<int,int> contain){
	if(start_pos>=list.size()) return false;
	if(exist_vec[start_pos]) {map<int,int> no_vec;return canFindCicle(exist_vec,list,start_pos++,no_vec);}

	map<int,int>::iterator it;
	it=contain.find(start_pos);
	if(it!=contain.end()) return true;
	
	vector<int> temp=list[start_pos];
	FOR(i,temp.size()){
		int cur_pos=temp[i];
		if(exist_vec[cur_pos])continue;
		else{
			map<int,int> no_vec(contain);
			no_vec.insert(pair<int,int>(start_pos,1));
			if(canFindCicle(exist_vec,list,cur_pos,no_vec)) return true;
		}
	}

	exist_vec[start_pos]=true;
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
	queue<int> exist_queue;
	map<int,int> contain;
	map<int,int>::iterator it;
	for(int i=min_val;i<numCourses;i++){
		if(i==605){
			int mm=1;
		}
		if(exist_vec[i]) continue;
		vector<int> temp=list[i];

		if(temp.size()==0) continue;

		FOR(j,temp.size())exist_queue.push(temp[j]);
		exist_vec[i]=true;
		sprintf(c,"%i",i);
		string output="";
		output += c;
		
		contain.insert(pair<int,int>(i,1));

		while(1){
			vector<int> next_queue;
			vector<int> next_contain;
			while(exist_queue.size()){
				vector<int> temp=list[exist_queue.front()];
				FOR(j,temp.size()){
					if(contain.find(temp[j]) != contain.end()) {
						cout<<output<<endl;
						return false;
					}
					else {next_queue.push_back(temp[j]);}
				}
				exist_vec[exist_queue.front()]=true;
				next_contain.push_back(exist_queue.front());
				exist_queue.pop();
			}
			if(next_queue.size()==0) break;

			output += "->";
			FOR(j,next_contain.size()){
				sprintf(c,"%i ",next_contain[j]);
				output += c;
				contain.insert(pair<int,int>(next_contain[j],1));
			}

			FOR(j,next_queue.size()){
				exist_queue.push(next_queue[j]);
			}		
		}
		contain.clear();
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