#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

typedef double cood;
const cood eps = 1e-9;

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
    bool operator== (const point &o) const {
        return fabs(o.x-x) < eps && fabs(o.y-y) < eps;   
    }
};

struct circle {
    point c;
    double r;
    circle () {}
    circle (point c, double r) : c(c), r(r) {}
};

const int N = 105;
circle v[N];

void fail(){
    puts("0");
    exit(0);
}

double qd(double x){
    return x*x;
}

double norm (point a){
    return sqrt(qd(a.x) + qd(a.y));
}

bool intersect(circle a, circle b) {
    return norm(b.c-a.c) < 2.*a.r + eps;
}

bool inside(point p, circle c){
    return norm(p-c.c) < c.r + eps;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d",&x,&y);
        v[i] = circle(point(x,y), 0);
    }
    int r, R;
    scanf("%d %d",&R,&r);
    if(r > R) fail();
    for(int i = 0; i < n; i++) v[i].r = R-r;

    vector<point> cand;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            if(!intersect(v[i],v[j])) continue;
            double b = .5 * norm(v[i].c-v[j].c);
            double r = v[i].r;
            double h = sqrt(qd(v[i].r) - qd(b));
            point m = point(.5*(v[i].c.x + v[j].c.x), .5*(v[i].c.y + v[j].c.y));
            point p = point(m.x + h*(v[j].c.y-v[i].c.y)/(2*b), m.y - h*(v[j].c.x-v[i].c.x)/(2*b));
            cand.pb(p);
            point q = point(m.x - h*(v[j].c.y-v[i].c.y)/(2*b), m.y + h*(v[j].c.x-v[i].c.x)/(2*b));
            if(p == q) continue;
            cand.pb(q);
        }

    int ans = 1;
    for(point p : cand){
        int loc = 0;
        for(int i = 0; i < n; i++)
            if(inside(p, v[i])) loc++;
        ans = max(ans, loc);
    }
    printf("%d\n",ans);
}

