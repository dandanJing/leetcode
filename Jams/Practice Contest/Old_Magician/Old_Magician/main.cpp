<<<<<<< HEAD
#include <iostream>
#include <fstream>  
using namespace std;

void doMagicianGame(FILE* fp, int white_num, int black_num, int case_num);

int main(){
	FILE * fp = fopen("A-small-practice.in","r");
	FILE * fp_out = fopen("result.txt","w");
	if(fp==NULL){
		printf("file open error");
		printf("\n\t\tpress enter to exit...");
	    getchar();
		return 0;
	}
	int exp_times=0, w_count=0, b_count=0;
	fscanf(fp,"%d",&exp_times);
	//printf("实验次数为 %i\n", exp_times);
	
	for(int i=0; i<exp_times; i++){
		if(feof(fp)) break;
		fscanf(fp,"%i %i",&w_count,&b_count);
		doMagicianGame(fp_out,w_count,b_count,i+1);
		//printf("白球为%i个，黑球为%i个\n",w_count,b_count);
	}

	fclose(fp);
	fclose(fp_out);
	printf("\n\t\tpress enter to exit...");
	getchar();
	return 0;
}

void doMagicianGame(FILE* fp, int white_num, int black_num, int case_num){
	float div_boun = 0.0;
	int random1, random2;
	while(white_num+black_num>1){
		random1 = rand()%(white_num+black_num);
		random2 = rand()%(white_num+black_num);
		while(random2==random1){
			random2 = rand()%(white_num+black_num);
		}
		if(random1<white_num && random2<white_num) white_num--;
		else if(random1>=white_num && random2>=white_num) white_num++,black_num-=2;
		else white_num--;
	}

	if(white_num>0){
		fprintf(fp,"Case #%i: %s\n",case_num,"WHITE");
		//printf("Case #%i:%s\n",case_num,"WHITE");
	}else{
		fprintf(fp,"Case #%i: %s\n",case_num,"BLACK");
		//printf("Case #%i:%s\n",case_num,"BLACK");
	}
=======
#include <iostream>
#include <fstream>  
using namespace std;

void doMagicianGame(FILE* fp, int white_num, int black_num, int case_num);

int main(){
	FILE * fp = fopen("A-small-practice.in","r");
	FILE * fp_out = fopen("result.txt","w");
	if(fp==NULL){
		printf("file open error");
		printf("\n\t\tpress enter to exit...");
	    getchar();
		return 0;
	}
	int exp_times=0, w_count=0, b_count=0;
	fscanf(fp,"%d",&exp_times);
	//printf("实验次数为 %i\n", exp_times);
	
	for(int i=0; i<exp_times; i++){
		if(feof(fp)) break;
		fscanf(fp,"%i %i",&w_count,&b_count);
		doMagicianGame(fp_out,w_count,b_count,i+1);
		//printf("白球为%i个，黑球为%i个\n",w_count,b_count);
	}

	fclose(fp);
	fclose(fp_out);
	printf("\n\t\tpress enter to exit...");
	getchar();
	return 0;
}

void doMagicianGame(FILE* fp, int white_num, int black_num, int case_num){
	float div_boun = 0.0;
	int random1, random2;
	while(white_num+black_num>1){
		random1 = rand()%(white_num+black_num);
		random2 = rand()%(white_num+black_num);
		while(random2==random1){
			random2 = rand()%(white_num+black_num);
		}
		if(random1<white_num && random2<white_num) white_num--;
		else if(random1>=white_num && random2>=white_num) white_num++,black_num-=2;
		else white_num--;
	}

	if(white_num>0){
		fprintf(fp,"Case #%i: %s\n",case_num,"WHITE");
		//printf("Case #%i:%s\n",case_num,"WHITE");
	}else{
		fprintf(fp,"Case #%i: %s\n",case_num,"BLACK");
		//printf("Case #%i:%s\n",case_num,"BLACK");
	}
>>>>>>> 194f7f9854ba2b4239e312aded309268c3e9d1d4
}