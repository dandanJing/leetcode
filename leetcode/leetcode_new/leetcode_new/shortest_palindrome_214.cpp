#include"top.h"
bool isPalin(string s){
	if(s.size() <= 1) return true;
	for(int i=0; i<s.size()/2; i++){
		if(s[i] != s[s.size()-1-i]) return false;
	}
	return true;
}
string Solution::shortestPalindrome(string s){
	if(s.size()==0) return s;
	if(isPalin(s)) return s;

	int len = s.size();
	string s_rev;
	s_rev.replace(s_rev.begin(),s_rev.end(),s.rbegin(),s.rend());

	int pos = s_rev.find(s[0]);
	while(pos != -1){
		string tmp = s.substr(0,len-pos);
		if(isPalin(tmp)){
			string result = s_rev.substr(0,pos);
			result += s;
			return result;
		}
		pos = s_rev.find(s[0],pos+1);
	}
	return "";
}

int compare(int a, int b) {
        int base1 = 1;
        while (a / 10 >= base1) {
            base1 *= 10;
        }
        int base2 = 1;
        while (b / 10 >= base2) {
            base2 *= 10;
        }
        int val1, val2;
        while (base1 && base2) {
            val1 = a / base1;
            val2 = b / base2;
            if (val1 > val2) return 1;
            else if (val1 < val2) return -1;
            a %= base1;
            b %= base2;
            base1 /= 10;
            base2 /= 10;
        }
        if (base1) {
			return -1;
		}
        if (base2) return 1;
        return 0;
    }
    string largestNumber(vector<int> &num) {
        // write your code here
        if (num.size() == 0) return 0;
        for (int i = 1; i < num.size(); i++) {
            int temp = num[i];
            int j;
            for(j = i - 1; j >= 0; j--) {
                if (compare(num[j], temp) >= 0) break;
                else num[j + 1] = num[j];
            }
            num[j + 1] = temp;
        }
        string res = "";
        for (int i = 0; i < num.size(); i++) {
            int temp = num[i];
            string cur = "";
            while (temp) {
                char c = (temp % 10) + '0';
                cur = c + cur;
                temp /= 10;
            }
            res += cur;
        }
        if (res.size() == 0) return "0";
        return res;
    }
int longestConsecutive(vector<int> &num) {
        // write you code here
        if (num.size() == 0) return 0;
        std::map<int,int> mp;
        std::map<int,int>::iterator it;
        int result = 1;
        for (int i = 0; i < num.size(); i++) {
            if (mp.find(num[i]) == mp.end()) {
                it = mp.find(num[i] - 1);
                bool isfind = false;
                int next = num[i] - 1;
                if (it != mp.end()) {
                    if (it->second >= num[i]) continue;
                    else if (it->second == num[i] - 1) {
                        it->second = num[i];
                        mp.insert(pair<int,int>(num[i], num[i] - 1));
                        result = max(result, 2);
                    } else {
                        next = it->second;
                        mp.erase(num[i] - 1);
                        mp.insert(pair<int,int>(num[i], next));
                        it = mp.find(next);
                        it->second = num[i];
                        result = max(result, num[i] - next + 1);
                    }
                    isfind = true;
                }
                it = mp.find(num[i] + 1);
                if (it != mp.end()) {
                    if (it->second <= num[i]) continue;
                    else if (isfind) {
                        int high = it->second;
                        if (high == num[i] + 1) {
                            it->second = next;
                            mp.erase(num[i]);
							it = mp.find(next);
							it->second = high;
                        } else {
                            mp.erase(num[i] + 1);
							mp.erase(num[i]);
							it = mp.find(next);
							it->second = high;
                            it = mp.find(high);
                            it->second = next;
                        }
                        result = max(result, high - next + 1);
                    } else if (it->second == num[i] + 1){
                        it->second = num[i];
                        mp.insert(pair<int,int>(num[i], num[i] + 1));
                        result = max(result, 2);
                    } else {
                        int high = it->second;
                        mp.erase(num[i] + 1);
                        mp.insert(pair<int,int>(num[i], high));
                        it = mp.find(high);
                        it->second = num[i];
                        result = max(result, high - num[i] + 1);
                    }
                    isfind = true;
                }
                if (!isfind) {
                    mp.insert(pair<int,int>(num[i], num[i]));
                }
            } 
        }
        return result;
    }
 vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> result;
        int len = s.size();
        if (len < 4 || len > 12) return result;
        
        int val1, val2, val3, val4;
        for (int i = 1; i <= 3; i++) {
            if (s[0] == '0' && i > 1) continue;
            val1 = atoi(s.substr(0, i).c_str());
            if (val1 > 255) continue;
            
            for (int j = i + 1; j <= min(i + 3, len - 2); j++) {
                if (s[i] == '0' && j > i + 1) continue;
                val2 = atoi(s.substr(i, j).c_str());
                if (val2 > 255) continue;
                
                for (int k = j + 1; k <= min(j + 3, len - 1); k++) {
                    if (s[j] == '0' && k > j + 1) continue;
                    if (s[k] == '0' && k < len - 1) continue;
                    val3 = atoi(s.substr(j, k).c_str());
                    val4 = atoi(s.substr(k).c_str());
                    if (val3 > 255 || val4 > 255) continue;
                    
                    string temp = s;
                    temp.insert(temp.begin() + i, '.');
                    temp.insert(temp.begin() + j + 1, '.');
                    temp.insert(temp.begin() + k + 2, '.');
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
void let_214(){
	string s = "002500";
	restoreIpAddresses(s);
	/*Solution sol;
	cout<<sol.shortestPalindrome("abcd")<<endl;*/
	vector<int>num;
	num.push_back(4);
	num.push_back(0);
	num.push_back(-4);
	num.push_back(-2);
	num.push_back(2);
	num.push_back(5);
	num.push_back(2);
	num.push_back(0);
	num.push_back(-8);
	num.push_back(-1);
	num.push_back(7);
	num.push_back(4);
	num.push_back(5);
	num.push_back(-4);
	num.push_back(6);
	num.push_back(6);
	num.push_back(-3);
	int result = longestConsecutive(num);
	for (int i = 0; i < num.size(); i++) cout<<num[i]<<",";
	num.push_back(5);
	num.push_back(13);
	largestNumber(num);
}