#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	long long C;
	cin >> C;
	int a[N], b[N];
	long long c[N];
	int Min = 1000000000, Max = 0;
	for(int i=0;i<N;i++){
		cin >> a[i] >> b[i] >> c[i];
		Min = min(a[i], Min);
		Max = max(b[i] + 1, Max);
	}
	vector<pair<int, long long>> e;
	for(int i=0;i<N;i++){
		pair<int, long long> x, y;
		x.first = a[i];
		x.second = c[i];
		y.first = b[i] + 1;
		y.second = -c[i];
		e.push_back(x);
		e.push_back(y);
	}
	sort(e.begin(), e.end());
	long long ans = 0;
	long long now = 0;
	int day = Min;
	int ind = 0;
	while(day <= Max){
		while(e[ind].first == day){
			now += e[ind].second;
			ind++;
			// cout << day << ":" <<ans << endl;
		}
		if(now > C) ans += C;
		else ans += now;
		day++;
	}
	cout << ans << endl;
}
