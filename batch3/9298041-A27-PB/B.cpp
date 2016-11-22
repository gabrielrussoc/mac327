#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;

int n, m;
int a[N], b[N];

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    for(int i = 0; i < m; i++) scanf("%d",b+i);
    sort(b,b+m);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = lower_bound(b,b+m,a[i]) - b;
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        if(x < m) ans1 = b[x] - a[i];
        if(x > 0) ans2 = a[i] - b[x-1];
        ans = max(ans, min(ans1,ans2));
    }
    printf("%d\n",ans);

}

