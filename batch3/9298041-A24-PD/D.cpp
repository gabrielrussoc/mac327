#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef int cood;

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

const int N = 55;
const double eps = 1e-9;

int n, m, xin, yin, visi[N][N], turn;
point p[1007], q[1007];
double memo[N][N];

double qd(double x){
    return x*x;
}

double norm (point a) {
    return sqrt(qd(a.x) + qd(a.y));
}

int sgn(int x){
    return (x > 0) - (x < 0);
}

bool orient(point a, point b){
    return sgn(a^b) < 0;
}

double dp(int i, int ls, int f, int a){
    if(i == n) {
        bool cant = false;
        for(int j = 0; j < m; j++)
            cant |= !orient(p[0]-p[ls], q[j]-p[ls]);
        if(cant || f < 3 || !a) return 1/0.;
        return norm(p[0]-p[ls]);
    }
    double &me = memo[i][ls];
    if(visi[i][ls] == turn) return me;
    visi[i][ls] = turn;
    bool cant = false;
    for(int j = 0; j < m; j++)
        cant |= !orient(p[i]-p[ls], q[j]-p[ls]);
    //printf("Para (%d,%d) cant = %d\n",ls,i,cant);
    if(cant) return 1/0.;
    int b = !!sgn((p[0]-p[ls])^(p[i]-p[ls]));
    me = min(dp(i+1, i, f+1, a|b) + norm(p[i]-p[ls]), dp(i+1,ls,f,a)); 
    return me;
}

void show(){
    puts("###");
    for(int i = 0; i < n ; i++)
        printf("%d %d\n",p[i].x,p[i].y);
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",&xin,&yin);
        p[i] = point(xin,yin);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&xin,&yin);
        q[i] = point(xin,yin);
    }
    double ans = 1/0.;
    for(int i = 0; i < n; i++){
        turn++;
        //show();
        ans = min(ans, dp(1,0,1,0));
        //printf("# %.2f\n",ans);
        rotate(p,p+1,p+n);
    }
    printf("%.2f\n",ans);
}

