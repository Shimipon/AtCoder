#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;


int main(){
	int N, Y;
	cin >> N >> Y;
	int check = 0;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N-i;j++){
			if(i * 1000 + j * 5000 + (N - i - j) * 10000 == Y){
				cout << N - i - j << " " << j << " " << i << endl;
				check = 1;
				break;
			}
		}
		if(check) break;
	}
	if(!check) cout << -1 << " " << -1 << " " << -1 << endl;
}



