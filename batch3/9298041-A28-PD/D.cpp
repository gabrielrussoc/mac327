#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
const int N = 5123;

int memo[N][N][2], visi[N][N][2], lcp[N][N];
int n;
char s[N];

bool can(int i, int j, int len) {
    int k = lcp[i][j];
    if(k >= len) return false;
    return s[j+k] > s[i+k];
}

int dp(int len, int i, bool big) {
    if(i == n) return 1;
    if(i+len > n || s[i] == '0') return 0;
    int &me = memo[len][i][big];
    if(visi[len][i][big]) return me;
    visi[len][i][big] = 1; 
    me = dp(len+1, i, true);
    if(big || can(i-len, i, len)) me = (me + dp(len, i+len, false)) % MOD; 
    return me;
}

int main() {
    scanf("%d",&n);
    scanf(" %s", s);
    for(int i = n-1; i >= 0; i--)
        for(int j = n-1; j >= 0; j--)
            lcp[i][j] = (s[i] == s[j]) ? 1 + lcp[i+1][j+1] : 0;
    printf("%d\n",dp(1,0,true));
}

