#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	long long N;
	cin >> N;
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	int check = 1;
	int count = 0;
	while(check){
		for(int i=0;i<N;i++){
			if(A[i] % 2) {
				check = 0;
				break;
			}
			else{
				A[i] /= 2;
			}
		}
		if(check)count++;
	}
	cout << count << endl;
}