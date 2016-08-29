#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 11234;
char s[N], t[N];
int m, l, r, k;

int main() {
    scanf(" %s",s);
    scanf("%d",&m);
    while(m--) {
        scanf("%d %d %d",&l,&r,&k); l--; r--;
        for(int i = l; i <= r; i++)
            t[(i-l+k)%(r-l+1)] = s[i];
        for(int i = l; i <= r; i++)
            s[i] = t[i-l];
    }
    puts(s);
}

