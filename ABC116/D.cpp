#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
using namespace std;

int main(){
	long long N, K;
	cin >> N >> K;
	vector<long long> t(N);
	vector<long long> d(N);
	for(int i=0;i<N;i++){
		cin >> t[i] >> d[i];
	}
	vector<pair<long long, long long>> point(N);
	for(int i=0;i<N;i++){
		point[i].first = d[i];
		point[i].second = t[i];
	}
	sort(point.rbegin(), point.rend());
	vector<long long> used(N+1,0);
	long long ans = 0;
	long long sum = 0;
	long long count = 0;
	vector<long long> same;
	for(int i=0; i<K;i++){
		sum += point[i].first;
		if(!used[point[i].second]){
			used[point[i].second] = 1;
			++count;
		}
		else{
			same.push_back(point[i].first);
		}
	}
	ans = sum + count * count;
	for(int i = K;i<N && same.size();i++){
		if(used[point[i].second]) continue;
		used[point[i].second] = 1;
		count++;
		sum -= same.back();
		same.pop_back();
		sum += point[i].first;
		ans = max(ans, sum + count * count);
	}
	cout << ans << endl;
}