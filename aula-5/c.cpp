#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
char s[N];
int z[N];
int n;

void zf () {
    int n = strlen(s);
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
    bool blank = false;
    while(scanf ("%d",&n) != EOF) {
        if(blank) putchar('\n');
        blank = true;
        scanf (" %s", s);
        s[n] = '$';
        scanf (" %s", s+n+1);
        zf();
        for (int i = 0; s[i]; i++) if(z[i] == n) printf("%d\n",i-n-1);
    }
}
