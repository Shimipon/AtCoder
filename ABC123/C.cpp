#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;


int main(){
	long long N;
	long long A[5];
	cin >> N;
	for(int i=0;i<5;i++){
		cin >> A[i];
	}
	long long mini = A[0];
	int num = 0;
	for(int i=1;i<5;i++){
		if(mini > A[i]){
			mini = A[i];
			num = i;
		}
	}
	long long ans = N / mini;
	if(N % mini) ans++;
	ans += 4;
	cout << ans << endl;
}