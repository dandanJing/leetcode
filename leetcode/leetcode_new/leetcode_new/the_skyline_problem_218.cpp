#include"top.h"

//-----!!!错误1：[[0,2,3],[2,5,3]],期望输出[0,3],[5,0]
//----!!!错误2:[[1,2,1],[1,2,2],[1,2,3]]，期望输出[1,3],[2,0]
//----!!!错误3：[[0,5,7],[5,10,7],[5,10,12],[10,15,7],[15,20,7],[15,20,12],[20,25,7]]，期望输出[[0,7],[5,12],[10,7],[15,12],[20,7],[25,0]]
//--测试序列期望输出： [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]
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
					if(next[0]>temp_build[1]) break;//--!!!不能取等号，否则将跳过相等的情形
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
			pair<int,int> last=result[result_count-1];
			if(last.first==buildings[i][0] && buildings[i][2]>last.second){
				result.pop_back();
				result.push_back(pair<int,int>(buildings[i][0],buildings[i][2]));
			}else if(last.first!=buildings[i][0]){
				result.push_back(pair<int,int>(buildings[i][0],buildings[i][2]));
				result_count++;
			}
				
		}
		//插入排序
		int insert_pos=0;
		bool isInsert=true;//--!!!---需要判断是否插入
		for(insert_pos=pos_array_count-1;insert_pos>=0;insert_pos--){
			int pos=pos_array[insert_pos];
			vector<int> next=buildings[pos];
			if(next[1]>=cur_build[1] && next[2]>=cur_build[2]) {isInsert=false;break;}

			if(next[1]>cur_build[1]){continue;}
			else{break;}
		}
		if(isInsert){
			for(int kk=pos_array_count-1;kk>insert_pos;kk--){
				pos_array[kk+1]=pos_array[kk];
			}
			pos_array[insert_pos+1]=i;
			pos_array_count++;
		}
		
	}

	for(int j=0;j<pos_array_count;j++){
		temp_pos=pos_array[j];
		temp_build=buildings[temp_pos];
		needPush=true;
		int height=0;
		for(int k=j+1;k<pos_array_count;k++){
			int pos=pos_array[k];
			vector<int> next=buildings[pos];
			if(next[0]>temp_build[1]) break;
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

	//错误1
	vector<int> temp1;
	temp1.push_back(0);
	temp1.push_back(2);
	temp1.push_back(3);
	vector<int> temp2;
	temp2.push_back(2);
	temp2.push_back(5);
	temp2.push_back(3);
	builds.push_back(temp1);
	builds.push_back(temp2);

	//错误2
	/*vector<int> temp1;
	temp1.push_back(1);
	temp1.push_back(2);
	temp1.push_back(1);
	vector<int> temp2;
	temp2.push_back(1);
	temp2.push_back(2);
	temp2.push_back(2);
	vector<int> temp3;
	temp3.push_back(1);
	temp3.push_back(2);
	temp3.push_back(3);
	builds.push_back(temp1);
	builds.push_back(temp2);
	builds.push_back(temp3);*/

	//错误3
	/*vector<int> temp1;
	temp1.push_back(0);
	temp1.push_back(5);
	temp1.push_back(7);
	vector<int> temp2;
	temp2.push_back(5);
	temp2.push_back(10);
	temp2.push_back(7);
	vector<int> temp3;
	temp3.push_back(5);
	temp3.push_back(10);
	temp3.push_back(12);
	vector<int> temp4;
	temp4.push_back(10);
	temp4.push_back(15);
	temp4.push_back(7);
	vector<int> temp5;
	temp5.push_back(15);
	temp5.push_back(20);
	temp5.push_back(7);
	vector<int> temp6;
	temp6.push_back(15);
	temp6.push_back(20);
	temp6.push_back(12);
	vector<int> temp7;
	temp7.push_back(20);
	temp7.push_back(25);
	temp7.push_back(7);
	builds.push_back(temp1);
	builds.push_back(temp2);
	builds.push_back(temp3);
	builds.push_back(temp4);
	builds.push_back(temp5);
	builds.push_back(temp6);
	builds.push_back(temp7);*/

	//错误4
	//vector<int> temp1;
	//temp1.push_back(533311);
	//temp1.push_back(958802);
	//temp1.push_back(705998);
	//vector<int> temp2;
	//temp2.push_back(565945);
	//temp2.push_back(674881);
	//temp2.push_back(149834);
	//vector<int> temp3;
	//temp3.push_back(615397);
	//temp3.push_back(704261);
	//temp3.push_back(746064);
	//vector<int> temp4;
	//temp4.push_back(624917);
	//temp4.push_back(909316);
	//temp4.push_back(831007);
	//vector<int> temp5;
	//temp5.push_back(788731);
	//temp5.push_back(924868);
	//temp5.push_back(633726);
	//vector<int> temp6;
	//temp6.push_back(791965);
	//temp6.push_back(912123);
	//temp6.push_back(438310);

	//vector<int> temp11;
	//temp11.push_back(503084);
	//temp11.push_back(561197);
	//temp11.push_back(625737);
	//vector<int> temp12;
	//temp12.push_back(502967);
	//temp12.push_back(704582);
	//temp12.push_back(918199);
	//vector<int> temp13;
	//temp13.push_back(436174);
	//temp13.push_back(442141);
	//temp13.push_back(612149);
	//vector<int> temp14;
	//temp14.push_back(397203);
	//temp14.push_back(478094);
	//temp14.push_back(436894);
	//vector<int> temp15;
	//temp15.push_back(382318);
	//temp15.push_back(992082);
	//temp15.push_back(300642);
	//vector<int> temp16;
	//temp16.push_back(368825);
	//temp16.push_back(882642);
	//temp16.push_back(535852);
	//vector<int> temp17;
	//temp17.push_back(329669);
	//temp17.push_back(790525);
	//temp17.push_back(416754);
	//vector<int> temp18;
	//temp18.push_back(316837);
	//temp18.push_back(802148);
	//temp18.push_back(899966);
	///*vector<int> temp15;
	//temp15.push_back();
	//temp15.push_back();
	//temp15.push_back();*/
	//builds.push_back(temp18);
	//builds.push_back(temp17);
	//builds.push_back(temp16);
	//builds.push_back(temp15);
	//builds.push_back(temp14);
	//builds.push_back(temp13);
	//builds.push_back(temp12);
	//builds.push_back(temp11);

	//builds.push_back(temp1);
	//builds.push_back(temp2);
	//builds.push_back(temp3);
	//builds.push_back(temp4);
	//builds.push_back(temp5);
	//builds.push_back(temp6);

	/*vector<int> temp1;
	temp1.push_back(2);
	temp1.push_back(12);
	temp1.push_back(10);
	vector<int> temp2;
	temp2.push_back(3);
	temp2.push_back(7);
	temp2.push_back(15);
	vector<int> temp3;
	temp3.push_back(5);
	temp3.push_back(9);
	temp3.push_back(12);
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
	builds.push_back(temp4);
	builds.push_back(temp5);*/

	Solution sol;
	vector<pair<int, int>> result=sol.getSkyline(builds);
	for(vector<pair<int, int>>::iterator it=result.begin();it<result.end();it++){
		cout<<"("<<it->first<<","<<it->second<<") ";
	}
	cout<<endl;
}