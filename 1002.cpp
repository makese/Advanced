#include <iostream>
#include <vector>
using namespace std;
double r[1005];
int count [1005];
int main(){
	int n;
	cin >> n;
	vector<int> x;
	vector<double> y;
	for(int i = 0 ; i < n; i ++){
		int a;
		double b;
		cin >> a >> b;
		r[a] += b;
		count[a] = 1;
	}
	cin >> n;
	for(int i = 0 ; i < n; i ++){
		int a;
		double b;
		cin >> a >> b;
		r[a] += b;
		count[a] = 1;
	}
	int sum = 0;
	for(int i = 1000 ; i >= 0; i--){
		if(r[i] != 0.0 && count[i] != 0){
			sum ++;
			x.push_back(i);
			y.push_back(r[i]);
		}
	}
	if(sum == 0){
		cout << sum;
		return 0;
	}
	cout << sum << " ";
	for(int i = 0 ; i < x.size(); i ++){
		cout << x[i] << " ";
		printf("%.1lf",y[i]);
		if(i != x.size() - 1){
			cout << " ";
		}
	}
}
