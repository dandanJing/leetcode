//Google Code jam, Practice, Cycles
//https://code.google.com/codejam/contest/32004/dashboard#s=p2
#include <iostream>
#include <fstream>  
#include "top.h"

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++) //forѭ��

struct Edge{ //��
	int node1;
	int node2;
};

struct Node{ //����
	Node* Next;
	int tempValue;
};

void DeleteList(Node* L){ //����б�
	  Node* p, *tmp;
	  p = L->Next;
	  L->Next=NULL;
	  while(p!=NULL){
		  tmp = p->Next;
		  delete p;
		  p=tmp;
	  }
}

void Insert(Node* L,int element){ //�����в���Ԫ��
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
	//ʵ��������3<=n<=300,0<=k<=15
	int  exp_times=0, n_count=0, k_count=0;
	Edge input_edges[15];

	int self_cycle_edge_vec[300];//��¼�Ի����ʱ����ĳ��������ӵĶ��㣬����0-1-4-3��self_cycle_edge_vec[0]=1,self_cycle_edge_vec[1]=4
	int self_cycle_vex_count;//�Ի��еĶ�����
	int two_edge_vex_set[300];//��¼����Ϊ2�Ķ��㣬����Ϊ2������ֵΪ1������Ϊ0
	int two_edge_vex_count;//����Ϊ2�Ķ��������
	int edge_vex[300];//��1bit��ʶ���ǵıߵļ������Ƿ����ĳ�����㣬������Ϊ1������Ϊ0

	fscanf(fp,"%d",&exp_times);//����ʵ�����

	int case_result;	 //��¼��ǰ�Ľ��
	int edge_vex_count=0;//��¼��ǰѭ���ıߵ�����
	int case_num;        //��¼��ǰ�Ǽ���ʵ��

	Node* nodeHead[300];
	FOR(k,300){//��ʼ���ڵ�
		nodeHead[k]=(Node*)new(Node);
		nodeHead[k]->Next=NULL;
	}

	FOR(case_num,exp_times){
		if(feof(fp)) break;
		fscanf(fp,"%i %i",&n_count,&k_count); //����n��k

		FOR(kk,k_count){fscanf(fp,"%i %i",&input_edges[kk].node1,&input_edges[kk].node2);}//�����
	
		case_result=1;//ʵ������λ
		for(int ii=n_count-1;ii>1;ii--)case_result*=ii;  //����(n-1)!

		int edge_index=1;
		FOR(j,1<<k_count){//��ǰѭ����j�ж�����1��λ��m��ʾ��m������Ҫ���ǣ�������1��������ʾ���ǵıߵ�����
			FOR(k,n_count){
				edge_vex[k]=0; //��������ִ�����ʼ��Ϊ0
				DeleteList(nodeHead[k]);
			}
		
			edge_vex_count=0; 
			FOR(k,k_count){
				if(1&(j>>k)){//���ǰ�����k����
					edge_vex[input_edges[k].node1-1]+=1;
					edge_vex[input_edges[k].node2-1]+=1;
					edge_vex_count++;//������1
					Insert(nodeHead[input_edges[k].node1-1],input_edges[k].node2-1);//��������洢��
					Insert(nodeHead[input_edges[k].node2-1],input_edges[k].node1-1);
				}
			}
			//�����ı�Ϊ����ʱ����Ҫ������ǰֵ��Ϊż��ʱ������Ҫ���ϵ�ǰֵ
			int temp=1;//��¼��ǰ�߼����ɵĻ�������

			//��������ѭ��������(n-1-edge_count)!*(2^edge_count)
			for(int k=n_count-1-edge_vex_count;k>1;k--) temp*=(k); 
			FOR(k,edge_vex_count) temp*=2;	

			two_edge_vex_count=0;
			FOR(k,n_count){//�жϱߵļ����нڵ���ֵĴ���������>2ʱ�������ܴ������������Ӧ�ѵ�ǰ�����Ϊ0
				//��ʼ��
				two_edge_vex_set[k]=0;

				if(edge_vex[k]>2){
					temp=0;break;//��ĳ�㷢���ı�������2ʱ�������ܹ���Hamiltonian��
				}
				if(edge_vex[k]==2){
					temp=temp>>1;//��ĳ�㷢���ı���Ϊ2ʱ�����ɶȼ�С1
					two_edge_vex_set[k]=1;//��k������ı���Ϊ2������ü���־Ϊ1
					two_edge_vex_count++;
				}
			}
			//����1����Ҫ����ǲ������Ի�����---------̫��Ҫ�ˣ���������þ��ˣ���������
			//����2���ַ���һ����������Ϊʲô�Ի�����Ҫ���ǣ���Ϊ�㷨���ǵ��ǹ̶�1��λ�ã�������Ԫ�ؽ������򣬴Ӷ�����Ԫ�ص��Ի��ǲ�������
			//����3�����������������ʼ�ͽ����ģ��������ж��Ƿ�����Ի�ʱ�������õ���������δ���жϸ������Ƿ���Ҫ���ǣ�����one_edge_vex_set,�������˼·��Ȼ������
			//����4��one_edge_vex_setֻ�ܱ�������ڣ����ǲ��ܱ����������Ƿ���ڣ�������赱ǰ1-5�ı�ʵ���ϲ����ǣ�����5�ĵ���ڣ������������д���1-5�ı�ʱ��
			//�Ͳ����жϳ��������Խ���취ֻ���Ƕ�̬��������

			//����Ϊ�Ի����
			while(two_edge_vex_count&&temp){
				FOR(k,n_count){
					if(!two_edge_vex_count) break;

					self_cycle_vex_count=0; //��¼���ܵĻ��а����Ľڵ���
					int temp_vex=k; //��ǰ�ڵ�
					int isCycle=0;  //�Ƿ�����Ի�
					Node* p;
					if(two_edge_vex_set[temp_vex]){//��ǰ�ڵ�temp_vex�Ǵ������������ӵģ������ſ��ܳ����Ի�
						FOR(jj,n_count) self_cycle_edge_vec[jj]=-1; //��ʼʱÿ������ĳ��߶�Ϊ��
					}else continue;

					p = nodeHead[temp_vex];
					while(two_edge_vex_set[temp_vex]){//��ǰ���������ߣ��ӵ�ǰ����������Ƿ�����Ի�
						two_edge_vex_set[temp_vex]=0;//��ǰ�����Ѿ����ǹ���������Ϊ0��������-1,�Ի�������+1
						two_edge_vex_count--;
						self_cycle_vex_count++;

						p = p->Next;
						if(p==NULL){//�������Ի�
							break;
						}else if(temp_vex==self_cycle_edge_vec[p->tempValue]){//�������Ѿ��������
							two_edge_vex_set[temp_vex]=1;//��ǰ������Ҫ���¿��ǣ���������λ
							two_edge_vex_count++;
							self_cycle_vex_count--;
							continue;
						}else if(p->tempValue==k && self_cycle_vex_count<n_count){
							isCycle=1;
							break;//�����Ի�
						}else if(p->tempValue==k){
							break;//�������Ի�
						}else if(two_edge_vex_set[p->tempValue]==0){
							break;//�������Ի�
						}else{//����ǰ�ڵ���뵽���ܵ��Ի�Ȧ�У��������
							self_cycle_edge_vec[temp_vex]=p->tempValue;
							temp_vex=p->tempValue;
							p = nodeHead[temp_vex];
						}
					}
					if(isCycle){//�����Ի���������ǰѭ��
						temp=0;
						two_edge_vex_count=0;
						break;
					}	
				}
			}

			if(edge_vex_count==n_count && temp)temp=2;//������ǡ��Ϊ������2��ʱ������Թ���������·
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