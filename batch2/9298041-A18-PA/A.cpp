#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 102;
const int M = 50001;

int memo[M];
int visi[M], turn, v[N],n,m;
const int inf = 12031248;

int dp(int q) {
    if(q == 0) return 0;
    int &me = memo[q];
    if(visi[q] == turn) return me;
    visi[q] = turn;
    me = inf;
    for(int i = 0; i < n; i++) if(q-v[i] >= 0) me = min(me,1+dp(q-v[i]));
    return me;
}

int main() {
    while(scanf("%d",&m) && m) {
        turn++;
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",v+i);
        int ans = dp(m);
        if(ans == inf) puts("Impossivel");
        else printf("%d\n",ans);
    }
}

