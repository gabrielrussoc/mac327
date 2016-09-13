#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 112345;
int z[N], n, ans, bit[N];
char s[N];

void add(int idx, int val) {
    for(int i = idx+2; i < N; i += i&-i)
        bit[i] += val;
}

int query(int idx) {
    int ret = 0;
    for(int i = idx+2; i > 0; i -= i&-i)
        ret += bit[i];
    return ret;
}

void upd(int r) {
    add(0,1);
    add(r+1,-1);
}

void zf () {
    int l, r;
    l = r = 0;
    for(int i = 1; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n && s[r] == s[r-l]) r++;
            z[i] = r-l; r--;
        } else {
            int k = i-l;
            if(z[k] < r-i+1) z[i] = z[k];
            else {
                l = i;
                while(r < n && s[r] == s[r-l]) r++;
                z[i] = r-l; r--;
            }
        }
    }
}

int main() {
    scanf(" %s",s);
    n = strlen(s);
    zf();
    for(int i = 1; i < n; i++) { 
        upd(z[i]);
        ans += (z[i] == n-i);
    }
    printf("%d\n",ans+1);
    for(int i = n-1; i > 0; i--)
        if(z[i] == n-i) printf("%d %d\n",z[i],query(z[i])+1);
    printf("%d 1\n",n);
}

