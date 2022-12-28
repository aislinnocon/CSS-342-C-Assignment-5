#include <iostream>
#include "transaction.h"
#include "account.h"
#include "bank.h"
#include <queue>
#include <string>
using namespace std;
	
int main(int argc, char* argv[])
{ 
  Bank bank;
  bank.ReadTransaction("bank_trans_in.txt");
  bank.ExecuteTransaction();
  bank.Print();
}  