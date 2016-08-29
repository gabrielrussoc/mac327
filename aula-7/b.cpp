#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 5003;

int k, c;
int prime[] = {2,3,5,7,11,13,17,19,23};
int ans[N];

void suc() {
    for(int i = 0; i < k; i++) printf("%d ",ans[i]);
    putchar('\n');
    exit(0);
}

int count(int i, int x) {
    if(i < 0) {
        return 1;
    }
    int ret = 0;
    if(prime[i]*x <= 2*k*k)
        ret += count(i, x*prime[i]);
    ret += count(i-1, x);
    return ret;
}

void get_ans(int i, int x) {
    if(i < 0){
        ans[c++] = x;
        if(c == k) suc();
        return;
    }
    if(prime[i]*x <= 2*k*k)
        get_ans(i, x*prime[i]);
    get_ans(i-1,x);
}

int main() {
    scanf("%d",&k);
    for(int q = 0; q < 6; q++) {
        if(count(q,1) >= k) {
            get_ans(q,1);
        }
    }
}

