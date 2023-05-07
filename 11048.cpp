#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void dp_calcul(vector<vector<int>>& mycandy, vector<vector<int>>& mydp) {
    mydp[0][0] = mycandy[0][0];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == (N - 1) && j == (M - 1)) continue;

            if(j == (M - 1)) {
                mydp[i + 1][j] = max(mydp[i + 1][j], mydp[i][j] + mycandy[i + 1][j]);
                continue;
            }
            if(i == (N - 1)) {
                mydp[i][j + 1] = max(mydp[i][j + 1], mydp[i][j] + mycandy[i][j + 1]);
                continue;
            }
            mydp[i][j + 1]     = max(mydp[i][j + 1], mydp[i][j] + mycandy[i][j + 1]);
            mydp[i + 1][j + 1] = max(mydp[i + 1][j + 1], mydp[i][j] + mycandy[i + 1][j + 1]);
            mydp[i + 1][j]     = max(mydp[i + 1][j], mydp[i][j] + mycandy[i + 1][j]);
        }
    }
}


int main() {
    cin >> N >> M;

    vector<vector<int>> candies(N, vector<int>(M, 0));
    vector<vector<int>> dp(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> candies[i][j];
        }
    }

    dp_calcul(candies, dp);

    cout << dp[N-1][M-1];
}
