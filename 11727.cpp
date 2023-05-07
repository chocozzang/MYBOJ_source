#include <iostream>
#include <vector>

using namespace std;

vector<int> pre_vec;

void pre_calcul(){
    for(int i = 0; i <= 1000; i++) {
        if (i == 0) pre_vec.push_back(0);
        else if (i == 1) pre_vec.push_back(1);
        else if (i == 2) pre_vec.push_back(3);
        else pre_vec.push_back((pre_vec[i - 1] + pre_vec[i - 2] * 2) % 10007);
    }
}

int main() {

    pre_calcul();

    int N;
    cin >> N;
    cout << pre_vec[N];
}
