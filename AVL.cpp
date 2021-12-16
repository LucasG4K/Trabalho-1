#include "AVL.hpp"

AvlNode* AVL::initialize() {
    return NULL;
}

void AVL::insertValue(AvlNode **node, Item requestedValue) {    
    if (*node == NULL) {
        *node           = (AvlNode*)malloc(sizeof(AvlNode));
        (*node)->item   = requestedValue;
        (*node)->left   = NULL;
        (*node)->right  = NULL;
        (*node)->weight = 0;
    } else {
        if ((*node)->item.value > requestedValue.value) {
            insertValue(&(*node)->left, requestedValue);
            // unbalanced to the left
            if (getWeight(&(*node)->left) - getWeight(&(*node)->right) == 2) {
                if ((*node)->left->item.value > requestedValue.value)
                    singleRightRotation(node);
                else
                    doubleRightRotation(node);
            }
        } else if ((*node)->item.value < requestedValue.value) {
            insertValue(&(*node)->right, requestedValue);
            // unbalanced to the right
            if (getWeight(&(*node)->right) - getWeight(&(*node)->left) == 2) {
                if ((*node)->right->item.value < requestedValue.value)
                    singleLeftRotation(node);
                else
                    doubleLeftRotation(node);
            }
        }
    }
    (*node)->weight = maxHeight(getWeight(&(*node)->left), getWeight(&(*node)->right)) + 1;
}

void AVL::search(AvlNode **node, AvlNode **temp, Item requestedValue) {
    if (*node == NULL) {
        // cout << "[ERROR]: NODE NOT FOUND" << endl;
        return;
    } else if ((*node)->item.value > requestedValue.value) { 
        search(&(*node)->left, temp, requestedValue);
        return;
    } else if ((*node)->item.value < requestedValue.value) {
        search(&(*node)->right, temp, requestedValue);
        return;
    }
    // cout << "NODE FOUNDED" << endl;
    *temp = *node;
}

int AVL::getWeight(AvlNode **node) {
    if (*node == NULL)
        return -1;
    return (*node)->weight;
}

int AVL::maxHeight(int left, int right) {
    if (left > right)
        return left;
    return right;
}

void AVL::singleRightRotation(AvlNode **node) {
    AvlNode *temp;
    temp = (*node)->left;
    (*node)->left = temp->right;
    temp->right = (*node);
    (*node)->weight = maxHeight(getWeight(&(*node)->left), getWeight(&(*node)->right)) + 1;
    temp->weight = maxHeight(getWeight(&temp->left), getWeight(&temp->right)) + 1;
    (*node) = temp;
}

void AVL::singleLeftRotation(AvlNode **node) {
    AvlNode *temp;
    temp = (*node)->right;
    (*node)->right = temp->left;
    temp->left = (*node);
    (*node)->weight = maxHeight(getWeight(&(*node)->left), getWeight(&(*node)->right)) + 1;
    temp->weight = maxHeight(getWeight(&temp->left), getWeight(&temp->right)) + 1;
    (*node) = temp;
}

void AVL::doubleRightRotation(AvlNode **node) {
    singleLeftRotation(&(*node)->left);
    singleRightRotation(node);
}

void AVL::doubleLeftRotation(AvlNode **node) {
    singleRightRotation(&(*node)->right);
    singleLeftRotation(node);
}

void AVL::preOrderPrint(AvlNode *node) {
    if (node != NULL) {
        // cout << node->item.value << ":" << node->weight << "\t";
        printf("%f ",  node->item.value);
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}

void AVL::inOrderPrint(AvlNode *node) {
    if (node != NULL) {
        inOrderPrint(node->left);
        printf("%f ",  node->item.value);
        inOrderPrint(node->right);
    }
}

void AVL::postOrderPrint(AvlNode *node) {
    if (node != NULL) {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        printf("%f ",  node->item.value);
    }
}