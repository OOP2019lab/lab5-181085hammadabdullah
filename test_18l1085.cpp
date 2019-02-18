#include "stdafx.h"
#include "q1_18l1085.h"
int main(){
	string name="john";
	int id=549002;
	bankaccount myaccount=bankaccount(name,id);
	myaccount.withdraw(2000);
	myaccount.depoist(2500000);
	myaccount.depoist(50000);//call withdraw and depoist
	//myaccount.depoist(10000);
	myaccount.withdraw(2000);
	myaccount.print();
	system("pause");
	return 0;
}
