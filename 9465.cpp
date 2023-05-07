#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int my_dp(vector<vector<int>> &dypro, vector<vector<int>> &sticker) {

    int mymax = max(sticker[1][1], sticker[2][1]);

    dypro[1][1] = sticker[1][1];
    dypro[2][1] = sticker[2][1];

    for(int j = 2; j < dypro[0].size(); j++) {
        for(int i = 1; i <= 2; i++) {
            int x, y;
            if(i == 1) {
                x = (dypro[i + 1][j - 2] + sticker[i][j]);
                y = (dypro[i + 1][j - 1] + sticker[i][j]);
            }
            else {
                x = (dypro[i - 1][j - 2] + sticker[i][j]);
                y = (dypro[i - 1][j - 1] + sticker[i][j]);
            }
            dypro[i][j] = max(x, y);
            mymax = (dypro[i][j] > mymax)? dypro[i][j] : mymax;
        }
    }
    return mymax;
}

int main() {
    int times, N;

    cin >> times;

    for(int t = 0; t < times; t++) {
        cin >> N;
        vector<vector<int>> dp(3, vector<int> (N + 1, 0));
        vector<vector<int>> stickers(3, vector<int> (N + 1, 0));
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> stickers[i][j];
            }
        }
        int res = my_dp(dp, stickers);
/*
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= N; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        cout << res << endl;
    }
}
