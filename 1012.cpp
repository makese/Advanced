#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node{
	int no;
	int c;
	int m;
	int e;
	int a;
};

bool cmpc(Node n1, Node n2){
	return n1.c > n2.c;
}

bool cmpm(Node n1, Node n2){
	return n1.m > n2.m;
}
bool cmpe(Node n1, Node n2){
	return n1.e > n2.e;
}
bool cmpa(Node n1, Node n2){
	return n1.a > n2.a;
}

int cm[1000000];
int mm[1000000];
int em[1000000];
int am[1000000];

int main(){
	int n,m;
	cin >> n >> m;
	vector<Node> node(n);
	for(int i = 0; i < n; i ++){
		cin >> node[i].no >> node[i].c >> node[i].m >> node[i].e;
		node[i].a =  round((node[i].c + node[i].m + node[i].e) / 3.0);
	}

	sort(node.begin(),node.end(),cmpc);
	for(int i = 0; i < node.size(); i ++){
		if(i != 0 && node[i - 1].c == node[i].c){
			cm[node[i].no] = cm[node[i - 1].no];
		}else {
			cm[node[i].no] = i + 1;	
		}
	}
	sort(node.begin(),node.end(),cmpm);
	for(int i = 0; i < node.size(); i ++){
		if(i != 0 && node[i - 1].m == node[i].m){
			mm[node[i].no] = mm[node[i - 1].no];
		}else {
			mm[node[i].no] = i + 1;	
		}		
	}
	sort(node.begin(),node.end(),cmpe);
	for(int i = 0; i < node.size(); i ++){
		if(i != 0 && node[i - 1].e == node[i].e){
			em[node[i].no] = em[node[i - 1].no];
		}else {
			em[node[i].no] = i + 1;	
		}	
	}
	sort(node.begin(),node.end(),cmpa);
	for(int i = 0; i < node.size(); i ++){
		if(i != 0 && node[i - 1].a == node[i].a){
			am[node[i].no] = am[node[i - 1].no];
		}else {
			am[node[i].no] = i + 1;
		}	
	}
	for(int i = 0 ; i < m; i ++){
		int no,min = 0x3f3f3f3f;
		char r;
		cin >> no;
		if(em[no] == 0){
			cout << "N/A" << endl;
			continue;
		}
		if(em[no] <= min){
			min = em[no];
			r = 'E';
		}
		if(mm[no] <= min){
			min = mm[no];
			r = 'M';
		}
		if(cm[no] <= min){
			min = cm[no];
			r = 'C';
		}
		if(am[no] <= min){
			min = am[no];
			r = 'A';
		}
		cout << min << " " << r << endl;
	}
}
