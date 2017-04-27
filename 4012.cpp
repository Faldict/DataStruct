#include <iostream>
#include <algorithm>
using namespace std;

int number_of_fruits = 0, fruits[10010] = {0};

int FindMinStrength(){
    int min_strength = 0, tmp_number;
    for(int i = 1; i < number_of_fruits; ++i){
        min_strength += fruits[i] += fruits[i - 1];
        for(int j = i + 1; j < number_of_fruits && fruits[j] < fruits[j - 1]; ++j){
            tmp_number = fruits[j];
            fruits[j] = fruits[j - 1];
            fruits[j - 1] = tmp_number;
        }
    }
    return(min_strength);
}

int main(){
    cin >> number_of_fruits;
    for(int i = 0; i < number_of_fruits; ++i)
        cin >> fruits[i];
    sort(fruits, fruits + number_of_fruits);

    int min_strength = FindMinStrength();
    cout << min_strength << endl;
    return 0;
}