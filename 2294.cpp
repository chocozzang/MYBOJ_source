#include <iostream>
#include <vector>

using namespace std;

int N, K;

void dp_calcul(vector<int>& mydp, vector<int>& mycoin) {
    for(int i = 0; i < mycoin.size(); i++) {
        for(int j = 0; j < mydp.size(); j++) {
            int nextcoin = j + mycoin[i];
            if(nextcoin >= mydp.size()) break;
            else {
                mydp[nextcoin] = min(mydp[nextcoin], mydp[j] + 1);
            }
        }
    }
}


int main() {
    cin >> N >> K;

    vector<int> coins;
    vector<int> coindp (K + 1, K + 1);
    coindp[0] = 0;

    for(int i = 0; i < N; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    dp_calcul(coindp, coins);

    int result;
    if(coindp[K] == K + 1) result = -1;
    else                             result = coindp[K];

    cout << result;
}
