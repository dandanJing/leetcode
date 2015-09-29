#include<iostream>
#include"top.h"
using namespace std;

#define FOR(i,n) for (int i=0; i<(int)(n); i++)

int gawry();

int temp_array[15][1<<15];
int main(){
	FILE* fp = fopen("test_in.txt","r");
	int N;fscanf(fp,"%d",&N);//ʵ�����

	FOR(i,N){
		int n,k,x[15],y[15];
		fscanf(fp,"%d %d",&n,&k);
		FOR(j,n) fscanf(fp,"%d %d",&x[j],&y[j]);//���붥������
		int minx,miny,maxx,maxy;
		FOR(j,1<<n){//j�Ķ���������1�ĸ�����Ϊ��ǰѭ����Ҫ���ǵĶ�������1��λ�ü�Ϊ�������Ķ���
			minx=miny=65000;
			maxx=maxy=0;
			FOR(ii,n){
				if(j&(1<<ii)){
					minx = minx < x[ii]? minx : x[ii];
					miny = miny < y[ii]? miny : y[ii];
					maxx = maxx > x[ii]? maxx : x[ii];
					maxy = maxy > y[ii]? maxy : y[ii];
				}
			}
			temp_array[0][j]=(maxx-minx)>(maxy-miny)?maxx-minx:maxy-miny;
		}

		for(int j=1;j<k;j++){
			FOR(ii,1<<n){//ii�Ķ���������1�ĸ�����Ϊ��ǰѭ����Ҫ���ǵĶ�������1��λ�ü�Ϊ�������Ķ���
				int temp=temp_array[j-1][ii],temp1;
				if(ii==15&&j==OUT_K){
					temp1=1;
				}
				for(int jj=ii;jj>0;jj=(jj-1)&ii){//�ܽ�1����ѭ����FOR(jj,ii)��Ϊ��ѭ����ִ���ٶ���ߺܶ࣬�൱�ڽ�O(n^3)��ߵ�O(n^2)
					temp1=temp_array[0][jj]<temp_array[j-1][ii-jj]?temp_array[j-1][ii-jj]:temp_array[0][jj];//����1������ط���Ҫ���������temp_array[0][jj]������temp_array[j-1][jj]
					temp = temp>temp1?temp1:temp;
				}
				temp_array[j][ii]=temp;
			}
		}
		/*FOR(kk,1<<n) {
			cout<<temp_array[OUT_K][kk]<<",";
			if(kk%10==9) cout<<endl;
		}
		cout<<endl;*/
		cout<<"Case #"<<i+1<<":"<<temp_array[k-1][(1<<n)-1]<<endl;
	}

	fclose(fp);

	cout<<"--------------gawry--------------"<<endl;
	gawry();
	printf("\n press any key to exit... \n");
	getchar();
	return 0;
}