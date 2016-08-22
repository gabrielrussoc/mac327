#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1123456;

char s[N], t[N];
char *p, *q;

char* cut(char *v) {
    while(*v == '0') v++;
    if(*v == 0) v[0] = '0', v[1] = 0;
    return v;
}

int main() {
    scanf(" %s %s",s,t);
    p = cut(s); q = cut(t);
    int n, m;
    n = strlen(p);
    m = strlen(q);
    if(n > m) puts(">");
    else if (n < m) puts("<");
    else {
        int k = strcmp(p,q);
        if(k > 0) puts(">");
        else if(k < 0) puts("<");
        else puts("=");
    }
}

