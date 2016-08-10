#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 11234;
int p[N], ps, f[N];

int main() {
    for(int i = 2; i < N; i++) {
        if(p[i]) continue;
        for(int j = i; j < N; j+= i)
            p[j] = i;
    }
    int x;
    for(int i = 0; i < 10; i++) {
        scanf("%d",&x);
        while(x > 1) {
            f[p[x]]++;
            x /= p[x];
        }
    }
    int ans = 1;
    for(int i = 0; i < N; i++) if(f[i]) { ans *= (f[i]+1); ans %= 10; }
    printf("%d\n",ans);
}
