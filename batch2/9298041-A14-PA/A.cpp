#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

char a[7], b[7];
int mv[] = {1,2,-2,-1};
set<string> s;

void suc() {
    puts("YES");
    exit(0);
}

int main() {
    for(int i = 0; i < 4; i++) scanf(" %c",a+i);
    for(int i = 0; i < 4; i++) scanf(" %c",b+i);
    a[5] = b[5] = 0;
    int x;
    string t;
    for(int i = 0; i < 4; i++) if(a[i] == 'X') x = i;
    t = a;
    for(int i = 0; i < 12; i++) {
        s.insert(t);
        int nx = mv[x] + x;
        swap(t[x], t[nx]);
        x = nx;
    }
    for(int i = 0; i < 4; i++) if(b[i] == 'X') x = i;
    t = b;
    for(int i = 0; i < 12; i++) {
        if(s.count(t)) suc();
        int nx = mv[x] + x;
        swap(t[x], t[nx]);
        x = nx;
    }
    puts("NO");
}

