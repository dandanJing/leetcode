#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)

int main(){
	string products[64];
	int price[64];
	string change_sets[64];
	ifstream fin;
	fin.open("test.txt");
	if(fin){
		int N;fin>>N;
		string temp;

		int products_num;
		FOR(i,N){
			products_num=0;
			getline(fin,temp);//跳过上一行的末尾
			getline(fin,temp);
			
			products[0]="";
			FOR(k,temp.size()){//输入商品名
				if(temp[k]==' '){
					products_num++;
					products[products_num]="";
				}else{
					products[products_num]+=temp[k];
				}
			}
			products_num++;

			FOR(k,products_num)fin>>price[k];//输入价格
			int unfit_index=0;
			int change_count=0,cur_change_index=0,cur_need_change=0;

			for(int k=1;k<products_num;k++){//遍历，获取需要改变的位置
				if(cur_need_change){
					if(products[k].compare(products[cur_change_index]) < 0) cur_change_index=k;
					change_sets[change_count]=products[cur_change_index];
					change_count++;
					cur_need_change=0;
					continue;
				}
				if(price[k]<price[k-1]&&price[k+1]>price[k-1]){//比如 10 |5 30
					price[k]=(price[k-1]+price[k+1])/2;
					change_sets[change_count]=products[cur_change_index];
					change_count++;
				}else if(price[k]<price[k-1]&&price[k]<price[k+1]){//比如 10 |5 50
					
				}else{
					if(products[k].compare(products[k-1]) < 0) cur_change_index=k;
					else cur_change_index=k-1;
					unfit_index=k;
					cur_need_change=1;
				}
			}
			//执行插入排序，调整顺序
			FOR(k,change_count){
				string cur_value=change_sets[k];
				for(int kk=k-1;kk>=0;kk--){
					if(change_sets[kk].compare(cur_value) > 0){change_sets[kk+1]=change_sets[kk]; if(kk==0)change_sets[kk]=cur_value;}
					else change_sets[kk+1]=cur_value;
				}
			}
			cout<<"Case #"<<i<<": ";
			FOR(k,change_count)cout<<change_sets[k]<<" ";
			cout<<endl;
		}
	}
	fin.close();

	printf("\n press any key to continue...");
	getchar();
	return 0;
}