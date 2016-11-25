#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
const int N = 5123;

int memo[N][N][2], visi[N][N][2], lcp[N][N];
int n;
char s[N];

int dp(int len, int i, bool big) {
    printf("%d %d %d\n",len,i,big);
    if(i == n) return 1;
    int &me = memo[len][i][big];
    if(visi[len][i][big]) return me;
    visi[len][i][big] = 1; 
    me = dp(len+1,i+1,true);
    if(i + len > n || s[i] == '0') return me;
    if(big) me = (me + dp(len,i+len,false)) % MOD;
    else {
        int j = lcp[i-len][i];
        if(j == len || s[i-len+j] < s[i+j])
           me = (me + dp(len, i+len, false)) % MOD; 
    }
    return me % MOD;
}

int main() {
    scanf("%d",&n);
    scanf(" %s", s);
    for(int i = n-1; i >= 0; i--)
        for(int j = n-1; j >= 0; j--)
            lcp[i][j] = (s[i] == s[j]) ? 1 + lcp[i+1][j+1] : 0;
    printf("%d\n",dp(1,1,true));
}

