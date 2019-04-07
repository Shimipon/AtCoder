#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
using namespace std;

int main(){
	long long N;
	cin >> N;
	vector<long long> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	long long count = 0;
	for(int i=0;i<N;i++){
		while(!(a[i] % 2)){
			a[i] /= 2;
			count++;
		}
	}
	cout << count << endl;
}