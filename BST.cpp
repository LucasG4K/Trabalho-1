#include "BST.hpp"

BstNode* BST::initialize() {
    return NULL;
}

void BST::insertValue(BstNode **node, Item requestedValue) {
    if (*node == NULL) {
        *node          = (BstNode*)malloc(sizeof(BstNode));
        (*node)->item  = requestedValue;
        (*node)->left  = NULL;
        (*node)->right = NULL;
    } else {
        if ((*node)->item.value > requestedValue.value) {
            insertValue(&(*node)->left, requestedValue);
        } else if ((*node)->item.value < requestedValue.value) {
            insertValue(&(*node)->right, requestedValue);
        }
    }
}

void BST::search(BstNode **node, BstNode **temp, Item requestedValue) {
    if (*node == NULL) {
        // cout << "[ERROR]: NODE NOT FOUND" << endl;
        return;
    }

    if ((*node)->item.value > requestedValue.value) { 
        search(&(*node)->left, temp, requestedValue);
        return;
    } else if ((*node)->item.value < requestedValue.value) {
        search(&(*node)->right, temp, requestedValue);
        return;
    }
    // cout << "NODE FOUNDED" << endl;
    *temp = *node;
}

void BST::preOrderPrint(BstNode *node){
    if (node != NULL) {
        preOrderPrint(node->left);
        preOrderPrint(node->right);
        printf("%f ",  node->item.value);
    }
}

void BST::inOrderPrint(BstNode *node){
    if (node != NULL) {
        inOrderPrint(node->left);
        printf("%f ",  node->item.value);
        inOrderPrint(node->right);
    }
}

void BST::postOrderPrint(BstNode *node){
    if (node != NULL) {
        printf("%f ",  node->item.value);
        postOrderPrint(node->left);
        postOrderPrint(node->right);
    }
}