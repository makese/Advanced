#include <iostream>
#include <string>
#include <vector>
using namespace std;

string map[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int toSum(string a){
	int sum = 0;
	for(int i = 0;a[i]; i ++){
		sum += a[i] - '0';
	}
	return sum;
}

int main(){
	string in;
	cin >> in;
	vector<int> r;
	int sum = toSum(in);
	if(sum == 0){
		cout << map[0];
		return 0;
	}
	while(sum != 0){
		r.push_back(sum % 10);
		sum /= 10;
	}
	for(int i = r.size()- 1; i >= 0; i --){
		cout << map[r[i]];
		if(i!= 0){
			cout << " ";
		}
	}
}
