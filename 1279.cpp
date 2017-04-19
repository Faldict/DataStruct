#include <iostream>
using namespace std;

// save the counts
int contact[10000000] = {};

int main() { 
    // define the telephone numbers
    int ascii[128] = {};
    ascii['1'] = 1;
    ascii['2'] = ascii['A'] = ascii['B'] = ascii['C'] = 2;
    ascii['3'] = ascii['D'] = ascii['E'] = ascii['F'] = 3;
    ascii['4'] = ascii['G'] = ascii['H'] = ascii['I'] = 4;
    ascii['5'] = ascii['J'] = ascii['K'] = ascii['L'] = 5;
    ascii['6'] = ascii['M'] = ascii['N'] = ascii['O'] = 6;
    ascii['7'] = ascii['P'] = ascii['R'] = ascii['S'] = 7;
    ascii['8'] = ascii['T'] = ascii['U'] = ascii['V'] = 8;
    ascii['9'] = ascii['W'] = ascii['X'] = ascii['Y'] = 9;

    // read the inputs
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        char number[15];
        cin >> number;
        int nmb = 0;
        for (int j=0; number[j]; j++) {
            if (number[j] != '-') nmb = nmb * 10 + ascii[number[j]];
        }
        contact[nmb]++;
    }

    int count = 0;
    // choose the duplicate numbers
    for (int i=0; i<10000000; i++) {
        if (contact[i] > 1) {
            char number[9] = "000-0000";
            int nmb = i;
            for (int j=0; j<8; j++) {
                if (j != 4) {
                    number[8 - j - 1] += nmb % 10;
                    nmb /= 10;
                }
            }

            cout<<number<<" "<<contact[i]<<endl;
            count++;
        }
    }

    // deal with no duplicates
    if (count == 0) cout<<"No duplicates."<<endl;
    return 0;
}