#include <bits/stdc++.h>
using namespace std;

int main(){
	double A, B, H, M;
	cin >> A >> B >> H >> M;
	double arH = ((60.0 * H + M) / 720.0);
	double arM = (M / 60.0);
	double coHM = cos((arH - arM) * M_PI * 2);
	double ans2 = A * A + B * B - 2  * A * B * coHM;
	double ans = sqrt(ans2);
	printf("%.15f\n", ans);
}