#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

char s[33];
int p[102], ps;

bool isp(int n) {
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0) return false;
    return true;
}

bool divisor(int n) {
    printf("%d\n", n);
    fflush(stdout);
    scanf(" %s", s);
    return strcmp(s, "yes") == 0;
}

int main() {
    for(int i = 2; i <= 100; i++)
        if(isp(i)) p[ps++] = i;

    int div = 0, cand;
    bool prime = true;
    for(int i = 0; i < 19; i++) {
        if(divisor(p[i])) {
            div++;
            cand = p[i];
        }
    }
    if(div == 1 && cand * cand <= 100)
        if(divisor(cand*cand)) div++;
    if(div > 1) prime = false;
    if(prime) puts("prime");
    else puts("composite");
    fflush(stdout);
}

