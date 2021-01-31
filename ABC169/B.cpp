#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
int main(){
	mp::cpp_int N;
	std::cin >> N;
	mp::cpp_int A = 1;
	for(mp::cpp_int i=0;i<N;i++){
		mp::cpp_int S;
		std::cin >> S;
		A *= S;
		if(A > 1000000000000000000 || A < 0){
			A = -1;
		}
	}
	std::cout << A << std::endl;
}
