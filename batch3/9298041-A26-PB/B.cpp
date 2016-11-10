#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 112345;
int n;
int v[N];
map<int, int> m;

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",v+i);
        m[v[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 32; j++) {
            int o = (1<<j) - v[i];
            ans += ll(m[o]);
            if(o == v[i]) ans--;
        }
    printf("%lld\n",ans/2ll);
}

