#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 112345;
set<pii> r;
int n;
map<int, int> f;
int res[N][4];

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        f[x]++;
    }
    for(auto e : f) r.insert(pii(-e.second, e.first));
    int ans = 0;
    while (r.size() >= 3) {
        pii a = *r.begin();
        r.erase(a);
        pii b = *r.begin();
        r.erase(b);
        pii c = *r.begin();
        r.erase(c);
        res[ans][0] = a.second;   
        res[ans][1] = b.second;   
        res[ans][2] = c.second;   
        if(++a.first) r.insert(a);
        if(++b.first) r.insert(b);
        if(++c.first) r.insert(c);
        ans++;
    }
    printf("%d\n",ans);
    for(int i = 0; i < ans; i++) {
        sort(res[i], res[i] + 3);
        printf("%d %d %d\n", res[i][2], res[i][1], res[i][0]);
    }
}

