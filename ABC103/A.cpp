#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
vector<long int> X;

int main(){
	int A[3];
	cin >> A[0] >> A[1] >> A[2];
	int ans = 3000;
	ans = min(abs(A[1] - A[0]) + abs(A[2] - A[1]), ans);
	ans = min(abs(A[2] - A[1]) + abs(A[0] - A[2]), ans);
	ans = min(abs(A[0] - A[2]) + abs(A[1] - A[0]), ans);
	cout << ans << endl;
}