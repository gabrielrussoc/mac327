#include <stdio.h>

const int N = 105;
int g[105][105];
int memo[105][105], visi[105][105];
int n, m, t, turn;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int dp(int i, int j) {
    if(i == n) return 0;
    if(visi[i][j] == turn) return memo[i][j];
    visi[i][j] = turn;
    memo[i][j] = g[i][j] + dp(i+1,j);
    if(j+1 < m) memo[i][j] = max(memo[i][j], g[i][j] + dp(i+1,j+1));
    if(j-1 >= 0) memo[i][j] = max(memo[i][j], g[i][j] + dp(i+1,j-1));
    return memo[i][j]; 
}

int main() {
    int i, j;
    scanf("%d", &t);
    for(turn = 1; turn <= t; turn++) {
        scanf("%d %d",&n,&m);
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                scanf("%d",&g[i][j]);
        int ans = 0;
        for(i = 0; i < m; i++) ans = max(ans, dp(0,i));
        printf("%d\n",ans);
    }
}

