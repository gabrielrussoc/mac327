#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

int n;
int v[22], p[55];

void bt(int mask, int k) {
    if(k == n) {
        for(int i = 0; i < n; i++)
            printf("%d%c",v[i], " \n"[i==n-1]);
        return;
    }
    for(int i = 1; i < n; i++) {
        if(mask&(1<<i)) continue;
        if(!p[v[k-1] + i+1]) continue;
        if(k == n-1) if(!p[v[0] + i+1]) continue;
        v[k] = i+1;
        bt(mask|(1<<i), k+1);
    }
}

int main() {
    bool blank = false; 
    int tc = 1;
    v[0] = 1;
    for(int i = 2; i < 55; i++) {
        p[i] = 1;
        for(int j = 2; j*j <= i; j++)
            if(i%j == 0) 
                p[i] = 0;    
    }
    while (scanf("%d",&n) != EOF) {
        if(blank) putchar('\n');
        blank = true;
        printf("Case %d:\n", tc++);
        bt(0, 1);
    }
}

