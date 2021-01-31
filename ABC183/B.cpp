#include <bits/stdc++.h>
using namespace std;

int main(){
	double sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	double ans = sx * gy + sy * gx;
	ans /= sy + gy;
	printf("%.9f\n", ans);
}
