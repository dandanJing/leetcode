#include"top.h"

void findSumValue(std::map<int,int>int_map,vector<int> pos_vec,vector<int> neg_vec,int count1,int count2,vector<vector<int>>& result){
	if(count1>pos_vec.size())return;
	if(count2>neg_vec.size())return;

	std::map<int,int>::iterator it;
	if(count1==1 && count2==1){
		FOR(i,pos_vec.size()){
			if(i && neg_vec[i]==neg_vec[i-1])continue;
			it=int_map.find(-pos_vec[i]);
			if(it!=int_map.end()){
				vector<int>temp_vec;
				temp_vec.push_back(-pos_vec[i]);temp_vec.push_back(0);temp_vec.push_back(pos_vec[i]);
				result.push_back(temp_vec);
			}
		}
	}else if(count1==2){
		int val1;
		FOR(i,pos_vec.size()){
			if(i && pos_vec[i]==pos_vec[i-1])continue;
			for(int i1=i+1;i1<pos_vec.size();i1++){
				if(i1>i+1 && pos_vec[i1]==pos_vec[i])continue;
				val1=pos_vec[i1]+pos_vec[i];
				if(val1+neg_vec[0]>0)break;

				it=int_map.find(-val1);
				if(it!=int_map.end()){
					vector<int>temp_vec;
					temp_vec.push_back(-pos_vec[i]);temp_vec.push_back(pos_vec[i]);temp_vec.push_back(pos_vec[i1]);
					result.push_back(temp_vec);
				}
			}
		}
	}else if(count2==2){
		int val1;
		FOR(i,neg_vec.size()){
			if(i && neg_vec[i]==neg_vec[i-1])continue;
			for(int i1=i+1;i1<neg_vec.size();i1++){
				if(i1>i+1 && neg_vec[i1]==neg_vec[i])continue;
				val1=neg_vec[i1]+neg_vec[i];
				if(val1+pos_vec[0]>0)break;

				it=int_map.find(-val1);
				if(it!=int_map.end()){
					vector<int>temp_vec;
					temp_vec.push_back(neg_vec[i]);temp_vec.push_back(neg_vec[i1]);temp_vec.push_back(-val1);
					result.push_back(temp_vec);
				}
			}
		}
	}
}
void findValue(vector<int> pos_vec,vector<int> neg_vec,int count1,int count2,vector<vector<int>>& result){
	if(count1>pos_vec.size())return;
	if(count2>neg_vec.size())return;
	int temp;
	if(count1==1 && count2==1){
		FOR(i,neg_vec.size()){
			if(i && neg_vec[i]==neg_vec[i-1])continue;
			if(neg_vec[i]+pos_vec[0]>0)continue;

			for(int j=pos_vec.size()-1;j>=0;j--){
				temp=neg_vec[i]+pos_vec[j];
				if(temp<0)break;
				else if(temp==0){
					vector<int>temp_vec;
					temp_vec.push_back(neg_vec[i]);temp_vec.push_back(0);temp_vec.push_back(pos_vec[j]);
					result.push_back(temp_vec);
					break;
				}
			}
		}
	}else if(count1==2){
		int val1;
		FOR(j1,pos_vec.size()-1){
			if(j1 && pos_vec[j1]==pos_vec[j1-1])continue;
			for(int j2=j1+1;j2<pos_vec.size();j2++){
				if(j2>j1+1 && pos_vec[j2]==pos_vec[j1])continue;
				val1=pos_vec[j1]+pos_vec[j2];
				if(val1+neg_vec[0]>0)break;

				for(int i=neg_vec.size()-1;i>=0;i--){
					temp=val1+neg_vec[i];
					if(temp<0)break;
					else if(temp==0){
						vector<int>temp_vec;
						temp_vec.push_back(neg_vec[i]);temp_vec.push_back(pos_vec[j1]);temp_vec.push_back(pos_vec[j2]);
						result.push_back(temp_vec);
						break;
					}
				}
			}
		}
	}else if(count2==2){
		int val1;
		FOR(i1,neg_vec.size()-1){
			if(i1 && neg_vec[i1]==neg_vec[i1-1])continue;
			for(int i2=i1+1;i2<neg_vec.size();i2++){
				if(i2>i1+1 && neg_vec[i2]==neg_vec[i1])continue;
				val1=neg_vec[i1]+neg_vec[i2];
				if(val1+pos_vec[0]>0)break;

				for(int j=pos_vec.size()-1;j>=0;j--){
					temp=val1+pos_vec[j];
					if(temp<0)break;
					else if(temp==0){
						vector<int>temp_vec;
						temp_vec.push_back(neg_vec[i1]);temp_vec.push_back(neg_vec[i2]);temp_vec.push_back(pos_vec[j]);
						result.push_back(temp_vec);
						break;
					}
				}
			}
		}
	}
}

vector<vector<int>> Solution::threeSum(vector<int>& nums){
	//vector<vector<int>> result;
	//vector<int> neg_vec;
	//vector<int> pos_vec;
	//std::map<int,int>int_map;
	//std::map<int,int>::iterator it;
	//int zero_count=0;
	//FOR(i,nums.size()){
	//	if(nums[i]==0)zero_count++;
	//	else if(nums[i]>0)pos_vec.push_back(nums[i]);
	//	else neg_vec.push_back(nums[i]);

	//	/*it=int_map.find(nums[i]);
	//	if(it!=int_map.end())it->second++;
	//	else int_map.insert(pair<int,int>(nums[i],1));*/
	//}
	//FOR(i,pos_vec.size()){
	//	int j,val=pos_vec[i];
	//	for(j=i-1;j>=0;j--){
	//		if(pos_vec[j]>val)pos_vec[j+1]=pos_vec[j];
	//		else break;
	//	}
	//	pos_vec[j+1]=val;
	//}
	//FOR(i,neg_vec.size()){
	//	int j,val=neg_vec[i];
	//	for(j=i-1;j>=0;j--){
	//		if(neg_vec[j]>val)neg_vec[j+1]=neg_vec[j];
	//		else break;
	//	}
	//	neg_vec[j+1]=val;
	//}
	//if(zero_count){
	//	if(zero_count>2){
	//		vector<int>temp;
	//		temp.push_back(0);temp.push_back(0);temp.push_back(0);
	//		result.push_back(temp);
	//	}
	//	//findSumValue(int_map,pos_vec,neg_vec,1,1,result);
	//	findValue(pos_vec,neg_vec,1,1,result);
	//}
	////findSumValue(int_map,pos_vec,neg_vec,2,1,result);
	////findSumValue(int_map,pos_vec,neg_vec,1,2,result);
	//findValue(pos_vec,neg_vec,2,1,result);
	//findValue(pos_vec,neg_vec,1,2,result);
	//return result;
	vector<vector<int>> result;
    	sort(nums.begin(),nums.end());
    	int n=nums.size();
    	FOR(i,n){
    	    if(i && nums[i]==nums[i-1])continue;
    	    int j=i+1;
    	    int k=n-1;
    	    while(j<k){
    	        if(j>i+1 && nums[j]==nums[j-1]){
    	            j++;continue;
    	        }
    	        if(k<n-1 && nums[k]==nums[k+1]){
    	            k--;continue;
    	        }
    	        int twosum=nums[i]+nums[j];
    	        if(twosum+nums[k]<0){
    	            j++;
    	        }else if(twosum+nums[k]>0){
    	            k--;
    	        }else{
    	            vector<int>temp;
    	            temp.push_back(nums[i]);
    	            temp.push_back(nums[j]);
    	            temp.push_back(nums[k]);
					result.push_back(temp);
    	            j++;k--;
    	        }
    	    }
    	}
    	return result;
}

void let_15(){
	ifstream fin;
	fin.open("let_15.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	vector<vector<int>> result=sol.threeSum(nums);
	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
}