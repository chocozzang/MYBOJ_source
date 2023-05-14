#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void dp_calcul(string& x, int xsz, string& y, int ysz, vector<vector<int>>& mydp,
               vector<char>& charres) {
    for(int i = 1; i <= xsz; i++) {
        for(int j = 1; j <= ysz; j++) {
            if(x.at(i - 1) == y.at(j - 1)) mydp[i][j] = mydp[i-1][j-1] + 1;
            else                           mydp[i][j] = max(mydp[i][j-1], mydp[i-1][j]);
        }
    }

    int tempres = mydp[xsz][ysz];
    int tempj = ysz;
    for(int i = xsz; i > 0; i--) {
        for(int j = tempj; j > 0; j--) {
            if(mydp[i][j - 1] == mydp[i][j]) continue;
            else {
                if(mydp[i - 1][j] == mydp[i][j]) {
                    tempj = j;
                    break;
                }
                else {
                    charres.push_back(x[i - 1]);
                    tempj = j - 1;
                    break;
                }
            }
        }
    }
}

int main() {

    string x, y;

    cin >> x;
    cin >> y;

    int sz1 = x.size();
    int sz2 = y.size();

    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1 , 0));
    vector<char> chardp;

    dp_calcul(x, sz1, y, sz2, dp, chardp);

    int res = dp[sz1][sz2];

    cout << res << "\n";
    if(res > 0) {
        for(int i = chardp.size() - 1; i >= 0; i--) {
            cout << chardp[i];
        }
    }
}
