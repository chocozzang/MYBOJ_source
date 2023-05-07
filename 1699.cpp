#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void dp_calcul(vector<int>& mydp, vector<int>& mysquare) {
    for(int i = 1; i < mysquare.size(); i++) {
        int nowsqr = mysquare[i];
        for(int j = 0; j < mydp.size(); j++) {
            if((j + nowsqr) >= mydp.size()) break;
            else {
                mydp[j + nowsqr] = min(mydp[j] + 1, mydp[j + nowsqr]);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    int max_sqrtn = int(sqrt(N)) + 1;

    vector<int> squares(max_sqrtn + 1, 0);
    vector<int> dp(N + 1, N);
    dp[0] = 0;

    for(int i = 0; i <= max_sqrtn; i++) squares[i] = i * i;

    dp_calcul(dp, squares);

    cout << dp[N];

    return 0;
}
