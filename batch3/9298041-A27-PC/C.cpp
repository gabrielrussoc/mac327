#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 505;
int l[N], r[N], p[N], n;
int memo[N][N], visi[N][N];

bool comp(int i, int j) {
    int sza = r[i] - l[i];
    int szb = r[j] - l[j];
    return sza > szb;
}

//j eh o antigo
bool can(int _i, int _j) {
    int i = p[_i];
    int j = p[_j];
    return l[i] > l[j] && r[i] < r[j];
}

int dp(int i, int last) {
    if(i == n) return 0;
    int &me = memo[i][last];
    if(visi[i][last]) return me;
    visi[i][last] = 1;
    me = dp(i+1, last);
    if(can(i, last)) me = max(me, 1 + dp(i+1,i));
    return me;
}

void show(int i, int last) {
    if(i == n) return;
    if (can(i, last)) {
        if (1 + dp(i+1,i) > dp(i+1, last)) {
            show(i+1, i);    
            printf("%d ",p[i]+1);
        } else {
            show(i+1, last);
        }
    } else {
        show (i+1, last);
    }
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",l+i, r+i);
        p[i] = i;
    }
    sort(p, p+n, comp);
    p[501] = 501;
    l[501] = -INT_MAX;
    r[501] = INT_MAX;
    int ans = dp(0, 501);
    printf("%d\n",ans);
    show(0, 501);
    putchar('\n');
}

