#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;


int main(){
	int K, S;
	cin >> K >> S;
	long ans = 0;
	for(int i=0;i<=K;i++){
		for(int j=0;j<=K;j++){
			if(S - i - j <= K && S - i - j >= 0)ans++;
		}
	}
	cout << ans << endl;
}



