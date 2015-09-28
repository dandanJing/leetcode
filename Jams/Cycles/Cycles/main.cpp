//Google Code jam, Practice, Cycles
//https://code.google.com/codejam/contest/32004/dashboard#s=p2
#include <iostream>
#include <fstream>  
#include "top.h"

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++) //for循环

struct Edge{ //边
	int node1;
	int node2;
};

struct Node{ //链表
	Node* Next;
	int tempValue;
};

void DeleteList(Node* L){ //清空列表
	  Node* p, *tmp;
	  p = L->Next;
	  L->Next=NULL;
	  while(p!=NULL){
		  tmp = p->Next;
		  delete p;
		  p=tmp;
	  }
}

void Insert(Node* L,int element){ //链表中插入元素
	Node* p;
	p = (Node*)new(Node);
	if(p){
		p->tempValue = element;
		p->Next=L->Next;
		L->Next=p;
	}
}

void usaco();
int bmerry();
int main(){
	FILE * fp = fopen("C-small-practice.in","r");
	if(fp==NULL){
		printf("file open error");
		printf("\n\t\tpress enter to exit...");
	    getchar();
		return 0;
	}
	//实验条件，3<=n<=300,0<=k<=15
	int  exp_times=0, n_count=0, k_count=0;
	Edge input_edges[15];

	int self_cycle_edge_vec[300];//记录自环检测时顶点的出边所连接的顶点，比如0-1-4-3则，self_cycle_edge_vec[0]=1,self_cycle_edge_vec[1]=4
	int self_cycle_vex_count;//自环中的顶点数
	int two_edge_vex_set[300];//记录边数为2的顶点，边数为2，顶点值为1，否则为0
	int two_edge_vex_count;//边数为2的顶点的数量
	int edge_vex[300];//用1bit标识考虑的边的集合中是否存在某个顶点，存在则为1，否则为0

	fscanf(fp,"%d",&exp_times);//输入实验次数

	int case_result;	 //记录当前的结果
	int edge_vex_count=0;//记录当前循环的边的总数
	int case_num;        //记录当前是几次实验

	Node* nodeHead[300];
	FOR(k,300){//初始化节点
		nodeHead[k]=(Node*)new(Node);
		nodeHead[k]->Next=NULL;
	}

	FOR(case_num,exp_times){
		if(feof(fp)) break;
		fscanf(fp,"%i %i",&n_count,&k_count); //输入n和k

		FOR(kk,k_count){fscanf(fp,"%i %i",&input_edges[kk].node1,&input_edges[kk].node2);}//输入边
	
		case_result=1;//实验结果复位
		for(int ii=n_count-1;ii>1;ii--)case_result*=ii;  //计算(n-1)!

		int edge_index=1;
		FOR(j,1<<k_count){//当前循环，j中二进制1的位置m表示第m条边需要考虑，二进制1的数量表示考虑的边的总数
			FOR(k,n_count){
				edge_vex[k]=0; //将顶点出现次数初始化为0
				DeleteList(nodeHead[k]);
			}
		
			edge_vex_count=0; 
			FOR(k,k_count){
				if(1&(j>>k)){//考虑包含第k条边
					edge_vex[input_edges[k].node1-1]+=1;
					edge_vex[input_edges[k].node2-1]+=1;
					edge_vex_count++;//边数加1
					Insert(nodeHead[input_edges[k].node1-1],input_edges[k].node2-1);//构建链表存储边
					Insert(nodeHead[input_edges[k].node2-1],input_edges[k].node1-1);
				}
			}
			//包含的边为奇数时，需要减掉当前值，为偶数时，则需要加上当前值
			int temp=1;//记录当前边集构成的环的数量

			//下面两个循环来计算(n-1-edge_count)!*(2^edge_count)
			for(int k=n_count-1-edge_vex_count;k>1;k--) temp*=(k); 
			FOR(k,edge_vex_count) temp*=2;	

			two_edge_vex_count=0;
			FOR(k,n_count){//判断边的集合中节点出现的次数，次数>2时，不可能存在这种情况，应把当前结果置为0
				//初始化
				two_edge_vex_set[k]=0;

				if(edge_vex[k]>2){
					temp=0;break;//当某点发出的边数大于2时，不可能构成Hamiltonian环
				}
				if(edge_vex[k]==2){
					temp=temp>>1;//当某点发出的边数为2时，自由度减小1
					two_edge_vex_set[k]=1;//从k点出发的边数为2，因而该集标志为1
					two_edge_vex_count++;
				}
			}
			//错误1：需要检测是不是有自环现象---------太重要了，纠结在这好久了！！！！！
			//错误2：又犯了一个致命错误，为什么自环不需要考虑，因为算法考虑的是固定1的位置，对其它元素进行排序，从而其它元素的自环是不成立的
			//错误3：致命错误，链表是最开始就建立的，但是在判断是否存在自环时，就是用的这个链表而未加判断该条边是否需要考虑，增加one_edge_vex_set,发现这个思路仍然有问题
			//错误4：one_edge_vex_set只能表明点存在，但是不能表明该条边是否存在，比如假设当前1-5的边实际上不考虑，但是5的点存在，这样在链表中存在1-5的边时，
			//就不能判断出来，所以解决办法只能是动态建立链表

			//下面为自环检测
			while(two_edge_vex_count&&temp){
				FOR(k,n_count){
					if(!two_edge_vex_count) break;

					self_cycle_vex_count=0; //记录可能的环中包含的节点数
					int temp_vex=k; //当前节点
					int isCycle=0;  //是否存在自环
					Node* p;
					if(two_edge_vex_set[temp_vex]){//当前节点temp_vex是存在两条边连接的，这样才可能出现自环
						FOR(jj,n_count) self_cycle_edge_vec[jj]=-1; //初始时每个顶点的出边都为空
					}else continue;

					p = nodeHead[temp_vex];
					while(two_edge_vex_set[temp_vex]){//当前点有两条边，从当前点出发，看是否存在自环
						two_edge_vex_set[temp_vex]=0;//当前顶点已经考虑过，将其置为0，顶点数-1,自环顶点数+1
						two_edge_vex_count--;
						self_cycle_vex_count++;

						p = p->Next;
						if(p==NULL){//不存在自环
							break;
						}else if(temp_vex==self_cycle_edge_vec[p->tempValue]){//该条边已经计算过了
							two_edge_vex_set[temp_vex]=1;//当前顶点需要重新考虑，将计数归位
							two_edge_vex_count++;
							self_cycle_vex_count--;
							continue;
						}else if(p->tempValue==k && self_cycle_vex_count<n_count){
							isCycle=1;
							break;//存在自环
						}else if(p->tempValue==k){
							break;//不存在自环
						}else if(two_edge_vex_set[p->tempValue]==0){
							break;//不存在自环
						}else{//将当前节点加入到可能的自环圈中，继续检测
							self_cycle_edge_vec[temp_vex]=p->tempValue;
							temp_vex=p->tempValue;
							p = nodeHead[temp_vex];
						}
					}
					if(isCycle){//存在自环，跳出当前循环
						temp=0;
						two_edge_vex_count=0;
						break;
					}	
				}
			}

			if(edge_vex_count==n_count && temp)temp=2;//当边数恰好为点数的2倍时，其可以构成两条环路
			/*if(!COUNT_VALUE) {
				int temp_mod = (temp/2)%9901;
				//if(edge_vex_count==EDGE_NUM&&temp) printf(" edge_index:%i value:%i temp value %i\n",edge_index++,temp_mod,j);
			}else {
				if(edge_vex_count==EDGE_NUM&&temp&&(temp/2)%9901==TEMP_VALUE) printf(" edge_index:%i value:%i temp value %i\n",edge_index++,(temp/2)%9901,j);
			}*/
			if(edge_vex_count<=n_count){
				if(edge_vex_count%2){
					case_result -= temp;
				}else if(edge_vex_count){
					case_result += temp;
				}
			}
		}
		//cout<<case_result<<endl;
		case_result =(case_result)/2;
		//if(case_result<0) case_result=0;
		case_result = case_result%9901;
		//fprintf(fp,"Case #%i: %i\n",case_num,case_result);
		printf("Case #%i: %i\n",case_num+1,case_result);
	}

	fclose(fp);

	usaco();

	printf("\n\t\tpress enter to exit...");
	getchar();
	return 0;
}