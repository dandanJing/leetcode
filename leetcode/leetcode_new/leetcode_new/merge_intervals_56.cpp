#include"top.h"

void sortIntervals(vector<Interval>& intervals, int pos1, int pos2){
    if(pos1>=pos2)return;
    
    Interval temp;
    if(pos1+1==pos2){
        temp=intervals[pos2];
        if(intervals[pos1].start>temp.start){
            intervals[pos2]=intervals[pos1];
            intervals[pos1]=temp;
        }
        return;
    }
    
    int mid=(pos1+pos2)/2;
    if(intervals[pos1].start>min(intervals[pos2].start,intervals[mid].start) && intervals[pos1].start<max(intervals[pos2].start,intervals[mid].start)){
        temp=intervals[pos2];
        intervals[pos2]=intervals[pos1];
        intervals[pos1]=temp;
    }else if(intervals[mid].start>min(intervals[pos2].start,intervals[pos1].start) && intervals[mid].start<max(intervals[pos2].start,intervals[pos1].start)){
        temp=intervals[pos2];
        intervals[pos2]=intervals[mid];
        intervals[mid]=temp;
    }
    temp=intervals[pos2];
    int ii=pos1,jj=pos2-1;
    while(ii<=jj){
        while(ii<=jj && intervals[ii].start<intervals[pos2].start){
            ii++;
        }

        while(jj>=ii && intervals[jj].start>intervals[pos2].start){
            jj--;
        }
		
		if(ii<=jj){
			temp=intervals[jj];
			intervals[jj]=intervals[ii];
			intervals[ii]=temp;
			ii++;jj--;
		}
    }
    temp=intervals[ii];
    intervals[ii]=intervals[pos2];
    intervals[pos2]=temp;
    sortIntervals(intervals,pos1,ii-1);
    sortIntervals(intervals,ii+1,pos2);
}

//vector<Interval> toMerge(vector<Interval>& intervals,int start, int end){
//	vector<Interval>result;
//	if(start>end)return result;
//	else if(start==end)result.push_back(intervals[end]);
//	else if(start+1==end){
//		if(intervals[end].start>intervals[start].end){
//			result.push_back(intervals[start]);
//			result.push_back(intervals[end]);
//		}else if(intervals[start].start>intervals[end].end){
//			result.push_back(intervals[end]);
//			result.push_back(intervals[start]);
//		}else {
//			int val1=min(intervals[end].start,intervals[start].start);
//			int val2=max(intervals[end].end,intervals[start].end);
//			Interval intr2=Interval(val1,val2);
//			result.push_back(intr2);
//		}
//	}else{
//		vector<Interval> temp1=toMerge(intervals,start,(start+end)/2);
//		vector<Interval> temp2=toMerge(intervals,(start+end)/2+1,end);
//		if(0){
//			int i;
//			for(i=0;i<temp2.size();i++){
//				bool isadd=false;
//				FOR(j,temp1.size()){
//					if(temp2[i].start >temp1[j].end )continue;
//					else if(temp1[j].start >temp2[i].end)continue;
//					else{
//						isadd=true;
//						temp1[j].start=min(temp1[j].start,temp2[i].start);
//						temp1[j].end=max(temp1[j].end,temp2[i].end);
//						break;
//					}
//					if(isadd)break;
//					else temp1.push_back(temp2[i]);
//				}
//			}
//			for(;i<temp2.size();i++){
//				temp1.push_back(temp2[i]);
//			}
//			if(temp1.size()==end-start+1)return temp1;
//			else return toMerge(temp1,0,temp1.size()-1);
//		}else{
//			FOR(i,temp2.size()){
//				temp1.push_back(temp2[i]);
//			}
//			return toMerge(temp1,0,temp1.size()-1);
//		}
//		
//		/*Interval temp;
//		FOR(i,temp2.size()){
//			temp1.push_back(temp2[i]);
//			temp=temp2[i];
//			int j;
//			for(j=temp1.size()+i-1;j>=0;j--){
//				if(temp1[j].start>temp.start)temp1[j+1]=temp1[j];
//				else break;
//			}
//			temp1[j+1]=temp;
//		}
//		
//		return toMerge(temp1,0,temp1.size()-1);*/
//		
//	}
//	return result;
//}
vector<Interval> Solution::merge(vector<Interval>& intervals){
	vector<Interval> result;
        if(intervals.size()==0)return result;
        else if(intervals.size()==1) return intervals;
        
        Interval temp;
        sortIntervals(intervals,0,intervals.size()-1);
        result.push_back(intervals[0]);
        temp=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start>temp.end){
                result.push_back(intervals[i]);
                temp=intervals[i];
            }else if(intervals[i].end<=temp.end){
                continue;
            }else{
                result[result.size()-1].end=max(temp.end,intervals[i].end);
				temp.end=result[result.size()-1].end;
            }
        }
        return result;
	//return toMerge(intervals,0,intervals.size()-1);
}
//vector<Interval> Solution::merge(vector<Interval>& intervals){
//	vector<Interval> result;
//	Interval temp;
//	FOR(i,intervals.size()){
//		temp=intervals[i];
//		int j;
//		for(j=i-1;j>=0;j--){
//			if(intervals[j].start>temp.start)intervals[j+1]=intervals[j];
//			else break;
//		}
//		intervals[j+1]=temp;
//	}
//	int pos=0;
//	while(pos<intervals.size()){
//		if(pos==intervals.size()-1){
//			result.push_back(intervals[pos]);
//		}
//		else if(intervals[pos+1].start<=intervals[pos].end){
//			intervals[pos+1].start=min(intervals[pos].start,intervals[pos+1].start);
//			intervals[pos+1].end=max(intervals[pos].end,intervals[pos+1].end);
//		}else{
//			result.push_back(intervals[pos]);
//		}
//		pos++;
//	}
//	return result;
//}

void let_56(){
	vector<Interval> intervals;

	ifstream fin;
	fin.open("let_56.txt");
	char tempc;
	int val1,val2;
	fin>>tempc;
	while(tempc!=']'){
		fin>>tempc>>val1>>tempc>>val2;
		Interval intr1=Interval(val1,val2);
		fin>>tempc>>tempc;
		intervals.push_back(intr1);
	}
	/*Interval intr1=Interval(1,3);
	Interval intr2=Interval(2,6);
	Interval intr3=Interval(8,10);
	Interval intr4=Interval(15,18);
	intervals.push_back(intr2);
	intervals.push_back(intr4);
	intervals.push_back(intr3);
	intervals.push_back(intr1);*/
	Solution sol;
	vector<Interval>result=sol.merge(intervals);
	FOR(i,result.size()){
		cout<<"["<<result[i].start<<","<<result[i].end<<"],";
	}
	cout<<endl;
}