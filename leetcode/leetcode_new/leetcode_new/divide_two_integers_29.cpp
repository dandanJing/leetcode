#include"top.h"

int Solution::divide(int dividend, int divisor){
	if(divisor==0 && dividend!=0) return 0x7fffffff;
        else if(divisor==0) return 0;
        else if(dividend==0) return 0;
        else if(divisor==1) return dividend;
        else if(divisor==-1 && dividend==0x80000000) return 0x7fffffff;
        else if(divisor==-1) return -dividend;
        else if(divisor==0x80000000 && dividend==0x80000000)return 1;
        else if(divisor==0x80000000) return 0;
        
        int divabs = abs(divisor);
        int dividabs = abs(dividend);
        if(dividend==0x80000000){
            dividabs = abs(dividend+1);
        }
        
        if(dividabs<divabs) return 0;
        
        int result = 0;
        int base=0;
        int temp=divabs>>1;
        while(temp){
            base++;
            temp=temp>>1;
        }
        
        int val1=dividabs>>(base+1);
        int val2=dividabs>>(base);
		temp = val2;
        int tbase=0;
        int tcum=dividabs;
        while(temp){
            if(temp%2){
                tcum-=(divabs<<tbase);
            }
            temp=temp>>1;
            tbase++;
        }

        bool isfit=false;
		if(divabs==1<<base) {isfit=true; result=val2;}
		else if(val2==1)result=val2;
		else if(tcum>0) result=val2;
        else{
            while(1){
                if(val1+1>=val2) {
					result=val1;
					break;
				}
                temp=(val1+val2)>>1;
                int cur=temp;
                int cum=0;
                base=0;
                while(temp){
                    if(temp%2){
                        cum+=(divabs<<base);
                    }
                    temp=temp>>1;
                    base++;
                }
                if(cum==dividabs){
                    result=cur;
                    isfit=true;
                    break;
                }else if(cum>dividabs || cum<0){
                    val2=cur;
                }else{
                    val1=cur;
                }
            }
        }
         if(dividend==0x80000000){
             temp = result+1;
             base=0;
             int cum=0;
             while(temp){
                 if(temp%2){
                     cum-=(divabs<<base);
                 }
                 temp=temp>>1;
                 base++;
             }
			 if(cum==0x80000000) {result=result+1;isfit=true;}
         }
        if((dividend<0 && divisor<0) || (dividend>0 && divisor>0))return result;
        else if(isfit)return -result;
        else return -result;
}

void let_29(){
	Solution sol;
	cout<<sol.divide(2147483647,3)<<endl;//715827882
	cout<<sol.divide(-1048958272,336470323)<<endl;//-3
	cout<<sol.divide(1026117192,-874002063)<<endl;//-1
	cout<<sol.divide(-2147483648,2)<<endl;//-1073741824
	cout<<sol.divide(1036963541,-24409858)<<endl;//-42
}