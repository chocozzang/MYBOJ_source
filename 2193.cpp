#include <iostream>
#include <vector>

using namespace std;

vector<long long> zeros;
vector<long long> ones;

void pre_calcul() {
    for(int i = 0; i < 90; i++) {
        if(i == 0) {
            zeros.push_back(0);
            ones.push_back(1);
        }
        else if (i == 1) {
            zeros.push_back(1);
            ones.push_back(0);
        }
        else {
            zeros.push_back(zeros[i-1] + zeros[i-2]);
            ones.push_back (ones[i-1]  + ones[i-2]);
        }
    }
}

int main(){

    pre_calcul();

    int N;
    cin >> N;

    cout << (zeros[N-1] + ones[N-1]);

}
