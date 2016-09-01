#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 300;

int uf[N*N], wf[N*N], n ,m;
int g[N][N];
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};
map<int,int> ans;

int find (int i) {
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

void join (int i, int j) {
    i = find(i); j = find(j);
    if(i == j) return;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
}

int id(int i, int j) {
    return i*m + j;
}

int isval(int i, int j) {
    if(i < 0 || i >= n) return 0;
    if(j < 0 || j >= m) return 0;
    return 1;
}


int main() {
    while(scanf("%d %d", &n, &m) && n && m) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                scanf("%d",&g[i][j]);
                int k = id(i,j);
                wf[k] = 1; uf[k] = k;
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 0) continue;
                int k = id(i,j);
                for(int q = 0; q < 4; q++) {
                    int ni = i+di[q], nj = j+dj[q];
                    if(!isval(ni,nj)) continue;
                    if(g[ni][nj] == 0) continue;
                    int kk = id(ni, nj);
                    join(k,kk);
                }
            } 

        ans.clear();
        int cont = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 0) continue;
                int k = id(i,j);
                if(uf[k] == k) {
                    cont++;
                    ans[wf[k]]++;
                }
            }

        printf("%d\n", cont);
        for(auto x : ans) 
            printf ("%d %d\n",x.first,x.second);
    }
}

