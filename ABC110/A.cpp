#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
	int A, B, C;
	cin >> A >> B >> C;
	int ans = 0;
	ans = max(ans, A * 10 + B + C);
	ans = max(ans, B * 10 + A + C);
	ans = max(ans, C * 10 + A + B);
	cout << ans << endl;
}
