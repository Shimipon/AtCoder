#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N, A, B;
	cin >> N >> A >> B;
	long long count = 0;
	for(int i=1;i<=N;i++){
		int x = i;
		int sum = 0;
		while(x > 0){
			sum += x % 10;
			x /= 10;
		}
		if(A <= sum && sum <= B) count += i;
	}
	cout << count << endl;
}