#include <iostream>
#include <vector>

using namespace std;

int map[100005];

struct node{
	int addr;
	int data;
	int next;
};

int main(){
	int s,n,k;
	cin >> s >> n >> k;
	vector<node> in(n);
	for(int i = 0; i < n; i ++){
		cin >> in[i].addr >> in[i].data >> in[i].next;
		map[in[i].addr] = i;
	}
	vector<node> r;
	node no = in[map[s]];
	while(true){
		r.push_back(no);
		if(no.next == -1){
			break;
		}
		no = in[map[no.next]];
	}
	vector<node> x;
	vector<node> y;
	vector<node> z;
	for(int i = 0; i < r.size(); i ++){
		if(r[i].data < 0){
			x.push_back(r[i]);
		}
	}
	for(int i = 0; i < r.size(); i ++){
		if(r[i].data >=0 && r[i].data <= k){
			y.push_back(r[i]);
		}
	}
	for(int i = 0; i < r.size(); i ++){
		if(r[i].data > k){
			z.push_back(r[i]);
		}
	}
	for(int i = 0; i < x.size(); i ++){
		if(i == x.size() - 1){
			if(y.size()){
				printf("%05d %d %05d\n",x[i].addr, x[i].data, y[0].addr);
			}else {
				if(z.size()){
					printf("%05d %d %05d\n",x[i].addr, x[i].data, z[0].addr);	
				} else {
					printf("%05d %d -1\n",x[i].addr, x[i].data);
				}
			}
		}else {
			printf("%05d %d %05d\n",x[i].addr, x[i].data, x[i + 1].addr);
		}
	}
	for(int i = 0; i < y.size(); i ++){
		if(i == y.size() - 1){
			if(z.size()){
				printf("%05d %d %05d\n",y[i].addr, y[i].data, z[0].addr);	
			} else {
				printf("%05d %d -1\n",y[i].addr, y[i].data);
			}
		}else {
			printf("%05d %d %05d\n",y[i].addr, y[i].data, y[i + 1].addr);
		}
	}
	for(int i = 0; i < z.size(); i ++){
		if(i == z.size() - 1){
			printf("%05d %d -1\n",z[i].addr, z[i].data);	
		} else {
			printf("%05d %d %05d\n",z[i].addr, z[i].data, z[i + 1].addr);	
		}
	}
}