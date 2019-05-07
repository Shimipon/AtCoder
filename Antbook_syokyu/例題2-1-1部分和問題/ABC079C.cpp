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
	int A[4];
	A[0] =S[0] - '0';
	A[1] =S[1] - '0';
	A[2] =S[2] - '0';
	A[3] =S[3] - '0';
	int ansi = -1;
	for(int i=0;i<8;i++){
		int idash = i;
		int ans = A[0];
		for(int j=1;j<=3;j++){
			if(idash % 2){
				ans += A[j];
			}
			else{
				ans -= A[j];
			}
			idash /= 2;
		}
		if(ans == 7) ansi = i;
	}
	cout << S[0];
	for(int j=1;j<=3;j++){
		if(ansi % 2){
			cout << "+";
		}
		else{
			cout << "-";
		}
		cout << S[j];
		ansi /= 2;
	}
	cout << "=7" << endl;
}



