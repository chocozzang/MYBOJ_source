#include <iostream>
#include <vector>

using namespace std;


int main() {

    const int N = 45;
    vector<int> AVEC = vector<int> (N + 1, 0);
    vector<int> BVEC = vector<int> (N + 1, 0);

    AVEC[0] = 1;

    for(int i = 0; i < N; i++) {
        AVEC[i + 1] = BVEC[i];
        BVEC[i + 1] = AVEC[i] + BVEC[i];
    }

    int n;
    cin >> n;
    cout << AVEC[n] << " " << BVEC[n];
}
