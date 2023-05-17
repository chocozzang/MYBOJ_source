#include <iostream>
#include <vector>

using namespace std;

void dp_calcul(vector<long long>& mydp) {

    mydp[1] = 1;
    mydp[2] = 2;
    mydp[3] = 4;

    for(int i = 4; i <= 1000000; i++) {
        mydp[i] = (mydp[i - 1] + mydp[i - 2] + mydp[i - 3]) % 1000000009;
    }

}

int main() {

    int N;
    cin >> N;

    vector<long long> dp(1000001, 0);
    dp_calcul(dp);

    for(int i = 0; i < N; i++) {
        int K;
        cin >> K;
        cout << dp[K] << "\n";
    }
}
