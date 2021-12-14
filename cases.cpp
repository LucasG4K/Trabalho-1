#include "BST.hpp"
#include "AVL.hpp"
#include "RB.hpp"
#include <string>
#include <ctime>
#include <fstream>

class Case {
public:
    double BST_time = 0;
    double AVL_time = 0;
    double RB_time  = 0;

    void initInsertionComparision(string ref);
    void initSearchComparision(string ref);
};


void Case::initInsertionComparision(string ref) {
    string data_from_txt;
    clock_t start;

    BST bst;
    AVL avl;
    RB  rb;
    Item item;

    BstNode *bstNode = bst.initialize();
    AvlNode *avlNode = avl.initialize();
    RB      *rbNode  = rb.initialize();

    cout << endl << "ALL TREES HAVE BEEN INITIALIZED" << endl;

    ifstream file;
    file.open(ref);

    if (!file) {
        cout << "Error while opening file '" << ref << "'! >>> ending process..." << endl;
        return;
    }

    cout << "..." << endl;

    // BST INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stof(data_from_txt);
        bst.insertValue(&bstNode, item);
    }
    BST_time = ((clock() - start) / (double)CLOCKS_PER_SEC);
    // bst.preOrderPrint(bstNode);

    file.clear();
    file.seekg(0, ios::beg);

    cout << "..." << endl;

    // AVL INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stof(data_from_txt);
        avl.insertValue(&avlNode, item);
    }
    AVL_time = ((clock() - start) / (double)CLOCKS_PER_SEC);
    
    file.clear();
    file.seekg(0, ios::beg);

    cout << "..." << endl;

    // RB INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stof(data_from_txt);
        rb.insertValue(rbNode, rb.newNode(item));
    }
    RB_time = ((clock() - start) / (double)CLOCKS_PER_SEC);

    cout << "PROCESS COMPLETED SUCCESSFULLY!" << endl;

    printf("BST TIME -> %fs\n", BST_time);
    printf("AVL TIME -> %fs\n", AVL_time);
    printf("RB  TIME -> %fs\n", RB_time);
    file.close();
}

void Case::initSearchComparision(string ref) {
    string data_from_txt;
    clock_t start;

    BST bst;
    AVL avl;
    RB  rb;
    Item item;

    BstNode *bstNode = bst.initialize();
    AvlNode *avlNode = avl.initialize();
    RB      *rbNode  = rb.initialize();

    cout << endl << "ALL TREES HAVE BEEN INITIALIZED" << endl;

    ifstream file;
    file.open(ref);

    if (!file) {
        cout << "Error while opening file '" << ref << "'! >>> ending process..." << endl;
        return;
    }

    cout << "..." << endl;

    // BST INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stof(data_from_txt);
        bst.insertValue(&bstNode, item);
    }
    BST_time = ((clock() - start) / (double)CLOCKS_PER_SEC);
    // bst.preOrderPrint(bstNode);

    file.clear();
    file.seekg(0, ios::beg);

    cout << "..." << endl;

    // AVL INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stof(data_from_txt);
        avl.insertValue(&avlNode, item);
    }
    AVL_time = ((clock() - start) / (double)CLOCKS_PER_SEC);
    
    file.clear();
    file.seekg(0, ios::beg);

    cout << "..." << endl;

    // RB INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stof(data_from_txt);
        rb.insertValue(rbNode, rb.newNode(item));
    }
    RB_time = ((clock() - start) / (double)CLOCKS_PER_SEC);

    cout << "PROCESS COMPLETED SUCCESSFULLY!" << endl;

    printf("BST TIME -> %fs\n", BST_time);
    printf("AVL TIME -> %fs\n", AVL_time);
    printf("RB  TIME -> %fs\n", RB_time);
    file.close();
}