#include"top.h"

vector<pair<int, int>> Solution::getSkyline(vector<vector<int>>& buildings){
	vector<pair<int, int>> result;
	if(buildings.size()==0) return result;
	
	int *pos_array=(int *) new int[buildings.size()];
	int pos_array_count=1;
	int result_count=1;
	result.push_back(pair<int,int>(buildings[0][0],buildings[0][2]));
	pos_array[0]=0;

	vector<int> cur_build;
	vector<int> temp_build;
	int temp_pos;
	bool needPush;
	for(int i=1;i<buildings.size();i++){
		cur_build=buildings[i];
		needPush=true;
		int j=0;
		while(j<pos_array_count){
			temp_pos=pos_array[j];
			temp_build=buildings[temp_pos];
			if(temp_build[1]>=cur_build[0] && temp_build[2]>=cur_build[2]){//包含当前矩形的左点
				needPush=false;
				break;
			}else if(cur_build[0]>temp_build[1]){
				int height=0;
				for(int k=j+1;k<pos_array_count;k++){
					int pos=pos_array[k];
					vector<int> next=buildings[pos];
					if(next[0]>=temp_build[1]) break;
					else if(next[1]>temp_build[1]){if(next[2]>height) height=next[2];}
				}
				if(height<temp_build[2]){
					result.push_back(pair<int,int>(temp_build[1],height));
					result_count++;
				}
				for(int k=j;k<pos_array_count-1;k++){
					pos_array[k]=pos_array[k+1];
				}
				pos_array_count--;
			}else{
				j++;
			}
		}
		
		if(needPush){//需要包含当前矩形的左点
			result.push_back(pair<int,int>(buildings[i][0],buildings[i][2]));
			result_count++;
		}
		//插入排序
		int insert_pos=0;
		for(insert_pos=pos_array_count-1;insert_pos>=0;insert_pos--){
			int pos=pos_array[insert_pos];
			vector<int> next=buildings[pos];
			if(next[1]>cur_build[1]){pos_array[insert_pos+1]=pos_array[insert_pos];}
			else{pos_array[insert_pos+1]=i;break;}
		}
		if(insert_pos==-1)pos_array[0]=i;
		pos_array_count++;
	}

	for(int j=0;j<pos_array_count;j++){
		temp_pos=pos_array[j];
		temp_build=buildings[temp_pos];
		needPush=true;
		int height=0;
		for(int k=j+1;k<pos_array_count;k++){
			int pos=pos_array[k];
			vector<int> next=buildings[pos];
			if(next[0]>=temp_build[1]) break;
			else if(next[1]>=temp_build[1] && next[2]>=temp_build[2]){needPush=false;break;}
			else if(next[1]>=temp_build[1] && next[2]>height){height=next[2];}
		}
		if(needPush){
			result.push_back(pair<int,int>(temp_build[1],height));
			result_count++;
		}
	}

	delete pos_array;
	return result;
}

void let_218(){
	vector<vector<int>> builds;
	vector<int> temp1;
	temp1.push_back(2);
	temp1.push_back(9);
	temp1.push_back(10);
	vector<int> temp2;
	temp2.push_back(3);
	temp2.push_back(7);
	temp2.push_back(15);
	vector<int> temp3;
	temp3.push_back(5);
	temp3.push_back(12);
	temp3.push_back(8);
	vector<int> temp4;
	temp4.push_back(15);
	temp4.push_back(20);
	temp4.push_back(10);
	vector<int> temp5;
	temp5.push_back(19);
	temp5.push_back(24);
	temp5.push_back(8);
	builds.push_back(temp1);
	builds.push_back(temp2);
	builds.push_back(temp3);
	/*builds.push_back(temp4);
	builds.push_back(temp5);*/

	Solution sol;
	vector<pair<int, int>> result=sol.getSkyline(builds);
	for(vector<pair<int, int>>::iterator it=result.begin();it<result.end();it++){
		cout<<"("<<it->first<<","<<it->second<<") ";
	}
	cout<<endl;
}