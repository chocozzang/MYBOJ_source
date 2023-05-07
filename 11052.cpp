#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> cards;

void pre_input() {
    cin >> N;
    int card;
    cards.push_back(0);
    for(int i = 1; i <= N; i++) {
        cin >> card;
        cards.push_back(card);
    }
}

int my_dp_func() {
    vector<int> dp;
    dp.push_back(0);

    for(int i = 1; i <= N; i++) {
        int now_max = cards[i];
        for(int j = 0; j < i; j++) {
            int next_max = dp[j] + cards[i - j];
            if(next_max > now_max) now_max = next_max;
        }
        dp.push_back(now_max);
    }

    return dp[N];
}

int main() {
    pre_input();
    int result = my_dp_func();
    cout << result;
}
