#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include "item.hpp"
using namespace std;

class AvlNode {
public:
    AvlNode *left;
    AvlNode *right;
    Item item;
    int  weight;
};

class AVL {
public:
    AvlNode *initialize();                                              // root of the tree          obs: to return a Null Ptr from a function, it must be a Ptr function too
    void insertValue(AvlNode **node, Item requestedValue);              // insert some requested int value on tree
    void search(AvlNode **node, AvlNode **temp, Item requestedValue);   // search for an exclusive value on the tree
    int  getWeight(AvlNode **node);                                     // return the current weight of each child or -1 if the children are NULL
    int  maxHeight(int left, int right);                                // get the most deep node -> the max height of tree
    
    void singleRightRotation(AvlNode **node);
    void singleLeftRotation(AvlNode **node);
    void doubleRightRotation(AvlNode **node);
    void doubleLeftRotation(AvlNode **node);


    void preOrderPrint(AvlNode *node);                                 // print the PreOrder tree
    void inOrderPrint(AvlNode *node);                                  //  ...  ... InOrder   ..
    void postOrderPrint(AvlNode *node);                                //  ...  ... PostOrder ..
};

#endif