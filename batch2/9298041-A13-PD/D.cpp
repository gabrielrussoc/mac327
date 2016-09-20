#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1024;
char s[N];
int p, lc[N], rc[N], sz[N], ts = 1;
vector<int> ans;

void get(int t, int l, int r) {
    if(!t) return;
    int k = sz[lc[t]]+l;
    ans.pb(k);
    get(lc[t],l, k-1);
    get(rc[t],k+1,r); 
}

int build() {
    int t = ts++;
    lc[t] = rc[t] = 0;
    p++;
    if(s[p] == ')') { sz[t] = 1; p++; }
    else {
        if(s[p] == '(') lc[t] = build();
        if(s[p] == ',') { p++; if(s[p] == '(') rc[t] = build(); }
        sz[t] = 1+sz[lc[t]] + sz[rc[t]];
        if(s[p] == ')') p++;
    }
    return t;
}

int main() {
    while (1) {
        scanf("%s",s);
        if(s[1] == ')') break;
        p = 0;
        ts = 1;
        ans.clear();
        int root = build();
        get(root, 1,ts-1);
        int q = ans.size();
        for(int i = 0; i < q; i++) printf("%d%c",ans[i], " \n"[i==q-1]); 
    }
}

