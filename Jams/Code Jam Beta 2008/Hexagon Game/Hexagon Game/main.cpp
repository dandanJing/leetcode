#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define CHECKMAXNUM 75

struct checker{
	int value;
	int pos;
	int isInLine;
};

void getLayerSmallNum();//��ȡÿһ�����СԪ��
void getLinePosForSnum(int sNum, int lineStyle);//��ȡ����������ֱ�ߵ�λ��
void checkIfInLine();//�жϵ�ǰԪ���Ƿ���ֱ����
int countCheckValue(int isPosOccupyBit[],int start_pos,int to_pos,int posOccupyValue[]);//��������ƶ�����
int findCheckerToCheckerLen(int pos1,int pos2);//��������֮��ľ���
void sortCheckerArray();//��checker������value��������

int linePos[CHECKMAXNUM];//��ȡֱ��Ԫ�ص�λ��
int layerSmallNum[CHECKMAXNUM];//��ȡÿ�����СԪ��
int isPosOccupyBit[CHECKMAXNUM];
int posOccupyValue[CHECKMAXNUM];

int smallestValue;//��С�ľ���
checker checkArray[CHECKMAXNUM];
int sNum;//s����

int main(){
	ifstream fin;
	fin.open("test.txt");
	if(fin){
		int N;fin>>N;
		string temp;
		int startPos[CHECKMAXNUM];
		int checkerValues[CHECKMAXNUM];

		getline(fin,temp);
		FOR(i,N){//ʵ�����
			//��ʼ��
			FOR(j,CHECKMAXNUM){
				startPos[j]=0;
				checkerValues[j]=0;
			}

			sNum=0;
			//��ȡ����
			getline(fin,temp);
			int curInt=0;
			FOR(k,temp.size()){
				if(temp[k]==' '){
					startPos[sNum++]=curInt;
					curInt=0;
				}else if(temp[k]>='0' && temp[k]<='9'){
					curInt=curInt*10+(temp[k]-'0');
				}
			}
			startPos[sNum++]=curInt;
			FOR(j,sNum) {
				fin>>checkerValues[j];
				checkArray[j].value=checkerValues[j];
				checkArray[j].pos=startPos[j];
				checkArray[j].isInLine=0;
			}
			sortCheckerArray();
			getline(fin,temp);

			smallestValue=0x7fffffff;
			FOR(j,3) {
				getLinePosForSnum(sNum,j);//��ȡ����ֱ��λ��
				checkIfInLine();//�жϵ�ǰ�ĵ��Ƿ���ֱ����
				getLayerSmallNum();//��ȡÿһ�����С��Ԫ��
				smallestValue=countCheckValue(isPosOccupyBit,0,sNum,posOccupyValue);//������̵ĸı����
			}
			cout<<"Case #"<<i+1<<": "<<smallestValue;
			cout<<endl;
		}
	}
	printf("\n press any key to continue...");
	getchar();
	return 0;
}

//��������ƶ�����
int countCheckValue(int isPosOccupyBit[],int start_pos,int to_pos,int posOccupyValue[]){
	if(start_pos>=to_pos) return 0;

	int tempPosOccupyBit[CHECKMAXNUM],tempPosOccupyValue[CHECKMAXNUM];
	FOR(i,sNum){
		tempPosOccupyBit[i]=isPosOccupyBit[i];
		tempPosOccupyValue[i]=posOccupyValue[i];
	}

	//�ҵ���start_pos��ʼ��to_pos��value����checkers
	int end_pos=start_pos,jj;
	int cur_value=checkArray[start_pos].value;
	for(jj=start_pos+1;jj<to_pos;jj++){
		if(checkArray[jj].value==cur_value){
			end_pos=jj;
		}else{
			break;
		}
	}
	//����Щcheckers����λ�ã������С���ƶ�����
	int smallestMoveValue=0;
	for(jj=start_pos;jj<=end_pos;jj++){
		if(checkArray[jj].isInLine)continue;
		int smallLenCount=0;
		int smallLen=0x7fffffff;
		int smallPos;
		int tempLen;
		FOR(k,sNum){
			if(tempPosOccupyBit[k] && checkArray[tempPosOccupyValue[k]].value>=checkArray[jj].value)
				continue;
			
			tempLen=findCheckerToCheckerLen(linePos[k],checkArray[jj].pos);
			if(tempLen<smallLen){
				smallLen=tempLen;
				smallPos=k;
				smallLenCount=1;
			}else if(tempLen==smallLen)smallLenCount++;
			else break;
		}

		if(smallLenCount==1){//ֻ��1����Сλ��ʱ
			tempPosOccupyBit[smallPos]=1;
			tempPosOccupyValue[smallPos]=jj;
			smallestMoveValue+=tempLen;
			continue;
		}

		//���������ϵ���Сλ��ʱ
		int tempSmallLenCount=smallLenCount;
		int tempSmallPos=smallPos;
		while(tempSmallLenCount){
			if(tempPosOccupyBit[tempSmallPos] && checkArray[tempPosOccupyValue[tempSmallPos]].value>=checkArray[jj].value){
				tempSmallPos++;
				continue;
			}
			int tempPosOccupyBit1[CHECKMAXNUM],tempPosOccupyValue1[CHECKMAXNUM];
			int curSmallMoveValue=0x7fffffff,temp;
			FOR(i,sNum){
				tempPosOccupyBit1[i]=tempPosOccupyBit[i];
				tempPosOccupyValue1[i]=tempPosOccupyValue[i];
				checkArray[jj].isInLine=1;
				if(tempPosOccupyBit1[tempSmallPos]){
					checkArray[tempPosOccupyValue1[tempSmallPos]].isInLine=0;
					tempPosOccupyValue1[tempSmallPos]=jj;
				}else{
					tempPosOccupyBit1[tempSmallPos]=1;
					tempPosOccupyValue1[tempSmallPos]=jj;
				}
				temp=countCheckValue(tempPosOccupyBit1,jj+1,end_pos,tempPosOccupyValue1);
				if(temp<curSmallMoveValue){
					curSmallMoveValue=temp;
					smallPos=i;
				}
			}
			tempSmallPos++;
			tempSmallLenCount--;
		}
		tempPosOccupyBit[smallPos]=1;
		tempPosOccupyValue[smallPos]=jj;
		smallestMoveValue+=tempLen;
	}
	smallestMoveValue=smallestMoveValue+countCheckValue(tempPosOccupyBit,end_pos+1,to_pos,tempPosOccupyValue);
	return smallestMoveValue;
}

//void countCheckValue(){
//	int isPosOccupyBit[CHECKMAXNUM];
//	FOR(i,sNum) isPosOccupyBit[i]=0;
//
//	smallestValue=0;
//	int ii=0,jj;
//	while(ii<sNum){
//		int start_pos=ii;
//		int end_pos=ii;
//		checker temp=checkArray[ii];
//		int cur_value=temp.value;
//		//�ҵ����value��Ԫ��λ��
//		for(jj=ii+1;jj<sNum;jj++){
//			if(checkArray[jj].value==cur_value){
//				end_pos=jj;
//				if(checkArray[jj].isInLine){
//					FOR(k,sNum){
//						if(linePos[k]==checkArray[jj].value){
//							if(isPosOccupyBit[k]==0)isPosOccupyBit[k]=1;
//							else checkArray[jj].isInLine=0;
//							break;
//						}
//					}
//				}
//			}else{
//				break;
//			}
//		}
//		ii=end_pos+1;
//		//�������Ԫ�ص�λ��ȷ����С���ƶ�����
//		int tempPos,tempSmall,tempLen;
//		for(int k=start_pos;k<=end_pos;k++){
//			tempPos=0;tempSmall=0x7fffffff;
//			FOR(kk,sNum){
//				if(isPosOccupyBit[kk])continue;
//				else{
//					tempLen=findCheckerToCheckerLen(linePos[kk],checkArray[k].pos);
//					if(tempSmall>tempLen)
//				}
//			}
//		}	
//	}
//}

void sortCheckerArray(){
	//��������
	FOR(i,sNum){
		checker temp=checkArray[i];
		int j;
		for(j=i-1;j>=0;j--){
			if(temp.value>checkArray[j].value) checkArray[j+1]=checkArray[j];
			else {checkArray[j+1]=temp;break;}
		}
		if(j==-1)checkArray[0]=temp;
	}
//	FOR(i,sNum){
//		int tempPos,tempValue,tempInline;
//		tempPos=checkArray[i].pos;
//		tempValue=checkArray[i].value;
//		tempInline=checkArray[i].isInLine;
//		int j;
//		for(j=i-1;j>=0;j--){
//			if(tempValue>checkArray[j].value){
//				checkArray[j+1].pos=checkArray[j].pos;
//				checkArray[j+1].value=checkArray[j].value;
//				checkArray[j+1].isInLine=checkArray[j].isInLine;
//			}else {
//				checkArray[j+1].pos=tempPos;
//				checkArray[j+1].value=tempValue;
//				checkArray[j+1].isInLine=tempInline;
//				break;
//			}
//		}
//		if(j==-1){
//			checkArray[0].pos=tempPos;
//			checkArray[0].value=tempValue;
//			checkArray[0].isInLine=tempInline;
//		}
//	}
}

//��ȡÿһ�����СԪ��
void getLayerSmallNum(){
	FOR(i,sNum){
		if(i==0)layerSmallNum[i]=1;
		else if(i<=(sNum/2+1))layerSmallNum[i]=(sNum+1)/2+(i-1)+layerSmallNum[i-1];
		else layerSmallNum[i]=layerSmallNum[i-1]+sNum-(i-(sNum/2+1));
	}
}

//��ȡ����������ֱ�ߵ�λ��
void getLinePosForSnum(int sNum, int lineStyle){
	int middleLine=sNum>>1;
	int middleValue=((3*sNum*sNum+1)/4+1)/2;
	linePos[middleLine]=middleValue;
	if(lineStyle==0){
		for(int i=1;i<=(sNum-1)/2;i++){
			linePos[middleLine-i]=linePos[middleLine-i+1]-(sNum-i+1);
			linePos[middleLine+i]=linePos[middleLine+i-1]+(sNum-i+1);
		}
	}else if(lineStyle==1){
		for(int i=1;i<=(sNum-1)/2;i++){
			linePos[middleLine-i]=linePos[middleLine-i+1]-(sNum-i);
			linePos[middleLine+i]=linePos[middleLine+i-1]+(sNum-i);
		}
	}else{
		for(int i=1;i<=(sNum-1)/2;i++){
			linePos[middleLine-i]=middleValue-i;
			linePos[middleLine+i]=middleValue+i;
		}
	}
}

//�жϵ�ǰԪ���Ƿ���ֱ����
void checkIfInLine(){
	checker* p;
	FOR(j,sNum){
		isPosOccupyBit[j]=0;
		posOccupyValue[j]=0;

		p=&checkArray[j];
		FOR(i,sNum){
			if(p->pos==linePos[i]){
				p->isInLine=1;break;
				isPosOccupyBit[i]=1;
				posOccupyValue[i]=j;

			}
		}
	}
}

//��������֮��ľ���
int findCheckerToCheckerLen(int pos1,int pos2){
	if(pos1==pos2) return 0;

	int maxValue=(3*sNum*sNum+1)/4;
	if(pos1>maxValue || pos2>maxValue) return -1;

	//�ж��������ڵĲ�
	int layer1=-1,layer2=-1;
	int length=0;
	FOR(i,sNum-1){
		if(pos1>=layerSmallNum[i] && pos1<layerSmallNum[i+1])layer1=i;
		if(pos2>=layerSmallNum[i] && pos2<layerSmallNum[i+1])layer2=i;
	}
	if(layer1==-1)layer1=sNum-1;
	if(layer2==-1)layer2=sNum-1;

	int smallPos,largePos;
	int smallLayer,largeLayer;

	if(pos1>pos2){smallPos=pos2;smallLayer=layer2;largePos=pos1;largeLayer=layer1;}
	else {smallPos=pos1;smallLayer=layer1;largePos=pos2;largeLayer=layer2;}

	if(smallLayer==largeLayer) return largePos-smallPos;
	
	int canReachSmall,canReachLarge,layerDiff;
	layerDiff=largeLayer-smallLayer;
	canReachSmall=largePos;
	canReachLarge=largePos;
	int tempLayer,tempDiff;
	FOR(i,layerDiff){
		tempLayer=largeLayer-i;
		tempDiff=layerSmallNum[tempLayer]-layerSmallNum[tempLayer-1];
		if(tempLayer>=(sNum/2+1)){
			canReachSmall-=tempDiff;
			canReachLarge-=(tempDiff-1);
		}else{
			if(canReachSmall==layerSmallNum[tempLayer])canReachSmall-=tempDiff;
			else canReachSmall-=(tempDiff+1);

			if(canReachLarge==layerSmallNum[tempLayer+1]-1)canReachLarge-=(tempDiff+1);
			else canReachLarge-=tempDiff;
		}
	}

	if(smallPos>=canReachSmall&&smallPos<=canReachLarge) return largeLayer-smallLayer;
	else if(smallPos<canReachSmall) return largeLayer-smallLayer+canReachSmall-smallPos;
	else return largeLayer-smallLayer+(smallPos-canReachLarge);
}