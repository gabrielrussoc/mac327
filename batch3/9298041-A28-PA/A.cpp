#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
    
int n, t;
const int N = 31234;
int a[N];

int main() {
    scanf("%d %d",&n,&t);
    t--;
    for(int i = 0; i < n - 1; i++) scanf("%d",a+i);
    int j = 0;
    while(j < n-1) {
        if(j == t) {
            puts("YES");
            return 0;
        }
        j += a[j];
    }
    if(j == t) puts("YES");
    else puts("NO");
}

