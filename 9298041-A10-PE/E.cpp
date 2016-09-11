#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 212345;

int n, m, k, x;
set<int> s[2*N];
int ans[N], pos[2*N], vis[2*N];
priority_queue<pii> q;

void fail() {
    puts("NO");
    exit(0);
}

int fix(int x) {
    if(x < 0) return abs(x) + m;
    return x;
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&k);
        for(int j = 0; j < k; j++) {
            scanf("%d",&x);
            s[i].insert(x);
            pos[fix(x)] = i;
        }
        q.push(pii(-s[i].size(), i));
    }

    while(q.size()) {
        int at = q.top().second;
        q.pop();

        if(vis[at]) continue;
        vis[at] = 1;

        if(s[at].empty()) fail();

        x = *s[at].begin();
        ans[abs(x)] = x>0;

        if(pos[fix(-x)]>0) {
            s[pos[fix(-x)]].erase(-x);
            q.push(pii(-s[pos[fix(-x)]].size(), pos[fix(-x)]));
        }
    }

    puts("YES"); 
    for (int i = 1; i <= m; i++) printf("%d", ans[i]);
    printf("\n");
}

