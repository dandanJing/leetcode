#include"top.h"

int result=0;
int size1,size2;
int calcuResult(vector<vector<int>>& dungeon,int posi,int posj,int temp){
	if(temp<=result) return 0x80000000;

	int cur1=temp,cur2=temp;
	if(posi<size1-1){
		if(dungeon[posi+1][posj]<0) cur1+=dungeon[posi+1][posj];
		if(cur1>result){
			int out1=calcuResult(dungeon,posi+1,posj,temp+dungeon[posi+1][posj]);
			if(out1==0x80000000)cur1=0x80000000;
			else if(cur1>out1) cur1=out1;
		}else{
			cur1=0x80000000;
		}
	}
	if(posj<size2-1){
		if(dungeon[posi][posj+1]<0) cur2+=dungeon[posi][posj+1];
		if(cur2>result){
			int out2=calcuResult(dungeon,posi,posj+1,temp+dungeon[posi][posj+1]);
			if(out2==0x80000000)cur2=0x80000000;
			else if(cur2>out2) cur2=out2;
		}else{
			cur2=0x80000000;
		}
	}
	return max(cur1,cur2);
}

//int Solution::calculateMinimumHP(vector<vector<int>>& dungeon){
//	if(dungeon.size()<=0)return 0;
//	size1=dungeon.size();
//	size2=dungeon[0].size();
//
//	int temp=0;
//	int i=0;int j=0;
//	while(i<size1 && j<size2){
//		temp+=dungeon[i][j];
//		if(temp<result)result=temp;
//		if(i==size1-1){
//			j++;
//		}else if(j==size2-1){
//			i++;
//		}else if(dungeon[i+1][j]>dungeon[i][j+1]){
//			i++;
//		}else{
//			j++;
//		}
//	}
//	int cur=calcuResult(dungeon,0,0,dungeon[0][0]);
//	result=max(cur,result);
//	if(result>0) return 0;
//	else return 1-result;
//}

int Solution::calculateMinimumHP(vector<vector<int>>& dungeon){
	if(dungeon.size()<=0)return 0;
	int size1=dungeon.size();
	int size2=dungeon[0].size();

	//int result;

	/*vector<vector<int>> res;
	FOR(i,size1){
		vector<int>temp;
		FOR(j,size2){
			temp.push_back(0);
		}
		res.push_back(temp);
	}
	res[0][0] = dungeon[0][0];*/
	int * result = (int*) new int[size2];
	for(int i=size1-1; i>=0; i--){
		for(int j=size2-1; j>=0; j--){
			if(i==size1-1 && j==size2-1){
				result[j] = max(1,1-dungeon[i][j]);
			}else if(i==size1-1){
				result[j] = max(1,result[j+1]-dungeon[i][j]);
			}else if(j==size2-1){
				result[j] = max(1,result[j]-dungeon[i][j]);
			}else{
				result[j] = min(result[j+1]-dungeon[i][j],result[j]-dungeon[i][j]);
				if(result[j] <= 0) result[j] = 1;
			}
		}
	}
	return result[0];
	/*vector<vector<int>> mid;
	FOR(i,size1){
		vector<int>temp;
		FOR(j,size2){
			temp.push_back(0x80000000);
		}
		mid.push_back(temp);
	}

	int curi=size1-1,curj=size2-1;
	while(1){
		if()
		for(int i=size1-2;i>curi,i--){

		}
		if(curi==0 && curj==0)break;
	}
	return res[0][0];
	return 5;*/
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