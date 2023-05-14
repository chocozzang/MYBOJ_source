#include <iostream>
#include <vector>

using namespace std;

void pelin(vector<int>& mynatures) {
    int M;
    cin >> M;

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        int times = ((y - x) % 2 == 0) ? (y - x) / 2 : ((y - x) / 2 + 1);

        bool is_pend = true;
        for(int t = 0; t < times; t++) {
            if(mynatures[x - 1 - t] != mynatures[y - 1 - t]) {
                cout << "0\n";
                is_pend = false;
                break;
            }
        }
        if(is_pend) cout << "1\n";
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> nature_numbers(N, 0);
    for(int i = 0; i < N; i++) cin>> nature_numbers[i];

    pelin(nature_numbers);
}
