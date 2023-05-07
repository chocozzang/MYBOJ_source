#include <iostream>
#include <vector>

using namespace std;

void dp_calcul(vector<int> &mycoin, vector<int> &mydp, int total_money) {
    mydp[0] = 1;
    int now_coin, next_pos;
    for(int i = 0; i < mycoin.size(); i++) {
        now_coin = mycoin[i];
        for(int j = 0; j <= mydp.size(); j++) {
            next_pos = j + now_coin;
            if(next_pos <= total_money) {
                mydp[next_pos] += mydp[j];
            }
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> coins;
    vector<int> dp (K + 1, 0);

    int coin;
    for(int i = 0; i < N; i++) {
        cin >> coin;
        coins.push_back(coin);
    }

    dp_calcul(coins, dp, K);

    cout << dp[K];
}
