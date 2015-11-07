#include"top.h"

bool findLine(vector<Point>& points,int pos1,int pos2,int pos3){
	int diffx1,diffx2;
	int diffy1,diffy2;
	diffx1=points[pos2].x-points[pos1].x;
	diffx2=points[pos3].x-points[pos1].x;
	diffy1=points[pos2].y-points[pos1].y;
	diffy2=points[pos3].y-points[pos1].y;
	if(diffx1==diffx2 && diffy1==diffy2) return true;
	else if(diffx1==0 && diffx2==0)return true;
	else if(diffx1==0 && diffy1==0)return true;
	else if(diffx2==0 && diffy2==0)return true;
	else if(diffx1==0 || diffx2==0) return false;
	else if((float)diffy1/diffx1==(float)diffy2/diffx2)return true;
	else return false;
}

int Solution::maxPoints(vector<Point>& points){
	if(points.size()<=2)return points.size();
	int result=2;
	for(int i=0;i<points.size()-2;i++){
		int count=1;
		for(int j=i+1;j<points.size()-1;j++){
			int temp=count+1;
			if(points[i].x==points[j].x && points[i].y==points[j].y){
				count++;
				continue;
			}
			for(int k=j+1;k<points.size();k++){
				if(findLine(points,i,j,k)) temp++;
			}
			if(temp>result)result=temp;
		}
		if(result<count+1) result=count+1;
	}
	return result;
}

void let_149(){
	vector<Point> points;
	int x,y;
	char cur;
	ifstream fin;
	fin.open("let_149.txt");
	while(fin.peek()!=']'){
		fin>>cur>>x>>cur>>y;
		Point temp(x,y);
		points.push_back(temp);
	}
	Solution sol;
	cout<<sol.maxPoints(points)<<endl;
}