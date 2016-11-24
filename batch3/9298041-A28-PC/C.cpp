#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 305;

int n, p[N], uf[N], wf[N];
char l[N];

int find(int i) {
    if(i == uf[i]) return i;
    return uf[i] = find(uf[i]);
}

void join(int i, int j) {
    i = find(i); j = find(j);
    if(i == j) return;
    if(wf[i] > wf[j]) swap(i,j);
    uf[i] = j;
    wf[j] += wf[i];   
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",p+i);
        uf[i] = i;
        wf[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        scanf(" %s", l);
        for(int j = 0; j < n; j++)
            if(l[j] == '1') join(i,j);
    }

    for(int i = 0; i < n; i++) {
        int bi, b;
        bi = i;
        b = p[i];
        for(int j = i; j < n; j++)
            if(find(i) == find(j) && p[j] < b) {
                b = p[j];
                bi = j;
            }
        swap(p[i], p[bi]);
    }
    for(int i = 0; i < n; i++) printf("%d ",p[i]);
    putchar('\n');

}

