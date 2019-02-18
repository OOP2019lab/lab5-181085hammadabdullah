#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
class bankaccount{
private://variables
	string Name;
	float bal;
	float ballimit;
	int *tran;
	int capacity;
	int accId;
	int nooftran;
public:
	//functions
	bankaccount(string name,int Id);
	void withdraw(int amount);
	void depoist(int account);
	void inctrancap();
	void print();

	~bankaccount();
};