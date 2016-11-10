#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 11234;
int v[N], lc[N], rc[N], key[N], ts;

int add(int r, int val) {
    if(r == -1) {
        key[ts] = val;
        lc[ts] = rc[ts] = -1; 
        return ts++;
    }
    if(key[r] > val) lc[r] = add(lc[r], val);
    else rc[r] = add(rc[r], val);
    return r;
}

void show(int r){
    if(r == -1) return;
    show(lc[r]);
    show(rc[r]);
    printf("%d\n",key[r]);
}

int main() {
    int n = 0;
    while(scanf("%d",v+n) != EOF) n++;
    int r = -1;
    for(int i = 0; i < n; i++) r = add(r, v[i]);
    show(r);
}

