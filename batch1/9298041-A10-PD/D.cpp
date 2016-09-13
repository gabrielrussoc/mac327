#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 55;
int g[N][N], s, t, k, seen[N*N], turn;
int n, tc;
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};

int isval(int i, int j) {
    if(i < 0 || i >= n) return 0;
    if(j < 0 || j >= n) return 0;
    if(!( (1<<(g[i][j]) ) & k )) return 0; 
    return 1;
}

int dfs(int u) {
    if(u == t) return 1;
    seen[u] = turn;
    for(int q = 0; q < 4; q++) {
        int i = u/n;
        int j = u%n;
        int ni = i+di[q], nj = j+dj[q];
        if(!isval(ni,nj)) continue;
        int v = ni*n + nj;
        if(seen[v] != turn && dfs(v)) return 1;
    }   
    return 0;
}

int main() {
    scanf("%d",&tc);
    while(tc--) {
        turn = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                scanf("%d", &g[i][j]);
                seen[i*n+j] = 0;
            }

        int x,y;
        scanf("%d %d",&x,&y);
        s = x*n + y;

        scanf("%d %d",&x,&y);
        t = x*n + y;

        int ans = 12345;
        for(k = 0; k < (1<<10); k++) {
            turn++;
            if(!isval(s/n,s%n)) continue;
            if(dfs(s)) ans = min(ans, __builtin_popcount(k));
        }
        printf("%d\n",ans);
    }
}

