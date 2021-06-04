#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	int ans = 4;
	if(A+B >= 15 && B >= 8) ans = 1;
	else if(A+B >= 10 && B >= 3) ans = 2;
	else if(A+B >= 3) ans = 3;
	cout << ans << endl;
}
