#ifndef RB_HPP
#define RB_HPP
#include <iostream>
#include "item.hpp"
using namespace std;

#define RED   true
#define BLACK false

class RbNode {
public:
    Item  item;
    RbNode *left;
    RbNode *right;
    RbNode *parent;
    bool  color;
};

class RB {
public:
    RbNode *root;
    RbNode *NIL;
    RB *initialize();                                               // root of the RB
    void insertValue(RB *tree, RbNode *node);                       // insert some requested int value on tree
    void search(RbNode **node, RbNode **temp, Item requestedValue); // search for an exclusive value on the tree
    RbNode *newNode(Item requestedValue);                           // must be passed to the insertValue function
    void rightRotation(RbNode *node, RB *tree);
    void leftRotation(RbNode *node, RB *tree);
    void insertion_fixup(RbNode *node, RB *tree);

    void preOrderPrint(RB *tree, RbNode *node);   // print the PreOrder tree
    void inOrderPrint(RB *tree, RbNode *node);    //  ...  ... InOrder   ..
    void postOrderPrint(RB *tree, RbNode *node);  //  ...  ... PostOrder ..
};

#endif