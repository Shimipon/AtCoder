#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
    int A, B, C, D, E, k;
    cin >>	A >> B >> C >> D >> E >> k;
    if(E - A  > k) cout << ":(" << endl;
    else cout << "Yay!" << endl;
}