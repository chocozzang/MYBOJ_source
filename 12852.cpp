#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dp_calcul(vector<int>& mydp, int sz) {

    for(int i = 1; i <= sz; i++) {
        if((i + 1) <= sz) {
           if(mydp[i + 1] == 0) mydp[i + 1] = mydp[i] + 1;
            else                 mydp[i + 1] = min(mydp[i] + 1, mydp[i + 1]);
        }

        if((i * 2) <= sz) {
           if(mydp[i * 2] == 0) mydp[i * 2] = mydp[i] + 1;
           else                 mydp[i * 2] = min(mydp[i] + 1, mydp[i * 2]);
        }

        if((i * 3) <= sz) {
            if(mydp[i * 3] == 0) mydp[i * 3] = mydp[i] + 1;
            else                 mydp[i * 3] = min(mydp[i] + 1, mydp[i * 3]);
        }
    }
}

int main() {

    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);

    dp_calcul(dp, N);

    int mymax = dp[N];
    int j = N;
    cout << mymax << "\n";
    cout << N << " ";

    mymax--;
    while(true) {

        if(j % 3 == 0) {
            if(dp[j / 3] == mymax) {
                cout << j / 3 << " ";
                j /= 3;
                mymax--;
                continue;
            }
        }

        if(j % 2 == 0) {
            if(dp[j / 2] == mymax) {
                cout << j / 2 << " ";
                j /= 2;
                mymax--;
                continue;
            }
        }

        if(dp[j - 1] == mymax) {
            cout << j - 1 << " ";
            j -= 1;
            mymax--;
        }

        if (dp[j] == 0) break;
    }

}

