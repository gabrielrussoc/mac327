#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
char s[N];
int z[N];
int n;

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
    int mz = 0;
    for(int i = 1; i < n; i++) {
        if(z[i] == n-i && mz >= n-i) {
            puts(s+i);
            return 0;
        }
        mz = max(z[i],mz);
    } 
    puts("Just a legend");
}
