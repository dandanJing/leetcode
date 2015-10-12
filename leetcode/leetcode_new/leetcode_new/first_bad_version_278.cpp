#include"top.h"

bool isBadVersion(int version);

int bad_first;
int Solution::firstBadVersion(int n){
	if(!isBadVersion(n)) return -1;
	if(isBadVersion(1)) return 1;

	int result=-1;
	int start_pos=1;
	int end_pos=n;
	int middle;
	while(1){
		if(start_pos==end_pos) return start_pos;

		middle=(end_pos+start_pos)/2;
		if (middle<0) middle=end_pos/2+start_pos/2;

		if(isBadVersion(middle)){ 
			if(middle==end_pos) middle--;
			end_pos=middle;
		}else {
			if(middle==start_pos)middle++;
			start_pos=middle;
		}
	}
	return result;
}

bool isBadVersion(int version){
	if(version>=bad_first) return true;
	return false;
}

void let_278(){
	int N=1;
	int n=1420736637;
	Solution sol;
	FOR(i,N){
		bad_first=rand()%n+1;
		bad_first=1150769282;
		cout<<"Case "<<i+1<<": "<<bad_first<<"->";
		cout<<sol.firstBadVersion(n)<<endl;
	}
}