#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dp_calcul(int sz) {

    vector<int> scores(3, 0);
    vector<vector<int>> max_dp(2, vector<int>(3, 0));
    vector<vector<int>> min_dp(2, vector<int>(3, 0));

    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> scores[j];
            if(i == 0) {
                max_dp[0][j] = scores[j];
                min_dp[0][j] = scores[j];
            }
        }
        if(i > 0) {
            max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + scores[0];
            max_dp[1][1] = *max_element(max_dp[0].begin(), max_dp[0].end()) + scores[1];
            max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + scores[2];
            min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + scores[0];
            min_dp[1][1] = *min_element(min_dp[0].begin(), min_dp[0].end()) + scores[1];
            min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + scores[2];
            for(int k = 0; k < 3; k++) {
                max_dp[0][k] = max_dp[1][k];
                min_dp[0][k] = min_dp[1][k];
            }
        }

    }

    cout << *max_element(max_dp[0].begin(), max_dp[0].end()) << " ";
    cout << *min_element(min_dp[0].begin(), min_dp[0].end());
}

int main() {
    int N;
    cin >> N;
    dp_calcul(N);
}
