<<<<<<< HEAD
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define PATHMAXNUM 50
#define CITYMAXNUM 100

typedef std::map<string, int> mapStrToInt;
int pathAppearSet[PATHMAXNUM];
float pathFreqSet[PATHMAXNUM];
int malcin();

struct pathNode{//路径链表
	int toCity;
	int pathLen;
	int pathIndex;
	pathNode* next;
};

pathNode* pathSets[CITYMAXNUM];

void DeleteList(pathNode* L){ //清空列表
	  pathNode* p, *tmp;
	  p = L->next;
	  L->next=NULL;
	  while(p!=NULL){
		  tmp = p->next;
		  delete p;
		  p=tmp;
	  }
}

void InsertNode(pathNode* L,int toCity, int pathLen,int pathIndex){ //链表中插入元素
	pathNode* p;
	p = (pathNode*)new(pathNode);
	if(p){
		p->toCity = toCity;
		p->pathLen=pathLen;
		p->pathIndex=pathIndex;
		p->next=L->next;
		L->next=p;
	}
}

void clearPathAppearNum(int* pathAppearNum){
	FOR(i,PATHMAXNUM){
		pathAppearNum[i]=0;
	}
}

void mergePathAppearNum(int* pathAppearNum1,int* pathAppearNum2){
	FOR(i,PATHMAXNUM){
		pathAppearNum1[i]+=pathAppearNum2[i];
	}
}

void findShortestPath(int from_city,int to_city,int& pathNum, int& pathLen, int* pathAppearNum,long int cityIncludeBit){
	int shortLen=0;
	int tempPathNum=0;
	pathNode*temp=pathSets[from_city]->next;
	while(temp!=NULL){
		if(temp->toCity==to_city){
			if(shortLen==0 || shortLen>=temp->pathLen){
				if(shortLen==0||shortLen>temp->pathLen){//初始化最短路径或者清空路径条数，重新计数
					shortLen=temp->pathLen;
					tempPathNum=0;
					clearPathAppearNum(pathAppearNum);
				}
				pathAppearNum[temp->pathIndex]++;
				tempPathNum++;
			}
		}else if((temp->pathLen<shortLen || shortLen==0)&& !(cityIncludeBit&(1<<temp->toCity))){//迭代查找
			int retPathAppearNum[PATHMAXNUM];
			clearPathAppearNum(retPathAppearNum);
			int retPathNum,retPathLen;
			long int tempCityIncludeBit=cityIncludeBit|(1<<from_city);
			findShortestPath(temp->toCity,to_city,retPathNum,retPathLen,retPathAppearNum,tempCityIncludeBit);
			if(retPathNum>0){
				int curpathLen=temp->pathLen+retPathLen;
				if(shortLen==0|| shortLen>=curpathLen){
					if(shortLen==0||shortLen>curpathLen){//初始化最短路径或者清空路径条数，重新计数
						shortLen=curpathLen;
						clearPathAppearNum(pathAppearNum);
						tempPathNum=0;
					}
					pathAppearNum[temp->pathIndex]+=retPathNum;
					tempPathNum+=retPathNum;
					mergePathAppearNum(pathAppearNum,retPathAppearNum);
				}
			}
		}
		temp=temp->next;
	}
	pathNum=tempPathNum;
	pathLen=shortLen;
}

int main(){
	ifstream fin;
	fin.open("test.txt");

	FILE* fp_out=freopen("output.txt","w",stdout);
	mapStrToInt pathDic;
	FOR(k,CITYMAXNUM){//链表初始化
		pathSets[k]=(pathNode*)new(pathNode);
		pathSets[k]->next=NULL;
	}
	
	if(fin){
		int N;fin>>N;
		FOR(i,N){//实验次数
			int path_num;fin>>path_num;//路径数量
			FOR(k,CITYMAXNUM) DeleteList(pathSets[k]);

			string start_city;fin>>start_city;
			pathDic.clear();

			int city_num=1;
			pathDic.insert( pair <string, int> (start_city,0));

			string fromCity,toCity;
			int pathLen;
			map <string, int>::iterator city_Iter;
			int fromCityIndex;
			FOR(j,path_num){//输入数据
				//输入路径的起始城市
				fin>>fromCity;
				city_Iter = pathDic.find(fromCity);
				if(city_Iter==pathDic.end()){
					fromCityIndex=city_num;
					pathDic.insert( pair <string, int> (fromCity,city_num++));//增加城市
				}else{
					fromCityIndex=city_Iter->second;
				}
				
				//输入路径的结束城市
				fin>>toCity>>pathLen;
				city_Iter=pathDic.find(toCity);
				if(city_Iter==pathDic.end()){
					InsertNode(pathSets[fromCityIndex],city_num,pathLen,j);//增加路径
					pathDic.insert( pair <string, int> (toCity,city_num++));//增加城市
				}else{
					InsertNode(pathSets[fromCityIndex],city_Iter->second,pathLen,j);
				}
			}
			FOR(j,path_num)pathFreqSet[j]=0;
			int noPathNode=0;
			for(int j=1;j<city_num;j++){
				int goPathNum,pathLen;long int cityIncludeBit;
				cityIncludeBit=0;
				findShortestPath(0, j, goPathNum, pathLen, pathAppearSet,cityIncludeBit);
				if(goPathNum){
					FOR(k,path_num) pathFreqSet[k]+=((float)pathAppearSet[k])/goPathNum/(city_num-1);
				}else{
					noPathNode++;
				}
				//cout<<"to city "<<j<<",pathnum:"<<goPathNum<<",pathlen:"<<pathLen<<endl;
			}
			if(noPathNode){
				FOR(k,path_num) pathFreqSet[k]=pathFreqSet[k]/(city_num-1-noPathNode)*(city_num-1);
			}
			cout<<"Case #"<<i+1<<": ";
			FOR(j,path_num) printf("%.07f ",pathFreqSet[j]);
			cout<<endl;
		}
	}
	fclose(stdout);
	fclose(fp_out);

	malcin();
	printf("\n press any key to continue...");
	getchar();
	return 0;
=======
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define PATHMAXNUM 50
#define CITYMAXNUM 100

typedef std::map<string, int> mapStrToInt;
int pathAppearSet[PATHMAXNUM];
float pathFreqSet[PATHMAXNUM];
int malcin();

struct pathNode{//路径链表
	int toCity;
	int pathLen;
	int pathIndex;
	pathNode* next;
};

pathNode* pathSets[CITYMAXNUM];

void DeleteList(pathNode* L){ //清空列表
	  pathNode* p, *tmp;
	  p = L->next;
	  L->next=NULL;
	  while(p!=NULL){
		  tmp = p->next;
		  delete p;
		  p=tmp;
	  }
}

void InsertNode(pathNode* L,int toCity, int pathLen,int pathIndex){ //链表中插入元素
	pathNode* p;
	p = (pathNode*)new(pathNode);
	if(p){
		p->toCity = toCity;
		p->pathLen=pathLen;
		p->pathIndex=pathIndex;
		p->next=L->next;
		L->next=p;
	}
}

void clearPathAppearNum(int* pathAppearNum){
	FOR(i,PATHMAXNUM){
		pathAppearNum[i]=0;
	}
}

void mergePathAppearNum(int* pathAppearNum1,int* pathAppearNum2){
	FOR(i,PATHMAXNUM){
		pathAppearNum1[i]+=pathAppearNum2[i];
	}
}

void findShortestPath(int from_city,int to_city,int& pathNum, int& pathLen, int* pathAppearNum,long int cityIncludeBit){
	int shortLen=0;
	int tempPathNum=0;
	pathNode*temp=pathSets[from_city]->next;
	while(temp!=NULL){
		if(temp->toCity==to_city){
			if(shortLen==0 || shortLen>=temp->pathLen){
				if(shortLen==0||shortLen>temp->pathLen){//初始化最短路径或者清空路径条数，重新计数
					shortLen=temp->pathLen;
					tempPathNum=0;
					clearPathAppearNum(pathAppearNum);
				}
				pathAppearNum[temp->pathIndex]++;
				tempPathNum++;
			}
		}else if((temp->pathLen<shortLen || shortLen==0)&& !(cityIncludeBit&(1<<temp->toCity))){//迭代查找
			int retPathAppearNum[PATHMAXNUM];
			clearPathAppearNum(retPathAppearNum);
			int retPathNum,retPathLen;
			long int tempCityIncludeBit=cityIncludeBit|(1<<from_city);
			findShortestPath(temp->toCity,to_city,retPathNum,retPathLen,retPathAppearNum,tempCityIncludeBit);
			if(retPathNum>0){
				int curpathLen=temp->pathLen+retPathLen;
				if(shortLen==0|| shortLen>=curpathLen){
					if(shortLen==0||shortLen>curpathLen){//初始化最短路径或者清空路径条数，重新计数
						shortLen=curpathLen;
						clearPathAppearNum(pathAppearNum);
						tempPathNum=0;
					}
					pathAppearNum[temp->pathIndex]+=retPathNum;
					tempPathNum+=retPathNum;
					mergePathAppearNum(pathAppearNum,retPathAppearNum);
				}
			}
		}
		temp=temp->next;
	}
	pathNum=tempPathNum;
	pathLen=shortLen;
}

int main(){
	ifstream fin;
	fin.open("test.txt");

	FILE* fp_out=freopen("output.txt","w",stdout);
	mapStrToInt pathDic;
	FOR(k,CITYMAXNUM){//链表初始化
		pathSets[k]=(pathNode*)new(pathNode);
		pathSets[k]->next=NULL;
	}
	
	if(fin){
		int N;fin>>N;
		FOR(i,N){//实验次数
			int path_num;fin>>path_num;//路径数量
			FOR(k,CITYMAXNUM) DeleteList(pathSets[k]);

			string start_city;fin>>start_city;
			pathDic.clear();

			int city_num=1;
			pathDic.insert( pair <string, int> (start_city,0));

			string fromCity,toCity;
			int pathLen;
			map <string, int>::iterator city_Iter;
			int fromCityIndex;
			FOR(j,path_num){//输入数据
				//输入路径的起始城市
				fin>>fromCity;
				city_Iter = pathDic.find(fromCity);
				if(city_Iter==pathDic.end()){
					fromCityIndex=city_num;
					pathDic.insert( pair <string, int> (fromCity,city_num++));//增加城市
				}else{
					fromCityIndex=city_Iter->second;
				}
				
				//输入路径的结束城市
				fin>>toCity>>pathLen;
				city_Iter=pathDic.find(toCity);
				if(city_Iter==pathDic.end()){
					InsertNode(pathSets[fromCityIndex],city_num,pathLen,j);//增加路径
					pathDic.insert( pair <string, int> (toCity,city_num++));//增加城市
				}else{
					InsertNode(pathSets[fromCityIndex],city_Iter->second,pathLen,j);
				}
			}
			FOR(j,path_num)pathFreqSet[j]=0;
			int noPathNode=0;
			for(int j=1;j<city_num;j++){
				int goPathNum,pathLen;long int cityIncludeBit;
				cityIncludeBit=0;
				findShortestPath(0, j, goPathNum, pathLen, pathAppearSet,cityIncludeBit);
				if(goPathNum){
					FOR(k,path_num) pathFreqSet[k]+=((float)pathAppearSet[k])/goPathNum/(city_num-1);
				}else{
					noPathNode++;
				}
				//cout<<"to city "<<j<<",pathnum:"<<goPathNum<<",pathlen:"<<pathLen<<endl;
			}
			if(noPathNode){
				FOR(k,path_num) pathFreqSet[k]=pathFreqSet[k]/(city_num-1-noPathNode)*(city_num-1);
			}
			cout<<"Case #"<<i+1<<": ";
			FOR(j,path_num) printf("%.07f ",pathFreqSet[j]);
			cout<<endl;
		}
	}
	fclose(stdout);
	fclose(fp_out);

	malcin();
	printf("\n press any key to continue...");
	getchar();
	return 0;
>>>>>>> 194f7f9854ba2b4239e312aded309268c3e9d1d4
}