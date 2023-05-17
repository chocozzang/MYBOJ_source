#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dp_calcul(vector<int>& mybx, vector<int>& mydp, int sz) {

    mydp[1] = 1;
    for(int i = 2; i <= sz; i++) {
        vector<int> dpvec;
        for(int j = i - 1; j >= 1; j--) {
            if(mybx[j] < mybx[i]) dpvec.push_back(mydp[j]);
        }
        if(dpvec.size() > 0) mydp[i] = *max_element(dpvec.begin(), dpvec.end()) + 1;
        else                 mydp[i] = 1;
    }
}

int main() {

    int N;
    cin >> N;

    vector<int> boxes(N + 1, 0);
    vector<int> dp   (N + 1, 0);

    for(int i = 1; i <= N; i++) cin >> boxes[i];

    dp_calcul(boxes, dp, N);

    cout << *max_element(dp.begin(), dp.end());
}
