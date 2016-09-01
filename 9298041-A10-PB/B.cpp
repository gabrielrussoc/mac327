#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1000000+7;
int d[N];
int inf = INT_MAX;
int f,s,g,u,dow;

int main() {
    scanf("%d %d %d %d %d",&f, &s, &g, &u, &dow);
    for(int i = 1; i <= f; i++) d[i] = inf;
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(q.size()) {
        int at = q.front();
        q.pop();
        int nx = at+u;
        if(nx <= f && d[nx] > d[at] + 1) {
            q.push(nx);
            d[nx] = d[at]+1;
        }
        nx = at-dow;
        if(nx > 0 && d[nx] > d[at] + 1) {
            q.push(nx);
            d[nx] = d[at]+1;
        }
    }
    if(d[g] == inf) puts("use the stairs");
    else printf("%d\n",d[g]);
}

