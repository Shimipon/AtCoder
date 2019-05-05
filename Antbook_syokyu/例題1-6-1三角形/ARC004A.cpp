#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;


int main(){
	int N;
	cin >> N;
	vector<double> x(N),y(N);
	for(int i=0;i<N;i++){
		cin >> x[i] >> y[i];
	}
	double ans = 0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			double ans1 = (x[i] - x[j]) * (x[i] - x[j]);
			ans1 += (y[i] - y[j]) * (y[i] - y [j]);
			ans1 = sqrt(ans1);
			ans = max(ans, ans1);
		}
	}
	cout << ans << endl;
}



