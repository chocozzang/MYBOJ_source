#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mydp(vector<int>& dpvec, vector<int>& numvec) {
    int nowmax = 0;
    for(int i = 0; i < numvec.size(); i++) {
        if(i == 0) dpvec[i] = 1;
        else {
            int next_val = numvec[i];
            vector<int> tempvec;
            bool is_pushed = false;
            for(int j = i - 1; j >= 0; j--) {
                if(next_val < numvec[j]) {
                    tempvec.push_back(dpvec[j]);
                    is_pushed = true;
                }
            }
            if(is_pushed) dpvec[i] = 1 + *max_element(tempvec.begin(), tempvec.end());
            else dpvec[i] = 1;
        }
        if (dpvec[i] > nowmax) nowmax = dpvec[i];
    }
    return nowmax;
}


int main() {
    int N;

    cin >> N;

    vector<int> dp (N, 0);
    vector<int> numbers;

    for(int i = 0; i < N; i++) {
        int number_input;
        cin >> number_input;
        numbers.push_back(number_input);
    }

    cout << mydp(dp, numbers);
}
