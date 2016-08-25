#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int t, n, s, v[33];

int mdc(int a, int b) { return b ? mdc(b,a%b) : a; }

void bt(int sum, int q, int last) {
    if(q == n && sum < s) return;
    if(sum == s) {
        if(q != n) return;
        for(int i = 0; i < n; i++) printf("%d%c",v[i]," \n"[i==n-1]);
        return;
    } 
    for(int i = last; i <= (s-sum); i++) {
        bool go = true;
        for(int j = 0; j < q && go; j++) if(mdc(i,v[j]) > 1) go = false;
        if(!go) continue;
        v[q] = i;
        bt(sum+i, q+1,i);
    }
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%d %d",&s,&n);
        printf("Case %d:\n",tc);
        bt(0,0,1);
    }
}

