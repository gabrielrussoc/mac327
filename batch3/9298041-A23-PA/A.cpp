#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

int main() {
    int n;
    scanf("%d",&n);
    double ans = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d",&x, &y);
        ans = max(ans, sqrt(x*x + y*y));
    }
    printf("0 0 %.10f\n",ans);
}

