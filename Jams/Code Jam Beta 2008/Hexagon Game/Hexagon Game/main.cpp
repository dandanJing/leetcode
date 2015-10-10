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
void countCheckValue(int isPosOccupyBit[],int start_pos,int curMoveValue,int posOccupyValue[]);//��������ƶ�����
int findCheckerToCheckerLen(int pos1,int pos2);//��������֮��ľ���
void sortCheckerArray();//��checker������value��������
int malcin();

int linePos[CHECKMAXNUM];//��ȡֱ��Ԫ�ص�λ��
int layerSmallNum[CHECKMAXNUM];//��ȡÿ�����СԪ��
int gisPosOccupyBit[CHECKMAXNUM];
int gposOccupyValue[CHECKMAXNUM];

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
			getLayerSmallNum();//��ȡÿһ�����С��Ԫ��
			FOR(j,3) {
				getLinePosForSnum(sNum,j);//��ȡ����ֱ��λ��
				checkIfInLine();//�жϵ�ǰ�ĵ��Ƿ���ֱ����				
				//countCheckValue(gisPosOccupyBit,0,0,gposOccupyValue);//������̵ĸı����
			}
			/*cout<<"Case #"<<i+1<<": "<<smallestValue;
			cout<<endl;*/
		}
	}
	malcin();

	printf("\n press any key to continue...");
	getchar();
	return 0;
}

//��������ƶ�����
int cout_count=1;
void countCheckValue(int isPosOccupyBit[],int start_pos,int curMoveValue,int posOccupyValue[]){
	if(start_pos>=sNum){if(curMoveValue<smallestValue)smallestValue=curMoveValue; return;}
	if(curMoveValue>=smallestValue)return;

	int tempPosOccupyBit[CHECKMAXNUM],tempPosOccupyValue[CHECKMAXNUM];
	FOR(i,sNum){
		tempPosOccupyBit[i]=isPosOccupyBit[i];
		tempPosOccupyValue[i]=posOccupyValue[i];
	}

	int tempCheckerPos=checkArray[start_pos].pos;
	int tempCheckerValue=checkArray[start_pos].value;
	int tempLen;
	int tempMoveValue;
	int tempSmallestMoveValue=0x7fffffff;
	int smallChange=0x7fffffff;
	int smallChange_start,smallChange_end;
	//�ҵ�start_pos�����ƶ���С�����λ����ʼ��
	FOR(i,sNum){
		tempLen=findCheckerToCheckerLen(linePos[i],tempCheckerPos);
		if(smallChange>tempLen){smallChange_start=i;smallChange_end=i;smallChange=tempLen;}
		else if(smallChange==tempLen)smallChange_end=i;
		else break;
	}
	tempMoveValue=tempCheckerValue*smallChange+curMoveValue;
	if(tempMoveValue>=smallestValue)return;//�����С�ƶ��ľ��뻹���ڵ�ǰ��Сֵ�������ټ���������

	for(int i=smallChange_start;i<=smallChange_end;i++){//�ȼ�����С�ƶ�λ��
		if(i) tempPosOccupyBit[i-1]=isPosOccupyBit[i-1];//��λ
		if(!tempPosOccupyBit[i]){//��ǰû�б�ռ
			tempPosOccupyBit[i]=1;
			tempPosOccupyValue[i]=start_pos;
			countCheckValue(tempPosOccupyBit,start_pos+1,tempMoveValue,tempPosOccupyValue);
		}
	}

	for(int i=1;i<sNum;i++){
		tempMoveValue+=tempCheckerValue;
		if(tempMoveValue>=smallestValue) break;

		int temp_small=smallChange_start-i;
		int temp_large=smallChange_start+i;
		if(temp_small>=0 && temp_small<sNum){
			if(!tempPosOccupyBit[temp_small]){//��ǰû�б�ռ
				tempPosOccupyBit[temp_small]=1;
				tempPosOccupyValue[temp_small]=start_pos;
				countCheckValue(tempPosOccupyBit,start_pos+1,tempMoveValue,tempPosOccupyValue);
				tempPosOccupyBit[temp_small]=0;
			}
		}
		if(temp_large>=0 && temp_large<sNum){
			if(!tempPosOccupyBit[temp_large]){//��ǰû�б�ռ
				tempPosOccupyBit[temp_large]=1;
				tempPosOccupyValue[temp_large]=start_pos;
				countCheckValue(tempPosOccupyBit,start_pos+1,tempMoveValue,tempPosOccupyValue);
				tempPosOccupyBit[temp_large]=0;
			}
		}
	}
}

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
		gisPosOccupyBit[j]=0;
		gposOccupyValue[j]=0;
		checkArray[j].isInLine=0;
	}
	FOR(j,sNum){
		p=&checkArray[j];
		FOR(i,sNum){
			if(p->pos==linePos[i]){
				p->isInLine=1;
				//gisPosOccupyBit[i]=1;
				//gposOccupyValue[i]=j;
				break;
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