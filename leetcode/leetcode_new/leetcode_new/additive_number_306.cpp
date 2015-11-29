#include"top.h"

bool Solution::isAdditiveNumber(string num){
	if(num.size()<3)return false;
        
        vector<vector<float>>num_vec1;
        vector<vector<float>>num_vec2;
        vector<float>temp;
        temp.push_back(num[0]-'0');
        num_vec1.push_back(temp);
        
        int val;
        for(int i=1;i<num.size();i++){
            val=num[i]-'0';
			if(i%2){
				while(num_vec1.size()){
					temp=num_vec1.back();
					num_vec1.pop_back();
				
						if(temp.size()>=3 && temp[temp.size()-1]==temp[temp.size()-2]+temp[temp.size()-3]){
							vector<float>temp2(temp);
							temp2.push_back(val);
							num_vec2.push_back(temp2);
						}else if(temp.size()<3){
							vector<float>temp2(temp);
							temp2.push_back(val);
							num_vec2.push_back(temp2);
						}
			
					if(temp[temp.size()-1]){
						temp[temp.size()-1]=10*temp[temp.size()-1]+val;
						if(temp.size()>=3 && temp[temp.size()-1]<=temp[temp.size()-2]+temp[temp.size()-3]){
							num_vec2.push_back(temp);
						}else if(temp.size()<3) num_vec2.push_back(temp);
					}
				}
				if(!num_vec2.size())return false;
			}else{
				while(num_vec2.size()){
					temp=num_vec2.back();
					num_vec2.pop_back();
					
					if(temp.size()>=3 && temp[temp.size()-1]==temp[temp.size()-2]+temp[temp.size()-3]){
						vector<float>temp2(temp);
						temp2.push_back(val);
						num_vec1.push_back(temp2);
					}else if(temp.size()<3){
						vector<float>temp2(temp);
						temp2.push_back(val);
						num_vec1.push_back(temp2);
					}
					
					if(temp[temp.size()-1]){
						temp[temp.size()-1]=10*temp[temp.size()-1]+val;
						if(temp.size()>=3 && temp[temp.size()-1]<=temp[temp.size()-2]+temp[temp.size()-3]){
							num_vec1.push_back(temp);
						}else if(temp.size()<3) num_vec1.push_back(temp);
					}
					
				}
				if(!num_vec1.size())return false;
			}
        }
        vector<vector<float>> cur_vec=num_vec1;
        if(num.size()%2==0){
            cur_vec=num_vec2;
        }
        
        for(int i=0; i<cur_vec.size();i++){
            temp=cur_vec[i];
            if(temp.size()>=3 && temp[temp.size()-1]==temp[temp.size()-2]+temp[temp.size()-3]) return true;
        }
        return false;
}

void let_306(){
	Solution sol;
	/*cout<<sol.isAdditiveNumber("199100199")<<endl;//1
	cout<<sol.isAdditiveNumber("112358")<<endl;//1
	cout<<sol.isAdditiveNumber("101")<<endl;//1*/
	cout<<sol.isAdditiveNumber("121474836472147483648")<<endl;//1
	
}