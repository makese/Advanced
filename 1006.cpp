#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){
	int n;
	string outmax = "00:00:00";
	string outname;
	string inmin = "23:59:59";
	string inname;
	cin >> n;
	for(int i = 0; i < n; i ++){
		string name,in,out;
		cin >> name >> in >> out;
		if(in < inmin){
			inmin = in;
			inname = name;
		}
		if(out > outmax){
			outmax = out;
			outname = name;
		}
	}
	cout << inname << " " << outname;
}
