#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 6123;

int memo[N][N], visi[N][N], turn;
int t, n;
char s[N];

int dp(int i, int j) {
    if(i >= j) return 0;
    int &me = memo[i][j];
    if(visi[i][j] == turn) return me;
    visi[i][j] = turn;
    me = N;
    if(s[i] == s[j]) me = min(me, dp(i+1,j-1));
    return me = min(me, 1 + min(dp(i+1,j),dp(i,j-1)));
}

int main() {
    scanf("%d",&t);
    while(t--){
        turn++;
        scanf(" %s", s);
        n = strlen(s);
        printf("%d\n",dp(0,n-1));
    }
}

