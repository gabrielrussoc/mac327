#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int inf = 12345678;
const int N = 107;
const int M = 10007;
int n,r,t;
double memo[N][M];
int visi[N][M];
int adj[N][N];
int turn;

double dp(int q, int s) {
    if(s < 0) return 0;
    if(q == 0) return 1;
    double &me = memo[q][s];
    if(visi[q][s] == turn) return me;
    visi[q][s] = turn;
    me = 0;
    for(int i = 1; i <= r; i++)
        me += (1./r) * dp(q-1,s-i); 
    return me;
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        turn++;
        scanf("%d %d",&n,&r);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                char c;
                scanf(" %c",&c);
                if(c == 'Y') adj[i][j] = 1;
                else adj[i][j] = inf;
            }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        int c;
        scanf("%d",&c);
        printf("Case %d\n",tc);
        while(c--) {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w); a--; b--;
            printf("%.20lf\n",dp(adj[a][b],w));
        }
        printf("\n");
    }
}

