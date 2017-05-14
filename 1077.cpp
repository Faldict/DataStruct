#include <iostream>
using namespace std;
#define max_score first
#define root_number second
#define SIZE 32
int link_point_number, score[SIZE];
pair<unsigned long long, int> saved_val[SIZE][SIZE] = {};

unsigned long long FindMaxScore(int begin_pos, int end_pos){
    if(begin_pos > end_pos)
        return 1;
    if(!saved_val[begin_pos][end_pos].max_score){
        unsigned long long tmp_score;
        for(int i = begin_pos; i <= end_pos; ++i){
            tmp_score = FindMaxScore(begin_pos, i - 1) * FindMaxScore(i + 1, end_pos) + score[i];
            if(saved_val[begin_pos][end_pos].max_score < tmp_score){
                saved_val[begin_pos][end_pos].max_score = tmp_score;
                saved_val[begin_pos][end_pos].root_number = i;
            }
        }
    }
    return saved_val[begin_pos][end_pos].max_score;
}

void OutputRoots(int begin_pos, int end_pos){
    if(begin_pos > end_pos)
        return;
    cout << saved_val[begin_pos][end_pos].root_number + 1 << ' ';
    OutputRoots(begin_pos, saved_val[begin_pos][end_pos].root_number - 1);
    OutputRoots(saved_val[begin_pos][end_pos].root_number + 1, end_pos);
}

int main(){
    cin >> link_point_number;
    for(int i = 0; i < link_point_number; ++i){
        cin >> score[i];
        saved_val[i][i].max_score = score[i];
        saved_val[i][i].root_number = i;
    }

    unsigned long long result = FindMaxScore(0, link_point_number - 1);
    cout << result << '\n';
    OutputRoots(0, link_point_number - 1);
    return 0;
}

