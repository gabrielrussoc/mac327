#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 212345;
int n, m;
int a[N], b[N];

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    for(int i = 0; i < m; i++) scanf("%d",b+i);
    sort(a,a+n);
    for(int i = 0; i < m; i++)
        printf("%d ", upper_bound(a,a+n,b[i]) - a);
}

