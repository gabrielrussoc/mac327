#include <bits/stdc++.h>
#define pb push_back
#define vert second
#define wei first
using namespace std;
typedef long long ll;
typedef pair<int,int> pb;
const int inf = 1234567;
const int N = 104;

int n, m;
int d[N][N], pos[N], ps;

void floyd() {
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    int t; 
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        ps = 0;
        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = inf;
        for(int i = 0; i < n; i++) d[i][i] = 0;
        for(int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d %d %d",&u, &v, &c); u--; v--;
            d[u][v] = d[v][u] = min(d[u][v], c);
        }
        floyd();
        bool f = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(d[i][j] == inf) f = false;
        if(!f) {
            printf("Map %d: -1\n", tc);
            continue;
        }
        for(int i = 0; i < n; i++) {
            bool f = true;
            for(int j = 0; j < 4; j++) 
                if(d[i][j] != d[i][j+1]) f = false;
            if(f) pos[ps++] = i;
        }
        if(!ps) {
            printf("Map %d: -1\n", tc);
            continue;
        }
        int ans = inf;
        for(int i = 0; i < ps; i++) {
            int u = pos[i];
            int loc = -1;
            for(int v = 0; v < n; v++) if(d[u][v] != inf) loc = max(loc, d[u][v]);
            if(loc != -1) ans = min(ans, loc);
        }
        printf("Map %d: %d\n",tc, ans);
    }
}

