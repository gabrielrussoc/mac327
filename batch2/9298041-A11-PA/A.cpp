#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m;
int g[12][12];
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};
int d[12][12];
pii s;

bool isval(int i, int j) {
    if(i < 0 || i >= n) return 0;
    if(j < 0 || j >= m) return 0;
    if(g[i][j] == 2) return 0;
    return 1;
}

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) {
            scanf("%d",&g[i][j]);
            if(g[i][j] == 3) s = pii(i,j); 
            d[i][j] = INT_MAX;
        }

    queue<pii> q;
    q.push(s);
    d[s.first][s.second] = 0;
    int ans = INT_MAX;
    while(!q.empty()) {
        pii u = q.front();
        int i = u.first;
        int j = u.second;
        if(g[i][j] == 0) ans = min(ans, d[i][j]);
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(!isval(ni,nj)) continue;
            if(d[ni][nj] > d[i][j] + 1) {
                d[ni][nj] = d[i][j] + 1;
                q.push(pii(ni,nj));
            } 
        }
    }
    printf("%d\n",ans);
}

