#include <bits/stdc++.h>
using namespace std;
#define INF 3000000000

int main(){
	int N;
	cin >> N;
	long long x[N], y[N];
	long long Mp = 0, mp = INF, Mm = -1 * INF, mm = INF;
	for(int i=0;i<N;i++){
		cin >> x[i] >> y[i];
		Mp = max(Mp, x[i] + y[i]);
		mp = min(mp, x[i] + y[i]);
		Mm = max(Mm, x[i] - y[i]);
		mm = min(mm, x[i] - y[i]);
	}
	long long ans = Mp - mp;
	ans = max(ans, Mm - mm);
	cout << ans << endl;
}