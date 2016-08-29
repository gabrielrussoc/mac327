#include <bits/stdc++.h>
#define pb push_back
#define hash xauhs
using namespace std;

typedef long long ll;
typedef unsigned long long hash;

const int N = 1123456;
hash h[N], x[N], X = 33;
char s[N];
int n, t, p[N], ans[N];

hash calc(int l, int r) {
    return h[r+1] - h[l]*x[r-l+1];
}

int main() {
    scanf("%d",&t);
    x[0] = 1;
    
    for(int tc = 1; tc <= t; tc++) {
        scanf("%d",&n);
        scanf(" %s",s);
        for(int i = 0; i < n; i++) {
            ans[i] = 1;
            x[i+1] = X*x[i];
            h[i+1] = h[i]*X + hash(s[i]-'a'+1);
        }
        printf("Test case #%d\n", tc);
        for(int i = 0; i < n; i++) {
            int j;
            int cont = 1;
            for(j = i+1; j < n-i; j += i+1) {
                if(calc(0,i) != calc(j, j+i))
                    break;
                ans[j+i] = max(ans[j+i], ++cont);
            }
        }
        for(int i = 1; i < n; i++)
            if(ans[i] > 1) printf("%d %d\n",i+1,ans[i]);
    }
}

