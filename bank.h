#ifndef BANK_H_
#define BANK_H_
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include "account.h"
#include "transaction.h"
#include "bstree.h"
using namespace std;

class Bank
{
public:
    Bank();
    ~Bank(); 

    //Actions
    void ReadTransaction(string file_name); 
    void ExecuteTransaction();
    void RemoveAccount(Account *acct); 
    void Print();

private:
    queue<Transaction> commands_;
    BSTree tree_; 
};
#endif