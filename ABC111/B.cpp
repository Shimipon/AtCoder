#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> num;
	for(int i=1;i<=9;i++){
		num.push_back(i + i * 10 + i * 100);
	}
	int ans =  *lower_bound(num.begin(), num.end(),N);
	cout << ans << endl;
}