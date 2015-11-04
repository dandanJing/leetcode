#include"top.h"

struct ListNode1 {
     int val;
	 int base;
     ListNode1 *next;
     ListNode1(int x,int y) : val(x),base(y), next(NULL) {}
};

int compareVal(int val1,int val2,int base1,int base2){
	if(val1==val2) return 0;

	int basediff=max(base1,base2)/min(base1,base2);
	int cmp1=val1,cmp2=val2;
	if(base1>base2){
		cmp1=val1/basediff;
	}else if(base1<base2){
		cmp2=val2/basediff;
	}
	if(cmp1>cmp2)return 1;
	else if(cmp1<cmp2) return -1;
	else if(base1>base2){
		int val_l= (val1%basediff);
		return compareVal(val_l,val2,basediff/10,base2);
	}else{
		int val_l= (val2%basediff);
		return compareVal(val1,val_l,base1,basediff/10);
	}
}

void insertNode(ListNode1* root, ListNode1* to_insert){
	if(root->base==-1) {
		root->base=to_insert->base;
		root->val=to_insert->val;
		delete to_insert;
		return;
	}
	ListNode1* temp=root,* p_pre=root;
	if(compareVal(temp->val,to_insert->val,temp->base,to_insert->base)<=0){
		int base=to_insert->base;
		int val=to_insert->val;
		to_insert->next=temp->next;
		temp->next=to_insert;
		to_insert->base=temp->base;
		to_insert->val=temp->val;
		temp->base=base;
		temp->val=val;
		return;
	}
	temp=root->next;
	while(temp){
		if(compareVal(temp->val,to_insert->val,temp->base,to_insert->base)<=0) break;
		p_pre=temp;
		temp=temp->next;
	}
	to_insert->next=p_pre->next;
	p_pre->next=to_insert;
}

void findBarrelSort(vector<int> nums,ListNode1* result[]){
	int base,temp;
	FOR(i,nums.size()){
		base=1;
		while(nums[i]/base>=10) base*=10;
		temp=nums[i]/base;
		ListNode1* cur=(ListNode1*) new ListNode1(nums[i],base);
		insertNode(result[temp],cur);
	}
}

//---!!!!错误1：输入[0,0]，输出"0"，实际输出为“00”
string Solution::largestNumber(vector<int>& nums){
	ListNode1* bar_sort[10];
	FOR(i,10) bar_sort[i]=(ListNode1*) new ListNode1(-1,-1);

	findBarrelSort(nums,bar_sort);
	string result="";
	char cur_char;
	int zero_count=0;
	for(int i=9;i>=0;i--){
		ListNode1* temp=bar_sort[i];
		if(temp->base==-1) continue;
		while(temp){
			int cur_val=temp->val;
			int cur_base=temp->base;
			if(cur_val==0 && zero_count && result.size()==1) {temp=temp->next;continue;}
			else if(cur_val==0)zero_count++;

			while(cur_base){
				cur_char=cur_val/cur_base+'0';
				result+=cur_char;
				cur_val%=cur_base;
				cur_base/=10;
			}
			temp=temp->next;
		}
	}
	return result;
}

void let_179(){
	ifstream fin;
	fin.open("let_179.txt");
	int value;
	char temp;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.largestNumber(nums)<<endl;
}