#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 66;

int d[N][N][N], memo[N][N][N], visi[N][N][N], c[N][N];
int n, m, r;
int inf = 1e9;

int dp(int u, int t, int k) {
    if(u == t) return 0;
    if(k == 0) return inf;
    int &me = memo[u][t][k];
    if(visi[u][t][k]) return me;
    visi[u][t][k] = 1;
    me = inf;
    for(int v = 0; v < n; v++) 
        me = min(me, c[u][v] + dp(v,t,k-1));
    return me;
}

int main() {
    scanf("%d %d %d",&n,&m, &r);
    for(int c = 0; c < m; c++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d",&d[c][i][j]);
    }    
    
    for(int c = 0; c < m; c++)
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    d[c][i][j] = min(d[c][i][j], d[c][i][k] + d[c][k][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            c[i][j] = d[0][i][j];

    for(int q = 1; q < m; q++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                c[i][j] = min(c[i][j], d[q][i][j]);
    }

    while(r--) {
        int s, t, k;
        scanf("%d %d %d",&s,&t,&k); s--; t--;
        k = min(k, 60);
        printf("%d\n",dp(s,t,k+1));
    }
}

