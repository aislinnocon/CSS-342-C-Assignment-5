#include "bank.h"

Bank::Bank()
{
}

Bank::~Bank()
{
}

// Reads transactions from a text file
void Bank::ReadTransaction(string file_name)
{
	ifstream in_file;
	in_file.open(file_name);
	while (!in_file.eof())
    {
        string holder; 
        string type, firstName, lastName;
        int accountID, otherAccountID, fundNumber, otherFundNumber, amount; 
        in_file >> type;
        if (type == "O")
        {
            in_file >> accountID >> lastName >> firstName; 
            Transaction trans(type, accountID, lastName, firstName); 
            commands_.push(trans);
        } 
        if (type == "D")
        {
            in_file >> accountID >> fundNumber >> amount;
            Transaction trans(type, accountID, fundNumber, amount); 
            commands_.push(trans);
        }
        if (type == "W")
        {
            in_file >> accountID >> fundNumber >> amount;
            Transaction trans(type, accountID, fundNumber, amount); 
            commands_.push(trans);
        }
        if (type == "T")
        {
            in_file >> accountID >> fundNumber >> otherAccountID >> otherFundNumber >> amount;
            Transaction trans(type, accountID, fundNumber, otherAccountID, otherFundNumber, amount); 
            commands_.push(trans);
        }
        if (type == "A")
        {
            in_file >> accountID;
            Transaction trans(type, accountID, fundNumber, amount); 
            commands_.push(trans);
        }
        if (type == "F")
        {
            in_file >> accountID >> fundNumber; 
            Transaction trans(type, accountID, fundNumber);
            commands_.push(trans);
        }
    }
    in_file.close(); 
} 

// Creates transaction 
void Bank::ExecuteTransaction()
{
    while(!commands_.empty())
    { 
        Transaction trans = commands_.front();  
        if (trans.getType() == "O")
        {          
            Account *acct = new Account(trans.getFirstName(), trans.getLastName(), trans.getAccountID());
            tree_.Insert(acct);  
        } 
        if (trans.getType() == "D")
        {
            Account *acct; 
            tree_.Retrieve(trans.getAccountID(), acct);
            acct->Deposit(trans.getFundNumber(), trans.getAmount());
            acct->AddFundHistory(trans.getType(), trans.getAccountID(), trans.getFundNumber(), trans.getAmount()); 
        }
        if (trans.getType() == "W")
        {
            Account *acct; 
            tree_.Retrieve(trans.getAccountID(), acct);
            acct->Withdraw(trans.getFundNumber(), trans.getAmount());
        }
        if (trans.getType() == "T")
        {
            Account *acct; 
            tree_.Retrieve(trans.getAccountID(), acct);
            if (trans.getAccountID() == trans.getOtherAccountID())
            {
                acct->FundTransfer(trans.getOtherFundNumber(), trans.getFundNumber(), trans.getAmount());
            }
            else
            {
                Account *other;
                if (tree_.Retrieve(trans.getOtherAccountID(), other))
                {
                    acct->AccountTransfer(*other, trans.getFundNumber(), trans.getOtherFundNumber(), trans.getAmount());
                }
            }
        }
        if (trans.getType() == "A")
        {
            Account *acct;
            tree_.Retrieve(trans.getAccountID(), acct);
            acct->PrintAccountHistory();
        }
        if (trans.getType() == "F")
        {
            Account *acct; 
            tree_.Retrieve(trans.getAccountID(), acct);
            acct->PrintFundHistory(trans.getFundNumber());             
        }
        commands_.pop(); 
    }
}

// Removes account 
void Bank::RemoveAccount(Account *acct)
{
    Account *remove; 
    tree_.Retrieve(acct->getID(), remove);
    remove = NULL; 
}

// Prints out transactions
void Bank::Print() 
{
    tree_.Display();  
}
