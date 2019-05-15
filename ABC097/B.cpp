#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int pow(int A, int P){
	int a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	int adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	int X;
	cin >> X;
	int ans = 1;
	for(int p=2;p<=X;p++){
		for(int i=1;pow(i,p)<=X;i++){
			ans = max(ans,pow(i,p));
		}
	}
	cout << ans << endl;
}