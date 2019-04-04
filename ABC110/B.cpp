#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	vector<int> x(N), y(M);
	for(int i=0;i<N;i++){
		cin >> x[i];
	}
	for(int i=0;i<M;i++){
		cin >> y[i];
	}
	int maxx = -101;
	int miny = 101;
	for(int i=0;i<N;i++){
		maxx = max(x[i],maxx);
	}
	for(int i=0;i<M;i++){
		miny = min(y[i],miny);
	}
	if(maxx < miny && miny > X && maxx < Y) cout << "No War" << endl;
	else cout << "War" << endl;
}