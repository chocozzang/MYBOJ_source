#include <iostream>
#include <vector>
using namespace std;

int N;

void dp_calcul(vector<vector<int>>& mydp, vector<vector<int>>& mypipe, int x, int y, int direction) {

    if(x >= N || y >= N) return;

    if(direction == 0) {
        if(mypipe[x][y + 1]  == 0 && mypipe[x + 1][y] == 0 && mypipe[x + 1][y + 1] == 0) {
            mydp[x + 1][y + 1] ++;
            dp_calcul(mydp, mypipe, x + 1, y + 1, 1);
        }

        if(mypipe[x][y + 1] == 0) {
            mydp[x][y + 1] ++;
            dp_calcul(mydp, mypipe, x, y +1, 0);
        }
    }
    else if (direction == 1) {
        if(mypipe[x][y + 1]  == 0 && mypipe[x + 1][y] == 0 && mypipe[x + 1][y + 1] == 0) {
            mydp[x + 1][y + 1] ++;
            dp_calcul(mydp, mypipe, x + 1, y + 1, 1);
        }

        if(mypipe[x][y + 1] == 0) {
            mydp[x][y + 1] ++;
            dp_calcul(mydp, mypipe, x, y +1, 0);
        }

        if(mypipe[x + 1][y] == 0) {
            mydp[x + 1][y] ++;
            dp_calcul(mydp, mypipe, x + 1, y, 2);
        }
    }
    else {
        if(mypipe[x][y + 1]  == 0 && mypipe[x + 1][y] == 0 && mypipe[x + 1][y + 1] == 0) {
            mydp[x + 1][y + 1] ++;
            dp_calcul(mydp, mypipe, x + 1, y + 1, 1);
        }

        if(mypipe[x + 1][y] == 0) {
            mydp[x + 1][y] ++;
            dp_calcul(mydp, mypipe, x + 1, y, 2);
        }
    }
}


int main() {
    cin >> N;

    vector<vector<int>> dp (N, vector<int>(N, 0));
    vector<vector<int>> pipes(N + 1, vector<int>(N + 1, 1));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> pipes[i][j];
        }
    }

    dp[0][0] = 1;
    dp[0][1] = 1;

    dp_calcul(dp, pipes, 0, 1, 0);

    cout << dp[N - 1][N - 1];
}
