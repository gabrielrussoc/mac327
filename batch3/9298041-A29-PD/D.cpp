#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 512340;
const int inf = INT_MAX;
int n, b, q;
int vis[N], head[N], to[N], nx[N], cap[N], fl[N], es = 2, s, t, turn = 1;

void add_edge (int u, int v, int cp) {
    to[es] = v; nx[es] = head[u]; cap[es] = cp; fl[es] = 0; head[u] = es++;
    to[es] = u; nx[es] = head[v]; cap[es] = 0; fl[es] = 0; head[v] = es++;
}

struct query{
    int up, qt;
    query () {}
    query (int up, int qt) : up(up), qt(qt) {}
    bool operator < (const query &o) const {
        if(up == o.up) return qt < o.qt;
        return up < o.up;
    }
} qry[N];

int dfs(int u, int mn) {
    vis[u] = turn;
    if (u == t) return mn;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(vis[v] != turn && cap[e]-fl[e] > 0){
            int k = dfs(v, min(mn, cap[e]-fl[e]));
            if(k) {
                fl[e] += k;
                fl[e^1] -= k;
                return k;
            }
        }
    }
    return 0;
}

int maxflow(){
    int mf = 0, k;
    while(k = dfs(s, inf)) {
        mf += k;
        turn++;
    }
    return mf;
}

void fail() {
    puts("unfair");
    exit(0);
}

int main() {
    scanf("%d %d %d",&n,&b,&q);
    for(int i = 0; i < q; i++) {
        int up, qt;
        scanf("%d %d", &up, &qt);
        qry[i] = query(up, qt);
    }
    qry[q++] = query(b, n);
    sort(qry, qry+q);
    s = q+5;
    t = q+6;
    for(int i = 0; i < 5; i++) add_edge(s, q+i, n/5);
    int last = 1, ql = 0;
    for(int i = 0; i < q; i++) {
        if(qry[i].qt - ql < 0) fail();
        if(qry[i].qt - ql > qry[i].up-last+1) fail();
        int freq[5] = {0, 0, 0, 0, 0};
        for(int j = last; j <= qry[i].up; j++) freq[j%5]++;
        for(int j = 0; j < 5; j++) add_edge(q+j, i, freq[j]);
        add_edge(i, t, qry[i].qt-ql); 
        last = qry[i].up + 1;
        ql = qry[i].qt;
    }
    if(maxflow() == n) puts("fair");
    else fail();
}

