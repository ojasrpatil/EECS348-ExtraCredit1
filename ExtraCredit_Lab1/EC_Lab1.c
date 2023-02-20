#include <stdio.h>
#include <stdbool.h>

int d[5][5] = {
    {1,5,3,2,4},
    {1,3,4,2,5},
    {3,4,2,5,1},
    {3,1,2,4,5},
    {4,3,1,2,5}
};

int p[5][5] = {
    {3,1,2,5,4},
    {4,3,1,5,2},
    {2,5,4,1,3},
    {4,5,2,1,3},
    {3,2,1,5,4}
};

int d_match[5] = {-1, -1, -1, -1, -1}; 
bool p_free[5] = {true, true, true, true, true}; 

void main() {
    while (true) {
        bool all_matched = true;
        for (int i = 0; i < 5; i++) {
            if (d_match[i] == -1) { 
                all_matched = false;
                for (int j = 0; j < 5; j++) {
                    int programmer = d[i][j] - 1;
                    if (p_free[programmer]) { 
                        d_match[i] = programmer;
                        p_free[programmer] = false;
                        break;
                    } else {
                        int current_match = d_match[programmer];
                        int current_rank = 0, new_rank = 0;
                        for (int k = 0; k < 5; k++) {
                            if (p[programmer][k] == i + 1) {
                                new_rank = k;
                            }
                            if (p[programmer][k] == current_match + 1) {
                                current_rank = k;
                            }
                        }
                        if (new_rank < current_rank) {
                            d_match[i] = programmer;
                            p_free[programmer] = false;
                            d_match[current_match] = -1;
                            break;
                        }
                    }
                }
            }
        }
        if (all_matched) {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("Department %d will get Programmer %d\n", i+1, d_match[i]+1);
    }
}
