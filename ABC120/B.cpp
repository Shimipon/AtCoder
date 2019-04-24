#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <vector>
using namespace std;
int main(){
	int A, B, K;
	cin >> A >> B >> K;
	int M = min(A,B);
	for(int i = B;i>0;i--){
		if(A % i == 0 && B % i ==0){
			K--;
			if(K == 0){
				cout << i << endl;
			}
		}
	}
}