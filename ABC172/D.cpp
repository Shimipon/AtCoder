#include <bits/stdc++.h>
using namespace std;
int main(){
	long N;
	cin >> N;
	long fx[N+1];
	for(int j=0;j<=N;j++){
		fx[j] = 0;
	}
	long ans = 1;
	for(int i=2;i<=N;i++){
		long f = 1;
		int frac[N];
		for(int j=0;j*j<=i;j++){
			frac[i] = 0;
		}
		int tmp = i;
		for(int j=2;j*j<=i;j++){
			while(tmp % j == 0){
				tmp /= j;
				frac[j]++;
			}
		}
		for(int j=2;j*j<=i;j++){
			f *= frac[j] + 1;
		}
		if(tmp > 1) f *= 2;
		ans += f * i;
		cout << i << ":" << f << endl;
		for(int j=0;j*j<=i;j++){
			frac[j] = 0;
		}
	}
	cout << ans << endl;
}
