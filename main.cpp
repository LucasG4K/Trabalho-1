#include "cases.cpp"

int main() {

    Case c;
    int option;
    do {
        cout << "=====================" << endl;
        cout << "    INPUT OPTIONS" << endl;
        cout << "=====================" << endl;
        cout << "1 - Insert 1.000" << endl << "2 - 10.000" << endl << "3 - 1.000.000" << endl << "0 - EXIT" << endl;
        cout << "1 - 1.000" << endl << "2 - 10.000" << endl << "3 - 1.000.000" << endl << "0 - EXIT" << endl;
        cout << "Option: ";
        cin  >> option;

        switch (option) {
        case 1:
            c.initInsertionComparision("sample/insert_thousand.txt");
            break;
        
        case 2:
            c.initInsertionComparision("sample/insert_ten_thousand.txt");
            break;
        
        case 3:
            c.initInsertionComparision("sample/insert_million.txt");
            break;

        case 0:
            return 0;
            break;
        
        default:
            cout << "Option not found!" << endl;
            break;
        }
    } while (option != 0);
    
    return 0;
}
