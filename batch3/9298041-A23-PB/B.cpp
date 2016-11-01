#include <bits/stdc++.h>
#define pb push_back
#define y0 uaehueah
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

set<pii> coef;
int n, x0, y0, x, y;

int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}

int main() {
    scanf("%d %d %d",&n,&x0,&y0);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",&x,&y);
        int num = y-y0;
        int den = x-x0;
        if(den == 0) coef.insert(pii(-1,-1));
        else {
            int g = gcd(num,den);
            coef.insert(pii(num/g,den/g));
        }
    }
    printf("%d\n",coef.size());
}

