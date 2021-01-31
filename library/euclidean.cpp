long long Euclidean(long long A, long long B){
	long long C = 0;
	if(A == B)return A;
	if(A > B){
		C = A % B;
		if(C == 0) return B;
		else return Euclidean(B, C);
	}
	else{
		C = B % A;
		if(C == 0) return A;
		else return Euclidean(A, C);
	}
}