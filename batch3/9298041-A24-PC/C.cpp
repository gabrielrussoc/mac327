#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef complex<ll> point;
const int N = 112345;

ll x (point a) {
    return a.real();
}

ll y (point a) {
    return a.imag();
}

int n, p[N];
ll xin, yin;
point v[N];

bool comp(int i, int j) {
    if(x(v[i]) == x(v[j])) return y(v[i]) < y(v[j]);
    return x(v[i]) < x(v[j]);
}

ll cross(point a, point b) { return y(conj(a)*b); }
int sgn(ll x) { return (x > 0) - (x < 0); }
bool ok (point a, point b, point c) { return sgn(cross(b-a,c-a)); }

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld",&xin,&yin);
        v[i] = point(xin,yin);
        p[i] = i;
    }
    sort(p, p+n, comp);
    for(int i = 0; i < n-2; i++) {
        if(ok(v[p[i]], v[p[i+1]], v[p[i+2]])) {
            printf("%d %d %d\n",p[i]+1,p[i+1]+1,p[i+2]+1);
            return 0;
        }
    }
}

