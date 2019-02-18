
#include "stdafx.h"
#include "q1_18l1085.h"

bankaccount::bankaccount(string name,int accid){
	Name=name;
	accId=accid;
	tran=nullptr;
	capacity=1;
	nooftran=0;
	bal=100000;
	ballimit=200000;
}
void bankaccount::inctrancap(){
	capacity=capacity*2;
}
void bankaccount::print(){
	cout<<"The Name Of Account Holder Is :"<<Name<<endl;
	cout<<"The Account Of User Is :"<<accId<<endl;
	cout<<"Thye balance Of User Is :"<<bal<<endl;
	cout<<"Total transictions of this user is "<<nooftran<<endl;
	for(int i=0;i<nooftran;i++){
		cout<<"Transition NO "<<i+1<<" is "<<tran[i]<<endl;
	}
}
void bankaccount::withdraw(int amount){
	if(bal>=amount){//Check
		if(tran!=nullptr && nooftran<capacity){//Enough Space
			bal=bal-amount;
			tran[nooftran]=-amount;
			nooftran++;
			cout<<"Trnasiction NO " <<nooftran <<" Successfull"<<endl;
		}
		else if(tran!=nullptr && nooftran>=capacity){//NOt Empty but no space more
			int *temp=new int[capacity*2];
			for(int i=0;i<nooftran;i++){
				temp[i]=tran[i];
			}
			bal=bal-amount;
			temp[nooftran]=-amount;
			delete [] tran;
			tran=temp;
			inctrancap();
			nooftran++;
			cout<<"Trnasiction NO " <<nooftran <<" Successfull"<<endl;

		}
		else if(tran==nullptr){//For First Transiction
			tran=new int[capacity];
			tran[0]=-amount;
			bal=bal-amount;
			nooftran++;
			cout<<"Trnasiction NO " <<nooftran <<" Successfull"<<endl;
		}
	}
	else{
		cout<<"Trnasiction Unsuccessfull Insufficient balance"<<endl;
	}

}
void bankaccount::depoist(int amount){
	if(bal+amount<=ballimit){
		if(tran!=nullptr && nooftran<capacity){//Enough Space
			bal=bal+amount;
			tran[nooftran]=amount;
			nooftran++;
			cout<<"Trnasiction NO " <<nooftran <<" Successfull"<<endl;
		}
		else if(tran!=nullptr && nooftran>=capacity){//NOt Empty but no more space
			int *temp=new int[capacity*2];
			for(int i=0;i<nooftran;i++){
				temp[i]=tran[i];
			}
			bal=bal+amount;
			temp[nooftran]=amount;
			delete [] tran;
			tran=temp;
			inctrancap();
			nooftran++;
			cout<<"Trnasiction NO " <<nooftran <<" Successfull"<<endl;
		}
		else if(tran==nullptr){//For First Transiction
			tran=new int[capacity];
			tran[0]=amount;
			bal=bal+amount;
			nooftran++;
			cout<<"Trnasiction NO " <<nooftran <<" Successfull"<<endl;
		}
	}
	else{
		cout<<"Transiction Unsuuessfull because Of crossing limit"<<endl;
	}
}

bankaccount::~bankaccount(){

	delete [] tran;
}
