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
	string S;
	cin >> S;
	int N = (int)S.size();
	int num = pow(2, N-1);
	long ans = 0;
	for(int i = 0;i<num;i++){
		int numdash = i;
		long plus = S[0] - '0';
		for(int j=1;j<N;j++){
			if(numdash % 2){
				ans += plus;
				plus = S[j] - '0';
			}
			else{
				plus *= 10;
				plus += S[j] - '0';
			}
			numdash /= 2;
		}
		ans += plus;
	}
	cout << ans << endl;
}



