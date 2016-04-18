#include <iostream>
#include <string.h>
#include <string>
#define MAX_N 1000

using std::cin;
using std::cout;
using std::string;
using std::endl;

void deleteShu();
int main(int argc, const char * argv[]) {
    cout << "created by Mr.Gu" << endl;
    cout << "please enter what service you want:" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1.delete the '|' and ' 'at the beginning of the line." << endl << endl;
    cout << "2.input 'q' to quit." << endl << endl;
    cout << "--------------------------------------" << endl;
    int func;
    cin >> func;
    switch (func) {
        case 1:
            cout << "delete the frist char of the line!" << endl;
            cout << "input EOF to end your input!" << endl << endl;
            deleteShu();
            break;
        default:
            break;
    }
    return 0;
}

//  eden答案去除｜输出
void deleteShu() {
    char _in[MAX_N][100];
    int count = 0;
    bool start;
    while (getchar() != EOF) {
        gets(_in[count]);
        count++;
    }
    for (int i = 0; i < count; i++) {
        start = false;
        for (int k = 0; k < strlen(_in[i]); k++) {
            if (_in[i][k] == '|' && start == false) {
                start = true;
            }
            else if (start == true) {
                cout << _in[i][k];
            }
        }
        cout << endl;
    }
}

