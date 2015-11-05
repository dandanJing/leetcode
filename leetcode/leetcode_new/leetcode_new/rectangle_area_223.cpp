#include"top.h"

//----!!!错误1，-1500000001,0,-1500000000,1,1500000000,0,1500000001,1，没有考虑maxx-minx溢出的情况
int Solution::computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
	int minx,maxx,miny,maxy;
	minx = A>E ? A:E;
	miny = B>F ? B:F;
	maxx = C>G ? G:C;
	maxy = D>H ? H:D;

	int result=(C-A)*(D-B)+(G-E)*(H-F);
	if(minx>=maxx)return result;
	else if(miny>=maxy)return result;
	int diffx=maxx-minx;
	int diffy=maxy-miny;

	return result-diffx*diffy;
}

void let_223(){
	Solution sol;
	cout<<sol.computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1)<<endl;
}