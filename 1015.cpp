#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isprime(int n){
	if(n == 1){
		return false;
	}
	for(int i = 2 ; i * i <= n; i ++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

bool isRe(int n, int r){
	vector<int> x;
	int temp = n;
	while(n != 0){
		x.push_back(n % r);
		n = n / r;
	}
	int sum = 0;
	for(int i = 0 ; i < x.size(); i ++){
		sum *= r;
		sum += x[i];
	}
	if(isprime(sum) && isprime(temp)){
		return true;
	} else {
		return false;
	}
}

int main(){
	while(true){
		int x,y;
		cin >> x;
		if(x >= 0){
			cin >> y;
		} else {
			return 0;
		}
		if(isRe(x, y)){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	
}
