#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int modn = 1e9+7;
const int N = 50001;
const int C = 301;
int memo[N][2];
int n,a,b;

int dp(int k, int ls) {
    if(k > n) return 0;
    if(k == n) return 1;
    int &me = memo[k][ls];
    if(me != -1) return me;
    me = 0;
    if(ls == 0) for(int i = 1; i <= a; i++) me = (me + dp(k+i,ls^1))%modn;
    else for(int i = 1; i <= b; i++) me = (me + dp(k+i,ls^1))%modn;
    return me%modn;
}

int main() {
    scanf("%d %d %d",&n,&a,&b);
    memset(memo,-1,sizeof memo);
    printf("%d\n",(dp(0,0) + dp(0,1))%modn);
}

