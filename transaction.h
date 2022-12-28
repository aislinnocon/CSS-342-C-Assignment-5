#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include "account.h"
using namespace std;

class Transaction
{
public:
    // Constructors
    Transaction();
    Transaction(string type, int accountID, string lastName, string firstName); 
    Transaction(string type, int accountID, int fundNumber, int amount);
    Transaction(string type, int accountID, int fundNumber, int otherAccountID, 
        int otherFundNumber, int amount);
    Transaction(string type, int accountID); 
    Transaction(string type, int accountID, int fundNumber); 
    
    // Deconstructors
    ~Transaction();

    // Getter-Setters
    string getType() const; 
    string getLastName() const;
    string getFirstName() const;
    int getAccountID() const;
    int getOtherAccountID() const;
    int getFundNumber() const;
    int getOtherFundNumber() const;
    int getAmount() const;    

    // Used for testing
    friend ostream & operator<<(ostream &os, Transaction &reader);
    
private:
    string type_; 
    string lastName_;
    string firstName_;
    int accountID_;
    int otherAccountID_;
    int fundNumber_;
    int otherFundNumber_; 
    int amount_;   
    
}; 
#endif