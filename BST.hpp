#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include "item.hpp"
using namespace std;

class BstNode {
public:
    BstNode *left;
    BstNode *right;
    Item item;
};

class BST {
public:
    BstNode *initialize();                                            // root of the tree          obs: to return a Null Ptr from a function, it must be a Ptr function too
    void insertValue(BstNode **node, Item requestedValue);            // insert some requested int value on tree
    void search(BstNode **node, BstNode **temp, Item requestedValue); // search for an exclusive value on the tree
    
    void preOrderPrint(BstNode *node);                                // print the PreOrder tree
    void inOrderPrint(BstNode *node);                                 //  ...  ... InOrder   ..
    void postOrderPrint(BstNode *node);                               //  ...  ... PostOrder ..
};

#endif