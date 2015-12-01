#include"top.h"

int Solution::minDistance(string word1, string word2){
	if(!word1.size())return word2.size();
    if(!word2.size())return word1.size();
    
	int m=word1.size()+1;
	int n=word2.size()+1;

	int** arr=(int**)new int*[m];
	for(int i=0;i<m;i++) arr[i]=new int[n];

	for(int i=0;i<m;i++) arr[i][0]=i;
	for(int i=1;i<n;i++) arr[0][i]=i;

	int row=1;
	while(row<m && row<n){
		for(int i=row;i<m;i++){
			if(word1[i-1]==word2[row-1]){
				arr[i][row]=arr[i-1][row-1];
			}else{
				int val12=min(arr[i-1][row-1],arr[i][row-1]);
				arr[i][row]=min(val12,arr[i-1][row])+1;
			}
		}
		for(int i=row+1;i<n;i++){
			if(word1[row-1]==word2[i-1]){
				arr[row][i]=arr[row-1][i-1];
			}else{
				int val12=min(arr[row-1][i-1],arr[row-1][i]);
				arr[row][i]=min(val12,arr[row][i-1])+1;
			}
		}
		row++;
	}
	int result=arr[m-1][n-1];
	delete arr;
	return result;
       /* int i=word1.size()-1;
        int j=word2.size()-1;
        if(word1[i]==word2[j])return minDistance(word1.substr(0,i),word2.substr(0,j));
        else{
            int val1=minDistance(word1.substr(0,i),word2.substr(0,j));
            int val2=minDistance(word1.substr(0,i),word2.substr(0,j+1));
            int val3=minDistance(word1.substr(0,i+1),word2.substr(0,j));
            return min(min(val1,val2),val3)+1;
        }
        return 0;*/
}

void let_72(){
	Solution sol;
	//cout<<sol.minDistance("dinit","benz")<<endl;
	cout<<sol.minDistance("dinitrophenylhydrazine","benzalphenylhydrazone")<<endl;
}