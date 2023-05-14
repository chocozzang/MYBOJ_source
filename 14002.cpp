#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mydp_calcul(vector<int>& myheight, vector<int>& myls, int sz, vector<int>& myres) {
    int mymax = 0;
    for(int i = 1; i < sz; i++) {
        bool is_pushed = false;
        vector<int> heights_tmp;
        for(int j = (i - 1); j >= 0; j--) {
            if(myheight[i] > myheight[j]) {
                heights_tmp.push_back(myls[j]);
                is_pushed = true;
            }
        }
        if(is_pushed) myls[i] = 1 + *max_element(heights_tmp.begin(), heights_tmp.end());
        else          myls[i] = 1;
    }

    int idx = max_element(myls.begin(), myls.end()) - myls.begin();
    myres.push_back(myheight[idx]);
    int whereis = myls[idx] - 1;
    for(int i = idx - 1; i >= 0; i--) {
        if(myls[i] == whereis) {
            myres.push_back(myheight[i]);
            whereis--;
        }
    }

    return myls[idx];
}

int main() {
    int N;
    cin >> N;

    vector<int> heights(N, 0);
    for(int i = 0; i < N; i++) cin >> heights[i];

    vector<int> long_sub(N, 0);
    long_sub[0] = 1;

    vector<int> result;
    int long_size = mydp_calcul(heights, long_sub, N, result);

    cout << long_size << "\n";
    for(int j = result.size() - 1; j >= 0; j--) cout << result[j] << " ";
}
