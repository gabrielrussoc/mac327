#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1123456;

int p[N], prime[N];

void build(){
    for(int i = 2; i < N; i++) {
        if(prime[i]) continue;
        for(int j = i; j < N; j += i)
            prime[j] = i;
    }
    p[1] = 0;
    for(int i = 2; i < N; i++) {
        int x = i;
        if(prime[i] == i) {
            p[i] = -1;
            continue;
        }
        while(x > 1) {
            p[i]++;
            x /= prime[x];
        }
    }
}

int main() {
    build();
    int a, b;
    int tc = 1;
    while(scanf("%d %d",&a,&b) && a != -1) {
        int ans = -INT_MAX;
        int at = 0, q = 0;
        for(int i = a; i <= b; i++) {
            at += p[i]; q++;
            ans = max(ans,at-q);
            if(at - q < 0) at = q = 0;
        }
        printf("%d. %d\n",tc++, ans);
    }
            
}
