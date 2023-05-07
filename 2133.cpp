#include <iostream>
#include <vector>

using namespace std;

void pre_calcul(vector<long long>& mydp, vector<long long>& myblock) {
    mydp[0] = 1;
    for(int i = 1; i <= 30; i++) {
        if(i % 2 == 0) {
            if(i == 2) myblock[i] = 3;
            else myblock[i] = 2;
        }
    }

    for(int i = 2; i <= 30; i++) {
        if(i % 2 == 0) {
            for(int j = (i - 2); j >= 0; j -= 2) {
                mydp[i] += mydp[j] * myblock[i - j];
            }
        }
    }
}

int main() {
    vector<long long> dp(31, 0);
    vector<long long> blocks(31, 0);
    pre_calcul(dp, blocks);

    int N;
    cin >> N;

    cout << dp[N];
}
