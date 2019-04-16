#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int A[5];
	for(int i=0;i<5;i++){
		cin >> A[i];
	}
	int ans = 1000000;
	for(int i=0;i<5;i++){
		int ansdash = 0;
		for(int j=0;j<5;j++){
			if(i != j){
				if(A[j] % 10) ansdash += A[j] + 10 - (A[j] % 10);
				else ansdash += A[j];
			}
			else ansdash += A[j];

		}
		ans = min(ansdash, ans);
	}
	cout << ans << endl;
}