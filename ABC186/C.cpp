#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int ans = 0;
	for(int i=1;i<=N;i++){
		int chk8 = 0, chk10 = 0;
		int i1 = i, i2 = i;
		while(i1 > 0){
			if(i1 % 10 == 7)chk10++;
			i1 /= 10;
		}
		while(i2 > 0){
			if(i2 % 8 == 7)chk8++;
			i2 /= 8;
		}
		if(chk8 == 0 && chk10 == 0)ans++;
	}
	cout << ans << endl;
}
