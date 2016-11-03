#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

double qd (double x) {
    return x*x;
}

int n;
const double PI = acos(-1);
double r, xl, yl, xa, ya, xi, yi;

int main() {
    scanf("%d %lf",&n,&r);
    scanf("%lf %lf",&xi,&yi);
    xl = xi, yl = yi;
    double ans = 0;
    for(int i = 1; i < n; i++) {
        scanf("%lf %lf",&xa,&ya);
        ans += sqrt(qd(xa-xl) + qd(ya-yl));
        xl = xa; yl = ya;
    }
    ans += 2. * PI * r;
    ans += sqrt(qd(xl-xi) + qd(yl-yi));
    printf("%.2f\n",ans);
}

