#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 105;
int n, m, q;
int uf[N][N], wf[N][N];

int find (int c, int i) {
    if(uf[c][i] == i) return i;
    return uf[c][i] = find(c, uf[c][i]);
}

void join (int c, int i, int j) {
    i = find(c, i); j = find(c, j);
    if(i == j) return;
    if(wf[c][i] > wf[c][j]) swap(i,j);
    wf[c][j] += wf[c][i];
    uf[c][i] = j;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            uf[i][j] = j, wf[i][j] = 1;

    for(int i = 0; i < m; i++) {
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        u--; v--;
        join(c,u,v);
    }
    scanf("%d",&q);
    while(q--) {
        int s,t;
        int cont = 0;
        scanf("%d %d",&s,&t); s--; t--;
        for(int c = 1; c <= m; c++)
            if(find(c,s) == find(c,t)) cont++;
        printf("%d\n",cont);
    }
}

