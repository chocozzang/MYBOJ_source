#include <iostream>
#include <vector>

using namespace std;

int* dp = new int[16];
int N;
vector<pair<int, int>> schedule;

void pre_data(){
    cin >> N;
    dp[0] = 0;
    schedule.push_back(make_pair(0, 0));
    for(int i = 1; i <= N; i++) {
        int day; int pay;
        cin >> day >> pay;
        schedule.push_back(make_pair(day, pay));
        dp[i] = 0;
    }
}

void dynamic(){
    int my_max = 0;

    for(int i = 1; i <= N; i++) {
        int next_time = i + schedule[i].first - 1;
        if(next_time <= N) {
            int next_pay  = schedule[i].second;
            dp[next_time] = max(dp[next_time], dp[i - 1] + next_pay);
        }
        dp[i] = max(dp[i] , dp[i - 1]);
    }
}

int main(){
    pre_data();
    dynamic();
    cout << dp[N];
}
