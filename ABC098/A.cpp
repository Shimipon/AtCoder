#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	int ans = A + B;
	ans = max(ans, A - B);
	ans = max(ans, A * B);
	cout << ans << endl;
}