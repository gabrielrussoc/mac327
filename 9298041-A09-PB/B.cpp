#include <bits/stdc++.h>
#define pb push_back
#define exit uaehueah
using namespace std;

typedef long long ll;

struct triple {
    int i,j,k;
};

const int inf = 1234567;
queue<triple> q;
triple start, exit;

int l, r, c, d[33][33][33];
char g[33][33][33];

int di[] = {1,-1,0,0,0,0};
int dj[] = {0,0,1,-1,0,0};
int dk[] = {0,0,0,0,1,-1};

bool isval(int i, int j, int k) {
    if(i < 0 || i == r) return false;
    if(j < 0 || j == c) return false;
    if(k < 0 || k == l) return false;
    return g[i][j][k] != '#';
}


void bfs() {
    d[start.i][start.j][start.k] = 0;
    q.push(start);
    while(q.size()) {
        triple at = q.front();
        q.pop();
        for(int qq = 0; qq < 6; qq++) {
            int ni = at.i + di[qq];
            int nj = at.j + dj[qq];
            int nk = at.k + dk[qq];
            if(isval(ni,nj,nk) && d[ni][nj][nk] > d[at.i][at.j][at.k] + 1) {
                d[ni][nj][nk] = d[at.i][at.j][at.k] + 1;
                q.push({ni,nj,nk});
            }
        }
    }
}

int main() {
    while(scanf("%d %d %d",&l, &r, &c) && l && r && c) {
        for(int k = 0; k < l; k++)
            for(int i = 0; i < r; i++)
                for(int j = 0; j < c; j++) {
                    scanf(" %c",&g[i][j][k]);
                    if(g[i][j][k] == 'S') start = {i,j,k};
                    else if (g[i][j][k] == 'E') exit = {i,j,k};
                    d[i][j][k] = inf;
                }

        bfs();
        int ans = d[exit.i][exit.j][exit.k];
        if(ans == inf) puts("Trapped!");
        else printf("Escaped in %d minute(s).\n", ans);
    }
}

