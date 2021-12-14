#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

float get_random() { return (1 + (float)rand() / (float)RAND_MAX * 10); }

int main() {

//     vector<char*> t_vector;
//     char data[20];
//     for (int i = 0; i < 5; i++) {
//         // char *data = (char*)malloc(sizeof(char*));
//         sprintf(data, "%.1f\n", get_random());
//         t_vector.push_back(data);
//     }

//     cout << "t_vector[1] = " << t_vector.at(0); 
//     cout << "t_vector[2] = " << t_vector.at(1); 
//     cout << "t_vector[3] = " << t_vector.at(2); 
//     cout << "t_vector[4] = " << t_vector.at(3); 
//     cout << "t_vector[5] = " << t_vector.at(4); 

//     return 0;
// }

    vector<char*> t_vector;
    vector<char*> tt_vector;
    vector<char*> m_vector;
    char *data = (char*)malloc(sizeof(char*));
    int j = 0;

    for (int i = 0; i < 20; i++) {
        cout << t_vector.size() << endl;
        if (i < 10) {
            j = i;
            while (j > 0) {
                data = (char*)realloc(data, sizeof(char*));
                sprintf(data, "%.6f\n", get_random());

                if (t_vector[j] != data) {
                    j--;
                }
            }
            t_vector.push_back(data);
        } else if (!t_vector.empty())
            t_vector.pop_back();

        if (i < 15) {
            j = i;
            while (j > 0) {
                char *value = (char*)malloc(sizeof(char*));
                sprintf(value, "%.6f\n", get_random());

                if (tt_vector[j] != value) {
                    data = value;
                    j--;
                }
            }
            tt_vector.push_back(data);
        } else if (tt_vector.size() > 1)
            tt_vector.pop_back();

        j = i;
        while (j > 0) {
            char *value = (char*)malloc(sizeof(char*));
            sprintf(value, "%.6f\n", get_random());

            if (m_vector[j] != value) {
                data = value;
                j--;
            }
        }
        m_vector.push_back(data);
    }
        
    // for (int t = 0; t < 10; t++) {
    //     cout << "imprime";
    //     // if (i < 10)
    //         cout << t_vector.at(t);
    //     // if (i < 15)
    //         // cout << tt_vector[i];
    //     // cout << m_vector[i];
    // }

    return 0;
}