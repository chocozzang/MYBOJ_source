#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> my_vec(201, vector<long long>(201, 0));

void comb_calcul() {
    for(int i = 0; i <= 200; i++) {
        for(int j = 0; j <= 200; j++) {
            if(j > i) continue;
            else {
                if(i == 0) my_vec[i][j] = 1;
                else {
                    if (j == 0) my_vec[i][j] = my_vec[i-1][j] % 1000000000;
                    else if(i == j) my_vec[i][j] = my_vec[i-1][j-1] % 1000000000;
                    else my_vec[i][j] = (my_vec[i-1][j-1] + my_vec[i-1][j]) % 1000000000;
                }
            }
        }
    }
}

int main (){
    comb_calcul();

    int N, K;
    cin >> N >> K;

    long long result = 0;
    for(int i = 0; i < K; i++) {
        result += ((my_vec[N - 1][i] * my_vec[K][i + 1]) % 1000000000);
    }
    cout << result % 1000000000;

}
