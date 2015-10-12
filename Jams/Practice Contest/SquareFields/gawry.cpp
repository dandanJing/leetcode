<<<<<<< HEAD
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include"top.h"
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

//Square Fields
int t[15][1<<15];
int gawry() {
	//FILE* fp = fopen("B-small-practice.in","r");
	FILE* fp = fopen("test_in.txt","r");
	int N;fscanf(fp,"%d",&N);
	for(int c=1;c<=N;c++){
		int n,k,x[30],y[30];
		fscanf(fp,"%d %d",&n,&k);
		FOR(i,n) fscanf(fp,"%d %d",&x[i],&y[i]);
		FOR(take,1<<n)if(take){ //在t[1]中存储任意L个点之间在x或者y方向的最大的距离，其中L的个数与标号take中的1的个数相同。
			//也即在k=1时，覆盖任意L个点所需要的最短边长
			int minx=1000000,maxx=-1,miny=1000000,maxy=-1;
			FOR(i,n) if(take&1<<i){
				//cout<<"For: "<<take<<" "<<i<<" "<<(take&1<<i)<<endl;
				minx=minx<x[i]?minx:x[i];
				maxx=maxx>x[i]?maxx:x[i];
				miny=miny<y[i]?miny:y[i];
				maxy=maxy>y[i]?maxy:y[i];
			}
			t[1][take]=(maxx-minx)>(maxy-miny)?(maxx-minx):(maxy-miny);
		}
		for(int kk=2;kk<=k;kk++)FOR(take,1<<n){
			t[kk][take]=t[kk-1][take];
			int temp = 0;
			//cout<<"take "<<take<<":";
			//动态规划思想，当前用kk个正方形覆盖，对于take表示的点而言，假设为L个，其中L为take用2进制表示时1的个数
			//在这L个点中选取i个点用kk-1个正方形覆盖，另外L-i个点用1个箱子覆盖，设i个点的二进制表示为take2
			//则有t[kk][take]=min(t[kk][take],max(t[kk-1][take2],t[1][take-take2]))
			for(int take2=take;take2;take2=(take2-1)&take){
				//cout<<take2<<" ";
				temp=t[kk-1][take-take2]>t[1][take2] ? t[kk-1][take-take2] : t[1][take2];//求t[1][take2]和t[kk-1][take-take2]中的最大值
				t[kk][take]=t[kk][take]<temp ? t[kk][take] : temp;//求t[kk][take]和temp中的最小值
			}
			//cout<<endl<<"kk-take:"<<t[kk][take]<<endl;
		}
		/*FOR(kk,1<<n) {
			cout<<t[OUT_K+1][kk]<<",";
			if(kk%10==9) cout<<endl;
		}
		cout<<endl;*/
		cout<<"Case #"<<c<<": "<<t[k][(1<<n)-1]<<endl;
	}
	fclose(fp);
	
	return 0;
=======
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include"top.h"
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

//Square Fields
int t[15][1<<15];
int gawry() {
	//FILE* fp = fopen("B-small-practice.in","r");
	FILE* fp = fopen("test_in.txt","r");
	int N;fscanf(fp,"%d",&N);
	for(int c=1;c<=N;c++){
		int n,k,x[30],y[30];
		fscanf(fp,"%d %d",&n,&k);
		FOR(i,n) fscanf(fp,"%d %d",&x[i],&y[i]);
		FOR(take,1<<n)if(take){ //在t[1]中存储任意L个点之间在x或者y方向的最大的距离，其中L的个数与标号take中的1的个数相同。
			//也即在k=1时，覆盖任意L个点所需要的最短边长
			int minx=1000000,maxx=-1,miny=1000000,maxy=-1;
			FOR(i,n) if(take&1<<i){
				//cout<<"For: "<<take<<" "<<i<<" "<<(take&1<<i)<<endl;
				minx=minx<x[i]?minx:x[i];
				maxx=maxx>x[i]?maxx:x[i];
				miny=miny<y[i]?miny:y[i];
				maxy=maxy>y[i]?maxy:y[i];
			}
			t[1][take]=(maxx-minx)>(maxy-miny)?(maxx-minx):(maxy-miny);
		}
		for(int kk=2;kk<=k;kk++)FOR(take,1<<n){
			t[kk][take]=t[kk-1][take];
			int temp = 0;
			//cout<<"take "<<take<<":";
			//动态规划思想，当前用kk个正方形覆盖，对于take表示的点而言，假设为L个，其中L为take用2进制表示时1的个数
			//在这L个点中选取i个点用kk-1个正方形覆盖，另外L-i个点用1个箱子覆盖，设i个点的二进制表示为take2
			//则有t[kk][take]=min(t[kk][take],max(t[kk-1][take2],t[1][take-take2]))
			for(int take2=take;take2;take2=(take2-1)&take){
				//cout<<take2<<" ";
				temp=t[kk-1][take-take2]>t[1][take2] ? t[kk-1][take-take2] : t[1][take2];//求t[1][take2]和t[kk-1][take-take2]中的最大值
				t[kk][take]=t[kk][take]<temp ? t[kk][take] : temp;//求t[kk][take]和temp中的最小值
			}
			//cout<<endl<<"kk-take:"<<t[kk][take]<<endl;
		}
		/*FOR(kk,1<<n) {
			cout<<t[OUT_K+1][kk]<<",";
			if(kk%10==9) cout<<endl;
		}
		cout<<endl;*/
		cout<<"Case #"<<c<<": "<<t[k][(1<<n)-1]<<endl;
	}
	fclose(fp);
	
	return 0;
>>>>>>> 194f7f9854ba2b4239e312aded309268c3e9d1d4
}