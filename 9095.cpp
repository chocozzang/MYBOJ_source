#include <iostream>
#include <vector>

using namespace std;

vector<int> array_calculation;

void pre_calcul(){
    for(int i = 0; i <= 10; i++) {
        if(i == 0) array_calculation.push_back(0);
        else if (i == 1) array_calculation.push_back(1);
        else if (i == 2) array_calculation.push_back(2);
        else if (i == 3) array_calculation.push_back(4);
            else {
                array_calculation.push_back(array_calculation[i-1] + array_calculation[i-2] + array_calculation[i-3]);
            }
        }
    }

int main(){

    pre_calcul();

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int which;
        cin >> which;
        cout << array_calculation[which] << endl;
    }

    return 0;
}
