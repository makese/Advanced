#include<iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		int m;
		int x[2005] = {0};
		int y[2005] = {0};
		int z[2005] = {0};
		cin >> m;
		vector<int> in(m);
		for(int j = 0; j < m; j ++){
			cin >> in[j];
		}
		bool flag = true;
		for(int j = 0; j < m && flag; j ++){
			int xx = in[j] - j + m;
			int yy = in[j] + j;
			if(x[xx] == 1 || y[yy] == 1 || z[in[j]] == 1){
				cout << "NO" << endl;
				flag = false;
				break;	
			}
			x[xx] ++;
			y[yy] ++;
			z[in[j]] ++;
		}
		if(flag){
			cout << "YES" << endl;
		}
	}
}
