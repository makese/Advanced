#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	vector<int> r;
	int sum = a + b;
	if(sum < 0 ){
		cout << "-";
		sum = -sum;
	}
	if(sum == 0){
		cout << 0;
		return 0;
	}
	while(sum != 0){
		r.push_back(sum % 1000);
		sum /= 1000;
	}
	reverse(r.begin(),r.end());
	for(int i = 0; i < r.size(); i ++){
		if(r[i] <= 100 && i != 0){
		 printf("%03d",r[i]);
		} else {
			cout << r[i];
		}
		if(i != r.size() -1){
			cout << ",";
		}
	}
}
