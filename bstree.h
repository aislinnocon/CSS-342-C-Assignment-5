#ifndef BSTree_H_
#define BSTree_H_
#include "account.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class BSTree
{

private:
    struct Node
    {
        Account *pAcct;
        Node *right;
        Node *left;
    };
    // Node* InsertHelper(Node *node, Account *acct); 
    Node *root;

public:
    BSTree();
    ~BSTree();
    bool Insert(Account *acct);
    bool InsertHelper(Node *&node, Account *acct);

    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    bool Retrieve(const int &ptr, Account * &acct) const;
    bool RetrieveHelper(Node *node, const int &ptr, Account * &acct) const; 

    // displays the contents of a tree to cout
    void Display() const;
    void DisplayHelper(Node *node) const; 

    void Empty();
    bool isEmpty() const;
};
#endif