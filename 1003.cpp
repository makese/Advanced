#include <iostream>
#include <cstring>
using namespace std;

int w[510];
int v[510][510];
bool vis[510];
int dv[510];
int num[510];
int weight[510];
const int MAX = 0x3f3f3f3f;
int main(){
	int n,m,c1,c2;
	cin >> n >> m >> c1 >> c2;
	memset(dv,MAX,sizeof(dv));
	memset(v,MAX,sizeof(v));
	for(int i = 0; i < n; i ++){
		cin >> w[i];
	}
	for(int i = 0 ; i < m; i ++){
		int x,y,z;
		cin >> x >> y >> z;
		v[x][y] = z;
		v[y][x] = z;
	}
	dv[c1] = 0;
	weight[c1] = w[c1];
	num[c1] = 1;
	for(int i = 0; i < n; i ++){
		int u = -1,minn = MAX;
		for(int j = 0; j < n; j++) {
            if(vis[j] == false && dv[j] < minn) {
                u = j;
                minn = dv[j];
            }
        }
		if(u == -1) break;
		vis[u] = true;
		for(int k = 0; k < n; k ++){
			if(vis[k] == false && v[u][k] != MAX){
				if(dv[u] + v[u][k] < dv[k]){
					dv[k] = dv[u] + v[u][k];
					num[k] = num[u];
					weight[k] = weight[u] + w[k];
				} else if(dv[u] + v[u][k] == dv[k]){
					num[k] += num[u];
					if(weight[u] + w[k] > weight[k]){
						weight[k] = weight[u] + w[k];
					}
				}
			}

		}		
	}
	printf("%d %d",num[c2],weight[c2]);
}
