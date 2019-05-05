#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int pow(int A, int P){
	int a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	int adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	int D, N;
	cin >> D >> N;
	if(N < 100) cout << pow(100,D) * N << endl;
	else cout << pow(100,D) * (N + 1) << endl;
}