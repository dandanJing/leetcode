#include"top.h"

int Solution::longestConsecutive(vector<int>& nums) {
	if(nums.size() == 0) return 0;
        std::map<int,int> nums_map;
        std::map<int,int>::iterator it;
        std::map<int,int>::iterator it2;

        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            it = nums_map.find(val);
            if(it != nums_map.end()) continue;
            
            for(int j = val - 1; j <= val + 1; j++){
                it = nums_map.find(j);
                
                if(it != nums_map.end()){
                    if(j < val && it->second < j ){
                        int tmp = it->second;
						nums_map.insert(pair<int,int>(val,tmp));
						it = nums_map.find(tmp);
						it->second = val;
                        nums_map.erase(j);
                    }else if(j < val && it->second == j ){
                        it->second = val;
                        nums_map.insert(pair<int,int>(val,j));
                    }else if(j > val && it->second >= j){
						int tmp = it->second;
						it2 = nums_map.find(val);
						int smVal = it2->second;
						int bgVal = it->second;
						it = nums_map.find(bgVal);
						it->second = smVal;
						it = nums_map.find(smVal);
						it->second = bgVal;
						
						if(tmp != j)nums_map.erase(j);
						if(bgVal != val && smVal != val) nums_map.erase(val);
                    }
                }else if(j == val){
                    nums_map.insert(pair<int,int>(j,j));
                }
				if(j == val+1)break;
            }
        }
        
        int result = 1;
        for(it = nums_map.begin(); it != nums_map.end(); it++){
            int tmp = abs(it->second - it->first) + 1;
            if(tmp > result) result = tmp;
        }
        return result;
}

void let_128(){
	ifstream fin;
	fin.open("let_128.txt");
	int value;
	char temp;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.longestConsecutive(nums)<<endl;
}