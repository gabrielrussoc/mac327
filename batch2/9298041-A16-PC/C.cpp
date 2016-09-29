#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int inf = INT_MAX;
const int N = 205;
const int M = 2*N*N;
int to[M], head[N], cap[M], fl[M], nx[M], vis[N], es, forbid[M];
int T, P, s, tt, t[N], p[N], ed[N][N], turn;

int dfs(int u, int mini) {
    vis[u] = turn;
    if(u == tt) return mini;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(forbid[e]) continue;
        if(vis[v] != turn && cap[e]-fl[e]) {
            int k = dfs(v, min(mini, cap[e]-fl[e]));
            if(k != inf) {
                fl[e] += k;
                fl[e^1] -= k;
                return k;
            }
        }
    }
    return inf;
}

int maxflow() {
    int mf = 0, k;
    turn++;
    while((k = dfs(s, inf)) != inf) {
        mf += k;
        turn++;
    }
    return mf;
}

void addedge(int u, int v, int _cap) {
    ed[u][v] = es;
    forbid[es] = 0;
    to[es] = v; nx[es] = head[u]; head[u] = es; cap[es] = _cap; fl[es++] = 0;
    ed[v][u] = es;
    forbid[es] = 0;
    to[es] = u; nx[es] = head[v]; head[v] = es; cap[es] = 0; fl[es++] = 0;
}

void show() {
    for(int e = 2; e < es; e++) {
        if(cap[e]) printf("%d %d %d\n", to[e^1], to[e], fl[e]);
    }
    printf("----\n");
}

int main() {
    bool blank = false;
    while(scanf("%d %d", &T, &P) && T && P) {
        if(blank) putchar('\n');
        blank = true;
        es = 2;
        int sp = 0, st = 0;
        memset(head,0,sizeof head);
        for(int i = 0; i < T; i++) { scanf("%d",t+i); st += t[i]; }
        for(int i = 0; i < P; i++) { scanf("%d",p+i); sp += p[i]; }
        s = T+P;
        tt = T+P+1;
        for(int i = 0; i < T; i++) addedge(s,i,t[i]);
        for(int i = 0; i < P; i++) addedge(i+T,tt,p[i]); 
        for(int i = 0; i < T; i++) for(int j = 0; j < P; j++) addedge(i, j+T, 1);

        int mf = maxflow();
        if(mf == st && mf == sp) {
            for(int i = 0; i < T; i++, putchar('\n'))
                for(int j = 0; j < P; j++) {
                    int e = ed[i][j+T];
                    int ee = ed[s][i];
                    int eee = ed[j+T][tt];
                    if(fl[e]) { 
                        fl[e]--; fl[ee]--; fl[eee]--;
                        fl[e^1]++; fl[ee^1]++; fl[eee^1]++;
                        forbid[e] = forbid[e^1] = 1;
                        if(maxflow()) putchar('N');
                        else {
                            putchar('Y');
                            forbid[e] = forbid[e^1] = 0;
                            maxflow();
                        }
                    }
                    else {
                        forbid[e] = forbid[e^1] = 1;
                        putchar('N');
                    }
                }
        } else {
            puts("Impossible");   
        }

    }
}


