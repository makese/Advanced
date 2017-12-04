#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> v[n];
	for(int i = 0; i < m; i ++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(i);
		v[y].push_back(i);
	}
	int nn,mm;
	cin >> nn;
	for(int i = 0; i < nn; i ++){
		map<int,bool> hash;
		cin >> mm;
		for(int j = 0; j < mm; j ++){
			int temp;
			cin >> temp;
			for(int k = 0; k < v[temp].size(); k ++){
				hash[v[temp][k]] = true;
			}
		}
		bool flag = true;
		for(int j = 0; j < m; j ++){
			if(!hash[j]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}