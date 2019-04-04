#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(){
	int K;
	cin >> K;
	if(K % 2 == 0) cout << (K / 2) * (K / 2) << endl;
	else cout << ((K - 1) / 2) * ((K - 1) / 2 + 1) << endl;
}