#include <bits/stdc++.h>
using namespace std;

int main(){
	long long K;
	cin >> K;
	long long ans = -1;
	if(K % 2 != 0 && K % 5 != 0){
		long long one = K % 10;
		long long keta = 0;
		long long car = 0;
		ans = 0;
		for(int i=0;i<10;i++){
			if((i * one + car) % 10 == 7){
				keta = i;
				break;
			}
		}
		car = (car + keta * K) / 10;
		ans++;
		while(car != 0){
			for(int i=0;i<10;i++){
				if((i * one + car) % 10 == 7){
					keta = i;
					break;
				}
			}
			car = (car + keta * K) / 10;
			ans++;
			//cout << car << endl;
		}
	}
	cout << ans << endl;

}
