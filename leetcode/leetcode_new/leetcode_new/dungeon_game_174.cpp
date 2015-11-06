#include"top.h"

int Solution::calculateMinimumHP(vector<vector<int>>& dungeon){
	if(dungeon.size()<=0)return 0;
	int size1,size2;
	size1=dungeon.size();
	size2=dungeon[0].size();

	int result=0;
	int temp=0;
	int i=0;int j=0;
	while(i<size1 && j<size2){
		temp+=dungeon[i][j];
		if(temp<result)result=temp;
		if(i==size1-1){
			j++;
		}else if(j==size2-1){
			i++;
		}else if(dungeon[i+1][j]>dungeon[i][j+1]){
			i++;
		}else{
			j++;
		}
	}

	vector<pair<int,int>> pair_vec;
	temp=0;
	int cur_result=1;
	for(int i=0;i<size2;i++){
		if(temp+dungeon[0][i]<result)break;

		temp+=dungeon[0][i];
		if(temp<cur_result)cur_result=temp;
		pair_vec.push_back(pair<int,int>(0,i));
	}
	if(pair_vec.size()==size2){
		bool isTrue=false;
		for(int i=1;i<size1;i++){
			if(temp+dungeon[i][size2-1]<result){isTrue=true;break;}

			temp+=dungeon[i][size2-1];
			if(temp<cur_result)cur_result=temp;
			pair_vec.push_back(pair<int,int>(i,size2-1));
		}
		if(!isTrue && cur_result>result)result=cur_result;
	}
	pair<int,int> cur_pair;
	pair<int,int> pre_pair;
	while(pair_vec.size()){
		if(pair_vec.size()==1){
			cur_pair=pair_vec.back();
			pair_vec.pop_back();
		}else{
			cur_pair=pair_vec.back();
			pre_pair=pair_vec[pair_vec.size()-2];
			temp-=dungeon[cur_pair.first][cur_pair.second];
			pair_vec.pop_back();
			if(pre_pair.first+1!=cur_pair.first && pre_pair.first+1<size1){
				if(temp+dungeon[pre_pair.first+1][pre_pair.second]<result)continue;

				temp+=dungeon[pre_pair.first+1][pre_pair.second];
				pair_vec.push_back(pair<int,int>(pre_pair.first+1,pre_pair.second));
				cur_result=temp;

				bool isBreak=false;
				for(int i=pre_pair.second+1;i<size2;i++){
					if(temp+dungeon[pre_pair.first+1][i]<result){isBreak=true;break;}

					temp+=dungeon[pre_pair.first+1][i];
					pair_vec.push_back(pair<int,int>(pre_pair.first+1,i));
					if(temp<cur_result)cur_result=temp;
				}
				if(!isBreak){
					for(int i=pre_pair.first+2;i<size1;i++){
						if(temp+dungeon[i][size2-1]<result){isBreak=true;break;}

						temp+=dungeon[i][size2-1];
						pair_vec.push_back(pair<int,int>(i,size2-1));
						if(temp<cur_result)cur_result=temp;
					}
					if(!isBreak && cur_result>result)result=cur_result;
				}
			}
		}
	}

	if(result>0) return 0;
	return 1-result;
}

void let_174(){
	ifstream fin;
	fin.open("let_174.txt");
	vector<vector<int>> dungeon;
	int N;fin>>N;
	int value;
	char temp;
	FOR(i,N){
		vector<int> nums;
		while(fin.peek()!=']'){
			fin>>temp>>value;
			nums.push_back(value);
		}
		fin>>temp;
		dungeon.push_back(nums);
	}
	
	Solution sol;
	cout<<sol.calculateMinimumHP(dungeon)<<endl;
}