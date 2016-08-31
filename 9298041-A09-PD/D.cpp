#include <bits/stdc++.h>
#define pb push_back
#define wei first
#define vert second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, int> pli;

const int N = 212345;
int hd[N], to[N], nx[N], hdR[N], toR[N], nxR[N], es;
ll wei[N], d[N], dR[N];
int n, m, s, t, pre[N], tempo, disc[N], vis[N], low[N], bridge[N], seen[N];
int shd[N], sto[N], snx[N], ss, sc[N];
const ll inf = 100000000000LL;

void dij() {
    priority_queue<pli> q;
    q.push(pii(0,s));
    d[s] = 0;
    while(!q.empty()) {
        int u = q.top().vert;
        ll aux = -q.top().wei;
        q.pop();
        if(aux > d[u]) continue;
        for(int e = hd[u]; e != -1; e = nx[e]) {
            int v = to[e];
            ll w = wei[e];
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(pii(-d[v], v));
            }
        }
    }
}

void dijR() {
    priority_queue<pii> q;
    q.push(pii(0,t));
    dR[t] = 0;
    while(!q.empty()) {
        int u = q.top().vert;
        ll aux = -q.top().wei;
        q.pop();
        if(aux > dR[u]) continue;
        for(int e = hdR[u]; e != -1; e = nxR[e]) {
            int v = toR[e];
            ll w = wei[e];
            if(dR[v] > dR[u] + w) {
                dR[v] = dR[u] + w;
                q.push(pii(-dR[v], v));
            }
        }
    }
}

void get_soares() {
    queue<int> q;
    q.push(t);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(seen[u]) continue;
        seen[u] = 1;
        for(int e = hdR[u]; e != -1; e = nxR[e]) {
            int v = toR[e];
            ll w = wei[e];
            if(d[u] == d[v] + w) {
                q.push(v);
                sto[ss] = v; snx[ss] = shd[u]; shd[u] = ss++; 
                sto[ss] = u; snx[ss] = shd[v]; shd[v] = ss++; 
                sc[e^1] = ss-1;
            }
        }
    }
}

void get_bridges(int u, int p) {
    vis[u] = 1;
    disc[u] = low[u] = tempo++;
    int k = 0;
    for(int e = shd[u]; e != -1; e = snx[e]) {
        int v = sto[e];
        if(v == p) k++;
        if(!vis[v]) {
            get_bridges(v, u);
            low[u] = min(low[u], low[v]);       
            if(low[v] > disc[u]) bridge[e] = bridge[e^1] = 1;
        } else if(v != p || k > 1) low[u] = min(low[u], disc[v]);
    }
}

int main() {
    scanf("%d %d %d %d",&n, &m, &s, &t); s--; t--;
    memset(hd, -1, sizeof hd);
    memset(hdR, -1, sizeof hdR);
    memset(shd, -1, sizeof shd);
    memset(sc, -1, sizeof sc);
    for(int i = 0; i < n; i++) d[i] = dR[i] = inf;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d",&u, &v, &w); u--; v--;
        wei[es] = w; to[es] = v; nx[es] = hd[u]; hd[u] = es++; 
        wei[es] = w; toR[es] = u; nxR[es] = hdR[v]; hdR[v] = es++; 
    }  
    dij(); dijR();
    get_soares();
    for(int i = 0; i < n; i++) if(!vis[i]) get_bridges(i, -1);
    for(int e = 0; e < es; e += 2) {
        int u, v;
        v = to[e], u = toR[e^1];
        if(sc[e] != -1 && bridge[sc[e]]) puts("YES");
        else {
            if(d[u] + dR[v] + 1ll < d[t]) printf("CAN %I64d\n",wei[e]-d[t]+d[u]+dR[v]+1ll);
            else puts("NO");
        }
    }
}

