#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	long N;
	cin >> N;
	long ans = 0;
	for(long i=1;i * i < N - i;i++){
		if(!((N - i) % i)) ans += (N - i) / i;
	}
	cout << ans << endl;
}