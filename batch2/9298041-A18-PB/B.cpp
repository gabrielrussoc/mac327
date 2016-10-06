#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 207;
int v[N], memo[N][N][N], visi[N][N][N], turn, n;

int dp(int i, int lp, int lb) {
    if(i == n) return 0;
    int &me = memo[i][lp][lb];
    if(visi[i][lp][lb] == turn) return me;
    visi[i][lp][lb] = turn;
    me = dp(i+1,lp,lb);
    if(v[i] > v[lp] || lp == n) me = max(me,1+dp(i+1,i,lb));
    if(v[i] < v[lb] || lb == n) me = max(me,1+dp(i+1,lp,i));
    return me;
}

int main() {
    while(scanf("%d",&n) && n != -1) {
        turn++;
        for(int i = 0; i < n; i++) scanf("%d",v+i);
        printf("%d\n",n-dp(0,n,n));
    }
}

