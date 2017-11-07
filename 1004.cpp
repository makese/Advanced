#include <iostream>
#include <vector>

using namespace std;
int maxdepth =0;
vector<vector<int>> r; 
int count[105];
void dfs(int index,int depth){
	if(r[index].size() == 0){
		count[depth] ++;
		maxdepth = maxdepth > depth ? maxdepth : depth;
		return;
	}
	for(int i = 0; i < r[index].size(); i ++){
		dfs(r[index][i],depth + 1);
	}
}


int main(){
	int n,m;
	cin >> n >> m;
	r.resize(n + 1);
	for(int i = 0; i < m; i ++){
		int x,num;
		cin >> x >> num;
		for(int j = 0; j < num; j ++){
			int y;
			cin >> y;
			r[x].push_back(y);
		}
	}
	dfs(1,1);
	for(int i = 1; i <= maxdepth; i ++){
		cout << count[i];
		if(i != maxdepth){
			cout << " "; 
		}
	}
}
