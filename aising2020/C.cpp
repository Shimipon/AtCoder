#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int ans = 0;
	for(int i=1;i<=N;i++){
		for(int x=1;x * x < i;x++){
			for(int y=1;y<=x;y++){
				for(int z=1;z<=y;z++){
					if(x*x + y*y + z*z + x*y + y*z + z*x == i){
						ans++;
						if(x == y && y != z) ans += 2;
						if(x != y && y == z) ans += 2;
						if(x != y && y != z) ans += 5;
					}
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	}
}
