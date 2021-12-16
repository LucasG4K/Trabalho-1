#include "BST.hpp"
#include "AVL.hpp"
#include "RB.hpp"
#include <fstream>
#include <string>
#include <ctime>

class Case {
public:
    double BST_time = 0;
    double AVL_time = 0;
    double RB_time  = 0;

    void initInsertionComparision(string ref);
    void initSearchComparision(string ref, BstNode *bstNode, AvlNode *avlNode, RB *rbNode);
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

    cout << "READING '" << ref << "' AND INSERTING INTO BST..." << endl;

    // BST INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stod(data_from_txt);
        bst.insertValue(&bstNode, item);
    }
    BST_time = ((clock() - start) / (double)CLOCKS_PER_SEC);

    file.clear();
    file.seekg(0, ios::beg);

    cout << "READING '" << ref << "' AND INSERTING INTO AVL..." << endl;

    // AVL INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stod(data_from_txt);
        avl.insertValue(&avlNode, item);
    }
    AVL_time = ((clock() - start) / (double)CLOCKS_PER_SEC);
    
    file.clear();
    file.seekg(0, ios::beg);

    cout << "READING '" << ref << "' AND INSERTING INTO RB..." << endl;

    // RB INSERTION
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stod(data_from_txt);
        rb.insertValue(rbNode, rb.newNode(item));
    }
    RB_time = ((clock() - start) / (double)CLOCKS_PER_SEC);

    cout << "PROCESS COMPLETED SUCCESSFULLY!" << endl;

    printf("BST TIME -> %fs\n", BST_time);
    printf("AVL TIME -> %fs\n", AVL_time);
    printf("RB  TIME -> %fs\n", RB_time);
    file.close();

    int option;
    do {
        cout << "=====================" << endl;
        cout << "    INPUT OPTIONS" << endl;
        cout << "=====================" << endl;
        cout << "ref: SEARCH" << endl;
        cout << "1 - 5.000" << endl << "2 - 10.000" << endl << "3 - 100.000" << endl << "0 - RETURN" << endl;
        cout << "Option: ";
        cin  >> option;

        switch (option) {
        case 1:
            initSearchComparision("sample/search_five_thousand.txt", bstNode, avlNode, rbNode);
            break;
        
        case 2:
            initSearchComparision("sample/search_ten_thousand.txt", bstNode, avlNode, rbNode);
            break;
        
        case 3:
            initSearchComparision("sample/search_one_hundred_thousand.txt", bstNode, avlNode, rbNode);
            break;

        case 0:
            return;
            break;
        
        default:
            cout << "Option not found!" << endl;
            break;
        }
    } while (option != 0);
}

void Case::initSearchComparision(string ref, BstNode *bstNode, AvlNode *avlNode, RB *rbNode) {
    string data_from_txt;
    clock_t start;

    BST bst;
    AVL avl;
    RB  rb;
    Item item;

    BstNode *bstTemp = NULL;
    AvlNode *avlTemp = NULL;
    RbNode  *rbTemp  = NULL;

    int bstFind = 0;
    int avlFind = 0;
    int rbFind  = 0;

    ifstream file;
    file.open(ref);

    if (!file) {
        cout << "Error while opening file '" << ref << "'! >>> ending process..." << endl;
        return;
    }
    
    cout << "READING '" << ref << "' AND SEARCHING IN BST..." << endl;

    // BST SEARCH
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stod(data_from_txt);
        bst.search(&bstNode, &bstTemp, item);
        if (bstTemp != NULL) {
            bstFind++;
        }
        bstTemp = NULL;
    }
    BST_time = ((clock() - start) / (double)CLOCKS_PER_SEC);
    free(bstTemp);

    file.clear();
    file.seekg(0, ios::beg);

    cout << "READING '" << ref << "' AND SEARCHING IN AVL..." << endl;

    // AVL SEARCH
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stod(data_from_txt);
        avl.search(&avlNode, &avlTemp, item);
        if (avlTemp != NULL) {
            avlFind++;
        }
        avlTemp = NULL;
    }
    AVL_time = ((clock() - start) / (double)CLOCKS_PER_SEC);
    free(avlTemp);
    
    file.clear();
    file.seekg(0, ios::beg);

    cout << "READING '" << ref << "' AND SEARCHING IN RB..." << endl;

    // RB SEARCH
    start = clock();
    while (file.good()) {
        file >> data_from_txt;
        item.value = stod(data_from_txt);
        rb.search(&rbNode->root, &rbTemp, item);
        if (rbTemp != NULL) {
            rbFind++;
        }
        rbTemp = NULL;
    }
    RB_time = ((clock() - start) / (double)CLOCKS_PER_SEC);
    free(rbTemp);

    cout << "PROCESS COMPLETED SUCCESSFULLY!" << endl;

    printf("BST FINDED -> %d\n", bstFind);
    printf("AVL FINDED -> %d\n", avlFind);
    printf("RB  FINDED -> %d\n", rbFind);

    printf("BST TIME -> %fs\n", BST_time);
    printf("AVL TIME -> %fs\n", AVL_time);
    printf("RB  TIME -> %fs\n", RB_time);
    file.close();
}