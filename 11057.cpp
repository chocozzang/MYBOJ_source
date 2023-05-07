#include <iostream>
#include <vector>

using namespace std;

void calcul_dp(vector<vector<long long>>& mydp) {
    for(int i = 1; i <= 1000; i++) {
        for(int j = 2; j <= 10; j++) {
            mydp[i][j] = (mydp[i - 1][j] + mydp[i][j - 1]) % 10007;
        }
    }
}


int main() {
    int N;
    vector<vector<long long>> dp (1001, vector<long long>(11, 1));

    calcul_dp(dp);

    cin >> N;

    long long result= 0;
    for(int i = 1; i <= 10; i++) {
        result += dp[N - 1][i];
        result %= 10007;
   }

   cout << result;
}
