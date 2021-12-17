#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "item.hpp"
#include "AVL.hpp"
using namespace std;

#define THOUSAND  1000
#define TEN_THOUSAND 10000
#define MILLION  1000000

double get_random() { return (1 + (double)rand() / (double)RAND_MAX * 100000); }

int main() {
    string ref1 = "sample/insert_thousand.txt";
    string ref2 = "sample/insert_ten_thousand.txt";
    string ref3 = "sample/insert_million.txt";

    fstream fileT, fileTT, fileM;
    fileT.open(ref1, ios::in | ios::out | ios::trunc);
    fileTT.open(ref2, ios::in | ios::out | ios::trunc);
    fileM.open(ref3, ios::in | ios::out | ios::trunc);

    // FILES VERIFICATION
    if (!fileT) {
        cout << "Error while opening file '" << ref1 << "'! >>> ending process..." << endl;
        exit(0);
    }
    if (!fileTT) {
        cout << "Error while opening file '" << ref2 << "'! >>> ending process..." << endl;
        exit(0);
    }
    if (!fileM) {
        cout << "Error while opening file '" << ref3 << "'! >>> ending process..." << endl;
        exit(0);
    }

    cout << "All files have been opened without error and are receiving data!" << endl;
    cout << "It may take a while to verify and allocate data..." << endl << endl;
    //=========================
    
    AVL avl;
    Item item;
    AvlNode *avlNode = avl.initialize();
    AvlNode *avlTemp = avl.initialize();

    int cont1 = 0, cont2 = 0, cont3 = 0;
    char *data = (char*)malloc(sizeof(char*));

    srand(time(NULL));
    
    for (int i = 0; i < MILLION; i++) {
        if (i < THOUSAND) {
            int j = i;
            while (j < i + 1) {
                i < THOUSAND - 1 ? sprintf(data, "%.6f\n", get_random()) : sprintf(data, "%.6f", get_random());
                item.value = stod(data);
                avlTemp = NULL;
                avl.search(&avlNode, &avlTemp, item);

                if (avlTemp == NULL) {
                    avl.insertValue(&avlNode, item);
                    fileT << data;
                    j++;
                } else cont1++;
            }
        }
        if (i < TEN_THOUSAND) {
            int j = i;
            while (j < i + 1) {
                i < TEN_THOUSAND - 1 ? sprintf(data, "%.6f\n", get_random()) : sprintf(data, "%.6f", get_random());
                item.value = stod(data);
                avlTemp = NULL;
                avl.search(&avlNode, &avlTemp, item);

                if (avlTemp == NULL) {
                    avl.insertValue(&avlNode, item);
                    fileTT << data;
                    j++;
                } else cont2++;
            }
        }
        int j = i;
        while (j < i + 1) {
            i < MILLION - 1 ? sprintf(data, "%.6f\n", get_random()) : sprintf(data, "%.6f", get_random());
            item.value = stod(data);
            avlTemp = NULL;
            avl.search(&avlNode, &avlTemp, item);
            if (avlTemp == NULL) {
                avl.insertValue(&avlNode, item);
                fileM << data;
                j++;
            } else cont3++;
        }
    }
    free(avlNode);
    
    fileT.close();
    fileTT.close();
    fileM.close();

    cout << "REPETITIONS AVOIDED IN 1.000 FILE: " << cont1 << endl;
    cout << "REPETITIONS AVOIDED IN 10.000 FILE: " << cont2 << endl;
    cout << "REPETITIONS AVOIDED IN 1.000.000 FILE: " << cont3 << endl << endl;

    cout << "ALL SET!" << endl;

    return 0;
}

/*  ========================================================================
    // CODE NOT USED; IT WAS MADE JUST TO BE SURE IF THERE IS NO REPETITION IN FILE
    INSERT IN LINE 99 TO TEST

    cout << "FILES ARE READY! VERIFYING POSSIBLE REPETITIONS" << endl;
    
    int repeat1 = 0, repeat2 = 0, repeat3 = 0;

    fileT.clear();
    fileT.seekg(0, ios::beg);
    fileTT.clear();
    fileTT.seekg(0, ios::beg);
    fileM.clear();
    fileM.seekg(0, ios::beg);

    string data_from_txt;
    AvlNode *avlSecondNode = avl.initialize();

    while (fileT.good()) {
        fileT >> data_from_txt;
        item.value = stod(data_from_txt);
        avlTemp = NULL;
        avl.search(&avlSecondNode, &avlTemp, item);
        if (avlTemp == NULL) avl.insertValue(&avlSecondNode, item);
        else repeat1++;
    }
    free(avlSecondNode);

    avlSecondNode = NULL;
    while (fileTT.good()) {
        fileTT >> data_from_txt;
        item.value = stod(data_from_txt);
        avlTemp = NULL;
        avl.search(&avlSecondNode, &avlTemp, item);
        if (avlTemp == NULL) avl.insertValue(&avlSecondNode, item);
        else repeat2++;
    }
    free(avlSecondNode);

    avlSecondNode = NULL;
    while (fileM.good()) {
        fileM >> data_from_txt;
        item.value = stod(data_from_txt);
        avlTemp = NULL;
        avl.search(&avlSecondNode, &avlTemp, item);
        if (avlTemp == NULL) {avl.insertValue(&avlSecondNode, item);}
        else repeat3++;
    }
    free(avlSecondNode);
    
    cout << "REPETITIONS FOUND IN 1.000 FILE: " << repeat1 << endl;
    cout << "REPETITIONS FOUND IN 10.000 FILE: " << repeat2 << endl;
    cout << "REPETITIONS FOUND IN 1.000.000 FILE: " << repeat3 << endl << endl; 
    ========================================================================*/