#include"top.h"

std::map<int,string>numToStr;
bool isInit=0;
void initNumToStrVec(){
	numToStr.insert(pair<int,string>(1,"One"));
	numToStr.insert(pair<int,string>(2,"Two"));
	numToStr.insert(pair<int,string>(3,"Three"));
	numToStr.insert(pair<int,string>(4,"Four"));
	numToStr.insert(pair<int,string>(5,"Five"));
	numToStr.insert(pair<int,string>(6,"Six"));
	numToStr.insert(pair<int,string>(7,"Seven"));
	numToStr.insert(pair<int,string>(8,"Eight"));
	numToStr.insert(pair<int,string>(9,"Nine"));
	numToStr.insert(pair<int,string>(10,"Ten"));
	numToStr.insert(pair<int,string>(11,"Eleven"));
	numToStr.insert(pair<int,string>(12,"Twelve"));
	numToStr.insert(pair<int,string>(13,"Thirteen"));
	numToStr.insert(pair<int,string>(14,"Fourteen"));
	numToStr.insert(pair<int,string>(15,"Fifteen"));
	numToStr.insert(pair<int,string>(16,"Sixteen"));
	numToStr.insert(pair<int,string>(17,"Seventeen"));
	numToStr.insert(pair<int,string>(18,"Eighteen"));
	numToStr.insert(pair<int,string>(19,"Nineteen"));
	numToStr.insert(pair<int,string>(20,"Twenty"));
	numToStr.insert(pair<int,string>(30,"Thirty"));
	numToStr.insert(pair<int,string>(40,"Forty"));
	numToStr.insert(pair<int,string>(50,"Fifty"));
	numToStr.insert(pair<int,string>(60,"Sixty"));
	numToStr.insert(pair<int,string>(70,"Seventy"));
	numToStr.insert(pair<int,string>(80,"Eighty"));
	numToStr.insert(pair<int,string>(90,"Ninety"));
	numToStr.insert(pair<int,string>(100,"Hundred"));
	numToStr.insert(pair<int,string>(1000,"Thousand"));
	numToStr.insert(pair<int,string>(1000000,"Million"));
	numToStr.insert(pair<int,string>(1000000000,"Billion"));
}

string Solution::numberToWords(int num){
	if(num==0) return "Zero";
	if(!isInit){
        initNumToStrVec();
        isInit=1;
    }
	string result="";
	string postfix="";
	int temp_base=1000000000;
	int temp_num;
	int temp_residu=num;
	int hundred_num,ten_num,one_num;

	//--------!!!错误1：当心除法，当temp_base=0时，除法会出错
	//--------!!!错误2：后缀处理，不能忘了，且需要当temp_num>0时才有效
	//--------!!!错误3：空格处理
	//--------!!!错误4：输入0
	while(temp_base){
		temp_num=temp_residu/temp_base;
		temp_residu=temp_residu%temp_base;

		postfix=numToStr.find(temp_base)->second;
		hundred_num=temp_num/100;
		ten_num=temp_num%100/10;
		one_num=temp_num%10;

		if(hundred_num){
			if(result.size()) result+=" ";
			result=result+numToStr.find(hundred_num)->second+" "+"Hundred";
		}
		if(ten_num>=2){
			if(result.size()) result+=" ";
			result=result+numToStr.find(ten_num*10)->second;
			if(one_num){
				if(result.size()) result+=" ";
				result=result+numToStr.find(one_num)->second;
			}
		}else if(ten_num){
			if(result.size()) result+=" ";
			result=result+numToStr.find(temp_num%100)->second;
		}else if(one_num){
			if(result.size()) result+=" ";
			result=result+numToStr.find(one_num)->second;
		}

		if(temp_base>1 && temp_num) result=result+" "+postfix;
		
		temp_base/=1000;
	}
	return result;
}
void let_273(){
	ifstream fin;
	fin.open("let_273.txt");
	int N;fin>>N;
	int value;

	Solution sol;
	FOR(i,N){
		fin>>value;
		cout<<"Case "<<i+1<<": "<<endl;
		cout<<sol.numberToWords(value)<<endl;
	}
}