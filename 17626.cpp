#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 50000;
const int maxroot = (int)(sqrt(50000));

void prev_data(vector<int> &numVec) {

    for(int i = 1; i <= N; i++) {
        int nowsqrt = (int)(sqrt(i));
        int nowtemp = maxroot;
        for(int j = nowsqrt; j >= 1; j--) {
            int temptemp = numVec[j * j] + numVec[i - j * j];
            if(temptemp < nowtemp) nowtemp = temptemp;
        }
        numVec[i] = nowtemp;
    }
}


int main() {

    vector<int> numbers = vector<int>(N + 1, 0);
    numbers[0] = 1;

    prev_data(numbers);

    int n;
    cin >> n;
    cout << numbers[n];
}
