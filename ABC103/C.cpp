#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	int ans = 0;
	for(int i=0;i<N;i++){
		cin >> a[i];
		ans += a[i]-1;
	}
	cout << ans;
}