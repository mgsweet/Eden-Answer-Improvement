#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cmath>
#define MAX_N 1000
#define MAX_CHAR_N 1000

using std::cin;
using std::cout;
using std::string;
using std::endl;

void deleteShu();
void UI();
void addSeNUM();

int main(int argc, const char * argv[]) {
    UI();
    int func;
    cin >> func;
    switch (func) {
        case 1:
            cout << "delete the frist char of the line!" << endl;
            cout << "input EOF to end your input!" << endl << endl;
            deleteShu();
            break;
        case 2:
            cout << "add sequence number at the beginning of the line!" << endl;
            cout << "input EOF to end your input!" << endl << endl;
            addSeNUM();
        default:
            break;
    }
    return 0;
}

void deleteShu() {
    char _in[MAX_N][MAX_CHAR_N];
    int count = 0;
    bool start;
    FILE * pFile;
    pFile = fopen ("result.txt","w");
    while (getchar() != EOF) {
        gets(_in[count]);
        count++;
    }
    for (int i = 0; i < count; i++) {
        start = false;
        int length = strlen(_in[i]);
        for (int k = 0; k < length; k++) {
            if (_in[i][k] == '|' && start == false) {
                start = true;
            }
            else if (start == true) {
                fprintf (pFile, "%c", _in[i][k]);
            }
        }
        fprintf (pFile, "\n");
    }
    fclose (pFile);
    pFile = NULL;
}

void addSeNUM() {
    char _in[MAX_N][MAX_CHAR_N];
    int count = 0;
    bool start;
    while (getchar() != EOF) {
        gets(_in[count]);
        count++;
    }
    int seqMax = count;
    int countS = 0;
    int zeroOutNum;
    while (seqMax) {
        countS++;
        seqMax /= 10;
    }
    for (int i = 0; i < count; i++) {
        for (int j = 1; j < countS; j++) {
            zeroOutNum = pow(10, j);
            if (i + 1 < zeroOutNum) {
                for (int l = 0; l < countS - j; l++) {
                    cout << '0';
                }
                break;
            }
        }
        cout << i + 1 << '|';
        start = false;
        int length = strlen(_in[i]);
        for (int k = 0; k < length; k++) {
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

void UI() {
    cout << "created by Mr.Gu" << endl;
    cout << "please enter what service you want:" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1.delete the '|' and ' 'at the beginning of the line." << endl << endl;
    cout << "2.add sequence number at the beginning of the line." << endl << endl;
    cout << "3.input anything else to quit." << endl << endl;
    cout << "--------------------------------------" << endl;
}

