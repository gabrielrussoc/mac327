#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef ll cood;
struct point {
    cood x, y;
    point () {}
    point (cood x, cood y):x(x), y(y) {}
    point operator+ (const point &o) {
        return point(x+o.x, y+o.y);
    }
    point operator- (const point &o) {
        return point(x-o.x, y-o.y);
    }
    cood operator* (const point &o) {
        return x*o.x + y*o.y;
    }
    cood operator^ (const point &o) {
        return x*o.y - o.x*y;
    }
    bool operator< (const point &o) const {
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
};

const int N = 11234;
point v[N];
int n,x,y, p[N];

int sgn(ll x) {
    return (x > 0) - (x < 0);
}

int orient (point a, point b, point c) {
    return sgn((b-a)^(c-a));
}


bool comp(int i, int j){
    int o = orient(v[p[0]], v[i], v[j]);
    return o == 1;   
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&x,&y);
        v[i] = point(x,y);
        p[i] = i;
    }
    for(int i = 1; i < n; i++)
        if(v[p[i]] < v[p[0]]) swap(p[i],p[0]); 

    sort(p+1,p+n,comp);
    if(p[0] > p[n/2]) swap(p[0],p[n/2]);
    printf("%d %d\n",p[0]+1,p[n/2]+1);
}

