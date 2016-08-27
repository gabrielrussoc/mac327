#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112;

int t, n, k, turn;
int adj[N][N], black[N], tmp[N], best, at;

void bt(int u) {
    if(u == n) {
        if(at > best) {
            for(int i = 0; i < at; i++)
                black[i] = tmp[i];
            best = at;
        }
        return;
    }
    bool go = true;
    for(int i = 0; i < at && go; i++)
        if(adj[u][tmp[i]] == turn)
            go = false;
    if(go) {
        tmp[at++] = u;
        bt(u+1);
        at--;
    }
    bt(u+1);
}

int main() {
    scanf("%d",&t);
    while(t--) {
        turn++;
        best = at = 0;
        scanf("%d %d",&n,&k);
        memset(adj,0,sizeof adj);
        for(int i = 0; i < k; i++) {
            int u, v;
            scanf("%d %d",&u,&v); u--; v--;
            adj[u][v] = adj[v][u] = turn;
        }
        bt(0);
        printf("%d\n",best);
        for(int i = 0; i < best; i++) printf("%d%c",black[i]+1," \n"[i==best-1]);
    }

}

