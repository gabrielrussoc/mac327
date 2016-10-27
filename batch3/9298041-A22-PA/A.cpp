#include <bits/stdc++.h>
using namespace std;

const int N = 4123;
int a, b, c;
int memo[N], visi[N];
int inf = 1234567;

int dp(int n) {
    if(n == 0) return 0;
    if(n < 0) return -inf;
    int &me = memo[n];
    if(visi[n]) return me;
    visi[n] = 1;
    me = -inf;
    return me = max(me, 1 + max(dp(n-a), max(dp(n-b), dp(n-c))));
}

int main() {
    int n;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    printf("%d\n",dp(n));
}

