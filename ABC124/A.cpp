#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	int ans = 0;
	ans = max(ans, A + B);
	ans = max(ans, A + A - 1);
	ans = max(ans, B + B - 1);
	cout << ans << endl;
}