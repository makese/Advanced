#include <iostream> 
#include <vector>
using namespace std;
int main() {
	bool flag = false;
    int n, sum = -1, temp = 0, left = 0, right = 0, index = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if(v[i] >= 0)
            flag = true;
        temp = temp + v[i];
        if(temp > sum) {
            sum = temp;
            left = index;
            right = i;
        } else if(temp < 0) {
            temp = 0;
            index = i + 1;
        }
    }
    if(!flag)
        printf("0 %d %d", v[0], v[n - 1]);
    else
        printf("%d %d %d", sum, v[left], v[right]);
    return 0;
}
