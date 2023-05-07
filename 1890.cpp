#include <iostream>
#include <vector>

using namespace std;

void dp_calcul(vector<vector<long long>>& myjmp, vector<vector<long long>>& mydp, int sz) {
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            if(myjmp[i][j] == 0) return;

            if(mydp[i][j] > 0) {
                int next_x_pos = i + myjmp[i][j];
                int next_y_pos = j + myjmp[i][j];

                if(next_x_pos < sz) mydp[next_x_pos][j] += mydp[i][j];
                if(next_y_pos < sz) mydp[i][next_y_pos] += mydp[i][j];
            }
        }
    }
}


int main() {
    int N;
    cin >> N;

    vector<vector<long long>> jumps(N, vector<long long>(N, 0));
    vector<vector<long long>> dp   (N, vector<long long>(N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> jumps[i][j];
        }
    }

    dp[0][0] = 1;

    dp_calcul(jumps, dp, N);

    cout << dp[N - 1][N - 1];
}
