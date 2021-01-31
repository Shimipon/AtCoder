#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}


int main() {

    vector<int> nums(5);
    iota(nums.begin(), nums.end(), 0);

    do {
        // ここに各順列に行う処理を書く
        printVector(nums);
    } while (next_permutation(nums.begin(), nums.end()));


    return 0;
}