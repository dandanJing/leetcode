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
		FOR(take,1<<n)if(take){ //��t[1]�д洢����L����֮����x����y��������ľ��룬����L�ĸ�������take�е�1�ĸ�����ͬ��
			//Ҳ����k=1ʱ����������L��������Ҫ����̱߳�
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
			//��̬�滮˼�룬��ǰ��kk�������θ��ǣ�����take��ʾ�ĵ���ԣ�����ΪL��������LΪtake��2���Ʊ�ʾʱ1�ĸ���
			//����L������ѡȡi������kk-1�������θ��ǣ�����L-i������1�����Ӹ��ǣ���i����Ķ����Ʊ�ʾΪtake2
			//����t[kk][take]=min(t[kk][take],max(t[kk-1][take2],t[1][take-take2]))
			for(int take2=take;take2;take2=(take2-1)&take){
				//cout<<take2<<" ";
				temp=t[kk-1][take-take2]>t[1][take2] ? t[kk-1][take-take2] : t[1][take2];//��t[1][take2]��t[kk-1][take-take2]�е����ֵ
				t[kk][take]=t[kk][take]<temp ? t[kk][take] : temp;//��t[kk][take]��temp�е���Сֵ
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
		FOR(take,1<<n)if(take){ //��t[1]�д洢����L����֮����x����y��������ľ��룬����L�ĸ�������take�е�1�ĸ�����ͬ��
			//Ҳ����k=1ʱ����������L��������Ҫ����̱߳�
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
			//��̬�滮˼�룬��ǰ��kk�������θ��ǣ�����take��ʾ�ĵ���ԣ�����ΪL��������LΪtake��2���Ʊ�ʾʱ1�ĸ���
			//����L������ѡȡi������kk-1�������θ��ǣ�����L-i������1�����Ӹ��ǣ���i����Ķ����Ʊ�ʾΪtake2
			//����t[kk][take]=min(t[kk][take],max(t[kk-1][take2],t[1][take-take2]))
			for(int take2=take;take2;take2=(take2-1)&take){
				//cout<<take2<<" ";
				temp=t[kk-1][take-take2]>t[1][take2] ? t[kk-1][take-take2] : t[1][take2];//��t[1][take2]��t[kk-1][take-take2]�е����ֵ
				t[kk][take]=t[kk][take]<temp ? t[kk][take] : temp;//��t[kk][take]��temp�е���Сֵ
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