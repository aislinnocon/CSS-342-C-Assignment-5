#include "bstree.h"
#include "account.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Default Constructor
BSTree::BSTree()
{
    root = NULL; 
}

// Destructor
BSTree::~BSTree()
{
    Empty(); 
}

// Inserts account into binary search tree
bool BSTree::Insert(Account *acct)
{ 
    return InsertHelper(root, acct);
}

// Recursive helper for Insert()
bool BSTree::InsertHelper(Node *&node, Account *acct)
{
    if(node == NULL)
    {
        node = new Node;
        node->pAcct = acct;
        node->left = NULL;
        node->right = NULL;    
        return true;  
    }
    else if (node->pAcct->getID() < acct->getID())
    {
        if (node->right == NULL)
        {
            Node *n = new Node;
            n->pAcct = acct;
            n->left = NULL;
            n->right = NULL; 
            node->right = n;    
            return true;  
        }
        else 
        {
            return InsertHelper(node->right, acct);
        }  
    } 
    else if (node->pAcct->getID() > acct->getID())
    {
        if (node->left == NULL)
        {
            Node *n = new Node;
            n->pAcct = acct;
            n->left = NULL;
            n->right = NULL;
            node->left = n;     
            return true;  
        }
        else 
        {
            return InsertHelper(node->left, acct);
        }
    }
    else
    {
        cerr << "ERROR: Account " << acct->getID() << " is already open. Transaction refused." << endl;
        return false;
    }
}  

// Finds the account within the binary search tree and sets a pointer to the account's value
bool BSTree::Retrieve(const int &ptr, Account * &acct) const 
{
    return RetrieveHelper(root, ptr, acct); 
}

// Recursive helper for Retrieve()
bool BSTree::RetrieveHelper(Node *node, const int &ptr, Account * &acct) const
{
    if(node != NULL && node->pAcct->getID() == ptr)
    {
        acct = node->pAcct;     
        return true; 
    }
    else if (node != NULL && node->pAcct->getID() < ptr)
    {
        return RetrieveHelper(node->right, ptr, acct);
    }
    else if (node != NULL && node->pAcct->getID() > ptr)
    {
        return RetrieveHelper(node->left, ptr, acct);
    }  
    else 
    {
        cerr << "ERROR: Account " << ptr << " not found. Transferal refused. " << endl;
        return false;
    }
} 

// Prints out lowest account ID to highest account ID
void BSTree::Display() const
{
    if (root == NULL)
    {
        cerr << "Error: Binary Search Tree is empty." << endl;
    }
    else 
    {
        DisplayHelper(root); 
    } 
}  

// Recursive helper for Display()
void BSTree::DisplayHelper(Node *node) const
{
    if (node == NULL)
    {
        return; 
    }
    DisplayHelper(node->left);
    cout << *node->pAcct << endl;
    DisplayHelper(node->right);    
}  

// Empties the binary search tree
void BSTree::Empty()
{
    delete root;
    root = NULL; 
}

// Checks if binary search tree is empty
bool BSTree::isEmpty() const
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    else 
    {
        return false; 
    } 
}