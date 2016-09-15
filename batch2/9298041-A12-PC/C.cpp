#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 33;
const int inf = INT_MAX;

int n, m, t, s;
int grave[N][N], d[N*N], fr[7*N*N*N], to[7*N*N*N], w[7*N*N*N] ;
int ti[N*N], tj[N*N], tw[N*N], es;
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};

bool isval(int i, int j) {
    if (i < 0 || i >= n) return 0;
    if (j < 0 || j >= m) return 0;
    if(grave[i][j] == -1) return 0;
    return 1;
}

void build() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(grave[i][j] == -1) continue;
            int u = i*m + j;
            if(u == t) continue;
            if(grave[i][j] > 0) { 
                int k = grave[i][j];
                int v = ti[k]*m + tj[k]; 
                int ww = tw[k];
                fr[es] = u; to[es] = v; w[es] = ww; es++;
                continue;
            }
            for(int k = 0; k < 4; k++) {
                int ni = i + di[k]; 
                int nj = j + dj[k];
                if(!isval(ni,nj)) continue;
                int v = ni*m + nj;
                fr[es] = u; to[es] = v; w[es] = 1; es++;
            }
        }
}

int main() {
    while(scanf("%d %d",&n,&m) && n && m) {
        es = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                grave[i][j] = 0;
                d[i*m+j] = inf;
            }
        int g;
        scanf("%d",&g);
        for(int k = 0; k < g; k++) {
            int i, j;
            scanf("%d %d", &i, &j);
            grave[i][j] = -1;
        }
        int e;
        scanf("%d", &e);
        for(int k = 1; k <= e; k++) {
            int i, j, ww;
            scanf("%d %d",&i, &j);
            grave[i][j] = k;
            scanf("%d %d %d",&i, &j, &ww);
            ti[k] = i; tj[k] = j; tw[k] = ww;
        }
        s = 0;
        t = (n-1)*m + m-1;
        build();
        d[s] = 0;
        for(int i = 0; i < n*m-1; i++)
            for(int j = 0; j < es; j++)
                if(d[fr[j]] != inf)
                    d[to[j]] = min (d[to[j]], d[fr[j]] + w[j]);
        bool f = true;
        for(int j = 0; j < es && f; j++)
            if(d[fr[j]] != inf && d[to[j]] > d[fr[j]] + w[j])
                f = false;
        if(!f) puts("Never");
        else {
            if(d[t] != inf) printf("%d\n",d[t]);
            else puts("Impossible");
        }
    }
}

