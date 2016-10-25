#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

ll memo[5123];
int visi[5123], turn, n;
char s[5123];

bool can(int i) {
    int a = 10*(s[i]-'0');
    a += s[i+1]-'0';
    return a <= 26;
}

ll dp(int i) {
    if(i == n) return 1;
    if(s[i] == '0') return 0;
    ll &me = memo[i];
    if(visi[i] == turn) return me;
    visi[i] = turn;
    me = dp(i+1);
    if(i < n-1 && can(i)) me += dp(i+2);
    return me;
}

int main() {
    while(scanf(" %s",s) && s[0] != '0') {
        n = strlen(s);
        ++turn;
        printf("%lld\n",dp(0));   
    }
}

