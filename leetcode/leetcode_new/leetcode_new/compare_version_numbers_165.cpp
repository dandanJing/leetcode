#include"top.h"

int Solution::compareVersion(string version1, string version2){
	int pos1=-1,pos2=-1,val1,val2;
	int last_pos1=-1,last_pos2=-1;
	while(1){
		pos1=version1.find('.',last_pos1+1);
		pos2=version2.find('.',last_pos2+1);
		val1=val2=0;
		if(pos1==-1)pos1=version1.size();
		if(pos2==-1)pos2=version2.size();
		for(int i=last_pos1+1;i<pos1;i++){
			val1=10*val1+version1[i]-'0';
		}
		for(int i=last_pos2+1;i<pos2;i++){
			val2=10*val2+version2[i]-'0';
		}
		if(val1>val2)return 1;
		if(val1<val2)return -1;
		if(pos1==version1.size()&&pos2==version2.size()) break;

		last_pos1=pos1;
		last_pos2=pos2;
	}
	return 0;
}

void let_165(){
	Solution sol;
	cout<<sol.compareVersion("2","1.2")<<endl;
	cout<<sol.compareVersion("0.1","0.1.1")<<endl;
}