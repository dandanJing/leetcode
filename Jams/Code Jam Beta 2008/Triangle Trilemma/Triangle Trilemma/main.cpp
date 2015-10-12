<<<<<<< HEAD
#include<iostream>
#include<fstream>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
int isTriangle(int *x, int *y);//判断是否是三角形
int isScalene(int *x, int *y);

int main(){
	FILE* fp=fopen("test.txt","r");
	freopen("out.txt","w",stdout);
	if(fp){
		int N;fscanf(fp,"%i",&N);
		int x[3],y[3];
		FOR(i,N){
			FOR(k,3) fscanf(fp,"%i %i",&x[k],&y[k]);

			int x12=x[0]-x[1];
			int x23=x[1]-x[2];
			int y12=y[0]-y[1];
			int y23=y[1]-y[2];
			int x13=x[0]-x[2];
			int y13=y[0]-y[2];

			
			//下面判断是不是三角形
			if(y23*x12==y12*x23) {cout<<"Case #"<<i+1<<": not a triangle"<<endl;continue;}
			else cout<<"Case #"<<i+1<<": ";

			int edge12=x12*x12+y12*y12;
			int edge13=x13*x13+y13*y13;
			int edge23=x23*x23+y23*y23;
			
			//判断是否是等腰三角形
			if(edge12==edge13 || edge13==edge23 || edge12==edge23) cout<<"isosceles ";
			else cout<<"scalene ";

			//判断是否是直角三角形/锐角三角形/钝角三角形
			int maxedge,smalledge1,smalledge2;
			if(edge12>edge13 && edge12>edge23){
				maxedge=edge12;smalledge1=edge13;smalledge2=edge23;
			}else if(edge13>edge12 && edge13>edge23){
				maxedge=edge13;smalledge1=edge12;smalledge2=edge23;
			}else{
				maxedge=edge23;smalledge1=edge12;smalledge2=edge13;
			}
			if(maxedge==smalledge1+smalledge2) cout<<"right ";
			else if(maxedge>smalledge1+smalledge2) cout<<"obtuse ";
			else cout<<"acute ";

			cout<<"triangle"<<endl;
		}
	}
	fclose(fp);
	fclose(stdout);

	printf("\n\t press any key to continue...");
	//getchar();
	return 0;
=======
#include<iostream>
#include<fstream>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
int isTriangle(int *x, int *y);//判断是否是三角形
int isScalene(int *x, int *y);

int main(){
	FILE* fp=fopen("test.txt","r");
	freopen("out.txt","w",stdout);
	if(fp){
		int N;fscanf(fp,"%i",&N);
		int x[3],y[3];
		FOR(i,N){
			FOR(k,3) fscanf(fp,"%i %i",&x[k],&y[k]);

			int x12=x[0]-x[1];
			int x23=x[1]-x[2];
			int y12=y[0]-y[1];
			int y23=y[1]-y[2];
			int x13=x[0]-x[2];
			int y13=y[0]-y[2];

			
			//下面判断是不是三角形
			if(y23*x12==y12*x23) {cout<<"Case #"<<i+1<<": not a triangle"<<endl;continue;}
			else cout<<"Case #"<<i+1<<": ";

			int edge12=x12*x12+y12*y12;
			int edge13=x13*x13+y13*y13;
			int edge23=x23*x23+y23*y23;
			
			//判断是否是等腰三角形
			if(edge12==edge13 || edge13==edge23 || edge12==edge23) cout<<"isosceles ";
			else cout<<"scalene ";

			//判断是否是直角三角形/锐角三角形/钝角三角形
			int maxedge,smalledge1,smalledge2;
			if(edge12>edge13 && edge12>edge23){
				maxedge=edge12;smalledge1=edge13;smalledge2=edge23;
			}else if(edge13>edge12 && edge13>edge23){
				maxedge=edge13;smalledge1=edge12;smalledge2=edge23;
			}else{
				maxedge=edge23;smalledge1=edge12;smalledge2=edge13;
			}
			if(maxedge==smalledge1+smalledge2) cout<<"right ";
			else if(maxedge>smalledge1+smalledge2) cout<<"obtuse ";
			else cout<<"acute ";

			cout<<"triangle"<<endl;
		}
	}
	fclose(fp);
	fclose(stdout);

	printf("\n\t press any key to continue...");
	//getchar();
	return 0;
>>>>>>> 194f7f9854ba2b4239e312aded309268c3e9d1d4
}