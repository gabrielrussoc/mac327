#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 157;

int n;
int memo[22][11][N], visi[22][11][N], turn;

int dp(int ls, int k, int s) {
    if(s < 0) return 0;
    if(k == 0) return (s == 0);
    if(ls > n) return 0;
    int &me = memo[ls][k][s];
    if(visi[ls][k][s] == turn) return me;
    visi[ls][k][s] = turn;
    me = 0;
    for(int i = ls; i <= n; i++)
        me += dp(i+1,k-1,s-i);
    return me;
}

int main() {
    int k, s;
    while(scanf("%d %d %d",&n,&k,&s) && n && k && s) {
        turn++;
        printf("%d\n",dp(1,k,s));
    }
}

