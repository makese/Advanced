#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10005][205];
int main(){
	int n,m;
	cin >> n;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; i ++){
		cin >> b[i];
	}
	cin >> m;
	vector<int> a(m);
	for(int i = 0; i < m; i ++){
		cin >> a[i];
	}
	int r = 0;
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			dp[i + 1][j + 1] = max(dp[i][j + 1],dp[i + 1][j]);
			if(a[i] == b[j]){
				dp[i + 1][j + 1] = max(dp[i][j] + 1,dp[i + 1][j + 1]);
				dp[i + 1][j + 1] = max(dp[i][j + 1] + 1,dp[i + 1][j + 1]);
			}
			if(dp[i + 1][j + 1] > r){
				r = dp[i + 1][j + 1];
			}
		}
	}
	cout << r;
}